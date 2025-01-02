#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

int main(){
	cout << setprecision(3);
	cout << fixed;
	freopen("alex.in" , "r" , stdin);
	freopen("alex.out" , "w" , stdout);
	double h,w;
	cin>>w>>h;
	double ans = 0;
	ans = max(ans,min(w/2,h/2));
	ans = max(ans,min(w/3,h));
	ans = max(ans,min(w,h/3));
	cout<<ans<<endl;
}