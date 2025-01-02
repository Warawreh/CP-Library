#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cout << string(n,char('0' + (i%2))) << '\n';
}