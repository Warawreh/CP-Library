#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int c;

const int nax = 1e6 + 3;
const int kax = 322;
short dp[kax][nax];

vector<pair<int,string>> py,ans;

short calc(int h,int c){
	if(h == -1){
		// cerr << c << '\n';
		return (c == 0 ? 0 : SHRT_MAX - 400);
	}
	if(c == 0)return 0;
	if(c < 0)return SHRT_MAX - 400;
	short &ret = dp[h][c];
	if(ret != -1)return ret;
	ret = min((int)calc(h-1,c)  , 1 + calc(h-1,c - py[h].first));
	// cerr << h << ' ' << c << ' ' << c - cost_high(h) << ' ' << c - cost_low(h) << ' ' << c - cost_high(h) - cost_low(h) << '\n';
	return ret;
}

void build(int h,int c){
	if(h == -1)return;
	// cerr << h << ' ' << c << '\n';
	if(calc(h,c) == 1 + calc(h-1,c - py[h].first)){
		ans.push_back(py[h]);
		c -= py[h].first;
	}
	build(h-1,c);
}

void solve(){
	ans.clear();
	if(calc(py.size() - 1,c) > 1000){
		cout << "impossible\n";
		return;
	}else{
		build(py.size() - 1,c);
		sort(all(ans));
		reverse(all(ans));
		for(auto &[x,a] : ans)
			cout << a << ' ';
		cout << '\n';
	}
}

int hi[2],low_odd[2],low_even[2];

int main(){
	fast
	bool A=0,B=0,C=0;
	low_odd[1] = 1;
	for(int i=1;i<kax;i++){
		hi[A] = hi[!A] + i*i;
		A = !A;
		if(i > 1){
			if(i % 2){
				low_odd[B] = low_odd[!B] + i*i;
				B = !B;
			}
			if(i % 2 == 0){
				low_even[C] = low_even[!C] + i*i;
				C = !C;
			}
		}
		if(i > 1 && hi[!A] <= 1e6)py.push_back({hi[!A] , to_string(i) + "H"});
		if(i % 2 == 1 && i > 1 && low_odd[!B] &&  low_odd[!B] <= 1e6)py.push_back({low_odd[!B],to_string(i) + "L"});
		if(i % 2 == 0 && i > 2 && low_even[!C] &&  low_even[!C] <= 1e6)py.push_back({low_even[!C],to_string(i) + "L"});
	}
	sort(all(py));
	// cerr << py.size() << '\n';
	// for(int i=0;i<py.size();i++){
	// 	cerr << py[i].first << ' ' << py[i].second << '\n';
	// }
	// return 0;
	memset(dp,-1,sizeof(dp));
	for(int Test = 1;;Test++){
		cin>>c;
		if(!c)break;
		cout << "Case " << Test << ": ";
		solve();
	}
}