#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Line{
	int x1,y1,x2,y2;
	Line(int a=0,int b=0,int c=0,int d=0){
		x1 = a;y1 = b;x2 = c;y2 = d;
	}
	void read(){
		cin>>x1>>y1>>x2>>y2;
		if(y2 < y1){
			swap(y2,y1);
			swap(x2,x1);
		}
	}
	bool operator<(const Line r){
		if(x2 == r.x2){
			return y2 < r.y2;
		}else{
			return x2 < r.x2;
		}
	}
};

struct P{
	int x,y,i;
	P(int a=0,int b=0,int c=0){
		x = a;y = b;i = c;
	}
};

ld get_clockwise_angle(const P& p){   
    return atan2(p.y, p.x);
}

ll S(ll a){return a*a;}
vector<P> p;
vector<ld> ang;

bool comp(int x,int y){
	P l = p[x],r = p[y];
	ld a = ang[x],b = ang[y];
	if(a == b)return S(l.x) + S(l.y) > S(r.x) + S(r.y);
	return a < b;
}


vector<int> dsu,sz,rnk;

void init(int n,int x){
	dsu = sz = rnk = vector<int> (n+x);
	iota(dsu.begin()+x,dsu.end(),x);
	fill(sz.begin(),sz.end(),1);
}

int find(int u){
	return u == dsu[u] ? u : dsu[u] = find(dsu[u]);
}

void merge(int u,int v){
	u = find(u);
	v = find(v);
	if(u == v)return;
	if(sz[u] < sz[v])swap(u,v); // enable for fast dsu
	// if(rnk[u] > rnk[v])swap(u,v);
	sz[u] += sz[v];
	rnk[v] = rnk[u] + 1;
	dsu[v] = u;
}

int main(){
	fast
	int n;
	cin>>n;
	vector<Line> l(n);
	p.resize(2*n);
	ang.resize(2*n);
	init(2*n,0);
	for(int i=0;i<n;i++){
		l[i].read();
		p[i*2] = P(l[i].x1,l[i].y1,i);
		p[i*2+1] = P(l[i].x2,l[i].y2,i);
		ang[i*2] = get_clockwise_angle(p[i*2]);
		ang[i*2+1] = get_clockwise_angle(p[i*2+1]);
		merge(i*2,i*2+1);
	}
	vector<int> id(2*n);
	iota(all(id),0);
	sort(all(id),comp);
	vector<Line> ans;
	for(int i=1;i<id.size();i++){
		int u = id[i];
		int v = id[i-1];
		if(find(u) == find(v))continue;
		merge(u,v);
		ans.push_back(Line(p[v].x,p[v].y,p[u].x,p[u].y));
	}
	assert(ans.size() == n-1);
	for(auto i : ans)cout << i.x1 << ' ' << i.y1 << ' ' << i.x2 << ' ' << i.y2 << '\n';
}