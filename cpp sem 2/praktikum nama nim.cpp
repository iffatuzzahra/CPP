#include <iostream>
using namespace std;
int main ()
{
	int b[5],a;
	bool c;
	
do { c= false;
		for (int i=0;i<5;i++){
			cout<<"masukkan angka : "; cin>>b[i];
		}
		cout<<"angka yang ingin dicari : "; cin>>a;
		for (int i=0;i<5;i++){
			if (b[i]==a) c=true; 
		}
		if (c) cout<<"ketemu ";
		else cout<<"tidak ketemu ";
   } while (true);
}
