#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m;
int calc(int k, vector<int> a, vector<int> b){
	vector<int> hv(n+1,0);

	for(int i=0;i<m;i++)hv[b[i]]++;
	for(int i=0;i<n;i++)a[i] = k - a[i];

	int ans = 0;
	int bf = 0;

	vector<int> st;
	for(int i=0;i<n;i++){
		if(a[i] <= 0){
			ans++;
			continue;
		}

		while(hv.size() > 1 && bf < a[i]){
			bf += hv.back();
			st.push_back(hv.back());
			hv.pop_back();
		}

		if(bf < a[i])break;

		int extra = a[i] - bf + st.back();
		hv.back() += extra;
		st.back() -= extra;
		bf -= extra;

		if(st.size() > 1){
			st[st.size() - 2] += st.back();
			st.pop_back();
		}

		ans++;

	}
	return ans;
}

int main(){
	fast
	cin>>n>>m;
	vector<int> a(n),b(m);

	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];

	sort(all(a));
	reverse(all(a));
	sort(all(b));

	ll q;
	cin>>q;
	while(q--){
		ll k;
		cin>>k;

		cout << calc(k , a , b) << ' ';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow
	3- Use assert
*/