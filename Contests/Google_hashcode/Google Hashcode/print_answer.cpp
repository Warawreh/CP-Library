void print_answer(vector<library> ans){
	cout << ans.size() << '\n';
	for(library x : ans){
		cout << x.id << ' ' << x.N << '\n';
		for(int i=0;i<x.N;i++)
			cout << x.books[i] << ' ';
		cout << '\n';
	}
}