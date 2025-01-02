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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n),nxt(n);
		vector<pair<int,int>> seg;
		int l = 0;
		set<int> st;
		for(int i=0;i<n;i++){
			cin>>a[i];
			st.insert(i);
			if(i && gcd(a[i-1] , a[i]) == 1){
				seg.push_back({l,i-1});
				l = i;
			}
		}
		st.insert(n);
		seg.push_back({l,n-1});
		vector<int> ans;
		while(seg.size() > 1){
			// cerr << "BEG\n";
			// for(int i=0;i<seg.size();i++)
			// 	cerr << seg[i].first << ' ' << seg[i].second << '\n';
			// cerr << "___________\n";
			vector<pair<int,int>> nxt;
			int sz = seg.size();
			for(int i=0;i<sz;i++){
				if(seg[i].first > seg[i].second)continue;
				if(gcd(a[seg[(i+1)%sz].first] , a[seg[i].second]) != 1)continue;
				st.erase(seg[(i+1)%sz].first);
				ans.push_back(seg[(i+1)%sz].first + 1);
				assert(st.size());
				seg[(i+1)%sz].first = *st.lower_bound(seg[(i+1)%sz].first);
			}
			for(int i=0;i<sz;i++){
				if(seg[i].first > seg[i].second)continue;
				if(nxt.size() && gcd(a[nxt.back().second] , a[seg[i].first]) != 1){
					nxt.back().second = seg[i].second;
				}
				else{
					nxt.push_back(seg[i]);
				}
			}
			seg = nxt;
			// cerr << seg.size() << '\n';
			// cerr << "After:\n";
			// for(int i=0;i<seg.size();i++)
			// 	cerr << seg[i].first << ' ' << seg[i].second << '\n';
			// cerr << "___________\n";
			// cerr << seg.size() << ' ' << st << '\n';
		}
		while(seg[0].first <= seg[0].second && gcd(a[seg[0].first] , a[seg[0].second]) == 1){
			st.erase(seg[0].first);
			ans.push_back(seg[0].first + 1);
			seg[0].first = *st.lower_bound(seg[0].first);
		}
		int lst = -1;
		for(auto it : st){
			if(it == n)break;
			if(lst != -1){
				if(gcd(a[lst] , a[it]) == 1){
					cerr << lst << ' ' << it << '\n';
					assert(0);
				}
				// assert;
			}
			lst = it;
		}
		cout << ans.size() << ' ';
		for(int i : ans)cout << i << ' ';
		cout << '\n';

	}
}