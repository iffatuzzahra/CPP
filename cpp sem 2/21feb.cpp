#include <iostream>
using namespace std;

 typedef struct 
	  {
	  string nama;
	  int bb;
	  int tb;
	  } kelas;
typedef struct
	  {
	  string nama_kelas;
	  int jumlah_siswa;
	  kelas ini;
	  } mahasiswa;
	  
int main ()
{
mahasiswa kls[50];
mahasiswa data[50][50];
int a[50],b;

cout<<"masukkan banyaknya kelas :"; cin>>b;
for (int j=0;j<b;j++)
{
	cout<<"\nmasukkan nama kelas ke "<<j+1<<":"; cin>>kls[j].nama_kelas;
	cout<<"masukkan jumlah siswa kelas "<<kls[j].nama_kelas<<":"; cin>>a[j];
	
}
	for (int j=0;j<b;j++){
		cout<<"\n\n\tmahasiswa kelas "<<kls[j].nama_kelas<<endl;
		for (int i=0;i<a[j];i++){
			cout<<"\n\t\tmasukkan nama mahasiswa "<<i+1<<" kelas "<<kls[j].nama_kelas<<":"; cin>>data[j][i].ini.nama;
			cout<<"\t\tmasukkan berat badan mahasiswa "<<i+1<<" kelas "<<kls[j].nama_kelas<<":"; cin>>data[j][i].ini.bb;
			cout<<"\t\tmasukkan tinggi badan mahasiswa "<<i+1<<" kelas "<<kls[j].nama_kelas<<":" ; cin>>data[j][i].ini.tb;
		}
	}
	
	cout<<"\n\tdata yang telah diinputkan :\n\n";
		for (int j=0;j<b;j++){
		cout<<"\n\n\nmahasiswa kelas "<<kls[j].nama_kelas<<endl;
		for (int i=0;i<a[j];i++){
			cout<<"\n\n\tnama mahasiswa "<<i+1<<" kelas "<<kls[j].nama_kelas<<":"<<data[j][i].ini.nama;
			cout<<"\n\tberat badan mahasiswa "<<i+1<<" kelas "<<kls[j].nama_kelas<<":"<<data[j][i].ini.bb;
			cout<<"\n\tmasukkan tinggi badan mahasiswa "<<i+1<<" kelas "<<kls[j].nama_kelas<<":" <<data[j][i].ini.tb;
		}
	}
	
}
