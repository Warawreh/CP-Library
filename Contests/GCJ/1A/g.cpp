#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


char incode(char a) {
	string key = "JO1QNX8H6K0DP3SVYA5FG2LT,WIR-7B4E9CUZM";
	if (a >= 'A' && a <= 'Z') {
		return key[a - 'A'];
	}
	else if (a >= '0' && a <= '9') {
		return key[a - '0' + 26];
	}
	else if (a == '-') {
		return key[key.size() - 2];
	}
	else {
		return key.back();
	}
}

string encode(string code) {
	string code2 = "";
	bool cntt = 0;
	//alert(code);
	for (int i = 0; i < code.size(); i++) {
		if (cntt == 0) {
			code2 += incode(code[i]);
			code2 += code[i] + 5;
			code2 += code[i] + 7;
		}
		else {
			code2 += code[i] + 4;
			code2 += incode(code[i]);
		}
		cntt = !cntt;
	}
	//alert(code2);
	return code2;
}
int main(){
	fast
	string a = "WHEREA0AMI";
	cout << encode(a);
}

// 4WGR780F2-Y9HEBQMK5VZUDXSCNIOJ1L6AT3P