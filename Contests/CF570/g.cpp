#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	vector<pair<int,int>> f(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		f[a[i]].first++;
		f[a[i]].second += b[i];
	}
	sort(all(f));
	int sum = 0 , ans=0;
	int at = f.back().first;
	vector<int> seq;
	for(int i=n;i>=0;i--){
		at = min(at , f[i].first);
		sum += max(0,at);
		if(at > 0)seq.push_back(at);
		at--;
	}
	reverse(all(seq));
	multiset<int> st;
	at = f.back().first;
	for(int i=n;i>=0;i--){
		at = min(at , f[i].first);
		while(seq.size() && at < seq.back()){
			at = min(at , f[i].first);
			// cerr << i << ' ' << at << ' ' << seq.back() << ' ' << st.size() << '\n';
			assert(st.size());
			ans += min(seq.back() , *st.rbegin());
			if(st.size()){
				auto it = st.end();
				it--;
				st.erase(it);
			}
			if(at == seq.back()){
				st.insert(f[i].second);
				i--;
			}
			seq.pop_back();
			at--;
		}
		st.insert(f[i].second);
	}

	cout << sum << ' ' << ans << '\n';
}

int main(){
	fast
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}