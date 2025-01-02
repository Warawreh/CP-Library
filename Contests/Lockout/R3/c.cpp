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
	vector<string> g(3);
	for(int i=0;i<3;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(isalpha(s[j])){
				g[i] += tolower(s[j]);
			}
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		string tmp;
		cin>>s;
		for(int j=0;j<s.size();j++){
			if(isalpha(s[j])){
				tmp += tolower(s[j]);
			}
		}
		bool good= 0;
		for(int x=0;x<3;x++){
			for(int y=0;y<3;y++){
				for(int z=0;z<3;z++){

				// cerr << g[x] + g[y] << ' ' << tmp << '\n';
				if(g[x] + g[y] + g[z] == tmp)
					good = 1;
				}
			}
		}
		// cout << tmp << '\n';
		cout << (good ? "ACC" : "WA") << '\n';
	}
}