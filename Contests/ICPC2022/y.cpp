#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    fast
    string s;
    cin>>s;
    string cur = "";
    
    int n = s.size();

    for(int i=0;i<n;i++){
        while(cur.size() >= 1){
            if(cur.back() == s[i])cur.pop_back();
            else break;
        }

        while(cur.size() >= 3){
            int sz = cur.size();
            if(cur[sz - 3] == cur[sz - 1] && cur[sz - 2] == s[i]){
                cur.pop_back();
                cur.pop_back();
            }else break;
        }

        cur += s[i];
    }

    cout << cur << '\n';
}
