void MaxDist(vector<pair<int, int> >& A, int N)
{
    // Variables to track running extrema
    int minsum, maxsum, mindiff, maxdiff;
 
    minsum = maxsum = A[0].first + A[0].second;
    mindiff = maxdiff = A[0].first - A[0].second;
    for (int i = 1; i < N; i++) {
        int sum = A[i].first + A[i].second;
        int diff = A[i].first - A[i].second;
        if (sum < minsum)
            minsum = sum;
        else if (sum > maxsum)
            maxsum = sum;
        if (diff < mindiff)
            mindiff = diff;
        else if (diff > maxdiff)
            maxdiff = diff;
    }
 
    int maximum = max(maxsum - minsum, maxdiff - mindiff);
 
    cout << maximum << endl;
}