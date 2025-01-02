#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
	 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

indexed_set s;

int main(){
	fast
	s.insert(1);
	s.insert(2);
	s.insert(4);
	cout << s.size() << ' ' << s.order_of_key(2) << '\n';
}