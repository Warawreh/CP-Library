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
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	vector<vector<int>> q;
	int cnt = 0;
	while(1){
		cnt++;
		vector<int> at(n);
		for(int i=0;i<n;i++){
			// cerr << a[i] << ' ' << i << '\n';
			at[a[i]] = i;
		}
		vector<int> tmp;
		for(int i=0;i<n-1;i++){
			if(at[i+1] < at[i]){
				int l = at[i+1],r = at[i+1];
				int x = 2;
				while(i + x < n && at[i+x] == r + 1){
					r++;
					x++;
				}
				if(l){
					tmp.push_back(at[i+1]);
				}
				tmp.push_back(r - l + 1);
				tmp.push_back(at[i] - r);
				if(at[i] != n-1)tmp.push_back(n - at[i] - 1);
				break;
			}
		}
		if(tmp.size()){
			vector<int> nxt;
			int sum = 0;
			// cerr << "LENS : ";
			for(int i=tmp.size() - 1;i>=0;i--){
				int len = tmp[i];
				sum += len;
				// cerr << len << ' ' ;
				for(int j=0;j<len;j++){
					nxt.push_back(a[n - sum + j]);
				}
			}
			// cerr << '\n';
			// cerr << "BEFORE : ";
			// for(int i : a){
			// 	cerr << i << ' ';
			// }
			// cerr << '\n';
			a = nxt;
			// cerr << "AFTER : ";
			// for(int i : a){
			// 	cerr << i << ' ';
			// }
			// cerr << '\n';
			q.push_back(tmp);
			// if(cnt == 3)break;
		}
		else break;
	}
	// if(q.size() > n)while(1);
	assert(q.size() <= n);
	assert(is_sorted(all(a)));
	cout << q.size() << '\n';
	for(vector<int> a : q){
		cout << a.size() << ' ';
		for(int i : a){
			cout << i << ' ';
		}
		cout << '\n';
	}
}