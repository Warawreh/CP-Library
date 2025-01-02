#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> g;
int d;
string dir = "><^v";
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n;
vector<pair<int,int>> dd;

vector< vector<ll> > vis ,onCycle;
int toD;
pair<int,int> head;

void dfs(int r,int c,int dist){
    if( vis[r][c] != -1 ){
        toD = dist;
        head = {r,c};
        return ;
    }
    vis[r][c] = dist;
    // cerr << r << ' ' << c << ' ' << dist << '\n';

    for(int i=0;i<4;i++){
        if(g[r][c] != dir[i])continue;
        int nr = r + dx[i];
        int nc = c + dy[i];
        dfs(nr , nc , dist + 1);
    }
}

void dfs2(int r,int c){
    if( onCycle[r][c] != -1 ){
        return ;
    }
    onCycle[r][c] = 1;

    for(int i=0;i<4;i++){
        if(g[r][c] != dir[i])continue;
        int nr = r + dx[i];
        int nc = c + dy[i];
        dfs2(nr , nc);
    }
}

void solve(){
    scanf("%d",&n);

    g.clear();
    g.resize(n);
    head = {0,0};
    vis = onCycle = vector< vector<ll> > ( n , vector<ll> ( n , -1 ) );

    for(int i=0;i<n;i++)cin>>g[i];


    dfs( 0 , 0 , 0 );
    dfs2( head.first , head.second);

    int l = toD - vis[head.first][head.second];
    ll ans = 1e10;  

    scanf("%d",&d);

    ll g = gcd(d , l);
    vector<pair<int,int>> dd(d);

    for(int i=0;i<d;i++){
        int r,c;
        cin>>r>>c;
        dd[i] = {r,c};
        if(onCycle[r][c] == -1){
            if(vis[r][c] != -1){
                if(vis[r][c] % d == i){
                    ans = min(ans , vis[r][c]);
                }
            }
        }else{
            int tr = vis[r][c]%d;
            int tc = (i - tr + d)%d;
            // cerr << tc << ' ' << g << '\n';
            if(tc % g == 0){
                
                tc = i;
                tr = vis[r][c];
                ll a = 0;
                while(1){
                    if(a * l + tr >= ans)break;
                    if((a * l + tr - tc) >= 0 && (a * l + tr - tc) % d == 0){
                        ans = min(ans , a * 1LL * l + tr);
                        break;
                    }
                    a++;
                }

            }
        }
    }

    for(int i=0;i<d;i++){
        int r = dd[i].first;
        int c = dd[i].second;
        if(onCycle[r][c] == -1){
            continue;
        }else{
            int tr = vis[r][c]%d;
            int tc = (i - tr + d)%d;
            // cerr << tc << ' ' << g << '\n';
            if(tc % g == 0){
                
                tc = i;
                tr = vis[r][c];
                ll a = 0;


                while(a < 2){
                    if(a * l + tr >= ans)break;
                    if((a * l + tr - tc) >= 0 && (a * l + tr - tc) % d == 0){
                        ans = min(ans , a * 1LL * l + tr);
                        break;
                    }
                    a++;
                }

            }
        }
    }

    if(ans >= 1e9)printf("never\n");
    else printf("%d\n",ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/