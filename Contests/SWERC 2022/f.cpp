#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
	set<pair<int,int>> st;

	node(){

	}
};

struct SegTree{
    typedef node T;
    int n;
    vector<T> seg;

    SegTree(int _n){
        n = _n;
        seg = vector<T>(4*n);
    }

    void update(int l,int r,pair<int,int> val,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
            seg[n].st.insert(val);
            return;
        }

        update(l,r,val,n+n,s,(s+e)/2);
        update(l,r,val,n+n+1,(s+e)/2+1,e);
    }

    int get(int at,int n,int s,int e){
  
        if(s > at || e < at)return -1;
        if(s == e){
            return n;
        }
        return max(get(at,n+n,s,(s+e)/2) , get(at,n+n+1,(s+e)/2+1,e));
    }

    void update(int l,int r,pair<int,int> val){
        update(l,r,val,1,1,n);
    }

    int get(int at){
        return get(at,1,1,n);
    }

};

struct SegTree2{
    typedef node T;
    int n;
    vector<T> seg;

    SegTree2(int _n){
        n = _n;
        seg = vector<T>(4*n);
    }

    void update(int at,pair<int,int> val,int n,int s,int e){
        if(s > at || e < at)return;
        seg[n].st.insert(val);
        if(s == e){
            return;
        }

        update(at,val,n+n,s,(s+e)/2);
        update(at,val,n+n+1,(s+e)/2+1,e);
    }

    vector<int> res;
    void get(int l,int r,int v,int n,int s,int e){
        if(s > r || e < l || l > r)return;
        if(s >= l && e <= r){
        	set<pair<int,int>> &st = seg[n].st;
        	while(st.size() && (*st.rbegin()).first >= v){
        		pair<int,int> cur = *st.rbegin();
        		st.erase(cur);
        		res.push_back(cur.second);
        	}
            return;
        }
        get(l,r,v,n+n,s,(s+e)/2);
        get(l,r,v,n+n+1,(s+e)/2+1,e);
        return ;
    }

    void update(int at,pair<int,int> val){
        update(at,val,1,1,n);
    }

    vector<int> get(int l,int r,int v){
    	res.clear();
    	get(l,r,v,1,1,n);
        return res;
    }

};

void solve(){
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> p(n);

	SegTree tree(n);
	SegTree2 tree2(n);

	for(int i=0;i<n;i++){
		cin>>p[i];
		int fr = i - p[i] + 1;
		int to = i + p[i] + 1;
		fr = max(fr , 1);
		to = min(to , n);
		tree.update(fr,to,{p[i],i+1});
		tree2.update(i+1,{p[i],i+1});
	}

	vector<int> q;
	vector<int> dist(n+1,-1);
	int qh = 0;
	q.push_back(a);
	dist[a] = 0;

	for(qh=0;qh<q.size();qh++){
		int u = q[qh];
		int at = tree.get(u);
		// cerr << u << ' ' << dist[u] << ": " << '\n';
		while(at){
			set<pair<int,int>> &st = tree.seg[at].st;
			while(st.size() && (*st.begin()).first <= p[u-1]){
				int v = (*st.begin()).second;
				// cerr << v << ' ' << dist[v] << '\n';
				// cerr << v << '\n';
				if(dist[v] == -1){
					dist[v] = dist[u] + 1;
					q.push_back(v);
				}
				st.erase(st.begin());
			}
			at/=2;

		}

		int fr = u - p[u-1];
		int to = u + p[u-1];
		fr = max(fr , 1);
		to = min(to , n);
		vector<int> res = tree2.get(fr,to,p[u-1]);

		for(int v : res){
			// cerr << v << ' ' << dist[v] << '\n';
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push_back(v);
			}
		}
	}

	if(dist[b] == -1)dist[b] = 0;
	cout << dist[b] << '\n';

}

int main(){
	fast
	int t;
	cin>>t;
	while(t--)solve();
}

/*
	1- Look at base case (n=1,m=1)
	2- Overflow 
	3- Use assert
*/