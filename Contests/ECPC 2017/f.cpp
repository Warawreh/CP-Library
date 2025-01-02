#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ld eps = 1e-13;

ld S(ld a){
	return a*a;
}

ld dist(ld x0,ld y0,ld x1,ld y1,ld x2,ld y2){
	ld l = S(x1 - x2) + S(y1-y2);
	if(l == 0)return sqrt(S(x0 - x1) + S(y0 - y1));
	ld t = ((x0 - x1) * (x2 - x1) + (y0 - y1) * (y2 - y1)) / l;
	t = max((ld)0.0,min((ld)1.0,t));
	ld x = x1 + t * (x2 - x1);
	ld y = y1 + t * (y2 - y1);
	ld dis = S(x0 - x) + S(y0 - y);
	return sqrt(dis);
}


ld len(ld x0,ld y0, ld x1,ld y1){
	return sqrt( S(x0 - x1) + S(y0 - y1) );
}

void solve(){
	int n;
	cin>>n;
	vector<pair<ld,ld>> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].first>>p[i].second;
	}

	int q;
	cin>>q;
	while(q--){
		ld x0,y0,x1,y1;
		cin>>x0>>y0>>x1>>y1;

		ld ans = 1e18;
		pair<ld,ld> at = {0,0};
		bool taken = 0;

		for(int i=0;i<n;i++){

			pair<ld,ld> p1 = p[i];
			pair<ld,ld> p2 = p[(i+1)%n];

			//find L , d1 , D1 , d2 , D2 , 
			ld d1 = dist(x0,y0 , p1.first , p1.second , p2.first , p2.second);
			ld d2 = dist(x1,y1 , p1.first , p1.second , p2.first , p2.second);

			ld D1,D2;
			if(len(x0,y0 , p1.first , p1.second) - len(x1,y1 , p1.first , p1.second) < eps){
				D1 = len(x0,y0 , p1.first , p1.second);
				D2 = len(x1,y1 , p2.first , p2.second);				
			}else{
				D1 = len(x0,y0 , p2.first , p2.second);
				D2 = len(x1,y1 , p1.first , p1.second);
				swap(p1,p2);
			}

			ld v1 = sqrt(S(D1) - S(d1));
			ld v2 = sqrt(S(D2) - S(d2));

			ld lenAll =  len(p1.first , p1.second , p2.first , p2.second);
			ld L = lenAll - v1 - v2;

			ld x = L * d1 / (d1 + d2) + v1;

			ld per = x / lenAll;

			ld dx = -(p1.first - p2.first) * per + p1.first;
			ld dy = -(p1.second - p2.second) * per + p1.second;

			if(!taken || len(x0,y0 , dx,dy) + len(x1,y1,dx,dy) - ans < eps){
				ans = len(x0,y0 , dx,dy) + len(x1,y1,dx,dy);
				at = {dx,dy};
				taken = 1;
			}

		}

		cout << ans << ' ' << at.first << ' ' << at.second << '\n';
	}
}



int main(){
	fast
	cout << setprecision(7) << fixed;

	freopen("flags.in","r",stdin);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case " << T << ":\n";
		solve();
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/