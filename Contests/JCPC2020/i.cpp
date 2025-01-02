#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e6+10;
const int mod = 998244353;

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.precision(10);
cout << fixed;
	freopen("one.in" , "r" , stdin );

	int n;cin>>n;
	vector<int> a,b;
	map<int,int> m;
	bool ok = false;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		m[x]++;
		if(m[x]==2) ok = true;
		a.push_back(x);
		b.push_back(x);
	}
	sort(b.begin(), b.end());
	int c = 0;
	for(int i=0;i<n;i++)
		c += (a[i]!=b[i]);
	if(c == 2 || (c == 0 && ok))cout<<"YES\n";
	else cout<<"NO\n";
}