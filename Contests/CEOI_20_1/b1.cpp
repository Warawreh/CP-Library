#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll sign(ll a){
	if(a == 0)return 0;//on it
	if(a > 0)return 1;//left
	if(a < 0)return -1;//right
	return 1;
}

ll side(pair<ll,ll> p,pair<ll,ll> s1,pair<ll,ll> s2){
	ll position = sign((s2.first - s1.first) * (p.second - s1.second) - (s2.second - s1.second) * (p.first - s1.first));
	return position;
}

struct Line{
	int x1,y1,x2,y2;
	void read(){
		cin>>x1>>y1>>x2>>y2;
		if(y2 < y1){
			swap(y2,y1);
			swap(x2,x1);
		}else if(y1 == y2 && x2 < x1){
			swap(y2,y1);
			swap(x2,x1);
		}
	}
	bool operator<(const Line r){
		ll s = side({x1,y1} , {r.x1,r.y1} , {r.x2,r.y2});
		assert(s == side({x2,y2} , {r.x1,r.y1} , {r.x2,r.y2}));
		if(s == 0)return y2 < r.y2;
		else return s == (x1 > x2 ? 1 : -1);
	}
};


int main(){
	fast
	int n;
	cin>>n;
	vector<Line> l(n);
	for(int i=0;i<n;i++)l[i].read();
	sort(all(l));
	for(int i=1;i<n;i++){
		cout << l[i-1].x2 << ' ' << l[i-1].y2 << ' ' << l[i].x1 << ' ' << l[i].y1 << '\n';
	}
}