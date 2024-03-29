// 15code.cpp: 定义控制台应用程序的入口点。
//
/*Begin：
读入初始状态和目标状态，并计算初始状态评价函数值f；
初始化两个open表和closed表，将初始状态放入open表中
If（open表为空）
查找失败；
End if
else
①	在open表中找到评价值最小的节点，作为当前结点，并放入closed表中；
②	判断当前结点状态和目标状态是否一致，若一致，跳出循环；否则跳转到③；
③	对当前结点，分别按照上、下、左、右方向移动空格位置来扩展新的状态结点，并计算新扩展结点的评价值f并记录其父节点；
④	对于新扩展的状态结点，进行如下操作：
A．新节点既不在open表中，也不在closed表中，则ADD(mj, OPEN)；
B．新节点在open表中，则IF f(n - mk) < f(mk)
THEN f(mk) := f(n - mk)，
C．新节点在closed表中，则IF f(n - ml) < f(ml)
THEN f(ml) : = f(n - ml)，
⑤	把当前结点从open表中移除；
End if
End*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "AStar.h"
using namespace std;

int main()
{
	//啊啊啊啊啊
	/*int s0[]={5,1,2,4,9,6,3,8,13,15,10,11,14,0,7,12};
	int g[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
	vector<int> s(s0,s0+16);
	vector<int> G(g,g+16);*/
	/*cout << "please input the origin state" << endl;
	int s0[4][4] = { 0 };
	for (int i = 1; i <= 4; i++)
	{
	cout << "please inpu the " << i << "line(4 integers) " << endl;
	for (int j = 1; j <= 4; j++)
	{
	cin >> s0[i - 1][j-1];
	}

	}*/
	int s0[4][4] = { {1,2,3,4},{5,0,6,8 },{9,10,7,11},{13,14,15,12} };
	//int s0[4][4] = { { 5,1,2,4 },{ 9,6,3,8 },{ 13,15,10,11 },{ 14,0,7,12 } };
	AStar test(s0);
	test.Amain();
	system("pause");
	return 0;
}

