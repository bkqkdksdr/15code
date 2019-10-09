#pragma once
class S{
public:
	int d;
	int f;
	int h;
	int state;
	int Direct;
	int G[4][4];
	int s[4][4];
public:
	S();
	void setS0(int d0, int f0);
	void setS(int s0[4][4]);
	void setState(int state0);
	void setH();
	int getH();
	void setD();
	int getD();
	void setF();
	int getF();
	bool compare(int temps[4][4]);
	void show();
	void error();
	void success(int i);
	bool Up();
	bool Down();
	bool Left();
	bool Right();
};