#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class unsignedBinMult
{
public:
	unsignedBinMult();
	~unsignedBinMult();

	void toBinary();
	void sum();
	void rightShift();

	ifstream inValues;
	ofstream outValues;

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

void main()
{
	unsignedBinMult ubm;
	ubm.inValues.open("valuesToMult.txt");
	ubm.inValues >> ubm.input_M >> ubm.input_Q;

	ubm.outValues.open("valuesToDisplay.txt");
	ubm.outValues << "Successfully read from C++ execution." << endl;
	ubm.outValues << ubm.input_M << ubm.input_Q;

}
