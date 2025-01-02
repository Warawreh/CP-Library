#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool good(string s){
	s.pop_back();
	if(s.empty() || s.size() == 1)return false;
	if(islower(s[0]) || isalpha(s[0]) == 0)return false;
	for(int i=1;i<s.size();i++){
		if(isalpha(s[i]) == false || isupper(s[i]))return false;
	}
	return true;
}

int main(){
	fast
	freopen("abbreviation.in" , "r" , stdin);
	freopen("abbreviation.out" , "w" , stdout);
	string s;
	bool g = 0;
	while(getline(cin,s)){
		if(g)cout << '\n';
		g = 1;
		vector<string> cur;
		string last,abb;
		for(int i=0;i<s.size();i++){
			last += s[i];
			if(isalpha(s[i]) == 0){
				if(good(last)){
					cur.push_back(last);
					abb+=last[0];
				}
				// cerr << last << ' ' << good(last) << '\n';
				if(!good(last) || s[i] != ' '){
					if(cur.size() > 1){
						cur.back().pop_back();
						if(good(last))last = last.back();

						cout << abb << " (";
						for(int j=0;j<cur.size();j++){
							// if(j)cout << ' ';
							cout << cur[j];
						}
						cout << ")";
						if(isalpha(last[0]))cout << ' ';
					}else if(cur.size() == 1 && !good(last)){
						cout << cur[0];
					}
					if(cur.size() > 1 && i && i-1 && s[i-1] == ' ' && s[i-2] != ' ')cout << ' ';
					cout << last;
					abb.clear();
					cur.clear();
				}
				last.clear();
				// cout << s[i];
			}
		}
		last += ' ';
		if(good(last)){
			cur.push_back(last);
			abb+=last[0];
		}
		// cerr << last << ' ' << good(last) << '\n';
		if(cur.size() > 1){
			cur.back().pop_back();
			if(good(last))last = last.back();

			cout << abb << " (";
			for(int j=0;j<cur.size();j++){
				// if(j)cout << ' ';
				cout << cur[j];
			}
			cout << ")";
			if(isalpha(last[0]))cout << ' ';
		}else if(cur.size() == 1 && !good(last)){
			cout << cur[0];
		}
		if(last.back() == ' ')last.pop_back();
		cout << last;
		abb.clear();
		cur.clear();

		last.clear();
	}
}