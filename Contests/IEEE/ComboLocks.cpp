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
    string l = "qweryuioplkjhgfdsazxcvbnm";

    vector<string> dic;
    {
	    string s;
	    while(cin>>s){
	    	dic.push_back(s);
	    }

    }

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
    			for(char &c : w[i])if(word[i] == c){
    				fnd = true;break;
    			}
    			if(!fnd){
    				good = false;
    				break;
    			}
    		}
    		// if(word == "the")cerr << good << '\n';
			res += good;
    	}
    	return res;
    };

    vector<vector<int>> fr(8,vector<int>(26));
    

    int ans = 0;
    vector<string> best;
    int tms = 10000;
    while(1){
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

	    		fr[i][w[i] - 'a'] += 8 - w.size();
		    }

    		sort(all(l) , [&](char a,char b){
    			return fr[i][a - 'a'] > fr[i][b - 'a'];
    		});
	    	words.push_back(l.substr(0,10));
	    	// cerr << words.back() << '\n';
	    	// shuffle(all(words.back()) , rng);
	    	// words.back()[0] = 't';
    	}


    	for(int r=1;r<=words.size() + 1;r++){
    		int cur = cnt(words);
    		if(cur > ans){
    			ans = cur;
    			best = words;
    		}
    		if(r <= words.size())words[words.size() - r].pop_back();
    	}
    }
    ld CUR = 99.02;
    ld score = pow(ans / 1559.0 , 8) * CUR;
    cout << setprecision(2) << fixed << score << ' ' << ans << '\n';
    cout << "vector<string> res = {";
    for(int i=0;i<best.size();i++){
    	cout << "\"" << best[i] << "\"";
    	if(i + 1 != best.size())cout << ',';
    }
    cout << "};";
}

/*
   Answer = 1376
*/