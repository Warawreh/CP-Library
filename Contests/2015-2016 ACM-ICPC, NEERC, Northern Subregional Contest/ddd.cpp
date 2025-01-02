#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end()
ll fp(ll a,ll b){
	if(!b)return 1;
	ll res = fp(a,b/2);
	res = res*res;
	if(b%2)res = res*a;
	return res;
}
ll val;
void process(int a,int b,int c,int d,int e,int f){
	if(c >= a || e >= c || f >= b || d >= b)return;
	ll z = fp(2,a)+fp(3,b)+fp(2,c)*fp(3,d)+fp(2,e)*fp(3,f);
	if(z>val)return;
	else if(z==val)cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
	else{
		process(a+1,b,c,d,e,f);
		process(a,b+1,c,d,e,f);
		process(a,b,c+1,d,e,f);
		process(a,b,c,d+1,e,f);
		process(a,b,c,d,e+1,f);
		process(a,b,c,d,e,f+1);
	}
}
int main(){
	// freopen("alex.in" , "r" , stdin);
	// freopen("alex.out" , "w" , stdout);
	cin>>val;
	process(1,1,1,1,1,1);
}