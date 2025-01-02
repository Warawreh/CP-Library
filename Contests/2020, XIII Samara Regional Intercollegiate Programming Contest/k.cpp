#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	vector<int> a(4);
	int g = 0;
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	sort(all(a));
	if(a[0] - a[1] == a[2] - a[3] ){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
}