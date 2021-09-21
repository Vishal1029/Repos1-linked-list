#include<iostream>
using namespace std;
int main()
{
	int n=5;
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==3)
			cout<<i+j;
			else if( i==j )
			cout<<i+j;
			else if((i+j)==(n+1))
			cout<<i+j;
			else if(j==(n/2)+1)
			cout<<i+j;
			else
			cout<<" ";
		}
		cout<<"\n";
	}
return 0;
}

