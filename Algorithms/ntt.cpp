const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

using cd = complex<double>;
const double PI = acos(-1);


void ntt(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = POW(n, mod - 2);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<ll> const& a, vector<ll> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    ntt(fa, true);

    return fa;
}

// Second implementation
const int mod=998244353, G=3;

ll POW(ll a,ll b){
    if(!b)return 1;
    ll res = POW(a,b/2);
    res = (res * res)%mod;
    if(b % 2)res = (res * a)%mod;
    return res;
}

unsigned int br(unsigned int a, int l) {
    a=((a&0x55555555U)<<1)|((a&0xAAAAAAAAU)>>1);
    a=((a&0x33333333U)<<2)|((a&0xCCCCCCCCU)>>2);
    a=((a&0x0F0F0F0FU)<<4)|((a&0xF0F0F0F0U)>>4);
    a=((a&0x00FF00FFU)<<8)|((a&0xFF00FF00U)>>8);
    a=((a&0x0000FFFFU)<<16)|((a&0xFFFF0000U)>>16);
    return a>>(32-l);
}


void ntt(vector<ll> &a, vector<ll> &b, bool iv) {
    int n=a.size(), lg=__lg(n);
    for(int i=0; i<n; ++i)
        b[br(i, lg)]=a[i];
    for(int st=1, id=1; 2*st<=n; st*=2, ++id) {
        ll wn=POW(G, iv?(mod-1-(mod-1>>id)):(mod-1>>id)), wi=1;
        for(int i=0; i<st; ++i, wi=wi*wn%mod) {
            for(int j=i; j<n; j+=2*st) {
                ll u=b[j], v=wi*b[j+st]%mod;
                b[j]=u+v;
                if(b[j]>=mod)b[j]-=mod;
                b[j+st]=u-v;
                if(b[j+st]<0)b[j+st]+=mod;
            }
        }
    }
    if(iv) {
        ll in=POW(n, mod-2);
        for(int i=0; i<n; ++i)
            b[i]=b[i]*in%mod;
    }
}
 
vector<int> multiply(vector<ll> const& a, vector<ll> const& b){
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    ntt(fa, fb, 0);
    for(int i=0; i<1<<20; ++i)
        b[i]=POW(b[i], n/2);
    ntt(fb, fa, 1);

    return fa;
}