#include <iostream>
using namespace std;


int faktorial(int n) 
{ int m;
    if(n == 1) return 1;
    else if (n%2==0) m=n/2;
    else if (n%2==1) m=n;
    return m * faktorial(n-1);
}
int main ()
{ int n;
	cout<<"masukkan angka yang akan difaktorial (1-10) :"; cin>>n;
	cout<<"faktorial ganjil genap dari "<<n<<" adalah :"<<faktorial(n);
}
