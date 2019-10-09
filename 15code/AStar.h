#pragma once
#include "S.h"
#include <vector>
using namespace std;
class AStar
{
private:
	int step;
	int G[4][4];
	S s0;
	S BestS;
	S U;
	S D;
	S L;
	S R;
	vector<S> open;
	vector<S> closed;
public:
	AStar(int s0[4][4]);
	void AA();
	void genChild();
	void sortOpen();
	bool ifInOpen(S temp);
	bool ifInClosed(S temp);
};

bool compare(S pfirst, S psecond);