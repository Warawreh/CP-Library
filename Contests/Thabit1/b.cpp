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
	string a,b;
	cin>>a>>b;
	if((a.size() + b.size())%2){
		cout << -1 << '\n';
	}else{
		if(a.size() >= b.size()){
			int need = a.size() - b.size();
			assert(need >= 0);
			need /=2;
			for(int i=0;i<=b.size();i++){
				string na,nb;
				if(need + i){
					na = b.substr(b.size() - i) + a.substr(i + need);
					nb = b.substr(0,b.size() - i) + a.substr(0,i + need);
				}else{
					na = a;
					nb = b;
				}
				if(na == nb){
					cout << na << '\n';
					return 0;
				}
			}
			cout << -1 << '\n';
		}else if(a.size() < b.size()){
			int need = b.size() - a.size();
			assert(need >= 0);
			need /=2;
			for(int i=0;i<=a.size();i++){
				string na,nb;
				if(need + i){
					na = b.substr(b.size() - i - need) + a.substr(i);
					nb = b.substr(0,b.size() - i - need) + a.substr(0,i);
				}else{
					na = a;
					nb = b;
				}
				if(na == nb){
					cout << na << '\n';
					return 0;
				}
			}
			cout << -1 << '\n';
		}
	}
}