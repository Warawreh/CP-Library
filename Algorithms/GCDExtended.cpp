/*
Name: Extended Euclidean Algorithm / Linear Diophantine Equations
Description: Find gcd of two numbers and the value x/y for equation : xa + yb = c (a,b,c are givens)
Time: O(LogN)
Notes:
if( c % g != 0)there is no solution
Valid values for x,y:
x0 = x * c/g
y0 = y * c/g
Find all any valid x,y:
x = x0 + k * b/g
y = y0 - k * a/g
*/

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}