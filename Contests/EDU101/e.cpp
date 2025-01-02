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
		int n,k;
		string s;
		cin>>n>>k>>s;
		vector<int> v;
		int l=0;	
		for(int i=0;i<k-1;i++){
			if(s[i] == '0')v.push_back(i);
		}
		set<int> st;
		for(int i=k-1;i<n;i++){
			if(s[i] == '0')v.push_back(i);
			if(i >= k && s[i-k] == '0')l++;

			if(v.size() - l <= 21){
				int a = 0;
				// cerr << i << ": \n";
				for(int j=l;j<v.size();j++){
					int b = k - 1 - (v[j] - (i-k+1));
					if(b > 21){
						// continue;
						a = 1e9;
						break;
					}
					// cerr << b << ' ';
					a |= (1 << b);
				}
				// cerr << '\n';
				// cerr << a << '\n';
				st.insert(a);
			}
		}
		int x = 0;
		for(auto it : st){
			if(it != x)break;
			x++;
		}
		string ans = "";
		while(x){
			ans += char('0' + x%2);
			x/=2;
		}
		while(ans.size() < k)ans += '0';
		reverse(all(ans));
		if(ans.size() > k)cout << "NO\n";
		else cout << "YES\n" << ans << '\n';

	}
}