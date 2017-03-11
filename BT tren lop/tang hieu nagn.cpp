#include<iostream>
#include<conio.h>

using namespace std;
inline double delta (double a, double b){
	return sqrt (a*a +b*b);
}
int main(){
	double k =6, m=9;
	cout<<delta(k,m)<<'\n';
	cout<<sqrt(k*k +m*m)<<'\n';
	return 0;
}
