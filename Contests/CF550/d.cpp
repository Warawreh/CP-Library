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
	int to = 0;
	int mx = 0;
	map<int,vector<int>> f;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		f[a[i]].push_back(i);
		
		if(f[a[i]].size() > mx){
			mx = f[a[i]].size();
			to = a[i];
		}
	}
	queue<int> q;
	for(int i : f[to]){
		q.push(i);
	}
	vector<vector<int>> e;
	while(q.size()){
		int i = q.front();
		q.pop();
		if(i - 1 >= 0){
			if(a[i-1] != to){
				if(a[i-1] > to){
					e.push_back({2,i-1,i});
				}else{
					e.push_back({1,i-1,i});
				}
				a[i-1] = to;
				q.push(i-1);
			}
		}
		if(i + 1 < n){
			if(a[i+1] != to){
				if(a[i+1] > to){
					e.push_back({2,i+1,i});
				}else{
					e.push_back({1,i+1,i});
				}
				a[i+1] = to;
				q.push(i+1);
			}	
		}
	}
	assert(e.size() == n - f[to].size());
	cout << e.size() << '\n';
	for(vector<int> a : e){
		cout << a[0] << ' ' << a[1] + 1 << ' ' << a[2] + 1 << '\n';
	}
}