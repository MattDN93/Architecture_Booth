#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#define DEBUG 0							//set this to enable debug features
#define BITSIZE 16						//bit-length of the values

class unsignedBinMult
{
public:
	unsignedBinMult();
	~unsignedBinMult();

	void toBinary(int,int);
	void sum();							//add 2 binary values 16-bit
	void rightShift();					//method for Logical Right Shift
	void doMult();						//perform the multiplication
	void outIntArr(vector <int>);		//displays integer content to user
	void dispLines(string,int);			//standard method to print iterations

	ifstream inValues;					//file objects for file I/O
	ofstream outValues;

	int carry;							//carry bit
	int count;							//count variable

	int input_M = 0;					//multiplicand in integer form
	string m_string="";					//stored string rep of binary value
	vector <int> bin_M;					//multiplicand in binary form

	int input_Q = 0;					//multiplier in integer form
	string q_string="";					//stored string rep of binary value
	vector <int> bin_Q;					//multiplier in binary form

	vector <int> acc;					//accumulator
	
	string adding = "C,A <- A + M";		//output strings
	string r_shifting = "RightShift";

};

unsignedBinMult::unsignedBinMult()
{
}

unsignedBinMult::~unsignedBinMult()
{
}

void main(int argc, char** argv)		//main receiving arguments (M and Q)
{
	unsignedBinMult ubm;				//instantiate object of class

	if (DEBUG)
	{
		//ubm.input_M = 22;
		//ubm.input_Q = 2;
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

void unsignedBinMult::outIntArr(vector <int> arr)	//output parameters
{
	for (int i = 0; i < BITSIZE; i++)
	{
		outValues << arr[i];
	}
}

void unsignedBinMult::toBinary(int m_in, int q_in)	//conversion decimal -> binary
{
	bin_M.resize(BITSIZE);
	bin_Q.resize(BITSIZE);
	m_string.resize(BITSIZE);
	q_string.resize(BITSIZE);

	int b = BITSIZE;

	outValues << "\nBinary Value Built:" << endl;
	outValues << "\nMultiplicand(M):";
	outValues << "\n--------------------------" << endl;

	while (m_in != 0)											//converts m to binary
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

	while (q_in != 0)						//converts Q to binary
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
		//system("pause");
	}


}

void unsignedBinMult::doMult()						//perform the unsigned binary multiplication
{
	acc.resize(BITSIZE);
	count = BITSIZE;
	int upcount = 0;

	outValues << "\n\n-----------------------" << endl;
	outValues << "\nStep\tProcess\t\t\t\t Multiplicand (M) \t\t\t Accumulator (A) \t\t\t Multiplier(Q) \t\t\tCount(n)" << endl;
	outValues << "\n" << upcount << "\t\tInit\t\t"; outIntArr(bin_M); outValues << "\t"; outIntArr(acc); outValues << "\t"; outIntArr(bin_Q); outValues << "\t" << count << endl;
	
	
	while (count > 0){											//while counts are still remaining
		upcount++;
		if (bin_Q[BITSIZE-1] == 1)								//start at LSB side of binary value
		{
			sum();												//if LSB = 1 do a addition
			dispLines(adding,upcount);
		}
		rightShift();											//..and either just right shift or RS and add
		count = count - 1;
		dispLines(r_shifting,upcount);
	} 
	
}

void unsignedBinMult::dispLines(string process, int upcount)
{
	outValues << "\n" << upcount << "\t\t" << process << "\t\t\t"; outIntArr(bin_M); outValues << "\t"; outIntArr(acc); outValues << "\t"; outIntArr(bin_Q); outValues << "\t" << count << "\n";
}

void unsignedBinMult::sum()										//addition process
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

void unsignedBinMult::rightShift()						//do the right shift
{
	int temp = 0;

	temp = acc[BITSIZE-1];								//ensure bits from ACC LSB go to Q MSB
	// = qr[0];
	cout << "\t\tashr\t\t";
	for (int i = BITSIZE - 1; i > 0 ; i--)
	{
		acc[i] = acc[i - 1];
		bin_Q[i] = bin_Q[i - 1];
	}
	bin_Q[0] = temp;

}