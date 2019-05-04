#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const int mod=9901;
LL A,B,res=1;
vector<pair<LL,LL> > p;
inline LL ksm(LL a,LL b)
{
	LL res=1;
	a%=mod;
	for(;b;b>>=1,a=a*a%mod) b&1?res=res*a%mod:0;
	return res;
}
LL sum(LL p,LL c)
{
	if(!p) return 0;
	if(!c) return 1;
	if(c&1) return (1+ksm(p,(c+1)/2))*sum(p,c/2)%mod;
	else return ((1+ksm(p,c/2))*sum(p,c/2-1)+ksm(p,c))%mod;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%lld%lld",&A,&B);
	for(int i=2;i*i<=A;i++) if(A%i==0)
	{
		int cnt=0;
		while(A%i==0) A/=i,cnt++;
		p.push_back(make_pair(i,cnt));
	}
	if(A!=1) p.push_back(make_pair(A,1));
	for(int i=0;i<p.size();i++) res=res*sum(p[i].first,p[i].second*B)%mod;
	printf("%lld\n",res);
	return 0;
}
