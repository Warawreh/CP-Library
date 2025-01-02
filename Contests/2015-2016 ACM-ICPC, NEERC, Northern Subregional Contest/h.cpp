#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

map<ll,int> f;

int main(){
	// freopen("alex.in" , "r" , stdin);
	// freopen("alex.out" , "w" , stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int p = 1;
		int sum = 0;
		for(int j=s.size()-1;j>=0;j--){
			// s[j]--;
			// cout << (int)s[j] << ' ';
			sum = sum + s[j] * p;
			// cout << s[j] * p << '\n';
			p *= 31;
		}
		// cout << '\n';
		cout << s << ' ' << sum << '\n';
	}
}