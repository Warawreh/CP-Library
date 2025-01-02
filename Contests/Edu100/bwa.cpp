	// •︿• \\
	/\\    //\
	 /\\  //\
	  /\\//\
	  
	#include <iostream>
	#include <iomanip>
	#include <algorithm>
	#include <vector>
	#include <cmath>
	#include <queue>
	#include <map>
	#include <set>
	#include <utility>
	#include <math.h>
	#include <string>
	#include <cstring>
	#include <cassert>
	using namespace std;
	 
	const double PI = acos(-1);
	const int N=1e5 + 10;
	const int M=998244353;
	typedef long long ll;
	typedef vector<int> vi;
	typedef vector<vi> vvi;
	typedef pair<int, int> ii;
	#define pb push_back
	#define mp make_pair
	#define f first
	#define s second
	#define all(c) (c).begin(),(c).end()
	#define rall(c) (c).rbegin(),(c).rend()
	#define oo 1000000001

	void solve(){	
		int n;
		cin>>n;
		ll s=0;
		ll sum=0;
		vi a(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			s+=a[i];
			sum+=a[i];
			while(a[i]-(a[i]&(-a[i]))){
				a[i]-=(a[i]&(-a[i]));
			}
			sum-=a[i];
		}
		
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
		}
		printf("\n");
	}

	int main(){
		int t=1;
		scanf("%d",&t);
		while(t--)
			solve();
		return 0;
	}	