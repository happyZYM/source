#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	int g;
	while(true)
	{
		cin>>g;
		if(!(g>30))
		{
			if(g<=10) cout<<"��Ҫ "<<0.8*g<<"Ԫ"<<endl;
			if(g>10&&g<=20) cout<<"��Ҫ "<<0.75*g<<"Ԫ"<<endl;
			if(g>20&&g<=30) cout<<"��Ҫ "<<0.7*g<<"Ԫ"<<endl;
		}
		else cout<<"�޷��ʼģ�"<<endl;
	}
}
