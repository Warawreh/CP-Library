/*
Name: Matrix Fast Power
Description: find M^p where x is a matrix in logarthmic time
Time: O(|M|^3 LogP) where |M| is the size of matrix |M| and P is the power
Space: O(|M|^2) 
*/

struct Matrix{
	vector<vector<ll>> mat;
 
	void init(int n,ll val){
		mat = vector<vector<ll>> (n,vector<ll> (n,val));
	}
	
	Matrix operator* (const Matrix &rhs){
		Matrix res;
		res.init(n,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					res.mat[i][k] = (res.mat[i][k] + (mat[i][j] * rhs.mat[j][k])%mod)%mod;
				}
			}
		}

		return res;
	}
};
 
Matrix mat,idn;

Matrix calc(Matrix a,ll b){
	if(!b)return idn;
	Matrix res = calc(a,b/2);
	res = res * res;
	if(b%2){
		res = res * a;
	}
	return res;
}

