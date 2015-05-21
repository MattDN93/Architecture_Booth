#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class unsignedBinMult
{
public:
	unsignedBinMult();
	~unsignedBinMult();

	void toBinary(int,int);
	void sum();
	void rightShift();

	ifstream inValues;
	ofstream outValues;

	int carry;				//carry bit
	int count;				//count variable

	int input_M = 0;			//multiplicand in integer form
	string m_string;
	vector <int> bin_M;		//multiplicand in binary form

	int input_Q = 0;			//multiplier in integer form
	string q_string;
	vector <int> bin_Q;		//multiplier in binary form

	vector <int> acc;		//accumulator

};

unsignedBinMult::unsignedBinMult()
{
}

unsignedBinMult::~unsignedBinMult()
{
}

void main(int argc, char** argv)
{
	unsignedBinMult ubm;
	/*ubm.inValues.open("valuesToMult.txt");
	getline(ubm.inValues,ubm.m_string);
	getline(ubm.inValues, ubm.q_string);*/

	ubm.input_M = atoi(argv[1]);
	ubm.input_Q = atoi(argv[2]);

	ubm.outValues.open("valuesToDisplay.txt");
	//ubm.outValues << "Successfully read from C++ execution." << endl;
	ubm.outValues << ubm.input_M <<"\t"<< ubm.input_Q;

}

void unsignedBinMult::toBinary(int m_in, int q_in)
{
	int b = 8;
	while (m_in != 0)
	{
		bin_M[--b] = m_in % 2;
		outValues << "Binary Value Built:" << endl;
		
		m_in /= 2;
	}


}
