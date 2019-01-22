#include<cstdio>
#include<cstdlib>
const int maxn=100005;
const int oo=1e9+7;
struct Node
{
	int v,r,size,cnt;
	Node *ch[2];
	inline void maintain() { size=ch[0]->size+ch[1]->size+cnt; }
};
Node *null=new Node(),mem[maxn],*mcnt=mem,*root;
inline void Rotate(Node* &o,int d)
{
	Node *p=o->ch[d^1]; o->ch[d^1]=p->ch[d]; p->ch[d]=o;
	o->maintain(); p->maintain(); o=p;
}
inline void Insert(Node* &o,int v)
{
	if(o==null) { mcnt->v=v; mcnt->cnt=mcnt->size=1; mcnt->ch[0]=mcnt->ch[1]=null; mcnt->r=rand(); o=mcnt++; }
	else
	{
		if(o->v==v) { o->cnt++; o->size++; return; }
		int d=v>o->v;
		Insert(o->ch[d],v); o->maintain();
		if(o->ch[d]->r > o->r) Rotate(o,d^1);
	}
}
void Remove(Node* &o,int v)
{
	if(o==null) return;
	if(o->v==v)
	{
		if(o->cnt>1) { o->cnt--; o->size--; return; }
		if(o->ch[0]==null&&o->ch[1]==null) o=null;
		else
		{
			if(o->ch[1]==null||o->ch[0]->r>o->ch[1]->r) Rotate(o,1),Remove(o->ch[1],v);
			else Rotate(o,0),Remove(o->ch[0],v);
			o->maintain(); 
		}
		return;
	}
	Remove(o->ch[v>o->v],v); o->maintain();
}
int Rank(Node* &o,int v)
{
	if(o==null) return 0;
	if(o->v==v) return o->ch[0]->size+1;
	if(v<o->v) return Rank(o->ch[0],v);
	if(v>o->v) return o->ch[0]->size+o->cnt+Rank(o->ch[1],v);
}
int Kth(Node* &o,int k)
{
	if(o->ch[0]->size>=k) return Kth(o->ch[0],k);
	if(o->ch[0]->size+o->cnt>=k) return o->v;
	return Kth(o->ch[1],k-o->ch[0]->size-o->cnt);
}
int Pre(Node* &root,int v)
{
	int res=-oo;
	Node* p=root;
	while(p!=null)
	{
		if(v==p->v)
		{
			if(p->ch[0]!=null)
			{
				p=p->ch[0];
				while(p->ch[1]!=null) p=p->ch[1];
				res=p->v;
			}
			break;
		}
		if(p->v<v&&p->v>res) res=p->v;
		p=p->ch[v>p->v];
	}
	return res;
}
int Next(Node* &root,int v)
{
	int res=oo;
	Node* p=root;
	while(p!=null)
	{
		if(v==p->v)
		{
			if(p->ch[1]!=null)
			{
				p=p->ch[1];
				while(p->ch[0]!=null) p=p->ch[0];
				res=p->v;
			}
			break;
		}
		if(p->v>v&&p->v<res) res=p->v;
		p=p->ch[v>p->v];
	}
	return res;
}
int main()
{
	null->ch[0]=null->ch[1]=null; null->size=null->cnt=0; root=null;
	int n,opt,x; scanf("%d",&n);
	Insert(root,-oo); Insert(root,oo);
	while(n-->0)
	{
		scanf("%d%d",&opt,&x);
		if(opt==1) Insert(root,x);
		else if(opt==2) Remove(root,x);
		else if(opt==3) printf("%d\n",Rank(root,x)-1);
		else if(opt==4) printf("%d\n",Kth(root,x+1));
		else if(opt==5) printf("%d\n",Pre(root,x));
		else if(opt==6) printf("%d\n",Next(root,x));
	}
	return 0;
}
