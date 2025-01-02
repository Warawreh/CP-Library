#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ld> v,o;

vector<ld> Pow(vector<ld> v,ll b){
	if(!b)return {0,1};
	vector<ld> res = Pow(v,b/2);
	vector<ld> nxt(2);
	nxt[0] = res[0] * res[1] + res[1] * res[0];
	nxt[1] = res[1] * res[1] + res[0] * res[0];
	res = nxt;
	if(b%2){
		nxt[0] = res[0] * v[1] + res[1] * v[0];
		nxt[1] = res[1] * v[1] + res[0] * v[0];
	}
	// cerr << b << ' ' << nxt[0] << ' ' << nxt[1] << ' ' << v[0] << ' ' << v[1] << '\n';
	return nxt;
}

int main(){
	fast
	int n;
	ld p;
	cin>>n>>p;
	o = {p,1-p};
	cout << setprecision(10) << fixed << Pow(o,n)[1] << '\n';
}