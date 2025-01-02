#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
typedef long long ll;

double S(double a){return a*a;}

double dist(pair<int,int> p,pair<int,int> s1,pair<int,int> s2){
	double l = S(s1.first - s2.first) + S(s1.second-s2.second);
	if(l == 0)return S(s1.first - p.first) + S(s1.second-p.second);
	double t = ((p.first - s1.first) * (s2.first - s1.first) + (p.second - s1.second) * (s2.second - s1.second)) / l;
	t = max(0.0,min(1.0,t));
	double x = s1.first + t * (s2.first - s1.first);
	double y = s1.second + t * (s2.second - s1.second);
	double dis = S(p.first - x) + S(p.second - y);
	return sqrt(dis);
}

double dist(pair<int,int> p1,pair<int,int> p2){
	double res = S(p1.first - p2.first) + S(p1.second - p2.second);
	return sqrt(res);
}

double line_len(pair<int,int> s1,pair<int,int> s2){
	ll dist = S(s1.first - s2.first) + S(s1.second - s2.second);
	return dist;
}

int sign(ll a){
	if(a == 0)return 0;
	if(a > 0)return 1;
	if(a < 0)return -1;
	return -2;
}

int side(pair<ll,ll> p,pair<ll,ll> s1,pair<ll,ll> s2){
	int position = sign((s2.first - s1.first) * (p.second - s1.second) - (s2.second - s1.second) * (p.first - s1.first));
	return position;
}

bool perf(double a){
	double x = sqrt(a);
	return x*x == a;
}

int T;
void print(double ans){
	printf("Case %d: %.2f\n" ,++T,ans);
	return;
}

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n == 0)break;
		vector<pair<int,int>> p(n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].first,&p[i].second);
		}
		double ans = 1e18;
		for(int i=0;i<n;i++){
			double w = 0;
			for(int j=i+1;j<n;j++){
				double wl=-1,wr=-1;
				double worst=1e18;
				w = max(w , dist(p[i] , p[j]));
				for(int x=0;x<n;x++){
					int y = (x+1)%n;
					if(x == i || x == j)continue;

					w = max(w , dist(p[x] , p[i] , p[j]));

					if(y == i || y == j)continue;
					if(mp(x,y) == mp(i,j))continue;

					int s = side(p[x],p[i],p[j]);
					int s2 = side(p[y],p[i],p[j]);
					assert(s == s2);
					double D = 1e18;
					D = min(dist(p[y] , p[i] , p[j]),dist(p[x] , p[i] , p[j]));
					if(s == +1)wl = max(wl , D);
					if(s == -1)wr = max(wr , D);	
					if(x != i && x != j)
						worst = min(worst , dist(p[x] , p[i] , p[j]));
				}

				// cerr << i << ' ' << j << ' ' << wl << ' ' << wr << '\n';
				if(wl == -1 && wr == -1)wl = wr = 1e18;
				if(!wl && !wr)wl = wr = 1e9;
				wl = max(wl,0.0);wr = max(wr,0.0);
				ans = min(ans , max(wl + wr,worst));
				ans = min(ans , line_len(p[i],p[j]));
			}
			if(w != 0)ans = min(ans , w);
		}
		ans = ceil(ans * 100)/100.0;
		print(ans);
	}
}