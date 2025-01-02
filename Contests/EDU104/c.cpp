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
		int n;
		// n++;
		cin>>n;
		vector<int> p(n,0);
		if(n % 2 == 0){
			int score = n * (n-1) / 2 * 3;
			int wins = score / n;

			for(int i=0;i<n;i++){
				if(i % 2 == 0){
					for(int j=i+1;j<n;j++){
						if(j == i+1 && i % 2 == 0){
							p[i]++;
							p[j]++;
							cout << 0 <<  ' ';
						}else if(p[i] == wins){
							cout << -1 << ' ';
							p[j] += 3;
						}else{
							cout << 1 << ' ';
							p[i] += 3;
						}
					}
				}else{
					vector<int> tmp;
					for(int j=n-1;j>i;j--){
						if(j == i+1 && i % 2 == 0){
							p[i]++;
							p[j]++;
							tmp.push_back(0);
							// cout << 0 <<  ' ';
						}else if(p[i] == wins){
							// cout << -1 << ' ';
							tmp.push_back(-1);
							p[j] += 3;
						}else{
							tmp.push_back(1);
							// cout << 1 << ' ';
							p[i] += 3;
						}
					}
					reverse(all(tmp));
					for(int i : tmp)
						cout << i << ' ';
				}
			}
			cout << '\n';
		}else{
			int score = n * (n-1) / 2 * 3;
			assert(score % n == 0);
			int wins = score / n;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					if(p[i] == wins){
						cout << -1 << ' ';
						p[j] += 3;
					}else{
						cout << 1 << ' ';
						p[i] += 3;
					}
				}
			}
			cout << '\n';
		}
		for(int i=0;i<n;i++){
			assert(p[i] == p[0]);
			// cerr << p[i] << ' ';
		}
		// cerr << '\n';
	}
}