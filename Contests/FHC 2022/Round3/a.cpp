#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
  
  S.push_back(-K);
  S.push_back(N + K + 1);
  
  sort(S.begin(),S.end());
  
  ll answer = 0;
  ll occ = K + K + 1;
  for(int i=1;i<S.size();i++){
    ll eSeats = S[i] - S[i-1] - 1;
    cout << S[i] << ' ' << S[i-1] << ' ' << eSeats << '\n';
    if(eSeats >= occ){
      eSeats-=occ;
      answer++;
      answer += eSeats / (K + 1);
    }
  }
  
  return answer;
}

int main(){
	fast
	cout << getMaxAdditionalDinersCount(10,1,2,{2,6}) << '\n';
}

/*
14 13 12 1
15 5 6 7
16 2 3 4
8 9 10 11

*/