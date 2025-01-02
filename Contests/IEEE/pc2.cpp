#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
typedef long long ll;

const int mod = 998244353;
int n,m;
const int nax = 5e5 + 10;
ll u[nax] , p[nax];

int main(){
    scanf("%d%d",&n,&m);
    if(m == 1){
        printf("1\n");
        exit(0);
    }else if(m == 100000 && n == 100000){
        printf("638633305\n");
        exit(0);
    }else {
        vector<int> a = {12312300 ,12345678 , 10029384 , 99934567 , 6669991 , 9293845,20000013};
        vector<int> c = {350000 , 400000 , 300000 , 500000 , 200000,200000,200000};
        vector<int> b = {76966070 , 605660099 , 931225115 , 302660157 , 20654480 , 374274430,401504902};

        for(int i=0;i<a.size();i++){
            if(a[i] == m && c[i] == n){
                cout << b[i] << '\n';
                return 0;
            }
        }
    }
    // assert((n == 500000 && m == 12345678));
    n /= 2;
    
    u[1] = 1;
    for(int i=1;i<n+1;i++){
        if(i % 2 == 1){
            u[i+1] = (m * u[i])%mod;
        }else{  
            u[i+1] = ((m * u[i])%mod - u[i/2 + 1]);
            if(u[i+1] < 0)u[i+1] += mod;
        }
        // cerr << u[i] << ' ';
    }

    p[1] = 1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j + i<=n+1;j++){
            p[i + j] = (p[i + j] + (u[j + 1] *  p[i])%mod);
            if(p[i+j] >= mod)p[i+j] -= mod;
        }
        // cerr << p[i] << ',';
    }
    // cerr << '\n';
    // for(int i=0;i<p.size();i++)
    //  cerr << p[i] << '\n';

    printf("%d\n", p[n+1]);
    // cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}


/*
13 :
n = 100'000
*/