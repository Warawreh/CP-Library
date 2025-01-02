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

	vector<int>scores,tmp;
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
			sort(libraries[i].books.begin(),libraries[i].books.end(),[&] (int a,int b){
				return scores[a] > scores[b];
			});
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
			if(a[j] == 0){
				a[j] = 1;
				score += in.scores[j];
			}
		}
	}
	//cout << maxday << endl;
	if(maxday > in.D){
		cerr << "problem in output format" << endl;
		return 0;
	}
	cerr << "ok" << endl;
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

int myrandom (int i) { return rand()%i;}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	#ifndef ONLINE_JUDGE
		freopen("f_libraries_of_the_world.txt","r",stdin);
		freopen("f_libraries_of_the_world.out","w",stdout);
	#endif
	srand(time(0));

	A.read();
	A.tmp = A.scores;
	
	for(int it=0;it<100000;it++){
		int cur_score = 0;
		random_shuffle(A.libraries.begin(),A.libraries.begin(), myrandom);
		int cur_day = 0;
		vector<library> qqq;
		A.scores = A.tmp;
		for(int i=0;i<A.libraries.size();i++){
			int g = rand()%2;
			if(g == 1)continue;
			cur_day += A.libraries[i].T;
			if(cur_day >= A.D)break;
			library tmp;
			tmp.id = A.libraries[i].id;
			int cnt = 0;
			for(int j=0;j<(int)A.libraries[i].books.size() && cnt < (A.D-cur_day) * A.libraries[i].M;j++){
				int cur_book = A.libraries[i].books[j];
				if(A.scores[cur_book] == 0)continue;
				cnt++;
				tmp.books.push_back(cur_book);
				cur_score += A.scores[cur_book];
				A.scores[cur_book] = 0;
			}
			tmp.N = tmp.books.size();
			qqq.push_back(tmp);
		}
		if(cur_score > score){
			score = cur_score;
			ans = qqq;
		}
	}
	// cerr << score << ' ' << getscore(A,ans) << '\n';
	// assert(score == getscore(A,ans));
	print_answer(ans);
}
