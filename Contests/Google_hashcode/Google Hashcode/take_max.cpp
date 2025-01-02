#include <bits/stdc++.h>

using namespace std;

#define debug(x) '[' << #x << " is: " << x << "] "
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

map<int,vector<int>> at;

struct library{
	int id, N,T, M;
	// N : Books in lib
	// T : Check for lib
	// M : Scane every day
	vector<int>books;
	int sum = 0,have = 0;
	void read(){
		cin>>N>>T>>M;
		have = N;
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
			for(int j : libraries[i].books){
				at[j].push_back(i);
				libraries[i].sum += scores[j];
			}
			libraries[i].id = i;
			sort(libraries[i].books.begin(),libraries[i].books.end(),[&](int a,int b){
				return scores[a] > scores[b];
			});
		}
		library tmp;
		libraries.push_back(tmp);
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
	int cnt = A.L;
	vector<int> order;
	for(int i=0;i<=A.L;i++)order.push_back(i);
	int cur_day=0;
	while(cnt--){
		sort(order.begin(),order.end(),[&] (int a,int b){
			bool res = (A.libraries[a].sum * A.libraries[b].T * (A.libraries[a].M+100) * A.libraries[b].have  >
			 A.libraries[b].sum * A.libraries[a].T * (A.libraries[b].M+100) * A.libraries[a].have);
			return res;
		});
		cur_day += A.libraries[order[0]].T;
		if(cur_day >= A.D || A.libraries[order[0]].sum == 0 || order[0] == A.L){
			cur_day -= A.libraries[order[0]].T;
			order[0] = A.L;
			continue;
		}
		// cerr << order[0] << ' ' << A.libraries[order[0]].books.size() << '\n';
		library tmp;
		tmp.id = A.libraries[order[0]].id;
		int cnt = 0;
		for(int j=0;j<(int)A.libraries[order[0]].books.size() && cnt < (A.D-cur_day) * A.libraries[order[0]].M;j++){
			int cur_book = A.libraries[order[0]].books[j];
			if(A.scores[cur_book] == 0)continue;
			cnt++;
			tmp.books.push_back(cur_book);
			// cerr << cur_book << ' ' << A.scores[cur_book] << '\n';
			score += A.scores[cur_book];
			for(int in : at[cur_book]){
				A.libraries[in].sum -= A.scores[cur_book];
				A.libraries[in].have--;
			}
			A.scores[cur_book] = 0;
		}
		order[0] = A.L;
		tmp.N = tmp.books.size();
		if(tmp.N == 0)continue;
		ans.push_back(tmp);
	}
	print_answer(ans);
}
