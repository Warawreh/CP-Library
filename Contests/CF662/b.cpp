#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e5 + 10;
int h[nax];
int t,f;

void add(int x){
	h[x]++;
	if(h[x] % 2 == 0)t++;
	if(h[x] % 4 == 0){
		t-=2;
		f++;
	}
}

void rem(int x){
	if(h[x] % 4 == 0){
		t+=2;
		f--;
	}
	if(h[x] % 2 == 0)t--;
	h[x]--;
}

int main(){
	fast
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		add(x);
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		char c;
		int x;
		cin>>c>>x;
		if(c == '+')add(x);
		else rem(x);
		if(f >= 2 || (f == 1 && t >= 2))cout << "Yes\n";
		else cout << "No\n";
	}
}