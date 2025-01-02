#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
    fast
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    vector<string> x(a),y(b);
    for(int i=0;i<a;i++)cin>>x[i];
	for(int i=0;i<b;i++)cin>>y[i];

	if(a > b){
		swap(a , b);
		swap(n,m);
		swap(x,y);
	}

	unordered_map<string , vector<string>> y12,x12;
	unordered_map<string , bool> hv;

	for(int i=0;i<b;i++){
		y12[y[i].substr(0,2)].push_back(y[i]);
		hv[y[i]] = 1;
	}

	for(int i=0;i<a;i++){
		x12[x[i].substr(0,2)].push_back(x[i]);
	}

	int ans = 0;
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			string l = x[i].substr(0,1) + x[j].substr(0,1);
			string r = x[i].substr(1,1) + x[j].substr(1,1);
			for(string &g : y12[l]){
				for(string &g2 : y12[r]){


					if(m == 4){
						string l2 = g.substr(2,1) + g2.substr(2,1);
						string r2 = g.substr(3,1) + g2.substr(3,1);
						// cerr << x[i] << ' ' << x[j] << '\n';
						// cerr << g << ' ' << g2 << ' ' << l2 << ' ' << r2 << '\n';

						for(string &gg : x12[l2]){
							for(string &gg2 : x12[r2]){

								bool good =1;

								for(int w=0;w<n;w++){
									string cur = x[i].substr(w,1) + x[j].substr(w,1) + gg.substr(w,1) + gg2.substr(w,1);
									if(w < 2)assert(hv[cur]);
									// cerr << x[i] << ' ' << x[j] << ' ' << gg << ' ' << gg2 << ' ' << cur << ' ' << hv[cur] << '\n';
									if(!hv[cur]){
										good = 0;
										break;
									}
								}
								ans+=good;

							}
						}

					}else if(m == 3){

						string l2 = g.substr(2,1) + g2.substr(2,1);

						for(string &gg : x12[l2]){

							bool good =1;

							for(int w=0;w<n;w++){
								string cur = x[i].substr(w,1) + x[j].substr(w,1) + gg.substr(w,1);
								// cerr << x[i] << ' ' << x[j] << ' ' << gg << '\n';
								if(w < 2)assert(hv[cur]);
								if(!hv[cur]){
									good = 0;
									break;
								}
							}

							// if(good)cerr << x[i] << ' ' << x[j] << ' ' << gg << '\n';
							ans += good;

						}

					}else{
						ans++;
					}



				}
			}
		}
	}
	cout << ans << '\n';
}

/*
   1- Look at base case (n=1,m=1)
   2- Overflow 
   3- Use assert
*/