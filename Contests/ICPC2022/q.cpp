#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    fast
    int n;
    cin>>n;
    
    ll mv = 0;
    int rem = 0;
    int at = n + 1;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x < at){
            rem += at - x;
            at = x;
        }
        rem--;
        mv += rem;
    }

    cout << setprecision(3) << fixed << n + mv * 0.5 << '\n';
}
