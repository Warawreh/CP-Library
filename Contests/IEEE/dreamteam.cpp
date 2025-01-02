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
    ll b;
    cin>>b;
    vector<vector<pair<int , string>>> a(5);
    for(int x=0;x<5;x++){
    	int sz;
    	cin>>sz;
    	a[x].resize(sz);
    	for(int i=0;i<sz;i++){
    		cin>>a[x][i].second>>a[x][i].first;
    	}
    }
    vector<pair<ll,string>> s12;
    for(int i=0;i<a[0].size();i++){
    	for(int j=0;j<a[1].size();j++){
    		s12.push_back({a[0][i].first + a[1][j].first , a[0][i].second + " " + a[1][j].second});
    	}
    }

    sort(all(s12) , [](pair<ll,string> a,pair<ll,string> b){
    	if(a.first == b.first){
    		return a.second > b.second;
    	}
    	return a.first < b.first;
    });


    ll ans = 0;
    string res;
    for(int i=0;i<a[2].size();i++){
    	for(int j=0;j<a[3].size();j++){
    		for(int k=0;k<a[4].size();k++){
    			ll cur = a[2][i].first + a[3][j].first + a[4][k].first;
    			if(cur >= b)continue;
    			ll need = b - cur;
    			pair<ll , string> tmp = {need + 1 , ""};
    			int at = lower_bound(all(s12) , tmp) - s12.begin();
    			if(at == 0)continue;
    			ll sum = cur + s12[at - 1].first;
    			string ord = s12[at-1].second + " " + a[2][i].second + ' ' + a[3][j].second + ' ' + a[4][k].second;
    			if(sum > ans){
    				ans = sum;
    				res = ord;
    			}else if(sum == ans)res = min(res , ord);
    		}
    	}
    }

    for(int i=0;i<res.size();i++){
    	if(res[i] == ' ')res[i] = '\n';
    }
    cout << res;
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/