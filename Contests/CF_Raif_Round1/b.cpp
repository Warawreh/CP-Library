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
	int tt;
	cin>>tt;
	while(tt--){
		int n;
		string s;
		cin>>n>>s;
		bool good = true;
		int a = 0,b=0;
		for(int i=0;i<n;i++){
			if(s[i] == '<')a++;
			if(s[i] == '>')b++;
		}
		if(a == 0 || b == 0){
			cout << n << '\n';
			continue;
		}
		vector<int> c(n,0);

		for(int i=0;i<n;i++){
			if(s[i] == '-'){
				c[i] = 1;
				c[(i+1)%n] = 1;
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++)ans += c[i];
		cout << ans << '\n';
	}
}

/*

1
7
->->-->


*/