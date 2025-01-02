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
	freopen("hard.in" , "r" , stdin);
	freopen("hard.out" , "w" , stdout);

	vector<pair<int,int>> seg;
	string s;
	bool done = false;

	while(done == false){
		string op;
		int val;
		cin>>op>>op>>val;
		string next;
		if(cin>>next);
		else done = true;
		int mn = (int)-32768 , mx = (int)32767;
		if(op == "<=")mx = min(mx , val);
		if(op == ">=")mn = max(mn , val);
		if(next == "&&"){
			cin>>op>>op>>val;
			if(op == "<=")mx = min(mx , val);
			if(op == ">=")mn = max(mn , val);
			string e;
			if(cin>>e);
			else done = true;
		}
		if(mn > mx)continue;
		seg.push_back({mn,mx});
	}
	if(seg.empty()){
		cout << "false\n";
		return 0;
	}
	sort(all(seg));
	vector<pair<int,int>> nxt;
	int to = -1e9,l = -1e9;
	for(int i=0;i<seg.size();i++){
		// cerr << seg[i].first << ' ' << seg[i].second << ' ' << to << '\n';
		if(to == -1e9){
			l = seg[i].first;
			to = seg[i].second;
		}
		if(seg[i].first - 1 <= to){
			to = max(to,seg[i].second);
		}else{
			nxt.push_back({l,to});
			l = seg[i].first;
			to = seg[i].second;
		}
	}
	assert(to != -1e9);
	nxt.push_back({l,to});
	if(nxt[0] == make_pair(-32768,32767))cout << "true\n";
	else{
		for(int i=0;i<nxt.size();i++){
			if(i)cout << " ||\n";
			string g;
			if(nxt[i].first != -32768 && nxt[i].second != 32767){
				g = "x >= " + to_string(nxt[i].first) + " && " + "x <= " + to_string(nxt[i].second);
			}else if(nxt[i].first != -32768){
				g = "x >= " + to_string(nxt[i].first);
			}else if(nxt[i].second != 32767){
				g = "x <= " + to_string(nxt[i].second);
			}
			cout << g;
		}
	}
}