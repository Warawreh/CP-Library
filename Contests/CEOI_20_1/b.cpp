#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Line{
	int x1,y1,x2,y2;
	void read(){
		cin>>x1>>y1>>x2>>y2;
		if(y2 < y1){
			swap(y2,y1);
			swap(x2,x1);
		}
	}
	bool operator<(const Line r){
		if(x2 == r.x2){
			return y2 < r.y2;
		}else{
			return x2 < r.x2;
		}
	}
};

int main(){
	fast
	int n;
	cin>>n;
	vector<Line> l(n);
	for(int i=0;i<n;i++)l[i].read();
	sort(all(l));
	for(int i=1;i<n;i++){
		cout << l[i-1].x2 << ' ' << l[i-1].y2 << ' ' << l[i].x1 << ' ' << l[i].y1 << '\n';
	}
}