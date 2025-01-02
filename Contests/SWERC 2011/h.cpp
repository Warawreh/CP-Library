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
	while(1){
		int k,n;
		cin>>k>>n;
		if(!k && !n)break;

		vector<string> inst(n);
		vector<vector<int>> reviwed(n);
		for(int i=0;i<n;i++){
			cin>>inst[i];
			for(int j=0;j<k;j++){
				int a;
				cin>>a;
				a--;
				reviwed[a].push_back(i);
			}
		}

		int errors = 0;
		for(int i=0;i<n;i++){
			bool bad = false;
			if(reviwed[i].size() != k){
				bad = true;
			}
			sort(all(reviwed[i]));
			for(int j=0;j<reviwed[i].size();j++){
				if(j && reviwed[i][j] == reviwed[i][j-1])bad = true;
				if(inst[i] == inst[reviwed[i][j]])bad = true;
			}
			errors+=bad;
		}

		if(errors== 0)
			cout << "NO PROBLEMS FOUND\n";
		else
			cout << errors << " PROBLEMS FOUND\n";

	}	
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/