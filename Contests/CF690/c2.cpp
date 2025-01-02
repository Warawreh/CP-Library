#include <bits/stdc++.h>

using namespace std ;

const int MAX = 50 + 10 ;

int n ;
long long arr[MAX] ;

void gen(long long x , int mask , int sum)
{
	if(sum > 50)
		return ;
	if(arr[sum] == -1)
		arr[sum] = x ;
	else
		arr[sum] = min(arr[sum] , x) ;
	for(int i = 0 ; i <= 9 ; ++i)
	{
		if((mask & (1 << i)) || (i == 0 && x == 0))
			continue ;
		gen(x * 10ll + i * 1ll , mask | (1 << i) , sum + i) ;
	}
}

int main()
{
	memset(arr , -1 , sizeof(arr)) ;
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	gen(0 , 0 , 0) ;
	int t ;
	cin>>t ;
	while(t--)
	{
		cin>>n ;
		cout<<arr[n]<<"\n" ;
	}
	return 0 ;
}