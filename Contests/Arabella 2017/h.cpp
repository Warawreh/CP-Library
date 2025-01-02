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
	string goodL = "AHIMOTUVWXY";
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		int n = a.size();
		bool mirror = true;
		for(int i=0;i<n;i++){
			bool good = false;
			for(char c : goodL){
				if(c == a[i])good = true;
			}
			if(!good)mirror = false;
		}
		string b = a;
		reverse(all(b));
		if(mirror && a == b)cout << "yes\n";
		else cout << "no\n";
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/