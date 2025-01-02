#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
    fast
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
	int dif = a[0];
	for(int i=1;i<n;i++)dif = max(dif , a[i] - a[i-1]);
	if(a[1] <= dif){
		cout << 0 << '\n';
		return 0;
	}
	for(int i=2;i<n;i++){

		if(a[i] - a[i-2] <= dif){
			cout <<  0 << '\n';
			return 0;
		}

	}
	cout << dif << '\n';
}
