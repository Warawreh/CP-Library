#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

vector<int> results = {21,8,7,9,11};
int cur = 0;

int ask(vector<ld> s){
    for(int i=0;i<3;i++)
        cout << s[i] << ' ';
    cout << endl;
    return results[cur++];
    fflush(stdout);
    int res;
    cin>>res;
    return res;
}

const double EPS = 1e-9;
const int INF = 2; 


int gauss (vector < vector<ld> > a,vector<ld> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col){
        int sel = row;
            for (int i=row; i<n; ++i)
 if (abs (a[i][col]) > abs
(a[sel][col]))
 sel = i;
 if (abs (a[sel][col]) < EPS)
 continue;
 for (int i=col; i<=m; ++i)
 swap (a[sel][i], a[row][i]);
 where[col] = row;
 for (int i=0; i<n; ++i)
 if (i != row) {
 ld c = a[i][col] /
a[row][col];
 for (int j=col; j<=m; ++j)
 a[i][j] -= a[row][j] * c;
 }
 ++row;
 }
 ans.assign (m, 0);
 for (int i=0; i<m; ++i)
 if (where[i] != -1)
 ans[i] = a[where[i]][m] /
a[where[i]][i];
 for (int i=0; i<n; ++i) {
 ld sum = 0;
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
    vector<vector<ld>> q = {
        {1,5,4},
        {2,4,2},
        {3,3,1},
        {4,2,3},
        {5,1,5}
    };

    vector<int> res(5);
    for(int i=0;i<5;i++){
        res[i] = ask(q[i]);
    }

    map<vector<int>,int> f;

    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            for(int k=j+1;k<5;k++){
                vector<vector<ld>> cur = {q[i], q[j], q[k]};
                cur[0].push_back(res[i]);
                cur[1].push_back(res[j]);
                cur[2].push_back(res[k]);

                vector<ld> ans(3);
                int res = gauss(cur, ans);
                if(res != 1)continue;

                vector<int> tmp;
                for(int l=0;l<3;l++){
                    tmp.push_back(round(ans[l]));
                }

                bool good = true;

                // cerr << tmp[0] << ' ' << tmp[1] << ' ' << tmp[2] << '\n';
                for(int l=0;l<3;l++){
                    if(tmp[0] * cur[l][0] + tmp[1] * cur[l][1] + tmp[2] * cur[l][2] != cur[l][3]){
                        good = false;
                    }
                }
                cerr << i << ' ' << j << ' ' << k << '\n';
                cerr << good << '\n';
                if(good){
                    f[tmp]++;
                }
            }
        }
    }

    for(auto x : f){
        if(x.second >= 4){
            cout << x.first[0] << ' ' << x.first[1] << ' ' << x.first[2] << endl;
            fflush(stdout);
        }
    }
}
