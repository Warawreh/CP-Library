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
	while(t--){
		int n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		int sum = a+b+c+d;
		cout << (sum * 2 >= n+1 ? "Yes" : "No") << '\n';
	}	
}