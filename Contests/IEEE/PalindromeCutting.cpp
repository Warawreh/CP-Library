#include <bits/stdc++.h>

using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(0);
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int mod = 998244353;
int n,m;
const int nax = 2.5e5 + 10;
long long u[nax] , p[nax];

int main(){
    scanf("%d%d",&n,&m);
    if(m == 1){
        printf("1\n");
        exit(0);
    }
    n /= 2;
    
	u[1] = 1;
	for(int i=1;i<n+1;i++){
		if(i % 2 == 1){
			u[i+1] = (m * u[i])%mod;
		}else{
			u[i+1] = ((m * u[i])%mod - u[i/2 + 1] + mod)%mod;
		}
	}

	p[1] = 1;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<=i;j++){
    		p[i+1] = (p[i+1] + (u[j+1] * p[i-j+1])%mod)%mod;
		}
		// cerr << p[i] << '\n';
	}

    printf("%d\n", p[n+1]);

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
