#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct SegTree{
    typedef ll T;
    int n;
    vector<T> seg,lazy;
    const T oo = 0;

    SegTree(int _n){
        n = _n;
        seg = lazy = vector<T>(4*n);
    }

    void update(int l,int r,T val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            lazy[n] += val;
            if(lazy[n])seg[n] = e - s + 1;
            else{
                if(s == e)
                    seg[n] = 0;
                else{
                    seg[n] = seg[n+n] + seg[n+n+1];
                }
            } 
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);

        if(lazy[n])seg[n] = e - s + 1;
        else{
            seg[n] = seg[n+n] + seg[n+n+1];
        }
    }

    void update(int l,int r,T val){
        update(l,r,val,1,1,n);
    }

    void update(int at,T val){
        update(at,at,val,1,1,n);
    }

};

int main(){
    fast
    int n,m,d,l;
    cin>>n>>m>>d>>l;
    vector<int> a(n);

    SegTree tree(n);

    a[0] = 0;
    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        int fr = x - l;
        int to = x + l;
        int st = lower_bound(all(a) , fr) - a.begin();
        int ed = upper_bound(all(a) , to) - a.begin() - 1;
        // cerr << fr << ' ' << to << '\n';
        // cerr << '!' << st << ' ' << ed << '\n';
        // cerr << ' ' << a[st] << ' ' << a[ed] << '\n';
        tree.update(st+1,ed+1,1);
    }

    cout << tree.seg[1] << '\n';


    while(d--){
        {
            int x;
            cin>>x;
            int fr = x - l;
            int to = x + l;
            int st = lower_bound(all(a) , fr) - a.begin();
            int ed = upper_bound(all(a) , to) - a.begin() - 1;
            // cerr << '-' << st << ' ' << ed << '\n';
            tree.update(st+1,ed+1,-1);
        }
        {
            int x;
            cin>>x;
            int fr = x - l;
            int to = x + l;
            int st = lower_bound(all(a) , fr) - a.begin();
            int ed = upper_bound(all(a) , to) - a.begin() - 1;
            // cerr << '+' << st << ' ' << ed << '\n';
            tree.update(st+1,ed+1,1);
        }

        cout << tree.seg[1] << '\n';

    }


}

/*
    1- Look at base case (n=1,m=1)
    2- Overflow 
    3- Use assert
*/