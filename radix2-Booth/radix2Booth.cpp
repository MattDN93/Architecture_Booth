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

	void add(int a[], int x[], int qrn);
	void complement(int a[], int n);
	void add(int ac[], int x[], int qrn);
	void ashr(int ac[], int qr[], int &qn, int qrn);
	void display(int ac[], int qr[], int qrn);
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







void Radix2Booth::complement(int a[], int n)
{
	int i;

	int x[8] = { NULL };
	x[0] = 1;
	for (i = 0; i < n; i++)
	{
		a[i] = (a[i] + 1) % 2;
	}
	add(a, x, n);
}

void Radix2Booth::add(int ac[], int x[], int qrn)
{
	int i, c = 0;
	for (i = 0; i < qrn; i++)
	{
		ac[i] = ac[i] + x[i] + c;
		if (ac[i] > 1)
		{
			ac[i] = ac[i] % 2;
			c = 1;
		}
		else
			c = 0;
	}

}

void Radix2Booth::ashr(int ac[], int qr[], int &qn, int qrn)
{
	int temp, i;

	temp = ac[0];
	qn = qr[0];
	cout << "\t\tashr\t\t";
	for (i = 0; i < qrn - 1; i++)
	{
		ac[i] = ac[i + 1];
		qr[i] = qr[i + 1];
	}
	qr[qrn - 1] = temp;
}

void Radix2Booth::display(int ac[], int qr[], int qrn)
{
	int i;

	for (i = qrn - 1; i >= 0; i--)
		cout << ac[i];
	cout << " ";
	for (i = qrn - 1; i >= 0; i--)
		cout << qr[i];
}

int main(int argc, char **argv)
{
	Radix2Booth b2;

	b2.input_M = 0;		
	b2.input_Q = 0;	

	b2.input_M = atoi(argv[1]);
	b2.input_Q = atoi(argv[2]);

	b2.outValues.open("valuesToDisplay.txt");
	b2.outValues << b2.input_M <<"\t"<< b2.input_Q;

	b2.toBinary(b2.input_M, b2.input_Q);			//convert M and Q to binary

	if(b2.input_M < 0) b2.two_complement("M");
	if(b2.input_Q < 0) b2.two_complement("Q");




	qn = 0;
	temp = 0;

	cout << "qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n";
	cout << "\t\t\tinitial\t\t";
	display(ac, qr, qrn);
	cout << "\t\t" << sc << "\n";

	while (sc != 0)
	{
		cout << qr[0] << "\t" << qn;
		if ((qn + qr[0]) == 1)
		{
			if (temp == 0)
			{
				add(ac, mt, qrn);
				cout << "\t\tsubtracting BR\t";
				for (i = qrn - 1; i >= 0; i--)
					cout << ac[i];
				temp = 1;
			}
			else if (temp == 1)
			{
				add(ac, br, qrn);
				cout << "\t\tadding BR\t";
				for (i = qrn - 1; i >= 0; i--)
					cout << ac[i];
				temp = 0;
			}
			cout << "\n\t";
			ashr(ac, qr, qn, qrn);
		}
		else if (qn - qr[0] == 0)
			ashr(ac, qr, qn, qrn);

		display(ac, qr, qrn);
		cout << "\t";

		sc--;
		cout << "\t" << sc << "\n";
	}
	cout << "Result=";
	display(ac, qr, qrn);
}