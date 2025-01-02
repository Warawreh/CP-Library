#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> dir = {{0,0},{1,0},{0,1},{1,1}};
vector<vector<int>> e;
vector<string> s;

void add (vector<int> a){
	e.back().push_back(a[0]);
	e.back().push_back(a[1]);
	if(s[a[0]][a[1]] == '0'){
		s[a[0]][a[1]] = '1';
	}else s[a[0]][a[1]] = '0';
	return;
}

void calc(int i,int j){
	int sum = 0;
	vector<vector<int>> p[2];
	for(int x=0;x<4;x++){
		int r = i + dir[x][0];
		int c = j + dir[x][1];
		p[s[r][c]-'0'].push_back({r,c});
		sum += s[r][c] - '0';
	}
	while(sum){
		if(sum == 1){
			e.push_back({});
			add(p[1][0]);
			add(p[0][0]);
			add(p[0][1]);
		}else if(sum == 2){
			e.push_back({});
			add(p[1][0]);
			add(p[0][0]);
			add(p[0][1]);
		}else if(sum == 3){
			e.push_back({});
			add(p[1][0]);
			add(p[1][1]);
			add(p[1][2]);
		}else if(sum == 4){
			e.push_back({});
			add(p[1][0]);
			add(p[1][1]);
			add(p[1][2]);
		}else assert(0);

		sum = 0;
		p[0].clear();
		p[1].clear();
		for(int x=0;x<4;x++){
			int r = i + dir[x][0];
			int c = j + dir[x][1];
			p[s[r][c]-'0'].push_back({r,c});
			sum += s[r][c] - '0';
		}
	}
}

void solve(){
	e.clear();
	int n,m;
	cin>>n>>m;
	s = vector<string>(n);

	for(int i=0;i<n;i++)cin>>s[i];

	if(n%2 && m%2 && s[n-1][m-1] == '1'){
		e.push_back({});
		add({n-1,m-1});
		add({n-2,m-2});
		add({n-1,m-2});
	}

	if(n % 2){
		for(int j=0;j<m;j+=2){
			if(j+1 >= m)break;
			if(s[n-1][j] == '1' && s[n-1][j+1] == '1'){
				e.push_back({});
				add({n-1,j});
				add({n-1,j+1});
				add({n-2,j});
			}else if(s[n-1][j] == '1'){
				e.push_back({});
				add({n-1,j});
				add({n-2,j+1});
				add({n-2,j});
			}else if(s[n-1][j+1] == '1'){
				e.push_back({});
				add({n-2,j+1});
				add({n-1,j+1});
				add({n-2,j});
			}
		}
	}
	if(m % 2){
		for(int i=0;i<n;i+=2){
			if(i+1 >= n)break;
			if(s[i][m-1] == '1' && s[i+1][m-1] == '1'){
				e.push_back({});
				add({i,m-1});
				add({i+1,m-1});
				add({i,m-2});
			}else if(s[i][m-1] == '1'){
				e.push_back({});
				add({i,m-1});
				add({i+1,m-2});
				add({i,m-2});
			}else if(s[i+1][m-1] == '1'){
				e.push_back({});
				add({i+1,m-2});
				add({i+1,m-1});
				add({i,m-2});
			}
		}
	}

	for(int i=0;i<n;i+=2){
		if(i + 1 >= n)break;
		for(int j=0;j<m;j+=2){
			if(j+1 >= m)break;
			calc(i,j);
		}
	}

	


	for(int i=0;i<n;i++){
		// cerr << s[i] << '\n';
		for(int j=0;j<m;j++){
			assert(s[i][j] == '0');
		}
	}
	// cerr << '\n';
	cout << e.size() << '\n';

	for(vector<int> a : e){
		for(int x : a){
			cout << x + 1 << ' ';
		}
		cout << '\n';
	}
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}