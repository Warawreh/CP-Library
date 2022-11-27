/*
Name: Suffix Array
Description: Sort all suffixes of a string in nlogn time
Time: O(NLogN) to build 
Space: O(N)
 
*/

int conv(char c){
    string sp = "$";
    for(int i=0;i<sp.size();i++)
        if(sp[i] == c)
            return i;
    return c - 'a' + sp.size();
}

vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();

    //replace with 256 for all chars and remove conv function
    const int alpha = 27;

    vector<int> p(n), c(n), cnt(max(alpha, n), 0);

    for (int i = 0; i < n; i++)cnt[conv(s[i])]++;
    for (int i = 1; i < alpha; i++)cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)p[--cnt[conv(s[i])]] = i;

    c[p[0]] = 0;
    int lvl = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])lvl++;
        c[p[i]] = lvl - 1;
    }

    vector<int> pn(n), cn(n);
    for(int h=0;(1 << h)<n;h++){
        for(int i=0;i<n;i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + lvl, 0);
        for(int i=0;i<n;i++)cnt[c[pn[i]]]++;
        for(int i=1;i<lvl;i++)cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--)p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        lvl = 1;
        for(int i=1;i<n;i++){
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)lvl++;
            cn[p[i]] = lvl - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string &s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    // sorted_shifts.erase(sorted_shifts.begin()); //Remove Empty String
    return sorted_shifts;
}
