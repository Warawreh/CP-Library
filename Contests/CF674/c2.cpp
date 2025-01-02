#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 5, MOD = 1e9 + 7;

int t, n, m, a, b, c, d;

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans = 1e9;
		for(int i = 1; i <= min(n,63244); i++){
			ans = min(ans,i - 1 + n / i - (n % i == 0));
		}
		printf("%d\n",ans);
	}
    return 0;
}
