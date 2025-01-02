#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

int main(){
	freopen("black.in" , "r" , stdin);
	freopen("black.out" , "w" , stdout);
	int b,w;
	char x='@',y='.';
	cin>>b>>w;
	if(b > w){
		swap(x,y);
		swap(b,w);
	}
	string line1 = "",line2 = "";
	for(int i=0;i<b/2;i++){line1+=x;line1+=y;line2+=y;line2+=x;}
	for(int i=0;i<w-2*(b/2);i++){line1+=x;line1+=y;line2+=x;line2+=x;}
	if(b%2 && b!=1){line1+=y;line1+=x;line2+=y;line2+=x;}
	cout<<2<<" "<<line1.size()<<endl;
	cout<<line1<<endl<<line2<<endl;
}