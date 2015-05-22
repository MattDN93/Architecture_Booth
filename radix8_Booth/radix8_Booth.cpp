#include <Windows.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

class Radix8Booth
{
public:
	Radix8Booth();			
	~Radix8Booth();

	ifstream inValues;		//Input File
	ofstream outValues;		//Output File

	int input_M;			//multiplicand in integer form
	vector <int> bin_M;		//multiplicand in binary form

	int input_Q;			//multiplier in integer form
	vector <int> bin_Q;		//multiplier in binary form
	vector <int> Q;			//Functions as "X"

	vector <int> acc;		//accumulator

	vector <int> DecToBin(int num);
	int BinToDec(vector <int> &t1);
	void display(vector <int> &t1);
	vector <int> shift_right(vector <int> &t1);
	vector <int> shift_left(vector <int> &t1);
	vector <int> Separate(vector <int> &t1,vector <int> &t2);
	vector <int> add(vector <int> &t1, vector <int> &t2);
};

Radix8Booth::Radix8Booth()	//Default Constructor
{
}

Radix8Booth::~Radix8Booth()	//Default Destructor
{
}

//Convert Decimal Value to Binary
vector <int> Radix8Booth::DecToBin(int num)
{
	vector <int> t1;
	while(num>0)
	{
		t1.push_back(num%2);
		num=num/2;	
	}
	return t1;
 }

//Convert Binary value to decimal
int Radix8Booth::BinToDec(vector <int> &t1)
{
	double dec =0;
	for(int i=0;i<t1.size();i++)
		dec=dec+(t1[i]*pow(2.0,i));
	return dec;
}

//Display any vector passed to it in order
 void Radix8Booth::display(vector <int> &t1)
 {
	for(int i=t1.size()-1;i>=0;i--)
	{
		outValues<<t1[i];
	}
	 outValues<<""<<endl;
 }

 //Perform a right shift on vector
 vector <int> Radix8Booth::shift_right(vector <int> &t1)
 {
	 t1.push_back(0);
	 return t1;
 }

 //Perform a left shift on vector
 vector <int> Radix8Booth::shift_left(vector <int> &t1)
 {
	 vector <int> t2;
	 t2.push_back(0);	//Insert 0 at beginning
	 for(int i=0;i<t1.size();i++)	//Insert remaining bits
		 t2.push_back(t1[i]);
	 return t2;
 }

 //Returns result of multiplication between x and a
 vector <int> Radix8Booth::Separate(vector <int> &t1,vector <int> &t2)
{
	vector <int> t3;
	vector <int> t4;

	//Decimal value of x between 0 and 7
	switch(BinToDec(t1))
	{	
		//Multiply by 0 . Return vector of zeroes => 0a.
		case 0:
			for(int i=0;i<t2.size();i++)
				t3.push_back(0);
			return t3;
		//Multiply by 1. Return 1a.
		case 1:
			return t2;
		//Multiply by 2. Return 2a which is a left shift.
		case 2:
			return shift_left(t2);
		//Multiply by 2 and add 1. Return 3a.
		case 3:
			t3=shift_left(t2);
			return add(t2,t3);
		//Multiply by 4 => shift left twice.
		case 4:
			t2=shift_left(t2);
			return shift_left(t2);
		//Multiply by 5 => shift left twice and add one => 4a+a
		case 5:
			t3=shift_left(t2);
			t3=shift_left(t3);
			return add(t2,t3);
		//Multiply by 6 => shift left twice and add one more shift => 4a+2a
		case 6:
			t3=shift_left(t2);
			t3=shift_left(t3);
			t2=shift_left(t2);
			return add(t3,t2);
		//Multiply by 7 => shift left twice + single shift + add one => 4a+2a+a
		case 7:
			t3=shift_left(t2);
			t3=shift_left(t3);
			t4=shift_left(t2);
			t4=add(t3,t4);
			return add(t4,t2);	
	}

}

 //Add two binary numbers
 vector <int> Radix8Booth::add(vector <int> &t1, vector <int> &t2)
 {
	 vector <int> t3;
	 int putzero = 0;
	 int count=0;
	 int carry=0;
	 //lengths must be the same
	 if(t1.size()>t2.size())
	{
		count=t1.size();
		putzero=t1.size()-t2.size();
		for(int i=0;i<putzero;i++)
			t2.push_back(0);
	 }
	else
	{
		count=t2.size();
		putzero=t2.size()-t1.size();
		for(int i=0;i<putzero;i++)
			t1.push_back(0);
	}
	 //Add bits + carry and check for carry
	for(int i=0;i<count;i++)
	{
		t3.push_back((t1[i]+t2[i]+carry)%2);
		if((t1[i]+t2[i]+carry)>1)
			carry=1;
		else
			carry=0;	
	}
	//Carry Occured, add 1 to next bit over and repeat
	if(carry==1)
	t3.push_back(carry);
	return t3;
}

 double calctime(clock_t time1,clock_t time2) {  //function to calculate time elapsed
	double diff=time1-time2;
	double diffms=(diff*1000)/CLOCKS_PER_SEC;	//milliseconds
	return diffms; 
}

 int main(int argc, char **argv)
{
	Radix8Booth b8;
	int loopcount=0;
	clock_t begin=clock();

	while(loopcount <= 100000){

	vector <int> temp;
	vector <int> temp2;
	int loop;

	b8.input_M = 0;		
	b8.input_Q = 0;	

	b8.input_M = atoi(argv[1]);
	b8.input_Q = atoi(argv[2]);

	b8.outValues.open("valuesToDisplay.txt");
	b8.outValues << b8.input_M <<"\t"<<"X"<< "\t"<<b8.input_Q;

	b8.bin_M=b8.DecToBin(b8.input_M); //Convert M to binary

	b8.bin_Q=b8.DecToBin(b8.input_Q);	//Convert Q to binary

	b8.outValues << "\n\nMultiplicand(M):";
	b8.outValues << "\n--------------------------" << endl;		//display binary
	b8.display(b8.bin_M);

	b8.outValues << "\nMultiplier (Q):" << endl;
	b8.outValues << "--------------------------" << endl;
	b8.display(b8.bin_Q);

	for(int i=0;i<b8.bin_Q.size();i++)	//initialise partial product
		b8.acc.push_back(0);

	if(b8.bin_Q.size()%3==0)			
		loop=(b8.bin_Q.size()/3);
	else
		loop=(b8.bin_Q.size()/3)+1;

	for(int i=0;i<loop;i++)				//groups of 3 bits
	{
		for(int j=0;j<3;j++)
		{
			if((j+i+(2*i))<b8.bin_Q.size())
				b8.Q.push_back(b8.bin_Q[j+i+(2*i)]);
		}

		b8.outValues << "\n--------------------------";
		b8.outValues <<endl<<"Iteration "<< i <<endl;
		b8.outValues << "Partial Product : "<<endl;
		b8.display(b8.acc);
		b8.outValues << "X"<<i<<": ";
		b8.display(b8.Q);

		temp=b8.bin_M;

		temp2=b8.Separate(b8.Q,temp);

		b8.outValues << b8.BinToDec(b8.Q) << "M : ";	//Convert to decimal

		for(int j=0;j<3;j++)
		{
			if(!b8.Q.empty())
			b8.Q.pop_back(); 
		}

		for(int j=0;j<3*(i);j++)
		{
			temp2=b8.shift_left(temp2);		//perform left shift
		}

		b8.display(temp2);

		b8.acc=b8.add(b8.acc,temp2);

		b8.outValues << "New Partial Product: "<<endl;

		b8.display(b8.acc);

		for(int j=0;j<3;j++)
		{
			b8.acc=b8.shift_right(b8.acc);
		}
		
		b8.outValues<<"Partial Product after shift : "<<endl;

		b8.display(b8.acc);

		}
	b8.outValues << "\n--------------------------\n";		//Final Results
	b8.outValues << "Result (Binary): "<<endl;
	b8.display(b8.acc);

	b8.outValues << "Result (Decimal) : "<<endl;
	b8.outValues << b8.BinToDec(b8.acc) << endl;

	loopcount++;
	cout<<loopcount;
	}
	clock_t end=clock();

	b8.outValues <<endl<<"Time Elapsed: "<< double(calctime(end,begin)) << "milliseconds";
}