#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<int,vector<pair<int,int>>> up,r;

struct node{
	node *l,*r;
	ll lazy,val;
	int sz;
	node(){
		l = r = NULL;
		sz = 1;
		lazy = val = 0;
	}
	void pro(){
		val += lazy * sz;
		if(l != NULL)l->lazy += lazy;
		if(r != NULL)r->lazy += lazy;
		lazy = 0;
	}
	void marge(node *lhs,node *rhs){
		sz = lhs->sz + rhs->sz;
		val = lhs->val + rhs->val;
	}
};

const int TO = 1e6 + 100;
node *head;

void update_range(int l,int r,ll val,node *&n = head,int s = 1,int e = TO){
	if(n == NULL)n = new node();
	n->pro();
	if(s > r || e < l || l > r)return;
	if(s >= l && e <= r){
		n->lazy += val;
		n->pro();
		return;
	}
	update_range(l , r , val , n->l , s , (s+e)/2);
	update_range(l , r , val , n->r , (s+e)/2+1 , e);
	n->marge(n->l,n->r);
}

ll get(int l,int r,node *& n = head,int s = 1,int e = TO){
	if(n == NULL)return 0;
	n->pro();
	if(s > r || e < l || l > r)return 0LL;
	if(s >= l && e <= r)return n->val;
	ll a = get(l , r , n->l , s , (s+e) / 2);
	ll b = get(l , r , n->r , (s+e)/2+1 , e);
	return a + b;
}

int main(){
	fast
	int h,v;
	head = new node();
	cin>>h>>v;
	for(int i=0;i<h;i++){
		int y,x1,x2;
		cin>>y>>x1>>x2;
		if(x1 == 0 && x2 == 1e6){
			r[y].clear();
			r[y].push_back({x1,x2});
		}else if(x1 == 0){
			if(r[y].empty()){
				r[y].push_back({x1,x2});
			}else{
				r[y][0].second = max(r[y][0].second,x2);
			}
		}else if(x2 == 1e6){
			if(r[y].empty()){
				r[y].push_back({0,0});
			}
			if(r[y].size() < 2){
				r[y].push_back({2e9,1e6});
			}
			r[y][1].first = min(r[y][1].first , x1);
		}else assert(0);
		if(r[y].size() == 2){
			if(r[y][0].second >= r[y][1].first){
				r[y].clear();
				r[y].push_back({0,1e6});
			}
		}
	}

	for(int i=0;i<v;i++){
		int y,x1,x2;
		cin>>y>>x1>>x2;
		if(x1 == 0 && x2 == 1e6){
			up[y].clear();
			up[y].push_back({x1,x2});
		}else if(x1 == 0){
			if(up[y].empty()){
				up[y].push_back({x1,x2});
			}else{
				up[y][0].second = max(up[y][0].second,x2);
			}
		}else if(x2 == 1e6){
			if(up[y].empty()){
				up[y].push_back({0,0});
			}
			if(up[y].size() < 2){
				up[y].push_back({2e9,1e6});
			}
			up[y][1].first = min(up[y][1].first , x1);
		}else assert(0);
		if(up[y].size() == 2){
			if(up[y][0].second >= up[y][1].first){
				up[y].clear();
				up[y].push_back({0,1e6});
			}
		}
	}
	ll ans = 1;
	vector<vector<int>> event;
	for(auto it : r){
		if(it.second.size() >= 1){
			if(it.second[0].first == 0 && it.second[0].second == 1e6)ans++;
			if(it.second[0].first || it.second[0].second)
				event.push_back({it.first,1,it.second[0].first,it.second[0].second});
		}
		if(it.second.size() == 2){
			if(it.second[1].first || it.second[1].second)
				event.push_back({it.first,1,it.second[1].first,it.second[1].second});
		}
	}
	for(auto it : up){
		if(it.second.size() >= 1){
			if(it.second[0].first == 0 && it.second[0].second == 1e6)ans++;
			event.push_back({it.second[0].first,0,it.first,1});
			event.push_back({it.second[0].second,2,it.first,-1});
		}
		if(it.second.size() == 2){
			event.push_back({it.second[1].first,0,it.first,1});
			event.push_back({it.second[1].second,2,it.first,2});
		}
	}
	sort(all(event));
	for(int i=0;i<event.size();i++){
		// cerr << event[i][0] << ' ' << event[i][1] << '\n';
		if(event[i][1]%2 == 0){//update
			update_range(event[i][2] + 1,event[i][2] + 1,event[i][3]);
		}else{//ask
			ans += get(event[i][2] + 1 , event[i][3] + 1);
		}
	}
	cout << ans << '\n';
}