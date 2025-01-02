#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
typedef long long ll;

double S(double a){return a*a;}

int T;
void print(double ans){
	printf("Case %d: %.2f\n" ,++T,ans);
	return;
}

int sign(int a){
	if(a == 0)return 0;//on it
	if(a > 0)return 1;//left
	if(a < 0)return -1;//right
	return -1;
}

int side(pair<int,int> p,pair<int,int> s1,pair<int,int> s2){
	int position = sign((s2.first - s1.first) * (p.second - s1.second) - (s2.second - s1.second) * (p.first - s1.first));
	return position;
}

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n == 0)break;
		vector<pair<int,int>> p(n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i].first,&p[i].second);
		}
		double ans = 1e18;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				double dist = 0;
				set<int> st;
				for(int x=0;x<n;x++){
					if(x == i || x == j)continue;
					ll dy = p[i].second - p[j].second;
					ll dx = p[i].first - p[j].first;
					ll a = -dy;
					ll b = dx;
					ll c = dy*p[i].first - dx * p[i].second;
					double cur = abs(p[x].first * a + p[x].second * b + c);
					if(side(p[x],p[i],p[j]) != 0){
						st.insert(side(p[x],p[i],p[j]));
					}
					cur /= sqrt(S(a) + S(b));
					dist = max(dist , cur);
				}
				if(st.size() != 1)continue;
				// if(dist == 10)cerr << i << ' ' << j << '\n';
				ans = min(ans , dist);
			}
		}
		ans = ceil(ans * 100)/100.0;
		print(ans);
	}
}