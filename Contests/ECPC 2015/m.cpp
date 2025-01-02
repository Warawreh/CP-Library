#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct point_2d{
	ld x , y ;
	point_2d operator-( point_2d p ){ return { x - p.x , y - p.y }; }
};
ld S( ld x ){ return x*x;}
ld dis( point_2d df ){ return sqrt( S(df.x) + S(df.y) );}

const int nax = 1010;
ld dp[nax];
bool vis[nax];
int n ; 
vector<point_2d> p;

ld calc(int i){
	if(i == n)return 0;
	ld &ret = dp[i];
	if(vis[i])return ret;
	ret = 1e18;
	vis[i] = 1;

	vector<point_2d> q = {p[i]};

	ld cur = 0;
	for(int j=i+1;j<n;j++){

		while(q.size() > 1 ){//p[j]
			point_2d pdf = q[q.size()-1] - q[q.size()-2] ;
			point_2d cdf = p[j] - q[q.size()-2] ;
			if( atan2( pdf.y , pdf.x ) <= atan2( cdf.y , cdf.x ) ){
				cur -= dis(pdf);
				q.pop_back();
			}else break;

		}

		q.push_back(p[j]);
		point_2d pdf = q[q.size()-1] - q[q.size()-2] ;
		// cerr << i << ' ' << j << ' ' << q.size() << ' ' << cur << ' ' << calc(j+1) << '\n';
		cur += dis(pdf);

		ret = min(ret , cur + calc(j+1));

	}

	return ret;
}

void solve(){
	cin >> n ;
	
	p = vector<point_2d>(n) ;
	for( int i = 0 ; i < n ; i++ ) cin >> p[i].x >> p[i].y ;
	for(int i=0;i<nax;i++){
		vis[i] = 0;
		dp[i] = 0;
	}
	
	cout << calc(0) << '\n';
}
int main(){
	fast
    cout << setprecision(6) << fixed;

	int t ; cin >> t ;
	while( t-- )solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/

/*
ld ans = 0 ;
int cp = 0 , np = 1 ;
while( true ){
	// cerr << p[cp].x << " " << p[cp].y << " " << cp << '\n';
	for( int i = cp + 1 ; i < n ; i++ ){
		point_2d df = p[i] - p[cp] ;
		point_2d mdf = p[np] - p[cp] ;
		if( atan2( df.y , df.x ) >= atan2( mdf.y , mdf.x ) ) np = i ;
		// cerr << i << " " << atan2( df.y , df.x ) << '\n';
	}
	// cerr << np << "?? \n";
	point_2d mdf = p[np] - p[cp] ;		
	if( (np == n-1) || (np-cp > 1) || (cp == 0) ){
		ans += dis(mdf);
	}
	cp = np ;
	np = np+1;
	// cerr << cp << " " << n-1 << endl; 
	if( cp == n-1 ) break;
}
*/