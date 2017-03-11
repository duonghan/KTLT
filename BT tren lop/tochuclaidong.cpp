#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string.h>

using namespace std;

const int MAX = 1000;
int count,i,j;

void creatSomething(int arr[], int top, int bot, int &mark){
	if(bot-top<2){
		for(int k = top; k<= bot; k++)
		{
			mark+=3;
			if(mark > 30){
			cout<<endl;
			mark=3;
			}
			cout<<arr[top]<<",";
		}
	}else{
		mark+=7;
		if(mark > 30){
			cout<<endl;
			mark=3;
		}
		cout<<arr[top]<<"-"<<arr[bot]<<",";
		
	}
	
	
}
void display(int * arr, int length){
	if(length ==0 ) return;
	int top=0,mark =0;
	
	for(int i=0; i< length; i++){
		
	if(arr[i] != arr[top] + i - top){
		creatSomething(arr,top,i-1,mark);
		top=i;
	}
	if(arr[i] == arr[top] + i - top) continue;
	}
	cout<<endl<<mark;
}

int chuyen(char c){
	return (int)c -48;
}

int * strtoDigit(char * str, int length){
	j=0;
	int * digit = new int[length];
	
	for(i=0; i< length; i++){
		if(str[i] == ','|| str[i]== ' ') continue;
		else{
			digit[j] = chuyen(str[i])*100 + chuyen(str[i+1])*10 + chuyen(str[i+2]);
			j++;
			i+=2;
		}
	}
	count = j;
	return digit;
}

int main(){
	char * str = new char[MAX];
	cout<<"Nhap vao day so: ";
	cin>>str;
	int length = strlen(str);
	int * digit = new int[count];
	digit = strtoDigit(str, length);
	display(digit,count);
	delete[] str;
	delete[] digit;
	return 0;
}
