#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int M,N;
	int *A = NULL;
	int *B = NULL;
	int *C = NULL;
	cout<<"Nhap so dong cua ma tran:";
	cin >> M;
	cout<<"Nhap so cot cua ma tran:"; cin>>N;
	//Cap phat vung nho cho ma tran A
	if(!AllocateMatrix(&A, M,N)){
		cout<<"Khong con du bo nho"<<endl;
		return 1;
	}
	
	
	//Cap phat vung nho cho ma tran B
	if(!AllocateMatrix(&B, M,N)){
		cout<<"Khong con du bo nho"<<endl;
		FreeMatrix(A);
		//Giai phong vung nho A
		return 1;
	}
	
	//Cong hai ma tran
	void addMatrix(int *A, int *B, int *C, int M)
	{
		for(int I=0)
	}
	
}
