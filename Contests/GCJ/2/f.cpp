#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define fast ios::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int order(vector<int> arr, int last){
	int count =0;
	for (int i = 0; i < last; i++)
		if (arr[i] > arr[i+1]){
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			count++;
		}
	if (last == 1)
		return count;
	else return (count + order(arr,last-1)); 
}

int main (){
	vector<int> a = {92,913,12,51,32,1,32,1412,13,12 };
	int Z= order(a,a.size() - 1);
	cout << Z << '\n';
	return 0;
}

