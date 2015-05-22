#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <ctime>
using namespace std;

class Radix4Booth
{
public:
	Radix4Booth();
	~Radix4Booth();

	ifstream inValues;
	ofstream outValues;

	int input_M;			//multiplicand in integer form
	string m_string;
	vector <int> bin_M;		//multiplicand in binary form
	vector <int> M_initial;	

	int input_Q;			//multiplier in integer form
	string q_string;
	vector <int> bin_Q;		//multiplier in binary form
	vector <int> Q;

	vector <int> acc;		//accumulator

	vector <int> Separate(vector <int> &t1);
	int BinToDec(vector <int> &t1);
	void display(vector <int> &t1);
	vector <int> shift_right(vector <int> &t1);
	vector <int> shift_left(vector <int> &t1);
	vector <int> add(vector <int> &t1, vector <int> &t2);
	vector <int> DecToBin(vector <int> &t1, int num);

};

Radix4Booth::Radix4Booth()
{
}

Radix4Booth::~Radix4Booth()
{
}

vector <int> Radix4Booth::DecToBin(vector <int> &t1, int num)
{
	vector <int> t2;  
	int length=0;       
	while(num>0)
	{
		t2.push_back(num%2); 
		num=num/2;	      
		length++;				 
	}
	return t2;    
 }

void Radix4Booth::display(vector <int> &t1)
{
	for (int i = t1.size()-1; i >= 0; i--)
		outValues << t1[i];
	outValues << endl;
}

int Radix4Booth::BinToDec(vector <int> &t1)
{
	double dec = 0;
	for(int i=0;i<t1.size();i++)
		dec=dec+(t1[i]*pow(2.0,i)); 
	return dec;
}

vector <int> Radix4Booth::shift_right(vector <int> &t1)
 {
	 t1.push_back(0);  
	 return t1;
 }

vector <int> Radix4Booth::shift_left(vector <int> &t1)
 {
	 vector <int> t2;   
	 t2.push_back(0);  
	 for(int i=0;i<t1.size();i++)
		 t2.push_back(t1[i]); 
	 return t2;
 }

vector <int> Radix4Booth::Separate(vector <int> &t1)
{
	vector <int> t2;
	switch(BinToDec(Q))    
	{		
		case 0:
			for(int i=0;i<t1.size();i++)
				t2.push_back(0); 
			return t2;
		case 1:
			return t1;     
		case 2:
			return shift_left(t1);  
		case 3:
			t2=shift_left(t1); 
			return add(t1,t2);
	}
}

vector <int> Radix4Booth::add(vector <int> &t1, vector <int> &t2)
 {
	 vector <int> t3;
	 int putzero = 0;
	 int carry=0;                
	 int count=0;	

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

	for(int i=0;i<count;i++)
	{
		t3.push_back((t1[i]+t2[i]+carry)%2); 
		if((t1[i]+t2[i]+carry)>1)    
			carry=1;                    
		else
			carry=0;                   
		
	}
	if(carry==1)
	t3.push_back(carry);  

	return t3;    
}

int main(int argc, char **argv)
{
	Radix4Booth b4;

	vector <int> temp;
	vector <int> temp2;

	b4.acc.resize(16);

	b4.input_M = 0;		
	b4.input_Q = 0;	

	b4.input_M = atoi(argv[1]);
	b4.input_Q = atoi(argv[2]);

	b4.outValues.open("valuesToDisplay.txt");
	b4.outValues << b4.input_M <<"\t"<<"X"<< "\t"<<b4.input_Q;

	b4.bin_M=b4.DecToBin(b4.bin_M,b4.input_M);

	b4.bin_Q=b4.DecToBin(b4.bin_Q,b4.input_Q);

	b4.outValues << "\n\nMultiplicand(M):";
	b4.outValues << "\n--------------------------" << endl;
	b4.display(b4.bin_M);

	b4.outValues << "\nMultiplier (Q):" << endl;
	b4.outValues << "--------------------------" << endl;
	b4.display(b4.bin_Q);

	for(int i=0; i<b4.bin_Q.size(); i++){
		b4.acc[i]=0;
	}

	for(int i=0;i<(b4.bin_Q.size()/2)+1;i++)
	{
		for(int j=0;j<2;j++)
		{
			if((j+2*i)<b4.bin_Q.size()){

				b4.Q.push_back(b4.bin_Q[j+2*i]);
			}
		}


		b4.outValues << "\n--------------------------";
		b4.outValues <<endl<<"Iteration "<< i <<endl;
		b4.outValues << "Partial Product : "<<endl;
		b4.display(b4.acc);
		b4.outValues << "X(0) : ";
		b4.display(b4.Q);

		temp=b4.bin_M;

		temp2=b4.Separate(temp);

		b4.outValues << b4.BinToDec(b4.Q) << "M : ";

		for(int j=0;j<3;j++)
		{
			if(!b4.Q.empty())
			b4.Q.pop_back(); 
		}

		for(int j=0;j<2*(i);j++)
		{
			temp2=b4.shift_left(temp2); 
		}

		b4.display(temp2);

		b4.acc=b4.add(b4.acc,temp2);

		b4.outValues << "New Partial Product: "<<endl;

		b4.display(b4.acc);

		for(int j=0;j<2;j++)
		{
			b4.acc=b4.shift_right(b4.acc);
		}
		
		b4.outValues<<"Partial Product after shift : "<<endl;

		b4.display(b4.acc);

	}
	b4.outValues << "\n--------------------------\n";
	b4.outValues << "Result (Binary): "<<endl;
	b4.display(b4.acc);

	b4.outValues << "Result (Decimal) : "<<endl;
	b4.outValues << b4.BinToDec(b4.acc) << endl;
}