#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(4);
	cout << fixed;
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int q,c = 0;
	cin>>q;
	while(q-- && ++c){
		int r;
		cin>>r;
		cout<<"Case "<<c<<": "<<.25 * r * r<<endl;
	}
	
}