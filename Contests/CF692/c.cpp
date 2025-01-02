#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void NO(){
	cout << "No\n";
	exit(0);
}

int main(){
	fast
	int n;
	ll t;
	string s;
	cin>>n>>t>>s;
	ll sum = t;
	vector<int> b(30);
	ll hv = 0;
	for(int i=0;i<n;i++){
		if(i == n-2)sum += pow(2 , s[i] - 'a');
		else if(i == n-1)sum -= pow(2,s[i] - 'a');
		else{
			hv += pow(2,s[i] - 'a');
			b[s[i] - 'a']++;
		}
		// cout << pow(2,s[i] - 'a') << ' ';
		// if(i == n-1)sum += pow(2,s[i] - 'a');
		// else sum -= pow(2,s[i] - 'a');
	}
	if(sum < 0)sum = -sum;
	sum += hv;
	for(int i=25;i>=0;i--){
		while(b[i] && sum >= (1 << (i + 1))){
			b[i]--;
			sum -= (1<< (i + 1));
		}
	}
	if(sum == 0)cout << "Yes\n";
	else cout << "No\n";
	return 0;
	int need = 0;
	for(int i=0;i<26;i++){
		if((sum >> i) & 1){
			if(b[i]){
				sum -= (1<<i);
				b[i]--;
			}else need++;
		}
	}
	// cerr << sum << '\n';
	for(int i=0;i<26;i++){
		if((sum >> i) & 1){
			// cerr << i << ' ' << b[i] << '\n';
			assert(b[i] >= 0);
			if(b[i] == 0)NO();
			need--;
			b[i]--;
		}
		if(b[i] % 2)NO();
		int need = ((sum >> (i+1)) & 1);
		if(b[i] == 0)continue;
		if(need){
			if((b[i]/2)%2){
				b[i+1] += b[i]/2;
			}else{
				b[i+1] += b[i]/2 - 1;
			}
		}else{
			if((b[i]/2)%2){
				b[i+1] += b[i]/2 - 1;
			}else{
				b[i+1] += b[i]/2;
			}
		}
	}
	cout << "Yes\n";
}