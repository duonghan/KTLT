#include<iostream>
#include<conio.h>

using namespace std;

int S1(int n); //day thu 1: 1,2,3,4,4,5,8,11,12,14,21,30,35,40,56,...
int S2(int n); //day thu 2: 1,2,3,4,6,9,14,21,32,48,73,110,167,252,...



int main(){

	int n;
	long sum = 0;
	
	cout<<"Nhap so phan tu cua day so thu nhat: ";
	cin>>n;
	cout<<"Day so thu nhat: ";
	for (int i = 1; i <= n; i++){
		cout<<S1(i)<<", ";
		sum+=S1(i);
	}
	
	cout<<endl;	
	cout<<"Tong cua "<<n<<" phan tu dau tien cua day thu nhat la "<<sum<<endl;
	cout<<"----------------------------------------"<<endl;
	
	sum = 0;
	cout<<"Nhap so phan tu cua day so thu hai: ";
	cin>>n;
	cout<<"Day so thu hai: ";
	for (int i = 1; i <= n; i++){
		cout<<S2(i)<<", ";
		sum+=S2(i);
	}
	
	cout<<endl;	
	cout<<"Tong cua "<<n<<" phan tu dau tien cua day thu hai la "<<sum<<endl;
	cout<<"----------------------------------------"<<endl;

	system("pause");
	return 0;
	
	}

int S1(int n){
	if(n <=4 )
		return n;
	
	return S1(n-1) - S1(n-2) + S1(n-3) + S1(n-4);	
}

int S2(int n){
	if(n <= 4)
		return n;
	return S2(n-1) + S2(n-2) - S2(n-3) + S2(n-4);
}
