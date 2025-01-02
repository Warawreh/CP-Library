#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()

int main(){
	freopen("hash.in" , "r" , stdin);
	freopen("hash.out" , "w" , stdout);
	int n;
	cin>>n;
	string ans(n,'a');
	string tmp = ans;
	for(int i=0;i<n;i++){
		ans = tmp;
		if(i){
			ans[i-1] = 'B';
			ans[i] = 'b';
		}
		reverse(all(ans));
		cout << ans << '\n';
	}
}