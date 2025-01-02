#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct line
{
	int y,fr,to;
	void read(){
		cin>>y>>fr>>to;
	}
};


int main(){
	fast
	int n;
	cin>>n;
	vector<line> l(n);
	for(int i=0;i<n;i++)l[i].read();
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++){
			
		}
	}
}