#include <iostream>
#define N 10
#define M 8

using namespace std;

int main()
{
	int A[N][M];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			A[i][j]=rand()%10;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	int t;
	for(int k=0;k<M;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<M-k-1;j++)
				if(A[i][j]<A[i][j+1])
				{
					t=A[i][j+1];
					A[i][j+1]=A[i][j];
					A[i][j]=t;
				}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	int n=0;
	cout<<"\nEnter number: ";
	cin>>n;
	cout<<endl;
	for(int i=0;i<N;i++)
	{
		int l=0,p=M,s;
		while(l<p)
		{
			s=l+(p-l)/2;
			if(n>=A[i][s])
				p=s;
			else
				l=s+1;
		}
		if (A[i][p] == n)
			cout<<(i+1)<<" row: element in "<<(p+1)<<" col"<<endl;
		else
			cout<<(i+1)<<" row: not found"<<endl;
	}
	return 0;
}
