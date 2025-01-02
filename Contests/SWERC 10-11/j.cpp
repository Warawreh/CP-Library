#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const double EPS = 1e-9;
const int INF = 2;

int gauss (vector < vector<ld> > a, vector<ld> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    bool bad = false;
    for (int i=0; i<m; ++i)
        if (where[i] != -1){
            ans[i] = a[where[i]][m] / a[where[i]][i];
            // cerr << ans[i] << ' ';
            if(ans[i] <= 0 || ans[i] >= 1)bad = true;
        }
    // cerr << '\n';
    if(bad)return 0;
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;
    return 1;
}

int main(){
    fast
    
    while(1){
        vector<vector<ld>> a(4,vector<ld>(4));
        vector<ld> ans(3);

        cin>>a[0][0]>>a[1][0]>>a[2][0];
        if(a[0][0]+a[1][0]+a[2][0] == 0)break;
        for(int i=1;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>a[j][i];
            }
        }
        a[3] = {1,1,1,1};
        for(int i=0;i<3;i++){
            cin>>a[i][3];
        }


        vector<int> x = {0,1,2};

        bool good = false;
        if(gauss(a,ans) >= 1){
            good = true;
        }

        if(good)cout << "YES\n";
        else cout << "NO\n";
    }
}

/*
    1- Look at base case (n=1,m=1)
    2- Overflow 
    3- Use assert
*/