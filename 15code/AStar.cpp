#include "stdafx.h"
#include "AStar.h"
#include "algorithm"
#include "iostream"
using namespace  std;

AStar::AStar(int ss0[4][4])
{
	int G0[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
	memcpy(G,G0,sizeof(int)*4*4);

	s0.setS0(-1,0);
	s0.setS(ss0);
	s0.setH();
	open.push_back(s0);//1.初始状态放入OPEN表中
	s0.setState(1);//2.改变s0的初始状态，1为在OPEN表中
	step=-1;
}

void AStar::AA()
{
	step++;
	if(open.size()!=0)
	{
		BestS=open[0];
		BestS.show();
		closed.push_back(open[0]);//open表第一个状态放入closed表中
		open.erase(open.begin());//将open表中第一个状态删除

		if(BestS.compare(G)==1)
		{
			BestS.success(step);
		}else
		{
			genChild();
			AA();
		}
	}else
	{
		BestS.error();
	}
}

void AStar::genChild()
{
	U=BestS;
	D=BestS;
	L=BestS;
	R=BestS;
	if(L.Left()==1)
	{
		L.setState(1);
		if(ifInOpen(L)!=1&&ifInClosed(L)!=1)
		{
			open.push_back(L);
		}
	}
	if(U.Up()==1)
	{
		U.setState(1);
		if(ifInOpen(U)!=1&&ifInClosed(L)!=1)
		{
			open.push_back(U);
		}
	}
	if(R.Right()==1)
	{
		R.setState(1);
		if(ifInOpen(R)!=1&&ifInClosed(R)!=1)
		{
			open.push_back(R);
		}
	}
	if(D.Down()==1)
	{
		D.setState(1);
		if(ifInOpen(D)!=1&&ifInClosed(D)!=1)
		{
			open.push_back(D);
		}
	}
	reverse(open.begin(), open.end());
	sortOpen();
}

void AStar::sortOpen()
{
	sort(open.begin(), open.end(), compare);//降序排列
}


bool AStar::ifInOpen(S temp)
{
	if(!open.empty())
	{
		for(int i = 0; i!=open.size(); i++)
		{
			if(temp.compare(open[i].s))
			{
				if(temp.getF()<open[i].getF())
				{
					open.erase(open.begin()+i);
					open.push_back(temp);
					return 1;
				}
			}
		}
	}
	return 0;
}

bool AStar::ifInClosed(S temp)
{
	if(!closed.empty())
	{
		for(int i = 0; i!=closed.size(); i++)
		{
			if(temp.compare(closed[i].s))
			{
				if(temp.getF()<closed[i].getF())
				{
					closed.erase(closed.begin()+i);
					open.push_back(temp);
					return 1;
				}
			}
		}
	}
	return 0;
}
bool compare(S pfirst, S psecond)//如果该vector存入的是对象的话该函数参数须是
{								//降序排列使用
	return pfirst.getF() < psecond.getF();
}
