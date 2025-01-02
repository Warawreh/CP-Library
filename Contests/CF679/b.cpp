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
	vector<int> s;
	vector<int> a(n);
	int at = 0;
	for(int t=0;t<2*n;t++){
		char c;
		cin>>c;
		if(c == '+'){
			s.push_back(at++);
		}else if(c == '-'){
			int v;
			cin>>v;
			int mx = 0;
			while(s.size() && s.back() < 0){
				mx = max(mx , -s.back());
				s.pop_back();
			}
			if(s.empty() || mx > v){
				cout << "NO\n";
				return 0;
			}
			a[s.back()] = v;
			s.pop_back();
			mx = max(mx , v);
			s.push_back(-mx);
		}else assert(0);
		// for(int i : s){
		// 	cerr << i << ' ';
		// }
		// cerr << '\n';
	}
	cout << "YES\n";
	for(int i : a){
		cout << i << ' ';
	}
}