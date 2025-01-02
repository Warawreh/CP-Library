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
	vector<vector<int>> l(26);
	for(int i=0;i<n;i++){
		l[s[i] - 'a'].push_back(i);
	}
	for(int i=0;i<26;i++)reverse(all(l[i]));
	set<int> st;
	for(int i=0;i<n;i++)st.insert(i);
	for(int i=0;i<n;i++){
		l[s[i] - 'a'].pop_back();
		for(int x=0;x<s[i]-'a'){
			
		}
	}
}


/*
x < y
string a = "..." x
string b = "........" y


*/