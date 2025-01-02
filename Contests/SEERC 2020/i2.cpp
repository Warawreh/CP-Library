#include <bits/stdc++.h>

using namespace std;


#define sim template < class c
#define ris return * this
#define dor > dout & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, dout&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct dout {
#ifdef LOCAL
~dout() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define esem(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
    fast
  	int n;
  	for(int n=8;n<=8;n++){

  		vector<int> a(n);
  		iota(all(a) , 1);
  		int ans = 0,tot = 0;
  		do{	
  			tot++;
  			bool good = true;
  			for(int i=0;i<n;i++){
  				if(a[i] % a[(i+1)%n] > 2)good = false;
  			}
  			ans += good;
         if(good){
            if(a[0] == 1)
                for(int i=0;i<a.size() - 1;i++){
                    if(a[i+1] == 2 && a[i] == 6)
                        dout() << a;
                }
         }

  		}while(next_permutation(all(a)));

  		assert(ans % n == 0);
  		cerr << ans << ',';
  	}  
    cerr << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/

/*
1 2 3 4  5  6   7    8     9      10
1 2 6 16 40 96  196  384   684    1200    1936     3120 
1 1 4 10 30 56  100  188   300    516

0 0 0 8  80 624 4844 39936 362196 3627600 39914864 
*/