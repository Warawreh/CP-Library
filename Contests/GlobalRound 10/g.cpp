#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
ll h[1000100];
ll n;
int main(){
    //ios_base::sync_with_stdio(0);
    cin>>n;
    ll sum=0;
    for(int i=0;i<n;i++){
        ll o;
      //  cin>>o;
        scanf("%lld",&o);
        sum+=o;
    }
    ll hi=1000000000000,lo=n-1,best=n-1;
    while(hi>=lo){
        ll mid=(hi+lo)/2LL;
        ll k=(mid+(mid+1-n))*n/2LL;

        if(k<=sum){
            best=max(best,mid);
           // cout<<k<<' '<<mid<<endl;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    for(int i=n;i>=1;i--){
        h[i]=best;
        best--;
        sum-=h[i];
    }
    for(int i=1;i<=n;i++){
        if(sum){
            sum--;
            h[i]++;
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",h[i]);

    return 0;
}
/*
n/2*(n+1)

*/
