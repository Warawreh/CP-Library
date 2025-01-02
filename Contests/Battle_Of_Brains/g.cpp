#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod = 1e9 + 7;

void add(int &a ,int b){
	a += b;
	if(a >= mod)a-=mod;
	if(a < 0)a += mod;
}

struct BIT{
	vector<int> tree;

	void init(int n){
		tree = vector<int> (n);
	}

	void update(int x,int val){
		while(x < tree.size()){
			add(tree[x] , val);
			x += x&(-x);
		}
	}

	int get(int x){
		int res = 0;
		while(x){
			add(res,tree[x]);
			x -= x & (-x);
		}
		return res;
	}

	int get(int l,int r){
		if(l > r)return 0;
		int res = get(r);
		add(res , -get(l-1));
		return res;
	}
};

BIT tree;

void solve(int C){
	int n;
	string s;
	cin>>n>>s;
	int ans = 0;
	int sum = 0;
	tree.init(n+1);
	for(int i=1;i<=n;i++){
		add(sum , i);
		tree.update(i,sum);
	}
	for(int i=0;i<n;i++){
		int cnt = ((tree.get(n-i , n) - tree.get(1,i))%mod + mod)%mod;
		ans = (ans + (cnt * 1ll * int(s[i]))%mod)%mod;
	}
	printf("Case %d: %d\n", C , ans);
}

int main(){
	// freopen("input.txt" , "r" , stdin); // Remove Before Submit
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		solve(++cnt);
	}	
}