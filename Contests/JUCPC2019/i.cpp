#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;
string s;

int getnxt(int st){
	int res = 0;
	for(int i=st;i<s.size();i++){
		if(s[i] == '(' || s[i] == ')')break;
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}

int main(){
	fast
	cin>>n>>s;
	vector<int> b;
	b.push_back(getnxt(0));
	vector<int> sup(n);
	for(int i=0;i<s.size();i++){
		if(s[i] == '('){
			int x = getnxt(i+1);
			// cerr << i << ' ' << x << ' ' << b.back() << '\n';
			sup[x-1] = b.back();
			b.push_back(x);
		}else if(s[i] == ')'){
			b.pop_back();
		}
	}
	for(int i=0;i<n;i++)cout << sup[i] << ' ';

}