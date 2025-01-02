#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string to_binary(char c){
	int res;
	if(isalpha(c))res = 10 + c - 'a';
	else res = c - '0';
	string s;
	for(int i=0;i<4;i++){
		s += char('0' + res%2);
		res /= 2;
	}
	reverse(all(s));
	return s;
}

int r,c;
vector<string> g;
vector<vector<int>> idx;
vector<int> hols;

void dfs_one(int i,int j,int col){
	if(i < 0 || j < 0 || i == r || j == c || g[i][j] == '0' || idx[i][j] != 0)return;
	// if(i == 12 )cerr << j << ' ' << r << ' ' << col << '\n';
	// cerr << ' ' << i << ' ' << j << ' ' << col << '\n';
	idx[i][j] = col;
	dfs_one(i+1,j,col);
	dfs_one(i-1,j,col);
	dfs_one(i,j+1,col);
	dfs_one(i,j-1,col);
}

set<int> st;

void dfs_zero(int i,int j){
	if(i < 0 || j < 0 || i == r || j == c){
		st.insert(0);
		return;
	}
	if(g[i][j] == '1'){
		st.insert(idx[i][j]);
		return;
	}
	if(idx[i][j] != 0)return;
	idx[i][j] = 1;
	dfs_zero(i+1,j);
	dfs_zero(i-1,j);
	dfs_zero(i,j+1);
	dfs_zero(i,j-1);
}

void solve(){
	int T = 0;
	g = vector<string> (r);
	for(int i=0;i<r;i++){
		string t;
		cin>>t;
		for(int j=0;j<c;j++){
			g[i] += to_binary(t[j]);
		}
	}

	c *= 4;
	idx = vector<vector<int>> (r,vector<int> (c*4,0));
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(g[i][j] == '1')
				// cerr << i << ' ' << j << '\n';
			if(!idx[i][j] && g[i][j] == '1'){
				dfs_one(i,j,++T);
			}
		}
	}
	hols = vector<int>(T+1,0);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(!idx[i][j] && g[i][j] == '0'){
				st.clear();
				dfs_zero(i,j);
				// cerr << st.size() << '\n';
				if(st.size() == 1){
					hols[*st.begin()]++;
				}
			}
		}
	}
	string ans;
	string type = "WAKJSD";
	for(int i=1;i<=T;i++){
		// cerr << i << ' ' << hols[i] << '\n';
		ans += type[hols[i]];
	}
	sort(all(ans));
	cout << ans << '\n';
}

int main(){
	fast
	for(int Test=1;;Test++){
		cin>>r>>c;
		if(!r && !c)break;
		cout << "Case " << Test << ": ";
		solve();
	}	
}