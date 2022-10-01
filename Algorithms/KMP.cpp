/*
Name: Knuth–Morris–Pratt algorithm
Description: find the number of occers of t in s
Time: O(n) for the build O(n + m) for search
Space: O(N) 
Notes:
	For intersecting occers use
		len = fail[len-1];
	For non-intersecting occers use
		len = 0;
*/

template<int SZ> struct KMP{
	int fail[SZ];

	void build(string s){
		fail[0] = 0;
		int n = s.size();
		int len = 0;
		for(int i=1;i<n;i++){
			while(len && s[i] != s[len]){
				len = fail[len-1];
			}
			if(s[i] == s[len]){
				len++;
			}
			fail[i] = len;
		}
	}

	int occers(string s,string t){
		int n = s.size();
		int m = t.size();
		int len = 0;
		int ans = 0;
		for(int i=0;i<n;i++){
			while(len && s[i] != t[len]){
				len = fail[len-1];
			}
			if(s[i] == t[len])
				len++;
			if(len == m){
				ans++;
				len = fail[len-1];
			}
		}
		return ans;
	}

};
