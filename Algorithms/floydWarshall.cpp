/*
Name: Floyd-Warshall
Description: Find all pairs shortest path 
Time: O(n^3)
Space: O(N^2) 
*/

for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}

if (d[i][k] + d[k][j] < d[i][j] - EPS)//For real weights
    d[i][j] = d[i][k] + d[k][j]; 
