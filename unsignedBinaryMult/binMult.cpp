#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#define DEBUG 0
#define BITSIZE 16

class unsignedBinMult
{
public:
	unsignedBinMult();
	~unsignedBinMult();

	void toBinary(int,int);
	void sum();
	void rightShift();
	void doMult();				//perform the multiplication
	void outIntArr(vector <int>);		//displays integer content to user
	void dispLines(string,int);

	ifstream inValues;
	ofstream outValues;

	int carry;				//carry bit
	int count;				//count variable

	int input_M = 0;			//multiplicand in integer form
	string m_string="";		//stored string rep of binary value
	vector <int> bin_M;		//multiplicand in binary form

	int input_Q = 0;			//multiplier in integer form
	string q_string="";		//stored string rep of binary value
	vector <int> bin_Q;		//multiplier in binary form

	vector <int> acc;		//accumulator
	string acc_string = "";

	string adding = "C,A <- A + M";
	string r_shifting = "RightShift";

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
		ubm.input_M = 22;
		ubm.input_Q = 2;
	}
	if (!DEBUG)
	{
		ubm.input_M = atoi(argv[1]);				//receive args
		ubm.input_Q = atoi(argv[2]);				//receive args from VB
	}


	ubm.outValues.open("valuesToDisplay.txt");
	//ubm.outValues << "Successfully read from C++ execution." << endl;
	ubm.outValues << "\nValues Entered:" << endl;
	ubm.outValues << ubm.input_M <<"\t"<< ubm.input_Q;	//read from VB process

	ubm.toBinary(ubm.input_M, ubm.input_Q);			//convert M and Q to binary
	ubm.doMult();									// do the multiplication

	ubm.outValues << "\n--------------------------" << endl;
	ubm.outValues << "\nResult: "; ubm.outIntArr(ubm.acc); ubm.outValues << " "; ubm.outIntArr(ubm.bin_Q);
	ubm.outValues << "\n--------------------------" << endl;
	ubm.outValues.close();							//close the file


}

void unsignedBinMult::outIntArr(vector <int> arr)
{
	for (int i = 0; i < BITSIZE; i++)
	{
		outValues << arr[i];
	}
}

void unsignedBinMult::toBinary(int m_in, int q_in)
{
	bin_M.resize(BITSIZE);
	bin_Q.resize(BITSIZE);
	m_string.resize(BITSIZE);
	q_string.resize(BITSIZE);

	int b = BITSIZE;

	outValues << "\nBinary Value Built:" << endl;
	outValues << "\nMultiplicand(M):";
	outValues << "\n--------------------------" << endl;

	while (m_in != 0)
	{
		bin_M[--b] = m_in % 2;
		//outValues << bin_M[b];
		m_in /= 2;
	}

	for (int i = 0; i < BITSIZE; i++)
	{
		outValues << bin_M[i];			//write to file
	}

	outValues << "\n\nMultiplier (Q):" << endl;
	outValues << "--------------------------" << endl;

	b = BITSIZE;							//reset the value of the counter 

	while (q_in != 0)
	{
		bin_Q[--b] = q_in % 2;
		//outValues << bin_Q[b];
		q_in /= 2;
	}

	for (int i = 0; i < BITSIZE; i++)
	{
		outValues << bin_Q[i];
	}
	outValues << "\n\nMultiplier Q0: " << bin_Q[0]<< endl;


	if (DEBUG){
		system("pause");
	}


}

void unsignedBinMult::doMult()
{
	acc.resize(BITSIZE);
	count = BITSIZE;
	int upcount = 0;

	outValues << "\n\n-----------------------" << endl;
	outValues << "\nStep\tProcess\t\t\t Multiplicand (M) \t Accumulator (A) \t Multiplier(Q) \tCount(n)" << endl;
	outValues << "\n" << upcount << "\t\tInit\t\t"; outIntArr(bin_M); outValues << "\t"; outIntArr(acc); outValues << "\t"; outIntArr(bin_Q); outValues << "\t" << count << endl;
	
	
	while (count > 0){
		upcount++;
		if (bin_Q[BITSIZE-1] == 1)
		{
			sum();
			dispLines(adding,upcount);
		}
		rightShift();
		count = count - 1;
		dispLines(r_shifting,upcount);
	} /*while (count > 0);*/
	
}

void unsignedBinMult::dispLines(string process, int upcount)
{
	outValues << "\n" << upcount << "\t\t"<< process <<"\t\t\t"; outIntArr(bin_M); outValues << "\t"; outIntArr(acc); outValues << "\t"; outIntArr(bin_Q); outValues << "\t" << count << endl;
}

void unsignedBinMult::sum()
{
	
		carry = 0;
		for (int i = 0; i < BITSIZE; i++)				//for the length of the data
		{
			acc[i] = acc[i] + bin_M[i] + carry;				//perform addition A <- A + M
			if (acc[i] > 1)
			{
				acc[i] = acc[i] % 2;					//deal with a carry
				carry = 1;
			}
			else
				carry = 0;
		}

}

void unsignedBinMult::rightShift()
{
	int temp = 0;

	temp = acc[BITSIZE-1];
	// = qr[0];
	cout << "\t\tashr\t\t";
	for (int i = BITSIZE - 1; i > 0 ; i--)
	{
		acc[i] = acc[i - 1];
		bin_Q[i] = bin_Q[i - 1];
	}
	bin_Q[0] = temp;

}