// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    
    while (!cin.eof())
    {
        int n, m;
        cin >> n >> m;
        if (n == 0) break;
        

        int all = (1 << n) - 1;
        vector<int> nxt(n, 0);

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            nxt[u] |= 1 << v;
            nxt[v] |= 1 << u;
        }

        if (m > n-1) {
            cout << "Impossible\n";
            continue;
        }

        queue<int> q;
        q.push(all);
        

        vector<int> prev(1 << n, -1);
        vector<int> shotPos(1 << n, -1);
        vector<int> shotsNumber(1 << n, -1);
        shotsNumber[all] = 0;

        while (!q.empty() && shotsNumber[0] == -1)
        {
            int cur = q.front();
            q.pop();
            int k = shotsNumber[cur];

            for (int i = 0; i < n; i++)
            {
                if (cur & (1 << i))
                {
                    int afterShoot = cur - (1 << i);
                    int afterMove = 0;
                    for (int j = 0; j < n; j++) {
                        if (afterShoot & (1 << j)) {
                            afterMove |= nxt[j];
                        }
                    }
                    if (shotsNumber[afterMove] < 0)
                    {
                        shotsNumber[afterMove] = k + 1;
                        q.push(afterMove);
                        shotPos[afterMove] = i;
                        prev[afterMove] = cur;
                    }
                }
            }
        }

        if (shotsNumber[0] == -1)
        {
            cout << "Impossible\n";
        }
        else
        {
            cout << shotsNumber[0] << ":";
            vector<int> path;

            int cur = 0;
            while (cur != all)
            {
                path.push_back(shotPos[cur]);
                cur = prev[cur];
            }

            for (int i = shotsNumber[0]-1; i >= 0; --i) {
                cout << " " << path[i];
            }
            cout << endl;
        }
    }
}