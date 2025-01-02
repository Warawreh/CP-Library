#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int t, n, ax[1009], ay[1009], inf=2e9;
ll l,r, ans;
ld eps=1e-8;
void simplify(pair<int,int> &p)
{
    int g=__gcd(abs(p.first),abs(p.second));
    p.first/=g, p.second/=g;
}
pair<int,int>  perp(pair<int,int> p)
{
    return  make_pair(-p.second,p.first);
}
int main()
{
    IO
     freopen("points.in", "r", stdin);
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>l>>r;
        r*=2, l*=2;
        for(int i=1; i<=n; i++)
            cin>>ax[i]>>ay[i];
        for(int i=1; i<=n; i++)
        {
            int cnt=1, go[2002]= {};
            map<ld,int> id ;
            vector<ld> v[2002];
            for(int j=1; j<=n; j++)
            {
                if(i==j)
                    continue;
                pair<int,int> p;
                p.first=ax[i]-ax[j], p.second=ay[i]-ay[j];
                simplify(p);
                ld slope1=p.second ? 1.0*p.first/p.second : inf ;
                if(!id[slope1])
                    id[slope1]=cnt++;
                ld d1=ax[i]-ax[j], d2=ay[i]-ay[j];
                int id1=id[slope1];
                v[id1].push_back(sqrt(d1*d1+d2*d2));
                pair<int,int> p2=perp(p);
                ld slope2=p2.second ? 1.0*p2.first/p2.second : inf ;
                if(!id[slope2])
                    id[slope2]=cnt++;
                go[id1]=id[slope2];
            }
            for(int j=1; j<=cnt; j++)
                sort(v[j].begin(),v[j].end());
            for(int j=1; j<=cnt; j++)
                for(auto d  : v[j])
                    ans+=upper_bound(v[go[j]].begin(),v[go[j]].end(),r/d+eps)
                         -lower_bound(v[go[j]].begin(),v[go[j]].end(),l/d-eps);

        }
        cout<<ans/2<<endl;
    }
}
