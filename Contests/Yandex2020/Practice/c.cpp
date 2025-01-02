#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	fast
	int n;
	cin>>n;
	if(n <= 2){
		cout << "Yes" << '\n';
		return 0;
	}
	vector<pair<ld,ld>> p;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t == 0){
			int r,x,y;
			cin>>r>>x>>y;
			p.push_back({x,y});
		}else{
			vector<int> a(4),b(4);
			for(int i=0;i<4;i++)cin>>a[i]>>b[i];
			sort(all(a));
			sort(all(b));
			p.push_back({(a[0] + a.back())/2.0 , (b[0] + b.back())/2.0});
		}
	}
	bool good = true;
	for(int i=2;i<n;i++){
		ld dy = p[i].second - p[0].second;
		ld dx = p[i].first - p[0].first;
		ld dy2 = p[1].second - p[0].second;
		ld dx2 = p[1].first - p[0].first;
		if(p[i] == p[0])continue;
		if(dx2 * dy != dy2 * dx && dx2 && dx && dy2 && dy)good = false;
		if((dx == 0 && dx2) || (dy == 0 && dy2) || 
			(dx && dx2 == 0) || (dy && dy2 == 0))
			good = false;
	}
	cout << (good ? "Yes\n" : "No\n");
}