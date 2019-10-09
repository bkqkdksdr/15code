#include "stdafx.h"
#include "S.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
#include<cstring>
using namespace std;

S::S()
{
	int G0[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
	memcpy(G,G0,sizeof(int)*4*4);
	state=0;
	Direct=-1;
}

void S::setS0(int d0, int f0)
{
	d=d0;
	f=f0;
}

void S::setS(int s0[4][4])
{
	memcpy(s,s0,sizeof(int)*4*4);
}

void S::setState(int state0)
{
	state=state0;
}

void S::setH()
{
	h=0;
	int p=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int m=0;m<4;m++)
			{
				for(int k=0;k<4;k++)
				{
					if(s[i][j]==G[m][k]&&s[i][j]!=0)
					{
						p=abs(i-m)+abs(j-k);
					}
				}
			}
			h=h+p;
			p=0;
		}
	}
	setD();
}

int S::getH()
{
	return h;
}

void S::setD()
{
	d=d+1;
	setF();
}

int S::getD()
{
	return d;
}

void S::setF()
{
	f=getD()+getH();
}

int S::getF()
{
	return f;
}

bool S::compare(int temps[4][4])
{
	int temp[4][4];
	memcpy(temp,temps,sizeof(int)*4*4);
	int sum=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i][j]==temps[i][j])
			{
				sum=sum+1;
			}
		}
	}
	if(sum==16)
	{
		return 1;
	}else
	{
		return 0;
	}
}

void S::show()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0; j<4;j++)
		{
			if(j!=3)
			{
				if(s[i][j]<10)
				{
					cout<<s[i][j]<<"  ";
				}else
				{
					cout<<s[i][j]<<" ";
				}
			}else
			{
				cout<<s[i][j]<<endl;
			}
		}
	}
	cout<<"D is "<<d<<"  ";
	cout<<"H is "<<h<<"  ";
	cout<<"F is "<<f<<endl;
	if(Direct == -1) cout << "This is origin map";
	else if(Direct == 0) cout << "This is Up step";
	else if(Direct == 1) cout << "This is Down step";
	else if(Direct == 2) cout << "This is Left step";
	else if(Direct == 3) cout << "This is Right step";
	cout<<endl;
}

void S::error()
{
	cout<< endl<<"failed"<<endl;
}

void S::success(int i)
{
	cout<<endl<<"used "<<i<<" steps to find target"<<endl<<endl;
}

bool S::Up()
{
	int temp;
	Direct=0;//这步是向上移
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i][j]==0&&i-1>=0)
			{
					temp=s[i][j];
					s[i][j]=s[i-1][j];
					s[i-1][j]=temp;
					setH();
					return 1;
					break;
				}
			}
		}
	setH();
	return 0;
}

bool S::Down()
{
	int temp;
	Direct=1;//这步是向下移
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i][j]==0&&i+1<4)
			{
				temp=s[i][j];
				s[i][j]=s[i+1][j];
				s[i+1][j]=temp;
				setH();
				return 1;
				break;
			}
		}
	}
	setH();
	return 0;
}

bool S::  Left()
{
	int temp;
	Direct=2;//这步是向左移
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i][j]==0&&j-1>=0)
			{
				temp=s[i][j];
				s[i][j]=s[i][j-1];
				s[i][j-1]=temp;
				setH();
				return 1;
				break;
			}
		}
	}
	setH();
	return 0;
}

bool S::Right()
{
	int temp;
	Direct=3;//这步是向右移
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i][j]==0&&j+1<4)
			{
				temp=s[i][j];
				s[i][j]=s[i][j+1];
				s[i][j+1]=temp;
				setH();
				return 1;
				break;
			}
		}
	}
	setH();
	return 0;	
}