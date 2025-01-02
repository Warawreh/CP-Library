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
	string s;
	cin>>s;
	int n = s.size();
	string k = "cba";
	int at = 0;
	vector<pair<int,int>> e;
	for(int i=n-1;i>=0;i--){	
		// cerr << i << ' ' << at << '\n';
		// cerr << s[i] << ' ' << k[at] << '\n';
		if(s[i] == k[at]){
			at++;
			if(at == 3)
				e.push_back({4,i+1});
			at%=3;
		}else{
			if(at == 0){
				if(s[i] == 'a'){
					e.push_back({1,i+1});
					e.push_back({2,i+2});
					e.push_back({4,i+1});
					at=0;
				}else if(s[i] == 'b'){
					e.push_back({2,i+1});
					at=2;
				}else{
					exit(1);
				}
			}else if(at == 1){
				if(s[i] == 'a'){
					e.push_back({1,i+1});
					e.push_back({4,i+1});
					at = 0;
				}else if(s[i] == 'c'){
					e.push_back({3,i+1});
					e.push_back({1,i+2});
					e.push_back({4,i+2});
					at = 1;
				}else{
					exit(2);
				}
			}else if(at == 2){
				if(s[i] == 'b'){
					e.push_back({2,i+1});	
					e.push_back({3,i+2});
					e.push_back({4,i+3});
					at = 2;
				}else if(s[i] == 'c'){
					e.push_back({3,i+1});
					e.push_back({4,i+2});
					at = 1;
				}else{
					exit(4);
				}
			}else exit(3);	
		}
	}
	if(at){
		cout << -1 << '\n';
		return 0;
	}
	assert(e.size() <= 3*n);
	cout << e.size() << '\n';
	for(pair<int,int> i : e)
		cout << i.first << ' ' << i.second << '\n';
}