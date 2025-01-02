#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<string,ld> val;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int c,n;
		scanf("%d %d" , &c , &n);

		for(int i=0;i<c;i++){
			string s;
			ld v;
			cin>>s;
			scanf("%lf" , &v);
			val[s] = v;
		}
		val["JD"] = 1;

		ld ans = 0;
		for(int i=0;i<n;i++){
			ld v;
			string s;
			scanf("%lf" , &v);
			cin>>s;
			ans += v * val[s];
		}
		printf("%.6lf\n", ans);
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/