#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class node{
    int a;
    double b;
};

int main(){
	fast
	string k = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789-,";
	shuffle(all(k),rng);
	cout << k << '\n';
}

//x,QjBFlGASUVuhcYPtRNoJazMDnfK5b0qs-WeZpXI4dk791w3i682vOLyEgrmTHC