#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double Pi=acos(-1.0);
const int maxn=10005;
int n,f;
double A[maxn];
bool ok(double area)
{
	int sum=0;
	for(int i=0;i<n;i++) sum+=floor(A[i]/area);
	return sum>=f+1;
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d%d",&n,&f);
		double maxa=-1;
		for(int i=0;i<n;i++)
		{
			int r;
			scanf("%d",&r);
			A[i]=Pi*r*r;
			maxa=max(maxa,A[i]);
		}
		double L=0,R=maxa;
		while(R-L>1e-5)
		{
			double M=(L+R)/2;
			if(ok(M)) L=M;
			else R=M;
		}
		printf("%.5lf\n",L);
	}
	return 0;
}
