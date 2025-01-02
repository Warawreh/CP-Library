#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<pair<ll,ll>> p;
int n;
ll l,r;

const ld eps = 1e-8;

inline ld S(ld a){return a*a;}

inline ld D(pair<ld,ld> a,pair<ld,ld> b){
	return sqrt(S(a.first - b.first) + S(a.second - b.second));
}

void fixIt(int &dx,int &dy){
	if(dy < 0){
		dy = -dy;
		dx = -dx;
	}

	if(dy == 0)dx = 1;
	if(dx == 0)dy = 1;

	int g = gcd(dx,dy);
	dx /= g;
	dy /= g;

}

ll count2(){
	ll res = 0;
	for(int i=0;i<n;i++){
		map<pair<int,int> , vector<ld>> lines;
		for(int j=0;j<n;j++){
			if(p[i] == p[j])continue;

			int dx = p[i].first - p[j].first;
			int dy = p[i].second - p[j].second;
			
			fixIt(dx,dy);

			ld len = D(p[i] , p[j]);
			
			// if(i < j)cerr << i << ' ' << j << ' ' << len << '\n';

			lines[{dx , dy}].push_back(len);
		}
		for(auto &it : lines)
			sort(all(it.second));

		for(int j=0;j<n;j++){
			if(p[i] == p[j])continue;

			int dx = p[i].first - p[j].first;
			int dy = p[i].second - p[j].second;
			fixIt(dx,dy);

			ld len = D(p[i] , p[j]);

			{
				int nx = -dy;
				int ny = dx;

				fixIt(nx,ny);


				vector<ld> &tmp = lines[{nx , ny}];	
				
				{
					ld val = r / len;
					res += upper_bound(all(tmp) , val + eps) - tmp.begin();
				}

				{
					ld val = l / len;
					res -= lower_bound(all(tmp) , val - eps) - tmp.begin();
				}
				// if(i == 0)cerr << res << '\n';
			}
		}
	}

	return res/2;
}

void solve(){
	
	cin>>n>>l>>r;
	p.clear();
	p.resize(n);

	for(int i=0;i<n;i++){
		cin>>p[i].first >> p[i].second;
	}

	l*=2;
	r*=2;

	cout << count2() << '\n';
}

int main(){
	fast
	freopen("points.in","r",stdin);	


	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/