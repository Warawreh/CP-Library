#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// bool sheldon(int i){
// 	string s;
// 	while(i){
// 		s += char('0' + i%2);
// 		i/=2;
// 	}
// 	vector<int> seg[2];
// 	int len = 1;
// 	for(int i=1;i<s.size();i++){
// 		if(s[i] != s[i-1]){
// 			seg[s[i-1] - '0'].push_back(len);
// 			len = 1;
// 		}else len++;
// 	}
// 	seg[s.back() - '0'].push_back(len);
// 	for(int it=0;it<2;it++){
// 		for(int i=0;i<seg[it].size();i++){
// 			if(seg[it][i] != seg[it][0])return false;
// 		}
// 	}
// 	return true;
// }

ull p2[66];

int calc(ll to){
	if(to <= 0)return 0;
	int ans = 0;
	// cerr << to << '\n' << '\n';
	for(ll st=1;st<=63;st++){
		if(p2[st-1] > to)break;
		for(ll o=1;o<=st;o++){
			for(ll z=0;z+o<=st;z++){
				if(z == 0 && o != st)continue;
				if(st % (z + o) == 0 || st % (z + o) == o){
					ll res = 0;
					for(int x =0;x<st/(z+o);x++){
						res *= p2[o];
						res += p2[o] - 1;
						res *= p2[z];
					}
					if(st % (z + o) == o && z){
						res *= p2[o];
						res += p2[o] - 1;
					}
					if(res <= to){
						// cerr << st << ' ' << o << ' ' << z << ' ' << sheldon(res) << '\n';
						// cerr << res << '\n';
						// assert(sheldon(res));
						ans++;
					}
				}
			}
		}
	}
	return ans;
}

int main(){
	fast
	p2[0] = 1;
	for(ll i=1;i<63;i++)p2[i] = p2[i-1] * 2ll;
	// cerr << p2[62] << '\n';

	ll x,y;
	cin>>x>>y;
	cerr << calc(y) << ' ' << calc(x-1) << '\n';
	cout << calc(y) - calc(x-1) << '\n';
	// int cnt = 0;
	// for(int i=1;i<=20;i++){
	// 	if(sheldon(i)){
	// 		cnt++;
	// 		cerr << i << ' ';
	// 	}
	// }
	// cerr << '\n' << cnt << '\n';
}