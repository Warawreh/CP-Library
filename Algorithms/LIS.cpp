/*
Name: Longest increasing/non-decreasing subsequance
Description: find the length (and values) in the longest increasing/non-decreasing subsequance
Time: O(NLogN)
Space: O(N)
*/
{
    vector<int> a = {1 , 3 , 3 , -100 , 4,-99,-98,-97};
    int n = a.size();
    multiset < int > s;
    multiset < int > :: iterator it;

    for(int i=0;i<n;i++){
        s.insert(a[i]);

        {//Non-Decresing allow duplicates
            it = s.upper_bound(a[i]);
        }

        {//Increasing no duplicates
            it = s.lower_bound(a[i]);   
            it++;
        }

        if(it != s.end())
            s.erase(it);

    }

    cout << s.size() << endl;
}