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
	int n,k;
	string s;
	cin>>n>>k>>s;
	// n = uniform_int_distribution<int>(1, 100)(rng);
	// k = uniform_int_distribution<int>(n, 100)(rng);
	// for(int i=0;i<n;i++){
	// 	s += char('a' + uniform_int_distribution<int>(0, 25)(rng));
	// }
	// n = 3000;
	// k = 5000;
	// s = string(2000,'z') + "a" + string(999,'z');
	
	int b = n;
	int cnt = 0;
	for(int i=n-1;i>=1;i--){
		for(int j=i;j<k;j++){
			if(s[j % i] < s[j % b]){
				b = i;
				break;
			}else if(s[j % i] > s[j % b]){
				// cerr << i << '\n';
				// cnt++;
				break;
			}
		}
	}
	cerr << n << ' ' << k << '\n' << s << '\n';
	cerr << cnt << '\n';
	for(int i=0;i<k;i++){
		cout << s[i%b];
	}
}



/*
znfxjahhsqzzrlauuyuoyxuuwjmiyxvoxxefyleohwfoqsrekagtkc
          ||         
*/