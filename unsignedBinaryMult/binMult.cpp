#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#define DEBUG 1

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

	if (DEBUG)
	{
		ubm.input_M = 12/*atoi(argv[1])*/;
		ubm.input_Q = 13/*atoi(argv[2])*/;
	}
	if (!DEBUG)
	{
		ubm.input_M = atoi(argv[1]);
		ubm.input_Q = atoi(argv[2]);
	}


	ubm.outValues.open("valuesToDisplay.txt");
	//ubm.outValues << "Successfully read from C++ execution." << endl;
	ubm.outValues << "\nValues Entered:" << endl;
	ubm.outValues << ubm.input_M <<"\t"<< ubm.input_Q;

	ubm.toBinary(ubm.input_M, ubm.input_Q);			//convert M and Q to binary



}

void unsignedBinMult::toBinary(int m_in, int q_in)
{
	bin_M.resize(8);
	bin_Q.resize(8);
	int b = 8;

	outValues << "\nBinary Value Built:" << endl;
	outValues << "\nMultiplicand(M):";
	outValues << "\n--------------------------" << endl;

	while (m_in != 0)
	{
		bin_M[--b] = m_in % 2;
		//outValues << bin_M[b];
		m_in /= 2;
	}

	for (int i = 0; i < 8; i++)
	{
		outValues << bin_M[i];
	}

	outValues << "\n\nMultiplier (Q):" << endl;
	outValues << "--------------------------" << endl;

	b = 8;							//reset the value of the counter 

	while (q_in != 0)
	{
		bin_Q[--b] = q_in % 2;
		//outValues << bin_Q[b];
		q_in /= 2;
	}

	for (int i = 0; i < 8; i++)
	{
		outValues << bin_Q[i];
	}
	outValues << "\n\nMultiplier Q0: " << bin_Q[0]<< endl;


	if (DEBUG){
		system("pause");
	}


}
