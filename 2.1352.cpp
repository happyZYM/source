int dice24[24][6]={
{2,1,5,0,4,3},
{2,0,1,4,5,3},
{2,4,0,5,1,3},
{2,5,4,1,0,3},
{4,2,5,0,3,1},
{5,2,1,4,3,0},
{1,2,0,5,3,4},
{0,2,4,1,3,5},
{0,1,2,3,4,5},
{4,0,2,3,5,1},
{5,4,2,3,1,0},
{1,5,2,3,0,4},
{5,1,3,2,4,0},
{1,0,3,2,5,4},
{0,4,3,2,1,5},
{4,5,3,2,0,1},
{1,3,5,0,2,4},
{0,3,1,4,2,5},
{4,3,0,5,2,1},
{5,3,4,1,2,0},
{3,4,5,0,1,2},
{3,5,1,4,0,2},
{3,1,0,5,4,2},
{3,0,4,1,5,2}
};
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=4;
int n,dice[maxn][6],res;
vector<string> names;
int ID(char* name)
{
	string s(name);
	int n=names.size();
	for(int i=0;i<n;i++)
		if(names[i]==s) return i;
	names.push_back(s);
	return n;
}
int r[maxn],color[maxn][6];
void check()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<6;j++) color[i][dice24[r[i]][j]]=dice[i][j];
	int tot=0;
	for(int j=0;j<6;j++)
	{
		int cnt[maxn*6];
		memset(cnt,0,sizeof(cnt));
		int maxface=0;
		for(int i=0;i<n;i++)
			maxface=max(maxface,++cnt[color[i][j]]);
		tot+=n-maxface;
	}
	res=min(res,tot);
}
void dfs(int d)
{
	if(d==n) check();
	else
		for(int i=0;i<24;i++)
		{
			r[d]=i;
			dfs(d+1);
		}
}
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	while(scanf("%d",&n)==1&&n)
	{
		names.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<6;j++)
			{
				char name[30];
				scanf("%s",name);
				dice[i][j]=ID(name);
			}
		res=n*6;
		r[0]=0;
		dfs(1);
		printf("%d\n",res);
	}
	return 0;
}
