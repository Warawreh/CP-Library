#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> st;

void solve(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> b(m);
	vector<int> g;
	for(int i=0;i<m;i++){
		cin>>b[i].second>>b[i].first;
		g.push_back(b[i].first);
	}
	sort(all(b));
	for(int i=1;i<m;i++){
		int dif = b[i].first - b[i-1].first;
		if(dif % 2 == 0 && dif)g.push_back(b[i].first - 1);
	}
	sort(all(g));
	g.resize(unique(all(g)) - g.begin());
	st = vector<int>(g.size() , 0);
	for(int i=0;i<m;i++){
		b[i].first = lower_bound(all(g) , b[i].first) - g.begin();

		st[b[i].first] |= (1 << (b[i].second - 1));
	}
	// for(int i=0;i<st.size();i++)
	// 	cerr << st[i] << ' ';
	// cerr << '\n';
	bool good = true;
	if(st.size() == 1 && st[0] % 3 != 0)good = false;
	for(int i=1;i<st.size();i++){
		// if(st[i-1] == 3)continue;
		if(st[i] == 3 && st[i-1]%3 != 0){
			good = false;
			break;
		}
		if((st[i] == 1 && st[i-1] == 2) || (st[i] == 2 && st[i-1] == 1)){
			good = false;
			break;
		}
		if(st[i] == 0 && st[i-1] != 0){
			st[i] = 3 - st[i-1];
		}else if(st[i] == st[i-1] && st[i]){
			st[i] = st[i-1] = 3;
		}
		if(i == st.size() - 1 && st[i] != 3)good = false;
		// cerr << st[i] << '\n';
	}
	cout << (good ? "Yes\n" : "No\n");
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}