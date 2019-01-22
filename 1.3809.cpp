#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn],n;
void build_sa(int sig)
{
	int *x=t,*y=t2;
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++) c[x[i]=s[i]]++;
	for(int i=1;i<sig;i++) c[i]+=c[i-1];
	for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
	for(int k=1;k<=n;k<<=1)
	{
		int p=0;
		for(int i=n-k;i<n;i++) y[p++]=i;
		for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;
		
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++) c[x[y[i]]]++;
		for(int i=1;i<sig;i++) c[i]+=c[i-1];
		for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
		
		swap(x,y);
		p=1; x[sa[0]]=0;
		for(int i=1;i<n;i++)
			x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++);
		if(p>=n) break;
		sig=p;
	}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%s",s); n=strlen(s);
	build_sa(128);
	for(int i=0;i<n;i++) printf("%d ",sa[i]+1);
	return 0;
}
