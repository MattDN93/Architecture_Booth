#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

class unsignedBinMult
{
public:
	unsignedBinMult();
	~unsignedBinMult();

	void toBinary();
	void sum();
	void rightShift();

	int carry;				//carry bit
	int count;				//count variable

	int input_M;			//multiplicand in integer form
	vector <int> bin_M;		//multiplicand in binary form

	int input_Q;			//multiplier in integer form
	vector <int> bin_Q;		//multiplier in binary form

	vector <int> acc;		//accumulator

};

unsignedBinMult::unsignedBinMult()
{
}

unsignedBinMult::~unsignedBinMult()
{
}