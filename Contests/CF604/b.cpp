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
	vector<int> a(4);
	for(int i=0;i<4;i++)cin>>a[i];
	int n = a[0] + a[1] + a[2] + a[3];
	if(n == 1){
		cout << "YES\n";
		for(int i=0;i<4;i++){
			if(a[i]){
				cout << i << '\n';
			}
		}
		return 0;
	}
	if(a[0] == n || a[1] == n || a[2] == n || a[3] == n){
		cout << "NO\n";
		return 0;
	}
	for(int i=0;i<=2;i++){
		if(a[i] + a[i+1] == n){
			if(abs(a[i] - a[i+1]) > 1){
				cout << "NO\n";
			}else{
				cout << "YES\n";
				if(a[i+1] > a[i]){
					for(int j=0;j<n;j++){
						cout << i + !(j%2) << ' ';
					}
				}else{
					for(int j=0;j<n;j++){
						cout << i + (j%2) << ' ';
					}
				}
			}
			return 0;
		}
	}
	if(!a[1] || !a[2]){
		cout << "NO\n";
	}else if(!a[0]){
		if(abs(a[1] + a[3] - a[2]) <= 1){
			cout << "YES\n";
			if(a[1] + a[3] - a[2] == -1){
				cout << "2 ";
			}
			for(int i=0;i<a[1];i++)cout << "1 2 ";
			for(int i=0;i<a[3];i++){
				if(i == a[3] - 1 && a[3] + a[1] - a[2] == 1)cout << "3 ";
				else cout << "3 2 ";
			}
		}else{
			cout << "NO\n";
		}
	}else if(!a[3]){
		if(abs(a[0] + a[2] - a[1]) <= 1){
			cout << "YES\n";
			if(a[0] + a[2] - a[1] == -1){
				cout << "1 ";
			}
			for(int i=0;i<a[0];i++)cout << "0 1 ";
			for(int i=0;i<a[2];i++){
				if(i == a[2] - 1 && a[2] + a[0] - a[1] == 1)cout << "2 ";
				else cout << "2 1 ";
			}
		}else{
			cout << "NO\n";
		}
	}else{
		if(a[0] > a[1] || a[3] > a[2] || a[2] > a[1] - a[0] + 1 + a[3] || a[1] > a[2] - a[3] + 1 + a[0]){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			int x = 0;
			if(a[1] > a[2] - a[3] + a[0]){
				cout << "1 ";
				x = 1;
			}
			for(int i=0;i<a[0];i++){
				cout << "0 1 ";
			}
			for(int i=0;i<a[1] - a[0] - x;i++){
				cout << "2 1 ";
			}

			for(int i=0;i<a[3];i++){
				cout << "2 3 ";
			}

			if(a[2] > a[1] - a[0] + a[3]){
				cout << "2 ";
			}
			cout << '\n';
		}
	}
}