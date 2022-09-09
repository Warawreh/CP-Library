/*
Name: Sieve
Description: find prime numbers <= n
Time: O(N) to build array prime
Space: O(#primes + n) for primes and array is_composite
*/

vector<int> prime;
vector<bool> is_composite;

void sieve (int n) {
   is_composite = vector<bool>(n+1);
   for(int i = 2;i <= n;i++){
      if(is_composite[i] == 0) prime.push_back (i);
      for(int j=0;j<prime.size() && i * prime[j] <= n;++j) {
         is_composite[i * prime[j]] = true;
         if (i % prime[j] == 0) break;
      }
   }
}