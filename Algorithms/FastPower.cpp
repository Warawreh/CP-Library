/*
Name: Fast Power
Description: Find a^b fast
Time: O(Logb)
*/

ll POW(ll a,ll b){
	if(!b)return 1;
	ll res = POW(a,b/2);
	res = (res * res)%mod;
	if(b % 2)res = (res * a)%mod;
	return res;
}