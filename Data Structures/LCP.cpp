/*
Name: Longest Common prefix (Suffix Array)
Description: Find the LCP for two prefixes 
Time: O(Nlogn) build O(Log n) query using Segment tree / O(nLogn) build O(1) query using Sparse Table
Space: O(N)
Notes: 
    - DSU helps a lot with this (merge by LCP largest first)
*/

vector<int> LCP(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)k--;
    }
    return lcp;
}