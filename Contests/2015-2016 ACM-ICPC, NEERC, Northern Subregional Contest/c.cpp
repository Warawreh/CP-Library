#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

int main(){
	freopen("concatenation.in" , "r" , stdin);
	freopen("concatenation.out" , "w" , stdout);
	string a,b;
	cin>>a>>b;
	vector<int> l(26);
	for(int i=1;i<a.size();i++)l[a[i] - 'a']++;
	ll ans = a.size() * 1ll * b.size();
	for(int i=b.size()-2;i>=0;i--)ans -= l[b[i] - 'a'];
	cout << ans << '\n';
}