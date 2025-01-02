#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
    fast
    int n,m;
    cin>>n>>m;
    vector<int> sz(m);
    for(int i=0;i<m;i++)cin>>sz[i];

    vector<vector<int>> customer(n),resturant(m);
    string s;
    getline(cin,s);
    for(int i=0;i<n;i++){
        getline(cin, s);
        istringstream in(s);
        int r;
        while(in>>r){
            customer[i].push_back(r-1);
        }
        reverse(all(customer[i]));
    }

    map<pair<int,int>,int> ord;
    for(int i=0;i<m;i++){
        getline(cin, s);
        istringstream in(s);
        int r;
        while(in>>r){
            if(!r)break;
            ord[{r-1,i}] = resturant[i].size();
            resturant[i].push_back(r-1);
        }   
    }

    vector<int> curC(n);
    iota(all(curC) , 0);
    vector<int> ans;
    vector<int> added(m,-1);
    vector<set<int>> rest(m);
    bool done = false;

    for(int c=0;c<n;c++){
        int to = customer[c].back();
        customer[c].pop_back();
        rest[to].insert(ord[{c,to}]);
    }

    while(!done){
        done = true;

        for(int r=0;r<m;r++){
            while(rest[r].size() > sz[r]){
                done = false;

                int c = *rest[r].rbegin();
                rest[r].erase(c);
                c = resturant[r][c];
                if(customer[c].empty())continue;
                int to = customer[c].back();
                customer[c].pop_back();
     
                rest[to].insert(ord[{c,to}]);
            }
        }
       
    }

    for(int r=0;r<m;r++){
        for(int c : rest[r]){
            ans.push_back(resturant[r][c]);
        }
    }

    sort(all(ans));
    for(int i : ans){
        cout << i + 1<< '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/