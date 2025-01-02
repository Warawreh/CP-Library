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
    int n,m;
    cin>>n>>m;
    vector<int> sz(m);
    for(int i=0;i<m;i++)cin>>sz[i];

    string s;
	vector<vector<int>> customer(n),resturant(m);
	getline(cin,s);
    for(int i=0;i<n;i++){
    	getline(cin, s);
    	istringstream in(s);
    	int r;
    	while(in>>r){
    		customer[i].push_back(r-1);
    	}
    	reverse(all(customer[i]));
    }

    unordered_map<ll,int> ord;
    for(int i=0;i<m;i++){
    	getline(cin, s);
    	istringstream in(s);
    	int r;
    	int at = 0;
    	while(in>>r){
    		if(!r)break;
    		ll cur = r * 1e9 + i;
    		ord[cur] = at++;
    		resturant[i].push_back(r-1);
    	}	
    }

    vector<int> curC(n),curR(m);
    iota(all(curC) , 0);
    vector<int> ans;
    vector<bool> done(n,0),doneR(m,0);
    vector<int> added(m,-1);
    int lvl=0;

    while(curC.size()){
    	lvl++;

    	vector<int> nxtC;
    	unordered_map<int,vector<int>> hv;
    	vector<int> curR;

    	for(int &c : curC){
    		int to = customer[c].back();
    		if(doneR[to])continue;
    		ll cur = (c+1) * 1e9 + to;
    		hv[to].push_back(ord[cur]);

    		if(added[to] != lvl){
    			added[to] = lvl;
    			curR.push_back(to);
    		}

    		customer[c].pop_back();
    		if(customer[c].empty())done[c] = 1;
    	}

    	for(int &r : curR){
    		vector<int> &cur = hv[r];
    		sort(all(cur));
			// cerr << "resturant " << r << ": \n";
    		for(int i=0;i<cur.size();i++){
    			if(!sz[r])break;
    			// cerr << resturant[r][cur[i]] << ' ';
    			ans.push_back(resturant[r][cur[i]]);
    			done[resturant[r][cur[i]]] = 1;
    			sz[r]--;
    		}
    		// cerr << '\n';
    		if(!sz[r])doneR[r] = 1;

    	}
    	// cerr << '\n';

    	for(int &c : curC)
    		if(!done[c])
    			nxtC.push_back(c);

    	// cerr << nxtC.size() << '\n';
    	// cerr << '\n';

    	curC = nxtC;
    	nxtC.clear();
    	hv.clear();

    }

    sort(all(ans));
    for(int i : ans){
    	cout << i + 1<< '\n';
    }
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/