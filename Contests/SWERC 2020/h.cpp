#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node{
    node *l;
    node *r;
    ll sum = 0;
    node(){
        l = r = nullptr;
        sum = 0;
    }
    node(int val){
        sum = val;
        l = r = nullptr;
    }
    node(node* a,node* b){
        l = a;
        r = b;
        sum = 0;
        if(l != nullptr)sum += l->sum;
        if(r != nullptr)sum += r->sum;
    }
};

struct PersistentSegTree{
    int TO;
    PersistentSegTree(int _n){
        TO = _n;
    }    

    node* update(int at,int val, node *n,int s,int e){
        if(n == nullptr)n = new node();

        if(s == e)return new node(n->sum + val);
        
        if(at <= (s + e)/2){
            return new node( update(at , val, n->l, s , (s + e)/2 ) , n->r);
        }else{
            return new node( n->l , update(at , val, n->r, (s+e)/2 + 1 , e));
        }
    }


    ll get(int l,int r,node *n,int s,int e){
        if(s > r || e < l || l > r || n == nullptr)return 0;
        if(s >= l && e <= r)return n->sum;
        return get(l,r,n->l , s, (s+e)/2) + get(l,r,n->r,(s+e)/2+1,e);
    }

    node* update(int at,int val,node *n){
        return update(at , val, n, 1 , TO);
    }

    ll get(int l,int r,node *n){
        return get(l , r , n , 1 , TO);
    }

};

int main(){
	fast
    int n;
    cin>>n;

    PersistentSegTree tree(n);
    vector<node*> head;
    head.push_back(new node());

	string s;
    getline(cin,s);
    for(int i=1;i<=n;i++){
    	getline(cin,s);
        head.push_back(head.back());
    	if(s.empty())continue;


    	int op = 1;
    	int val = 0;
    	for(int j=0;j<s.size();j++){
    		if(s[j] == '-'){
    			op = -1;
    		}else if(s[j] == '+'){
    			op = 1;
    		}else if(s[j] == ' '){
    			assert(val < n);

                head[i] = tree.update(val + 1 , op, head[i]);
    			val = 0;
    		}else{
    			val *= 10;
    			val += (s[j] - '0');
    		}
    	}

    	assert(val < n);
		head[i] = tree.update(val + 1 , op, head[i]);
		val = 0;
    }


    int x = 0;
    for(int i=0;i<n;i++){
    	int d;
    	cin>>d;
    	ll y = tree.get(x+1 , n, head[d]);
    	x = (x + y)%n;
    }
    cout << x << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/