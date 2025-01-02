#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N = 1e6+10;
const int mod = 1e9+7;
#define all(x) (x).begin(), (x).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

int ask(string a){
	cout << a << endl;
	fflush(stdout);
	int o;
	cin>>o;
	return o;
}

void solve(){
	int ones = ask("00000000");
	for(;;){
		if(ones == 0){
			return;
		}
		if(ones == 8){
			ones = ask("11111111");
			return;
		}
		if(ones < 4){
			ones = ask("11111111");
		}else{
			int z = 8 - ones;
			string cur = string(z,'1')+string(ones,'0');
			shuffle(cur.begin(),cur.end(),rng);
			ones = ask(cur);
		}
		if(ones == -1)assert(0);
	}
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.precision(10);
cout << fixed;

	int t;
	cin>>t;
	while(t--)solve();
}