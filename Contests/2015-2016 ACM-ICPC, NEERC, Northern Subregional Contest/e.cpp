#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(),(x).end();

int main(){
	// freopen("easy.in" , "r" , stdin);
	// freopen("easy.out" , "w" , stdout);
	string x,ans = "";
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i] == '-'){
			ans+=x[i];
			ans+=x[i+1];
			ans+='+';
			i++;
		}else if(x[i] == '+'){
			if(ans[ans.size()-1] == x[i])continue;
			else ans+='+';
		}else{
			if(ans[ans.size()-1] == '0' && ans[ans.size()-2] == '+' && ans.size()-2 >= 0)ans+='+';
				ans+=x[i];
		}
	}
	for(int i=0;i<ans.size();i++){
		if(ans[i] == '+' && ans[i+1] == '-' || ans[i] == '+' && ans[i+1] == '+' && i!=ans.size()-1)i++;
		if(i == ans.size()-1 && ans[i] == '+')continue;
		cout<<ans[i];
	}
	cout<<endl;
}