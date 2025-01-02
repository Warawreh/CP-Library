#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

struct library{
	int id, N,T, M;
	// N : Books in lib
	// T : Check for lib
	// M : Scane every day
	vector<int>books;
	void read(){
		cin>>N>>T>>M;
		for(int i=0; i<N; i++){
			int a;
			cin>>a;
			books.push_back(a);
		}
	} 
};

struct  input{
	int B, L, D;

	vector<int>scores;
	vector<library>libraries;
	void read(){
		cin>>B>>L>>D;
		for(int i=0; i<B; i++){
			int a;
			cin>>a;
			scores.push_back(a);
		}
		libraries.resize(L);
		for(int i=0; i<L; i++){
			libraries[i].read();
			libraries[i].id = i;
		}
	}	
};

int getscore(input in , vector<library> out){
	int a[100001],currday=0,maxday=0,score=0;
	for(int i = 0 ; i < 100001 ; i += 1){
		a[i] = 0;
	}
	for(library i : out){
		currday += in.libraries[i.id].T;
		maxday = max(maxday,currday + ((i.N+in.libraries[i.id].M-1)/in.libraries[i.id].M)*in.libraries[i.id].M);
		for(int j : i.books){
			if(a[in.libraries[i.id].books[j]] == 0){
				a[in.libraries[i.id].books[j]] = 1;
				score += in.scores[in.libraries[i.id].books[j]];
			}
		}
	}
	//cout << maxday << endl;
	if(maxday > in.D){
		cout << "problem in output format";
		return 0;
	}
	return score;
}

bool cmp(library a,library b){
	return a.T < b.T;
}

input A;
vector<library> ans;
ll score = 0;

void print_answer(vector<library> ans){
	cout << ans.size() << '\n';
	cerr << score << '\n';
	for(library x : ans){
		cout << x.id << ' ' << x.N << '\n';
		for(int i=0;i<x.N;i++)
			cout << x.books[i] << ' ';
		cout << '\n';
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
		freopen("f_libraries_of_the_world.txt","r",stdin);
		freopen("f_libraries_of_the_world.out","w",stdout);
	#endif
	A.read();	
	// sort(A.libraries.begin(),A.libraries.begin(),cmp);
	int cur_day = 0;
	for(int i=0;i<A.libraries.size();i++){
		cur_day += A.libraries[i].T;
		if(cur_day >= A.D)break;
		library tmp;
		tmp.id = A.libraries[i].id;
		int cnt = 0;
		for(int j=0;j<A.libraries[i].books.size() && cnt < A.D - cur_day;j++){
			if(A.scores[A.libraries[i].books[j]] == 0){
				continue;
			}
			cnt++;
			tmp.books.push_back(A.libraries[i].books[j]);
			score += A.scores[A.libraries[i].books[j]];
			A.scores[A.libraries[i].books[j]] = 0;
		}
		tmp.N = cnt;
		ans.push_back(tmp);
	}
	// cerr << score << ' ' << getscore(A,ans) << '\n';
	// assert(score == getscore(A,ans));
	print_answer(ans);
}
