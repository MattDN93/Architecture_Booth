#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class Radix2Booth
{
public:
	Radix2Booth();
	~Radix2Booth();

	ifstream inValues;
	ofstream outValues;

	int input_M;			//multiplicand in integer form
	string m_string;
	vector <int> bin_M;		//multiplicand in binary form

	int input_Q;			//multiplier in integer form
	string q_string;
	vector <int> bin_Q;		//multiplier in binary form

	vector <int> acc;		//accumulator

	int count;
	int n_Q;
	int qn;

	void add();
	void asr();
	void display();
	void toBinary(int m_in, int q_in);
	void two_complement(char c);

};

Radix2Booth::Radix2Booth()
{
}

Radix2Booth::~Radix2Booth()
{
}

void Radix2Booth::toBinary(int m_in, int q_in)
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
		m_in /= 2;
	}

	for (int i = 0; i < 8; i++)
	{
		outValues << bin_M[i];
	}

	outValues << "\n\nMultiplier (Q):" << endl;
	outValues << "--------------------------" << endl;

	b = 8;		//reset the value of the counter 

	while (q_in != 0)
	{
		bin_Q[--b] = q_in % 2;
		q_in /= 2;
	}

	for (int i = 0; i < 8; i++)
	{
		outValues << bin_Q[i];
	}
	outValues << "\n\nMultiplier Q0: " << bin_Q[0]<< endl;
}

void Radix2Booth::two_complement(char c)
{
	int carry;

	if(c == 'M'){

		for(int i=0; i<bin_M.size(); i++) bin_M[i] = (bin_M[i] + 1) % 2;

		carry=1;

		for(int i=bin_M.size(); i>0; i--){

			if(carry)bin_M[i]++;

			if(bin_M[i]>1){

				bin_M[i] = bin_M[i] % 2;
				carry=1;
			}

			else break;
		}
	}

	if(c == 'Q'){

		for(int i=0; i<bin_Q.size(); i++) bin_Q[i] = (bin_Q[i] + 1) % 2;

		carry=1;

		for(int i=bin_Q.size(); i>0; i--){

			if(carry)bin_Q[i]++;

			if(bin_Q[i]>1){

				bin_Q[i] = bin_Q[i] % 2;
				carry=1;
			}

			else break;
		}
	}
}

void Radix2Booth::add()
{
	int i, c = 0;
	for (i = 0; i < n_Q ; i++)
	{
		acc[i] = acc[i] + bin_M[i] + c;
		if (acc[i] > 1)
		{
			acc[i] = acc[i] % 2;
			c = 1;
		}
		else
			c = 0;
	}

}

void Radix2Booth::asr()
{
	int temp, i;

	temp = acc[0];
	qn = bin_Q[0];
	outValues << "\t\tashr\t\t";
	for (i = 0; i < n_Q - 1; i++)
	{
		acc[i] = acc[i + 1];
		bin_Q[i] = bin_Q[i + 1];
	}
	bin_Q[n_Q - 1] = temp;
}

void Radix2Booth::display()
{
	for (int i = n_Q - 1; i >= 0; i--)
		outValues << acc[i];
	cout << " ";
	for (int i = n_Q - 1; i >= 0; i--)
		outValues << acc[i];
}

int main(int argc, char **argv)
{
	Radix2Booth b2;

	int temp = 0;

	for(int i=0; i<16; i++){
		b2.acc[i]=0;
	}
	
	b2.input_M = 0;		
	b2.input_Q = 0;	

	b2.input_M = atoi(argv[1]);
	b2.input_Q = atoi(argv[2]);

	b2.outValues.open("valuesToDisplay.txt");
	b2.outValues << b2.input_M <<"\t"<< b2.input_Q;

	b2.toBinary(b2.input_M, b2.input_Q);			//convert M and Q to binary

	if(b2.input_M < 0) b2.two_complement('M');
	if(b2.input_Q < 0) b2.two_complement('Q');

	b2.n_Q = b2.bin_Q.size();
	b2.count= b2.n_Q;
	b2.qn = 0;
	
	cout << "qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n";
	cout << "\t\t\tinitial\t\t";

	b2.display();

	b2.outValues << "\t\t" << b2.count << "\n";

	while (b2.count != 0)
	{
		b2.outValues << b2.bin_Q[0] << "\t" << qn;
		if ((qn + b2.bin_Q[0]) == 1)
		{
			if (temp == 0)
			{
				b2.add();
				b2.outValues << "\t\tsubtracting BR\t";
				for (int i = b2.n_Q - 1; i >= 0; i--)
					b2.outValues << b2.acc[i];
				temp = 1;
			}
			else if (temp == 1)
			{
				b2.add();
				b2.outValues << "\t\tadding BR\t";
				for (int i = b2.n_Q - 1; i >= 0; i--)
					cout << b2.acc[i];
				temp = 0;
			}
			b2.outValues << "\n\t";
			b2.asr();
		}
		else if (qn - b2.bin_Q[0] == 0)
			b2.asr();

		b2.display();
		b2.outValues << "\t";

		b2.count--;
		b2.outValues << "\t" << b2.count << "\n";
	}
	b2.outValues << "Result=";
	b2.display();
}