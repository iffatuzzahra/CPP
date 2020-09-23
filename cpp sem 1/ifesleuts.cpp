#include <iostream>
using namespace std;
int main()
{
	float x;
	cout<<"masukkan nilai ipk :";
	cin>>x;
	//pengendalian 
	
	if (x>=3.5 && x<=4) 
	
		cout<<"cumloud ";
	
	else if(x>2.5 && x<=3.5)
	
		cout<<"memuaskan";
	
	else if(x>=2 && x<=2.5)
	
		cout<<"cukup";
	else if(x>4)
		cout<<"error";
	
	else
	
		cout<<"drop out";
	
}
