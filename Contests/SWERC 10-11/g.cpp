#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
vector<int> fr,to,gr;
int T;
vector<vector<int>> g;

struct node{
	node* left;
	node* right;
	int id;
	node(){
		left = right = NULL;
		id = -1;
	}

	node(int i){
		left = right = NULL;
		id = i;
	}
};

struct lst{
	node* head;
	node* tail;

	lst(){
		head = tail = NULL;
	}

	void addNew(int id){
		if(head == NULL){
			head = new node(id);
			tail = head;
		}else{
			tail->right = new node(id);
			tail = tail->right;
		}
	}

	void erase(node* a){
		if(a == head)head = 	head->right;
		a->left->right = a->right;
		a->right->left = a->left;
	}
};

void dfs(int u,int p,int gg){
	gr[u] = gg;
	fr[u] = ++T;

	for(int &v : g[u]){
		if(v == p)continue;
		dfs(v,u,gg);
	}
	to[u] = T;
}

vector<pair<ll,pair<int,int>>> ed;

void solve(){
	int m;
	cin>>m;

	fr = to = gr = vector<int>(n);
	g.resize(n);
	ed.resize(m);

	for(int i=0;i<m;i++){
		cin>>ed[i].second.first>>ed[i].second.second>>ed[i].first;
	}
	sort(all(ed));

	ll res = 1e18;
	// set<int> chosn;

	lst chosn;
	int hv = 0;

	for(int i=0;i<m;i++){
		int &u = ed[i].second.first;
		int &v = ed[i].second.second;

		// cerr << u << ' ' << v << '\n';

		for(int j=0;j<n;j++){
			fr[j] = to[j] = 0;
			g[j].clear();
		}

		node* at;
		while(at != NULL){
			int it = at->id;
			int &a = ed[it].second.first;
			int &b = ed[it].second.second;
			g[a].push_back(b);
			g[b].push_back(a);
			at = at->right;
		}

		T = 0;

		for(int j=0;j<n;j++){
			if(fr[j])continue;
			dfs(j,-1,j);
		}


		if(gr[u] == gr[v]){//Remove edge with smallest index so the graph stay connected
			// cerr << u << ' ' << v << '\n';
			int fnd = -1;

			node* at = chosn.head;
			while(at != NULL){
				int it = at->id;
				int &a = ed[it].second.first;	
				int &b = ed[it].second.second;

				int cnt1 = (fr[u] >= fr[a] && fr[u] <= to[a]) + (fr[v] >= fr[a] && fr[v] <= to[a]);
				int cnt2 = (fr[u] >= fr[b] && fr[u] <= to[b]) + (fr[v] >= fr[b] && fr[v] <= to[b]);

				if(cnt1 == 1 || cnt2 == 1){
					chosn.erase(at);
					break;
				}
				at = at->right;
			}

		}else hv++;
		chosn.addNew(i);
		if(hv == n-1){
			int l = chosn.head->id;
			cerr << l << ' ' << i << '\n';
			res = min(res , ed[i].first - ed[l].first);
		}
		

	}
	cout << res << '\n';
}

int main(){
	fast
	while(1){
		cin>>n;
		if(!n)break;
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/