/*
Tested : https://dmoj.ca/problem/fibonacci
Source : https://cp-algorithms.com/algebra/fibonacci-numbers.html#periodicity-modulo-p
*/

const int mod = 1e9 + 7;
pair<ll, ll> fib (ll n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    ll c = (p.first * (2 * p.second - p.first + mod)%mod)%mod;
    ll d = ((p.first * p.first)%mod + (p.second * p.second)%mod)%mod;

    if (n & 1)
        return {d, (c + d)%mod};
    else
        return {c, d};
}