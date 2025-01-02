#include <bits/stdc++.h>
    using namespace std;
    #define pb push_back 
    #define mk make_pair 
    #define ff first 
    #define ss second 
    typedef long long ll;
    const int MX=1e7;
    bool prime[MX+5];
    const int Mod=1e9+7;
		
    int main(){
		// freopen("valid.in","r",stdin);
		fill(prime,prime+MX+5,1);
		for(int i=2;i<=sqrt(MX);i++){
			if(prime[i]){
				for(int j=i+i;j<=sqrt(MX);j+=i) prime[j]=0;
				}
			}
		
		vector<vector<int>>f;
		f.resize(5000);
		for(int i=2;i<=sqrt(MX);i++){
			for(int j=2;j<=sqrt(i);j++){
				if(i%j==0){
					f[j].pb(i);
					break;
					}
				}	
			}
			
		int t;
		cin>>t;
		while(t--){
			int n,k;
			cin>>n>>k;
			int target=k;
			for(int i=2;i<=sqrt(k);i++){
				if(k%i==0){
					target=i;
					break;
					}
				}
			ll prp[n];
			fill(prp,prp+n,1);
			ll idx=-1,tt=0;
			bool oneTime=1;
			for(int i=0;i<n;i++){
				int a;
				cin>>a;
				if(a==target)tt++;
				if(a>sqrt(k)||a==1)continue;
				prp[i]=lower_bound(f[a].begin(),f[a].end(),k)-f[a].begin()+1;
				if(a==target&&oneTime){
					oneTime=0;
					idx=i;
					}
				}
			ll ans=1;
			oneTime=1;
			for(int i=0;i<n;i++){
				if(oneTime&&i==idx){
					oneTime=0;
					continue;
					}
				ans = (ans*prp[i])%Mod;
				}
			tt = (tt*(tt+1)/2)%Mod;
			ans = (ans*tt)%Mod;
			cout<<ans<<endl;		
			}	
		
	return 0;
	}
