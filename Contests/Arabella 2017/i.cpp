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
		vector<vector<bool>> isP(n,vector<bool>(n));
		for(int l=n-1;l>=0;l--){
			for(int r=l;r<n;r++){
				if(l == r)isP[l][r] = 1;
				else if(l +1 == r)isP[l][r] = (a[l] == a[r]);
				else{
					isP[l][r] = ((a[l] == a[r]) && isP[l+1][r-1]);
				}
			}
		}

		int ans = 0;
		for(int l=0;l<n;l++){
			for(int r=l;r<n;r++){
				bool good = false;
				for(char c : goodL){
					if(c == a[r])good = true;
				}
				if(!good)break;
				if(isP[l][r])ans = max(ans , r - l + 1);
			}
		}
		cout << ans << '\n';
	}
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/