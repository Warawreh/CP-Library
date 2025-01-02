#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
    fast
    vector<int> ans(3);
    cout << "1 0 0" << endl;
    fflush(stdout);
    cin>>ans[0];
    cout << "0 1 0" << endl;
    fflush(stdout);
    cin>>ans[1];
    cout << "0 0 1" << endl;
    fflush(stdout);
    cin>>ans[2];

    cout << "3 5 7" << endl;
    fflush(stdout);
    int res1;
    cin>>res1;
    cout << "3 5 7" << endl;
    fflush(stdout);
    int res2;
    cin>>res2;
    
    if(res1 != res2){
        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
        fflush(stdout);
    }else{
        for(int i=0;i<3;i++){
            int cur = res1 - 3 * ans[0] - 5 * ans[1] - 7 * ans[2];
            if(i == 0){
                cur += 3 * ans[0];
                if(cur % 3 == 0 && cur >= 0){
                    ans[0] = cur / 3;
                    break;
                }x
            }
            else if(i == 1){
                cur += 5 * ans[1];
                if(cur % 5 == 0 && cur >= 0){
                    ans[1] = cur / 5;
                    break;
                }
            }
            else if(i == 2){
                cur += 7 * ans[2];
                if(cur % 7 == 0 && cur >= 0){
                    ans[2] = cur / 7;
                    break;
                }
            }
        }

        cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
        fflush(stdout);
    }
}
