#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define mk make_pair 
#define ff first 
#define ss second 
typedef long long ll;
bool ok[1000005];
			
int main(){
	freopen("rock.in","r",stdin);
	vector<int>v;
	for(int i=2;i<2000;i++){
		int x=i*(i+1)/2;
		if(x>1000000)break;
		v.pb(x);
		ok[x]=1;
		}	
	ok[3]=1;
	for(int i=4;i<=1000000;i++){
		if(i%3==0 || ok[i]==1){
			ok[i]=1;
			continue;
			}
		for(int j=0;j<v.size();j++){
			if(v[j]<=i&&ok[i-v[j]]){
				ok[i]=1;
				break;
				}
			}
		}	
	int t;
	cin>>t;
	while(t--){
			int x;
			cin>>x;
			if(ok[x])cout<<"YES\n";
			else cout<<"NO\n";
		}
return 0;
}
