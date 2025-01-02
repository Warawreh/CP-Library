#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	int cnt = 0;
	while(t--){
		cnt++;
		string s;
		cin>>s;
		string a = s;
		a.pop_back();
		reverse(a.begin(),a.end());
		cout << "Case " << cnt << ": " << s << a << '\n';
	}	
}