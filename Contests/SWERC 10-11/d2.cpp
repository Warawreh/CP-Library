#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;

bool can(int st,int skip,vector<int> t,vector<pair<int,int>> p){


	for(int i=st;i<t.size();i++){
		sort(all(p));

		// cerr << t[i] << '\n';

		// for(int j=0;j<p.size();j++)
		// 	cerr << p[j].first << ' ';
		// cerr << '\n';

		int rem = t[i];

		for(int j=p.size()-1;j>=0;j--){
			if(p[j].second < skip)continue;
			if(!rem)break;
			if(p[j].first == 0){
				// cerr << i << ' ' << j << ' ' << p[j].first << ' ' << p[j].second << ' ' << rem << '\n';
				return false;
			}
			p[j].first--;
			rem--;
		}

		skip = 0;



	}

	for(int i=0;i<p.size();i++){
		if(p[i].first != 0)return false;
	}

	return true;

}

void solve(){
	vector<int> t(n);
	vector<pair<int,int>> p(m);
	for(int i=0;i<n;i++){
		cin>>t[i];
		t[i] = m-t[i];
	}

	for(int i=0;i<m;i++){
		cin>>p[i].first;
		p[i].first = n-p[i].first;
		p[i].second = i;
	}

	if(!can(0,0,t,p)){
		cout << "Impossible\n\n";
		return;
	}

	for(int i=0;i<n;i++){
		string cur="";

		for(int j=0;j<m;j++){
			if(t[i] == 0 || p[j].first == 0){
				cur += 'Y';
			}else{
				t[i]--;
				p[j].first--;
				if(can(i,j+1,t,p)){
					cur += 'N';
				}else{
					t[i]++;
					p[j].first++;
					cur += 'Y';
				}

			}
		}
		cout << cur << '\n';
	}
	cout << '\n';
}

int main(){
	fast
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)break;
		solve();
	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/