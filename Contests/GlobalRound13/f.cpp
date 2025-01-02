#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long double getWinProbability(long double ra, long double rb) {
    return 1.0 / (1.0 + pow((long double) 10.0, (rb - ra) / 400.0));
}

long double aggregateRatings(vector<long double> teamRatings)
{
    long double left = 1;
    long double right = 1E4;

    for (int tt = 0; tt < 100; tt++) {
        long double r = (left + right) / 2.0;

        long double rWinsProbability = 1.0;
        for(int i = 0;i < teamRatings.size();i++)
            rWinsProbability *= getWinProbability(r, teamRatings[i]);

        long double rating = log10(1 / (rWinsProbability) - 1) * 400 + r;

        if (rating > r)
            left = r;
        else
            right = r;
    }

    return (left + right) / 2.0;
}

int main(){
	fast
	cout << aggregateRatings({1743,1781,2237}) << '\n';
}