#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn=100005;
int n,m; LL a[maxn],s[maxn],c[2][maxn];
inline LL ask(int id,int x)
{
	LL res=0;
	for(;x;x-=(x&-x)) res+=c[id][x];
	return res;
}
inline void add(int id,int x,int y)
{
	for(;x<=n;x+=(x&-x)) c[id][x]+=y;
}
inline LL query(int x) { return s[x]+(x+1)*ask(0,x)-ask(1,x); }
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	while(m-->0)
	{
		char op; int l,r,d; scanf("%s%d%d",&op,&l,&r);
		if(op=='C')
		{
			scanf("%d",&d);
			add(0,l,d);
			add(0,r+1,-d);
			add(1,l,l*d);
			add(1,r+1,-(r+1)*d);
		}
		else printf("%lld\n",query(r)-query(l-1));
	}
	return 0;
}
