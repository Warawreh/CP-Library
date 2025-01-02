#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const int LOG = 30;

int n , m , q;

int grid[N][N];

pair< int , int > st[N][N][LOG];

int dr[9] = {-1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1};
int dc[9] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1};

pair< int , int > getKth(int r,int c,int k){
    for(int nr , nc , i = LOG - 1;i >= 0;i--){
        if(r == -1)
            break;
        if(k >= (1 << i)){
            k -= (1 << i);
            nr = st[r][c][i].first;
            nc = st[r][c][i].second;
            r = nr;
            c = nc;
        }
    }
    return make_pair(r , c);
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int nr , nc , i = 0 ;i < n;i++){
        for(int j = 0 ;j < m;j++){
            scanf("%d",&grid[i][j]);
            nr = i + dr[grid[i][j]];
            nc = j + dc[grid[i][j]];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                st[i][j][0] = make_pair(-1 , -1);
            else
                st[i][j][0] = make_pair(nr , nc);
        }
    }
    for(int nr , nc , k = 1;k < LOG;k++){
        for(int i = 0 ;i < n;i++){
            for(int j = 0 ;j < m;j++){
                nr = st[i][j][k - 1].first;
                nc = st[i][j][k - 1].second;
                if(nr == -1)
                    st[i][j][k] = make_pair(-1 , -1);
                else
                    st[i][j][k] = st[nr][nc][k - 1];

            }
        }
    }
    int x1 , y1 , x2 , y2 , k;
    pair< int , int > tmp;
    while(q--){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&k);
        x1--,x2--,y1--,y2--;
        tmp = getKth(x1 , y1 , k - 1);
        if(max(abs(tmp.first - x2) , abs(tmp.second - y2)) <= 1){
            puts("Yes");
            continue;
        }
        bool good = false;
        for(int nr , nc , i = 0 ;i < 9;i++){
            nr = x1 + dr[i];
            nc = y1 + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            tmp = getKth(nr , nc , k - 1);
            //cout << nr << " " << nc << " " << k - 1 << " " << tmp.first << " " << tmp.second << endl;
            if(tmp.first == x2 && tmp.second == y2){
                good = true;
                break;
            }
        }
        if(good)
            puts("Yes");
        else
            puts("No");
    }

}
