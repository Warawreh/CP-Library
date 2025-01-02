#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int nax = 1111;
int ans[nax];

int ask(int i,int v){
	cout << "? " << i << ' ' << v << '\n';
	fflush(stdout);
	char res;
	cin>>res;
	if(res == '=')return 0;
	if(res == '<')return -1;
	return 1;
}

void init(){
	struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);

}
int rand_range(int l,int r){
	int dif = r-l+1;
	return l + rand()%dif;
}

void solve(vector<int> a,vector<int> b){
	if (a.empty()) return;
	if(a.size() == 1) {
	    ans[a[0]] = b[0];
	    return;
	}else{
	int x = a[rand_range(0,a.size()-1)];
	vector <int> l, r;
	int same = -1;
	for (int t : b) {
		int go = ask(x, t);
		if (go < 0) {
			l.push_back(t);
		} else if (go == 0) {
			same = t;
		} else {
			r.push_back(t);
		}
	}
	ans[x] = same;
	vector <int> left, right;
	for (int t : a) {
		if (t == x) continue;
		int go = ask(t, same);
		if (go > 0) {
			left.push_back(t);
		} else if (go < 0) {
			right.push_back(t);
		}
	}
	solve(left, l);
	solve(right, r);
	}
}

int main(){
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.precision(10);
	// cout << fixed;
	int n;
	cin>>n;
	init();
	vector<int> a(n);
	for(int i=0;i<n;i++)a[i] = i+1;
	solve(a,a);
	cout << "! ";
	for(int i=1;i<=n;i++)
		cout << ans[i] << ' ';
	cout << '\n';
}