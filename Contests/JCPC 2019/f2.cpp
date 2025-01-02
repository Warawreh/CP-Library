#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int n,k;
vector<vector<pair<int,int> > > g;
bool mark[N],on[N];
char label[N];
int last;
bool DFS(int u,int p){
	bool ret=false;
	if(mark[u]){
		last=u;
		ret=true;
	}
	for(auto v:g[u])
		if(v.first!=p && DFS(v.first,u))
			ret=true;
	if(ret)
		on[u]=true;
	return ret;
}
void labelTree(int u,int p){
	string s="UDLR";
	for(int i=0;i<4;++i)
		if(s[i]==label[p]){
			s.erase(s.begin()+(i^1));
			break;
		}
	for(auto e:g[u])
		if(e.second!=p){
			label[e.second]=s.back();
			s.pop_back();
			labelTree(e.first,e.second);
		}
}
int main() {
	int t;
	scanf("%d",&t);
	int totalK=0;
	vector<int> F(10);
	while(t--){
		scanf("%d%d",&n,&k);
		totalK+=k;
		g.clear();
		g.resize(n);
		fill(mark,mark+n,0);
		fill(label,label+n,0);
		fill(on,on+n,0);
		int root;
		for(int i=0,x;i<k;++i){
			scanf("%d",&x);
			--x;
			mark[x]=true;
			root=x;
		}
		for(int i=0,a,b;i+1<n;++i){
			scanf("%d%d",&a,&b);
			--a;--b;
			g[a].push_back({b,i});
			g[b].push_back({a,i});
		}
		DFS(root,-1);
		bool bad=false;
		vector<int> ends;
		vector<char> adj(n);
		{
			int u=last;
			last=-1;
			vector<pair<int,int> > path;
			while(true){
				bool f=false;
				for(auto v:g[u])
					if(v.second!=last && on[v.first]){
						path.push_back({u,v.second});
						u=v.first;
						last=v.second;
						f=true;
						break;
					}
				if(!f)
					break;
			}
			path.push_back({u,-1});
			string str="LU";
			int idx=0;
			if(path.size()>1){
    			label[path[0].second]=str[0];
    			adj[path[0].first]=str[0];
			}
			for(int i=1;i+1<path.size();++i){
				if(mark[path[i].first])
					label[path[i].second]=str[idx^=1];
				else
					label[path[i].second]=str[idx];
				adj[path[i].first]=label[path[i].second];
				adj[path[i+1].first]=label[path[i].second];
			}
		}
		for(int u=0;u<n;++u)
			if(on[u]){
				int adjC=0;
				vector<pair<int,int> > other;
				for(auto v:g[u])
					if(on[v.first])
						++adjC;
					else
						other.push_back(v);
				if(adjC>2){
				    ++F[0];
					bad=true;
					break;
				}
				if(adjC<2){
					++F[1];
					ends.push_back(u);
					continue;
				}
				if(mark[u]==false){
					string str=adj[u]=='L'?"UD":"LR";
					if(str=="UD")
					    ++F[2];
					else
					    ++F[3];
					for(int i=0;i<other.size();++i){
						label[other[i].second]=str[i];
						labelTree(other[i].first,other[i].second); // label and avoid parent
					}
				}else{
				    ++F[4];
					if(other.size()>0){
					    ++F[5];
						bad=true;
						break;
					}
				}
			}
		if(!bad)
		for(auto u:ends){
		    string str="UDRL";
		    if(adj[u]=='U'){
		        reverse(str.begin(),str.end());
		        ++F[6];
		    }else
		        ++F[7];
			vector<pair<int,int> > who;
			for(auto v:g[u])
				if(!on[v.first])
					who.push_back(v);
			if(who.size()%2){
			    ++F[8];
				bad=true;
				break;
			}else{
			    ++F[9];
				for(int i=0;i<who.size();++i){
					label[who[i].second]=str[i];
					labelTree(who[i].first,who[i].second);
				}
			}
		}
		if(bad)
			puts("-1");
		else{
			label[n-1]='\0';
			puts(label);
		}
	}
	for(auto x:F)
	    cerr<<x<<" ";
	return 0;
}