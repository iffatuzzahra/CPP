#include <iostream>
#include <string.h>

using namespace std;
char kalimat[50];

void masuk(int n)
{
	char save;
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-1-i;j++){
			if (kalimat[j]>kalimat[j+1]){
				save=kalimat[j]; kalimat[j]=kalimat[j+1]; kalimat[j+1]=save;
			}
		}
	}
	for (int i=0;i<=n;i++){
		cout<<kalimat[i];
	} 
}
int main ()
{
	int n;
	cout<<"masukkan kalimat yang anda inginkan : "<<endl;  cin.getline(kalimat, sizeof(kalimat));
	n=strlen(kalimat); 
	masuk(n);
	
}
