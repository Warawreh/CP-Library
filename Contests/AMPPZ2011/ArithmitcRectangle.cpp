#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> a(n,vector<int>(m));
    vector<vector<bool>> g(n,vector<bool>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    int ans = 0;

    {
        vector<vector<int>> D(n,vector<int>(m));
        for(int j=0;j<m;j++){
            D[n-1][j] = 1;
            for(int i=n-2;i>=0;i--){
                if(i+2 < n && a[i+1][j] - a[i][j] == a[i+2][j] - a[i+1][j]){
                    D[i][j] = 1 + D[i+1][j];
                }else{
                    D[i][j] = 2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m-1;j++){
                ans = max(ans , min(D[i][j] , D[i][j+1]) * 2);
                ans = max(ans , D[i][j]);
            }
            ans = max(ans , D[i][m-1]);
        }

        //Find Arthi Right
        D = vector<vector<int>>(n,vector<int>(m));
        for(int i=0;i<n;i++){
            D[i][m-1] = 1;
            for(int j=m-2;j>=0;j--){
                if(j+2 < m && a[i][j+1] - a[i][j] == a[i][j+2] - a[i][j+1]){
                    D[i][j] = 1 + D[i][j+1];
                }else{
                    D[i][j] = 2;
                }
            }
        }

        for(int j=0;j<m;j++){
            for(int i=0;i<n-1;i++){
                ans = max(ans , min(D[i][j] , D[i+1][j]) * 2);
                ans = max(ans , D[i][j]);
            }
            ans = max(ans , D[n-1][j]);
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool good = true;

            int bad = 0;
            if(!i || i + 1 == n)bad++;
            if(!j || j + 1 == m)bad++;
            if(bad == 2)continue;

            if(j && j + 1 < m){
                for(int x=i-1;x<=i+1;x++)
                    if(x >= 0 && x < n && a[x][j] - a[x][j-1] != a[x][j+1] - a[x][j])good = false;
            }

            if(i && i+1 < n){
                for(int x=j-1;x<=j+1;x++)
                    if(x >= 0 && x < m && a[i][x] - a[i-1][x] != a[i+1][x] - a[i][x])good = false;
            }

            // if(i == 1 && j == 2)cerr << good << '\n';

            g[i][j] = good;
        }
    }
    a.clear();
    vector<vector<int>> D(n,vector<int>(m));
    //Find Arthi Down
    for(int j=0;j<m;j++){
        D[n-1][j] = g[n-1][j];
        for(int i=n-2;i>=0;i--){
            if(g[i][j])D[i][j] = D[i+1][j] + 1;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //         cerr << g[i][j] << ' ';
    //     cerr << '\n';
    // }
    // cerr << '\n';

    vector<vector<int>> toL(n,vector<int>(m)),toR(n,vector<int>(m));
    //Find Smallest to left
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            toL[i][j] = j-1;
            while(toL[i][j] != -1 && D[i][toL[i][j]] >= D[i][j]){
                toL[i][j] = toL[i][toL[i][j]];
            }
        }
    }
    //Find Smallest to right
    for(int i=0;i<n;i++){
        for(int j=m-1;j>=0;j--){
            toR[i][j] = j+1;
            while(toR[i][j] != m && D[i][toR[i][j]] >= D[i][j]){
                toR[i][j] = toR[i][toR[i][j]];
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j] == 0)continue;
            int fr = toL[i][j], to = toR[i][j];
            fr = max(fr , 0);
            to = min(to , m-1);
            if(i + D[i][j] < n)D[i][j]++;
            if(i)D[i][j]++;
            // cerr << i << ' ' << j << ' ' << fr << ' ' << to << ' ' << D[i][j] << '\n';
            ans = max(ans , ((to - fr + 1)) * (D[i][j]));
        }
    }
    cout << ans << '\n';
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
    
}
/*
    1- Look at base case (n=1,m=1)
    2- Overflow 
    3- Use assert
*/