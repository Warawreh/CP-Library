#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(vector<int> a){
	sort(all(a));
	cout << "? " << a.size();
	for(int i : a)cout << ' ' << i;
	cout << '\n';
	fflush(stdout);
	int res;
	cin>>res;
	if(res == -1)assert(0);
	return res;
}

void answer(vector<int> a){
	cout << "! ";
	for(int i=0;i<a.size();i++){
		if(i)cout << ' ';
		cout << a[i];
	}
	cout << '\n';
	fflush(stdout);
	string res;
	cin>>res;
	assert(res == "Correct");
	return;
}

void solve(){
	int n,k;
	cin>>n>>k;
	vector<vector<int>> s(k);
	for(int i=0;i<k;i++){
		int x;
		cin>>x;
		s[i] = vector<int>(x);
		for(int j=0;j<x;j++)cin>>s[i][j];
	}
	int mx = 0;
	vector<int> a(n);
	iota(all(a) , 1);
	mx = ask(a);
	int md,lo=1,hi=n,at=-1;
	while(lo <= hi){
		md = (lo + hi)/2;
		vector<int> tmp;
		for(int x = lo;x<=md;x++)tmp.push_back(x);
		int x = ask(tmp);
		if(x == mx){
			hi = md-1;
			at = md;
		}else{
			lo = md+1;
		}
	}
	vector<int> ans(k,-1);
	for(int i=0;i<k;i++){
		bool good = 1;
		for(int j : s[i])if(j == at)good=0;
		if(good)ans[i] = mx;
		else{
			set<int> st;
			for(int j=1;j<=n;j++)st.insert(j);
			for(int j : s[i]){
				st.erase(j);
			}
			vector<int> tmp;
			while(st.size()){
				tmp.push_back(*st.begin());
				st.erase(st.begin());
			}
			ans[i] = ask(tmp);
		}
	}
	answer(ans);
}

int main(){
	// fast
	int t;
	cin>>t;
	while(t--)solve();
}