#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n;

int T(vector<pair<int,int>> s){
	sort(all(s),[](auto a,auto b){
		return a.second < b.second;
	});
	int res = 0;
	int lst = -1;
	for(int i=0;i<n;i++){
		if(s[i].first < lst)continue;
		res++;
		lst = s[i].second;
	}
	return res;
}

int A(vector<pair<int,int>> s){
	sort(all(s));
	int res = 0;
	int lst = -1;
	for(int i=0;i<n;i++){
		if(s[i].first < lst)continue;
		res++;
		lst = max(lst , s[i].second);
	}
	return res;
}

int main(){
	fast
	cin>>n;
	vector<pair<int,int>> s(n);
	for(int i=0;i<n;i++)cin>>s[i].first>>s[i].second;
	cout << T(s) << ' ' << A(s) << '\n';
}