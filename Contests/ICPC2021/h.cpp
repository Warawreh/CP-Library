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
    int n;
    cin>>n;

    vector<pair<int,int>> a(n);
    set<pair<int,int>> st,hv;
    vector<int> ans(n);
    int tot = 0;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;

    	int need=0,give = 0;
    	int cur = 0;
    	for(int j=0;j<s.size();j++){
    		if(s[j] == '(')cur++;
    		else cur--;

    		need = max(need , -cur);
    	}
    	tot += cur;

    	cur = 0;
    	for(int j=s.size() - 1;j>=0;j--){
    		if(s[j] == '(')cur++;
    		else cur--;

    		give = max(give , cur);
    	}

    	a[i] = {need , give};
    	st.insert({need , i});
    }

    if(tot != 0){
    	cout << "impossible\n";
    	return 0;
    }

    int extra = 0;
    int at = 0;
    while(st.size()){

    	while(hv.size()){
    		if(hv.rbegin()->first < 0)break;
    		int i = hv.rbegin()->second;
    		extra += a[i].second;
    		extra -= a[i].first;
    		ans[i] = ++at;
    		hv.erase(--hv.end());
    	}

    	if(st.begin()->first > extra){
    		cout << "impossible\n";
	    	return 0;
    	}

    	while(st.size()){
    		if(st.begin()->first > extra)break;
    		int i = st.begin()->second;
    		hv.insert({a[i].second - a[i].first , i});
    		st.erase(st.begin());
    	}
    }

    while(hv.size()){
		int i = hv.rbegin()->second;
	    // cerr << i << ' ' << a[i].first << ' ' << a[i].second << ' ' << extra << '\n';
		if(a[i].first > extra){
			cout << "impossible\n";
	    	return 0;
		}
		extra += a[i].second;
		extra -= a[i].first;
		ans[i] = ++at;
		hv.erase(--hv.end());
	}
	vector<int> res(n);
	for(int i=0;i<n;i++)res[ans[i]-1] = i + 1;

	for(int i=0;i<n;i++)
		cout << res[i] << '\n';	
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/