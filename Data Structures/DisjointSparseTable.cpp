/*
Name: Disjoint Sparse Table
Description: Used to find assositve functions for a range in constant time
Time: O(NLogN) to build the table and O(1) for each query
Space: O(NlogN)
Note: assositve functions (min , max , sum , product , division, counting)
*/

struct DST{

    vector<vector<ll>> table;
    vector<ll> a;
    int mxLvl;
    
    DST(){}
    DST(int LOG){init(LOG);}
    void init(int LOG){
        table = vector<vector<ll>>(LOG + 1,vector<ll>((1<<LOG)));
        mxLvl = LOG + 1;
    }
    void build(int lvl,int l,int r){

        int md = (l + r) / 2;

        table[lvl][md] = a[md] % p;
        for(int i=md-1;i>=l;i--){
            table[lvl][i] = (table[lvl][i+1] * 1LL * a[i])%p;
        }

        if(md + 1 < r){
            table[lvl][md+1] = a[md+1] % p;
            for(int i=md+2;i<r;i++){
                table[lvl][i] = (table[lvl][i-1] * 1LL * a[i])%p;       
            }
        }

        if(l+1 != r){
            build(lvl + 1, l , md);
            build(lvl + 1, md , r);
        }
    }
    void build(vector<ll> &A){
        a = A;
        int n = a.size();
        int log = 0;
        while((1 << log) < n)log++;
        while(a.size() < (1 << log))a.push_back(0);
        init(log);
        build(0,0,(1<<log));
    }

    ll query(int l,int r){
        if(l == r)return a[l] % p;

        int k2 = __builtin_clz(l^r) ^ 31;//if used ll replace 31 with 63
        int lvl = mxLvl - 1 - k2 - 1;

        int ans = table[lvl][l];
        if(r & ((1<<k2) - 1))ans = (ans * 1LL *  table[lvl][r]) % p;

        return ans;
    }

};