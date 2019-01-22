#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e6+7;
struct TwoSAT
{
	int n;
	vector<int> G[maxn*2];
	bool mark[maxn*2];
	int S[maxn*2],c;
	bool dfs(int x)
	{
		if(mark[x^1]) return false;
		if(mark[x]) return true;
		mark[x]=true;
		S[c++]=x;
		for(int i=0;i<G[x].size();i++)
			if(!dfs(G[x][i])) return false;
		return true;
	}
	//x = xval or y = yval
	void add_clause(int x,int xval,int y,int yval)
	{
		x=x*2+xval;
		y=y*2+yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	bool solve()
	{
		for(int i=0;i<n*2;i+=2)
			if(!mark[i]&&!mark[i+1])
			{
				c=0;
				if(!dfs(i))
				{
					while(c>0) mark[S[--c]]=false;
					if(!dfs(i+1)) return false;
				}
			}
		return true;
	}
}Ago;
int m,x,xval,y,yval;
int main()
{
#ifdef local
	freopen("pro.in","r",stdin);
#endif
	scanf("%d%d",&Ago.n,&m);
	while(m-->0)
	{
		scanf("%d%d%d%d",&x,&xval,&y,&yval);
		Ago.add_clause(x,xval,y,yval);
	}
	if(!Ago.solve()) printf("IMPOSSIBLE\n");
	else
	{
		for(int i=1;i<=Ago.n;i++)
			if(Ago.mark[i<<1]) printf("0 ");
			else printf("1 ");
		printf("\n");
	}
	return 0;
}
