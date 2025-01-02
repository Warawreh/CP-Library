#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	int n;
	cin>>n;
	int d = (n < 0 ? -1 : 1);
	n *= d;
	for(int i=0;i<=n;i+=3){
		cout << i*d << '\n';
	}
}