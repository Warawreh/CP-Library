#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    vector<node*> nxt;
    ll val;

    node(){
        nxt = vector<node*>(26,nullptr);
        val = 0;
    }
};

node* head = new node();

void add(string &s,int val){
    node* cur = head;
    for(char &c : s){
        int v = c-'a';
        if(cur->nxt[v] == nullptr)cur->nxt[v] = new node();
        cur = cur->nxt[v];
    }
    cur->val = val;
}

ll get(string &s){
    node* cur = head;
    ll res = 0;
    for(char &c : s){
        int v = c-'a';
        cur = cur->nxt[v];
        res += cur->val;
    }
    return res;
}

int main(){
    fast
    int n ; cin >> n ;
    
    vector< pair<string,ll> > v(n);
    for( int i = 0 ; i < n ; i++ ) cin >> v[i].first >> v[i].second ;

    vector<int> id(n);
    iota(all(id) , 0);
    sort(all(id) , [&](int a,int b){
        return v[a].first.size() < v[b].first.size();
    });

    ll ans = 0 ;
    for( int i : id){
        add(v[i].first , v[i].second);
        ans = max(ans , get(v[i].first));
    }
    cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/