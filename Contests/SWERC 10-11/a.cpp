#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<ld,ld> merge(vector<pair<ld,ld>> r){
	sort(all(r));
	ld st = r[0].first;
	ld to = r[0].second;
	for(int i=0;i<r.size();i++){
		if(r[i].first <= to)to = max(to , r[i].second);
		else break;
	}
	return {st,to};
}

int main(){
	fast
	while(1){
		int a,b;
		ld w;
		cin>>a>>b>>w;
		w/=2;
		if(a == 0 && b == 0 && w == 0.0)break;

		pair<ld,ld> tot,tot2;
		{
			vector<pair<ld,ld>> r;
			for(int i=0;i<a;i++){
				ld x;
				cin>>x;
				r.push_back({max((ld)0.0 , x - w) , min((ld)75.0 , x + w)});
			}

			tot = merge(r);
		}

		{
			vector<pair<ld,ld>> r;
			for(int i=0;i<b;i++){
				ld x;
				cin>>x;
				r.push_back({max((ld)0.0 , x - w) , min((ld)100.0 , x + w)});
			}

			tot2 = merge(r);
		}


		if((tot.first == 0 && tot.second == 75.0) && (tot2.first == 0 && tot2.second == 100.0))
			cout << "YES\n";
		else cout << "NO\n";

	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/