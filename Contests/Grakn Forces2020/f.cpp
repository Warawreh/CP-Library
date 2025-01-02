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
	int nxt = 1;
	vector<pair<int,int>> ans;
	vector<vector<int>> a;

	for(int i=1;i<=n;i++)a.push_back({i});
	while(1){
		int to = 1;
		vector<vector<int>> nxt;
		sort(all(a),[](vector<int> x , vector<int> y){
			return x.size() < y.size();
		});
		bool done = 0;
		cerr << a.size() << '\n';
		for(vector<int> x : a){
			cerr << x.size() << ' ';
		}
		cerr << '\n';
		for(int i = 0;i<a.size();i++){
			if(i + 1 < a.size() && a[i].size() == a[i+1].size()){
				vector<int> tmp;
				for(int j=0;j<a[i].size();j++){
					ans.push_back({a[i][j] , a[i+1][j]});
					tmp.push_back(a[i][j]);
					tmp.push_back(a[i+1][j]);
				}
				sort(all(tmp));
				nxt.push_back(tmp);
				i++;
				done = 1;
			}else if(i+1 < a.size() && a[i].size() > 1 && a[i].size() * 2 == a[i+1].size()){
				vector<int> tmp;
				for(int j=0;j<a[i+1].size;j+=2){
					
				}
				for(int j=0;j<a[i].size();j++){
					ans.push_back({a[i][j*2] , a[i+1][j]});
					ans.push_back({a[i][j*2+1] , a[i+1][j]});
					tmp.push_back(a[i][j]);
					tmp.push_back(a[i+1][j]);
				}
				sort(all(tmp));
				nxt.push_back(tmp);
				i++;
				done = 1;
			}else{
				vector<int> tmp;
				for(int j : a[i]){
					tmp.push_back(j);
				}
				sort(all(tmp));
				nxt.push_back(tmp);
				if(i+1<a.size()){
					vector<int> tmp;
					for(int j : a[i+1]){
						tmp.push_back(j);
					}
					sort(all(tmp));
					nxt.push_back(tmp);
				}
				break;
			}
		}
		// cerr << nxt.size() << '\n';
		if(!done){
			break;
		}
		a = nxt;
	}
	if(n >= 4){
		ans.push_back({n-1,n});
		ans.push_back({n-3,n-1});
		ans.push_back({n-2,n});
	}
	assert(ans.size() <= (int)5e5);
	cout << ans.size() << '\n';
	for(auto i : ans)
		cout << i.first << ' ' << i.second << '\n';
}