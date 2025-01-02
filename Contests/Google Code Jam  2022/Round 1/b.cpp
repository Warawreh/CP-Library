#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

vector<int> ask(vector<int> a){
	for(int i=0;i<n;i++){
		if(i)cout << ' ';
		cout << a[i];
	}
	cout << endl;
	fflush(stdout);
	vector<int> res(n);
	for(int i=0;i<n;i++)cin>>res[i];
	return res;	
}

void solve(){
	cin>>n;

	ll p2 = 1;
	vector<int> a;
	map<int,int> used;
	while(p2 <= 1e9){
		a.push_back(p2);
		used[p2] = 1;
		p2 *= 2;
	}

	for(int i=3;a.size() < n;i++){
		if(used[i])continue;
		a.push_back(i);
	}
	sort(all(a));
	vector<int> b = ask(a);
	vector<int> c = b;

	ll tot = 0;
	for(int i=0;i<n;i++){
		tot += a[i] + b[i];
		if(!used[a[i]]){
			c.push_back(a[i]);
		}
	}
	sort(all(c));
	assert(tot % 2 == 0);
	tot /= 2;

	bool pr=0;
	for(int i= c.size() - 1;i>=0;i--){
		if(tot >= 1e9){
			tot -= c[i];
			if(pr)cout << ' ';
			cout << c[i];
			pr = 1;
		}
	}

	for(int i=0;i<30;i++){
		if((tot >> i) & 1){
			if(pr)cout << ' ';			
			cout << (1 << i);
			pr = 1;
		}
	}
	cout << endl;
	fflush(stdout);
}

int main(){
	fast
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		solve();
	}
}