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
    string s;
    cin>>s;
    int n = s.size();
    int z=0;
    ll tot = 0;
    for(int i=n-1;i>=0;i--){
    	if(s[i] == '0')z++;
    	else tot += z;
    }
    cout << (tot % 3 == 0 ? "Bob\n" : "Alice\n");
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/