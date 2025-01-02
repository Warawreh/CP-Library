#include <bits/stdc++.h>

using namespace std;

int Geter(int sum, int steps, int m)
{
    int count = steps / 7;
    steps -= count;
    sum -= steps + count * 3;
    if (count > m || sum < 0)
    {
        return -1;
    }
    if (sum > 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
  int t;
  cin >> t ;
  while (t--)
  {

      int a , b , c ;
      cin >> a >> b >> c ;
      int mi = min(min(a,b),c);
      int sum = a +b +c ;
      int s = 1 ;
      int r = 3 * 100000000;
      bool flag = false;
      while(s <= r)
      {
          int m = s + (r-s) / 2 ;
          int val = Geter(sum , m*7 , mi);
          if(val > 0 )
          {
              s = m + 1 ;

          }
          else if (val < 0 )
          {
              r = m - 1 ;
          }
          else
          {flag = true; break;}
      }
      if (flag)
        cout << "YES" << endl;
        else
            cout << "NO" << endl;
  }
}

