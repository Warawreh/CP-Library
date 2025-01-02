#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<string> to;

bool isVowel(char c){
	string v = "aeiou";
	for(char x : v){
		if(x == c)return true;
	}
	return false;
}

bool calc(string s,int t){
	if(s.size() == 1){
		return isVowel(s[0]);
	}

	string l;
	for(int i=0;i+1<s.size();i+=2){
		l += to[s[i] - 'a'][s[i+1] - 'a'];
	}
	if(s.size() % 2)l += s.back();

	bool left = calc(l , !t);

	string r;
	for(int i=(int)s.size() - 1;i - 1>=0;i-=2){
		r += to[s[i] - 'a'][s[i-1] - 'a'];
	}
	if(s.size() % 2)r += s[0];
	
	bool right = calc(r , !t);

	if(t == 0){
		if(left || right)return 1;
		else return 0;
	}else{
		if(left == 0 || right == 0)return 0;
		else return 1;
	}

}

void solve(){
	to = vector<string>(26);
	for(int i=0;i<26;i++)cin>>to[i];
	string s;
	cin>>s;

	cout << (calc(s , 0) ? "Salah" : "Marzo") << '\n';
}

int main(){
    fast
    int t;
    cin>>t;
    while(t--)solve();
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/