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

    vector<vector<int>> a(n);
    set<pair<int,int>> st,hv;
    vector<string> g;
    vector<int> ans(n);
    int tot = 0;
    for(int i=0;i<n;i++){
    	string s;
    	cin>>s;
    	g.push_back(s);

    	int need=0,give = 0;
    	int cur = 0;
    	for(int j=0;j<s.size();j++){
    		if(s[j] == '(')cur++;
    		else cur--;

    		need = max(need , -cur);
    	}
    	tot += cur;

    	a[i] = {need , give, cur};
    	st.insert({need , i});
    }

    if(tot != 0){
    	cout << "impossible\n";
    	return 0;
    }

    int extra = 0;
    int at = 0;


    while(st.size()){
		if(st.begin()->first > extra){
			cout << "impossible\n";
	    	return 0;
		}
		int i = st.begin()->second;
		if(a[i][2] >= 0){
			extra += a[i][2];
			ans[at++] = i;
		}else{
			hv.insert({a[i][0] + a[i][2] , i});
		}
		st.erase(st.begin());
	}

    while(hv.size()){
		int i = hv.rbegin()->second;
	    // cerr << i << ' ' << a[i][0] << ' ' << a[i][1] << ' ' << extra << '\n';
		if(a[i][0] > extra){
			cout << "impossible\n";
	    	return 0;
		}
		extra += a[i][2];
		ans[at++] = i;
		hv.erase(*hv.rbegin());
	}

	assert(extra == 0);
	{
		string res;
		for(int i=0;i<n;i++)
			res += g[ans[i]];

		int cur = 0;
		for(int i=0;i<res.size();i++){
			if(res[i] == '(')cur++;
			else cur--;
			assert(cur >= 0);
		}
		assert(cur == 0);
	}


	for(int i=0;i<n;i++)
		cout << ans[i] + 1 << '\n';	
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/