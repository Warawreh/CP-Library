#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int N = 1e6+10;
const int mod = 1e9+7;
#define all(x) (x).begin(), (x).end()

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
vector<vector<string>> shape;
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

//Functions:-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
void print_shape( int i ){
	for( auto i : shape[i] )
		cout << i << '\n';
}
void hand_pose_1( int i , int j ){
	if( j == 0 ){
		shape[0][1][2] = ' ';
		shape[0][0][2] = ')';
		shape[1][1][0] = ' ';
		shape[1][0][0] = '(';
	}else{
		shape[0][1][0] = ' ';
		shape[0][0][0] = '(';
		shape[1][1][2] = ' ';
		shape[1][0][2] = ')';
	}
	print_shape( i );
}
void hand_pose_2( int i , int j ){
	if( j == 0 ){
		shape[0][1][2] = '>';
		shape[0][0][2] = ' ';
		shape[1][1][0] = '<';
		shape[1][0][0] = ' ';
	}else{
		shape[0][1][0] = '<';
		shape[0][0][0] = ' ';
		shape[1][1][2] = '>';
		shape[1][0][2] = ' ';
	}
	print_shape( i );
}
void hand_pose_3( int i , int j ){
	if( j == 0 ){
		shape[0][1][2] = '\\';
		shape[0][0][2] = ' ';
		shape[1][1][0] = '/';
		shape[1][0][0] = ' ';
	}else{
		shape[0][1][0] = '/';
		shape[0][0][0] = ' ';
		shape[1][1][2] = '\\';
		shape[1][0][2] = ' ';
	}
	print_shape( i );
}
void leg_pose_1( int i , int j ){
	if( j == 0 ){
		shape[0][2][2] = '>';
		shape[1][2][0] = '<';
	}else{
		shape[0][2][0] = '<';
		shape[1][2][2] = '>';
	}
	print_shape( i );
}
void leg_pose_2( int i , int j ){
	if( j == 0 ){
		shape[0][2][2] = '\\';
		shape[1][2][0] = '/';
	}else{
		shape[0][2][0] = '/';
		shape[1][2][2] = '\\';
	}
	print_shape( i );
}
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
cout.precision(10);
cout << fixed;

// #ifndef ONLINE_JUDGE
// freopen("input.txt" , "r" , stdin );
// #endif
	int t ; cin >> t ;
	vector<string> start;
	start.push_back(" o " );
	start.push_back("/|\\");
	start.push_back("/ \\");
	while( t-- ){
		int n ; cin >> n ;
		shape.clear();
		shape.resize(2);
		shape[0] = start;
		shape[1] = start;
		int dis = 0 ;
		for( int i = 0 ; i < n ; i++ ){
			string x ; cin >> x ;
			if( x == "say" ){
				string y ; getline( cin , y ) ;
				y = y.substr( 1 , y.size()-2 );
				cout << y << '\n';
			}else if( x == "turn" ){
				dis = 1 - dis ;
				print_shape( dis );
			}else{
				int j = 0 ;
				if( x != "left" ) j = 1 ;
				string y ; getline( cin , y ) ;
				y = y.substr( 1 , y.size()-2 );
				if( y == "hand to head" ) hand_pose_1( dis , j );
				else if( y == "hand to hip" ) hand_pose_2( dis , j );
				else if( y == "hand to start" ) hand_pose_3( dis , j );
				else if( y == "leg in" ) leg_pose_1( dis , j );
				else if( y == "leg out" ) leg_pose_2( dis , j );
				
			 //   cout << j << "-" << y.size() << endl;
			 //   exit(0);
			}
		}
	}
}