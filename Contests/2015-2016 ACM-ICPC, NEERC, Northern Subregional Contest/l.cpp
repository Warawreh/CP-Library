#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

int main(){
	freopen("lucky.in" , "r" , stdin);
	freopen("lucky.out" , "w" , stdout);
	ll ans = 0;
	int n,m;
	cin>>n>>m;
	int x[n][m],val[n][m][4];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>x[i][j];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			int a = 0;
			for(int c = i-1;c>=0;c--)a = max(x[c][j],a);
			if(a < x[i][j])ans++;
			a = 0;
			for(int c = i+1;c<n;c++)a = max(x[c][j],a);
			if(a < x[i][j])ans++;
			a = 0;
			for(int c = j-1;c>=0;c--)a = max(x[i][c],a);
			if(a < x[i][j])ans++;
			a = 0;
			for(int c = j+1;c<m;c++)a = max(x[i][c],a);
			if(a < x[i][j])ans++;
		}
	cout<<ans<<endl;
}