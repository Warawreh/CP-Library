/*
Name: Ordred Set
Description: it is a set/Multiset but with indexes
Time: O(LogN) per insert/query
Space: O(N)
Resources: codeforces.com/blog/entry/11080
*/

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef int T;
typedef tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

indexed_set s;
s.insert(x);//Add x to the set (duplicate is allowed)
s.order_of_key(x);//Get the position of the first number more than or equal to x
s.find_by_order(x);//Return a pointer to the x'th element (start from 0)
s.erase(x);//if x is a pointer remove if exisit
		   //if x is T then remove value T (this is janky  always remove with pointer)
note:
	less_equal<T>: allow duplicate (multiset)
	less<T>:  Remove duplicate (set)
	to use custom comparator use:
		auto cmp = [](int a, int b){return a > b;};
    	tree<T, null_type, decltype(cmp), rb_tree_tag, tree_order_statistics_node_update> s(cmp);