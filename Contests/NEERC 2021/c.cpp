#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define getrand(l, r) uniform_int_distribution<int>(l, r)(rng)

int n;
vector<int> a;
int ASK=0;
void init(){
	a = vector<int>(n);
	iota(all(a),0);
	shuffle(all(a) , rng);
}

string bot(int i,int j){
	string ret = "STAY";
	if(a[i] > a[j]){
		swap(a[i] , a[j]);
		ret = "SWAPPED";
	}
	ASK++;
	if(ASK % (n+n) == 0){
		int x = getrand(0,n-1);
		int y = getrand(0,n-1);
		swap(a[x] , a[y]);
	}
	vector<int> b = a;
	sort(all(b));
	if(a == b)return "WIN";
	return ret;
}


int asked;

int ask(int a,int b){
	if(a > b)swap(a,b);
	asked++;
	cout << a + 1 << ' ' << b + 1 << endl;
	fflush(stdout);
	string res;
	cin>>res;
	// res = bot(a,b);
	if(res == "WIN"){

	    // cerr << ASK << '\n';
    
		exit(0);
	}
	if(res == "SWAPPED")return 1;
	else return 0;
}

int main(){
    fast
    
    cin>>n;
    // init();


    for(int i=0;i<n;i++){
    	for(int j=i+1;j<n;j++){

    		if(asked == n+n){
    			asked = 0;

    			for(int k=1;k<=i;k++){
    				if(ask(k , k-1)){
    					int at = -1;
    					for(int x=k+1;x<n;x++){
    						if(ask(k - 1 , x)){
    							if(at == -1)at = x;
    						}
    					}
    					if(at != -1){
    						// cerr << k << ' ' << at << '\n';
    						// cerr << a[k] << ' ' << a[at] << '\n';

    						// for(int w=0;w<n;w++)
    						// 	cerr << a[w] << ' ';
    						// cerr << '\n';

    						assert(ask(k , at));
    					}
    					break;

    				}
    			}
    			j = i;
    			continue;
    		}

    		ask(i,j);
    	}

    	if(asked == n+n){
    		asked = 0;

			for(int k=1;k<=min(i+1, n-1);k++){
				if(ask(k , k-1)){
					int at = -1;
					for(int x=k+1;x<n;x++){
						if(ask(k - 1 , x)){
							if(at == -1)at = x;
						}
					}
					if(at != -1){
						// cerr << k << ' ' << at << '\n';
						// cerr << a[k] << ' ' << a[at] << '\n';
						assert(ask(k , at));
					}
					break;

				}
			}

		}
    }

    
}
