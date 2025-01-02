#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef int64_t      LI;
typedef pair<LI,LI>  Pair;

const int  MaxN = 500005;

class SegmentTree
{
  public:
    #define lKid  rt << 1
    #define rKid  rt << 1 | 1
    const Pair    OK = Pair( 1, 0 );

    struct STNode
    {
        LI  s;
        LI  mn;
        LI  mx;
        LI  len;
        STNode( LI a = 0, LI b = 0, LI c = 0, LI d = 0 )
        { s = a;  mn = b;  mx = c;  len = d; }
    };

  private:
    STNode  T[MaxN<<2];
    Pair    lzy[MaxN<<2];     

  public:
    LI  a[MaxN];

    // --METHODS
    void build( int rt, int L, int R )
    {
        T[rt].len = R - L + 1;

        if( L == R )  
        {
            T[rt].mn = a[L];
            T[rt].mx = a[L];
            T[rt].s  = a[L];
            return;
        }
        
        int  mid = ( L + R ) >> 1;
        build( lKid, L, mid );
        build( rKid, mid + 1, R );
        
        lzy[rt]  = OK;

        combineKids( rt );
    }

    void update( int rt, int L, int R, int x, int y, Pair v )
    {
        if( y < L  ||  R < x )    return;

        if( L >= x  &&  R <= y )
        {
            merge( rt, v );
            return;
        }

        propagate( rt );

        int  mid = ( L + R ) >> 1;
        update( lKid, L, mid, x, y, v );
        update( rKid, mid + 1, R, x, y, v );

        combineKids( rt );
    }

    void minUpdate( int rt, int L, int R, int x, int y, LI v )
    {
        if( y < L  ||  R < x  ||  T[rt].mx <= v )    return;

        if( L >= x  &&  R <= y  &&  v <= T[rt].mn )
        {
            merge( rt, Pair( 0, v ) );
            return;
        }

        propagate( rt );

        int  mid = ( L + R ) >> 1;
        minUpdate( lKid, L, mid, x, y, v );
        minUpdate( rKid, mid + 1, R, x, y, v );

        combineKids( rt );
    }

    void maxUpdate( int rt, int L, int R, int x, int y, LI v )
    {
        if( y < L  ||  R < x  ||  T[rt].mn >= v )    return;

        if( L >= x  &&  R <= y  &&  v >= T[rt].mx )
        {
            merge( rt, Pair( 0, v ) );
            return;
        }

        propagate( rt );

        int  mid = ( L + R ) >> 1;
        maxUpdate( lKid, L, mid, x, y, v );
        maxUpdate( rKid, mid + 1, R, x, y, v );

        combineKids( rt );
    }

    LI query( int rt, int L, int R, int x, int y )
    {
        if( y < L  ||  R < x )     return LI( 0 );

        if( L >= x  &&  R <= y )   return T[rt].s;

        propagate( rt );

        int  mid = ( L + R ) >> 1;
        
        return add( query( lKid, L, mid, x, y ),
                    query( rKid, mid + 1, R, x, y ) );
    }

  private:
    LI add( LI x, LI y ) 
    {
        return x + y;
    }

    void combineKids( int rt )
    {
        T[rt].s  = add( T[lKid].s,  T[rKid].s );
        T[rt].mn = min( T[lKid].mn, T[rKid].mn );
        T[rt].mx = max( T[lKid].mx, T[rKid].mx );
    }

    void merge( int rt, Pair v ) 
    {
        LI  k = v.first;
        LI  b = v.second;
        if( k )
        {
            T[rt].s        = add( T[rt].s * k, T[rt].len * b );
            T[rt].mn       = T[rt].mn * k + b;
            T[rt].mx       = T[rt].mx * k + b;
            lzy[rt].first  = lzy[rt].first * k;
            lzy[rt].second = lzy[rt].second * k + b;
        }
        else
        {
            T[rt].s        = T[rt].len * b;
            lzy[rt].first  = 0;
            T[rt].mn = T[rt].mx = lzy[rt].second = b;
        }
    }

    void propagate( int rt )
    {
        if( lzy[rt] == OK )   return;

        merge( lKid, lzy[rt] );
        merge( rKid, lzy[rt] );
        lzy[rt] = OK;
    }
};

SegmentTree  tree;

int main(){
	fast
	int n;
	string s;
	cin>>n>>s;

    tree.build( 1, 1, n );
    int len = 0;
    ll ans = 0;
    int l = -1;
    for(int i=0;i<n;i++){
    	if(s[i] == '1'){
    		len++;
    		if(l == -1)l = i;
    		tree.update(1, 1, n, l+1, i+1, Pair( 1, 1 ) );
    		if(l)tree.maxUpdate(1,1,n,1,l,len);
    	}else{
    		l = -1;
    		len = 0;
    	}
    	ans +=  tree.query(1,1,n,1,i+1);
    	// cerr << tree.query(1,1,n,1,i+1) << '\n';
    }
    cout << ans << '\n';
}