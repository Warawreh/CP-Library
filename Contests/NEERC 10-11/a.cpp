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

	// freopen("alignment.in","r",stdin);
	// freopen("alignment.out","w",stdout);

	string s;
	bool b2 = false;
	while(getline(cin,s)){
		if(b2)cout << '\n';
		string cur = "";
		bool b = false;

		for(int i=0;i<s.size();i++){
			if(s[i] == ' '){
				if(cur.size()){
					if(b)cout << ' ';
					cout << cur;
					cur.clear();
					b = true;
				}
			}else cur+=s[i];
		}
		if(cur.size()){
			if(b)cout << ' ';
			cout << cur;
			cur.clear();
		}
		b2 = 1;
	}

}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/