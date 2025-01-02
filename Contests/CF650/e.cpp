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
		vector<int> l(26);
		for(int i=0;i<n;i++)l[s[i] - 'a']++;
		int kk = k;
		for(int len = n;len>=1;len--){
			k = __gcd(len , kk);
			if(1){
				vector<int> tmp = l;
				bool can = true;
				for(int i=0;i<k;i++){
					int need = len / k + (i < (len % k));
					for(int j=0;j<26;j++){
						if(tmp[j] >= need){
							tmp[j] -= need;
							need = 0;
							break;
						}
					}
					if(need)can = false;
				}
				if(can){
					cout << len << '\n';
					break;
				}

			}else{
				bool f=false;
				for(int i=0;i<26;i++){
					if(l[i] >= len){
						cout << len << '\n';
						f = true;
						break;
					}
				}
				if(f)break;
			}
		}
	}
}