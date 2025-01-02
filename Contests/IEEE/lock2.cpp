#include <bits/stdc++.h>

using namespace std;
 
#define endl "\n"
#define int long long
#define all(x) (x).begin(), (x).end()

typedef long long ll ;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll ooo = 4e18 ;
const ll oo = 2e9 ;
const double PI = acos(-1) ;
const ll M = 1e9+7 ;
const int N = 10000010  ;

map<char,pair<int,int>> mp;

main(){
	cout.precision(12);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    srand(time(NULL));

   string l = "abcdefghijklmnopqrstuvwxyz";

    vector<string> dic;

    string s;
    map<char,int> mp[10];
    while(cin>>s){
    	dic.push_back(s);
    	for(int i = 0; i < s.size(); ++i){
    		mp[i][s[i]]++;
    	}
    }
	cerr << 1 << '\n';
	return 0;

    auto cnt = [&](vector<string> &w){
    	int res = 0;
    	for(string &word : dic){
    		bool good = true;
    		for(int i=0;i<8;i++){
    			if(i >= word.size() && w[i].size() == 10){
    				good = false;
    				break;
    			}else if(i >= word.size())break;

    			bool fnd = false;
    			for(char &c : w[i]){
    				if(word[i] == c){
    					// cout << word[i] << " " << c << endl;
    					fnd = true;break;
    				}
    			}
    			if(!fnd){
    				good = false;
    				break;
    			}
    		}
			res += good;
    	}
    	return res;
    };


    vector<vector<int>> fr(8,vector<int>(26));
    
    int ans = 0;
    vector<string> best;
    int tms = 1;
    while(true){
    	vector<string> words;
    	
    	// words = {"toaiuvzxcn","toahuvzecn","toaiuezxcn"};

    	for(int i=0;i<8;i++){

    		for(string &w : dic){
    			if(i >= w.size())continue;
    			bool good = true;
    			for(int j=0;j<i;j++){
	    			bool fnd = false;
	    			for(char &c : words[j])
		    			if(w[j] == c){
		    				fnd = true;
		    				break;
		    			}
	    			if(!fnd){
	    				good = false;
	    				break;
	    			}
	    		}
	    		if(!good)continue;

	    		fr[i][w[i] - 'a'] += 1;
		    }

		    // shuffle(all(l) , rng);
    		sort(all(l) , [&](char a,char b){
    			return fr[i][a - 'a'] > fr[i][b - 'a'];
    		});
	    	words.push_back(l.substr(0,10));
	    	shuffle(all(words.back()) , rng);
    	}


    	for(int r=1;r<=words.size() + 1;r++){
    		// cout << words[words.size() - r] << " " 
    		int cur = cnt(words);
    		if(cur > ans){
    			ans = cur;
    			if(ans > 1500) break;
    			best = words;
    		}
    		if(r <= words.size())words[words.size() - r].pop_back();
    	}
    	if(ans > 1500) break;
    }
    ld CUR = 98.04;
    ld score = pow(ans / 1574.0 , 8) * CUR;
    cout << setprecision(2) << fixed << score << ' ' << ans << '\n';
    cout << "vector<string> res = {";
    for(int i=0;i<best.size();i++){
    	cout << "\"" << best[i] << "\"";
    	if(i + 1 != best.size())cout << ',';
    }
    cout << "};";

}