#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int r,c;
	cin>>r>>c;
	vector<string> s(r*2+1,string(c*2+1,'.'));
	for(int i=1;i<2*r+1;i+=2){
		for(int j=1;j<2*c+1;j+=2){
			s[i-1][j] = '-';
			s[i-1][j-1] = '+';
			s[i-1][j+1] = '+';

			s[i][j-1] = '|';
			s[i][j+1] = '|';

			s[i+1][j-1] = '+';
			s[i+1][j] = '-';
			s[i+1][j+1] = '+';
		}
	}

	s[0][0] = s[0][1] = s[1][0] = '.';

	for(int i=0;i<r*2+1;i++)
		cout << s[i] << '\n';

}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": " << '\n';
		solve();
	}
}