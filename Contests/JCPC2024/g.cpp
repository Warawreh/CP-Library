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
    cin >> n;
    if(n <= 2) return cout << -1 << endl, 0;
    int bPrime = n;
    while(bPrime > 0){
        bool flag = true;
        for(int i = 2; i*i<= bPrime ; ++i){
            if(bPrime% i == 0){
                flag =false;
                break;
            }
        }
        if(flag) break;
        bPrime--;
    }
    cerr << bPrime << endl;
    cout << bPrime / 2 << " " << bPrime / 2 << " " << bPrime - (bPrime / 2) * 2 << endl;
}
