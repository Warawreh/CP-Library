#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 1e6 + 10;

vector<vector<int>> divisors;
map<pair<int,int>,int> dp;
map<pair<int,int>,bool> vis;

int calc(int n,int lst){
	if(n == 0)return 0;	
	if(n < 0)return (int)-1e9;
	pair<int,int> g = {n,lst};
	int &ret = dp[g];
	if(vis[g])return ret;
	ret = -1e9;
	vis[g] = 1;
	for(int p : divisors[lst]){
		// assert(p != lst);
		ret = max(ret , calc(n - p,p) + 1);
	}
	return ret;	
}

int n = 1;
void solve(){
	// n++;
	cin>>n;
	int ans = 1,res =1;
	int nn = n;
	for(int lst =3;lst<=n;lst++){
		ans = 1;
		n = nn - lst;
		// int lst = 1;
		
		while(1){
			int gg = lst;
			for(int x : divisors[n]){
				if(x > lst && x + x < n && x % lst == 0){
					if(divisors[n - x].size() == 0){
						res = max(res , ans + 1);
						continue;
					}
					lst = x;
					n -= x;
					ans++;
					break;
				}
			}
			// cerr << lst << ' ' << gg << '\n';
			if(gg == lst)break;
		}
		if(n % lst == 0)ans++;
		res = max(res , ans);
	}
	cout << res << '\n';
}

int main(){
	fast

	int sum = 0,cnt = 0;
	divisors.resize(nax);
	for(int i=3;i<nax;i++){
		for(int j=i+i;j<nax;j+=i){
			divisors[j].push_back(i);
		}
	}
	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++){
		cout << "Case #" << T << ": ";
		solve();
	}
}





/*
addi x5,x0,-5
sw x5,0(x3)
addi x5,x0,6
sw x5,4(x3)
addi x5,x0,20
sw x5,8(x3)
addi x5,x0,-83
sw x5,12(x3)
addi x5,x0,99
sw x5,16(x3)
addi x5,x0,19
sw x5,20(x3)
addi x5,x0,100
sw x5,24(x3)
addi x5,x0,0
sw x5,28(x3)
addi x5,x0,-46
sw x5,32(x3)
addi x5,x0,25
sw x5,36(x3)


addi x12,x0,9
order:
addi sp,sp,-12
sw x1,8(sp)
sw x12,4(sp)
sw x10,0(sp)
addi x5,x0,0
addi x6,x0,0
loop:
bge x6,x12,endloop
slli x7,x6,2
add x31,x7,x3
lw x28,0(x31)
addi x7,x7,4
add x31,x7,x3
lw x29,0(x31)
bge x28,x29,else
slli x7,x6,2
add x31,x7,x3
sw x29,0(x31)
addi x7,x7,4
add x31,x7,x3
sw x28,0(x31)
addi x5,x5,1
else:
addi x6,x6,1
beq x0, x0, loop
endloop:
addi x28,x12,-1
bne x28,x0,else2
addi x10,x5,0
jalr x0,0(x1)
else2:
lw x10,0(sp)
lw x12,4(sp)
lw x1,8(sp)
addi sp,sp,12
add x10,x10,x5
jalr x0,0(x1)


addi x5,x0,-5
sw x5,0(x3)
addi x5,x0,6
sw x5,4(x3)
addi x5,x0,20
sw x5,8(x3)
addi x5,x0,-83
sw x5,12(x3)
addi x5,x0,99
sw x5,16(x3)
addi x5,x0,19
sw x5,20(x3)
addi x5,x0,100
sw x5,24(x3)
addi x5,x0,0
sw x5,28(x3)
addi x5,x0,-46
sw x5,32(x3)
addi x5,x0,25
sw x5,36(x3)

*/

