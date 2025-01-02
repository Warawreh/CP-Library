#include <bits/stdc++.h>

using namespace std ;

const int MAX = 200 + 10 ;

int arr[3][MAX] ;
int sz[3] ;

int dp[MAX][MAX][MAX] ;

int calc(int idx , int a , int idx2 , int b)
{
	if(a >= sz[idx] || b >= sz[idx2])
		return 0 ;
	return (arr[idx][a] * arr[idx2][b]) ; 
}

int solve(int i , int j , int k)
{
	if(i > sz[0] || j > sz[1] && k > sz[2])
		return 0 ;
	int &ret = dp[i][j][k] ;
	if(ret != -1)
		return ret ;
	ret = solve(i+1 , j+1 , k) + calc(0 , i , 1 , j) ;
	ret = max(ret , solve(i+1 , j , k+1) + calc(0 , i , 2 , k)) ;
	ret = max(ret , solve(i , j+1 , k+1) + calc(1 , j , 2 , k)) ;
	return ret ;
}

int main()
{
	memset(dp , -1 , sizeof(dp)) ;
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>sz[0]>>sz[1]>>sz[2] ;
	for(int i = 0 ; i < 3 ; ++i)
	{
		for(int j = 0 ; j < sz[i] ; ++j)
			cin>>arr[i][j] ;
		sort(arr[i] , arr[i] + sz[i]) ;
		reverse(arr[i] , arr[i] + sz[i]) ;
	}
	return cout<<solve(0 , 0 , 0)<<"\n" , 0 ;
}		