struct line
{
	long long m,b;
	mutable function<const line*()> succ;
 
	bool operator<(const line& rhs) const
	{
		if (rhs.b!=(1LL<<62))return (m<rhs.m);
		const line* s=succ();
		if (!s)return 0;
		return b-s->b<rhs.m*(s->m-m);
	}
};
 
struct hull:public multiset<line>
{
	bool bad(iterator y)
	{
		auto z=next(y);
		if (y==begin())
		{
			if (z==end())return 0;
			return (y->m==z->m && y->b<=z->b);
		}
		auto x=prev(y);
		if (z==end())return (y->m==x->m && y->b<=x->b);
		return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
	}
	void add(long long m,long long b)
	{
		auto it=insert({m,b});
		if (bad(it))
		{
			erase(it);
			return;
		}
		it->succ=[=]{return (next(it)==end()? 0:&*next(it));};
		while (next(it)!=end() && bad(next(it)))erase(next(it));
		while (it!=begin() && bad(prev(it)))erase(prev(it));
	}
	long long eval(long long x)
	{
		line l=*lower_bound((line){x,(1LL<<62)});
		return x*l.m+l.b;
	}
};
