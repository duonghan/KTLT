#include<iostream>
#include<conio.h>

using namespace std;
class phanso{
	private:
		int tuso;
		int mauso;
	public:
		void setTuso(int tuso)
		{
			this->tuso=tuso;
		}
		void setMauso(int mauso){
			this->mauso=mauso;
		}
		int getTuso(){
			return tuso;
		}
		int getMauso(){
			return mauso;
		}
		phanso(int a, int b){
			tuso=a;
			mauso=b;
		}
		phanso(){
			
		}
		
};

void display(phanso p){
	cout<<p.getTuso()<<"/"<<p.getMauso();
}
//ham tim UCLN
int UCLN(int a, int b){
	while(a!= b){
		a>b?a-b:b-a;
	}
	return a;
}
//ham tin BCNN
int BCNN(int a, int b){
	return a*b/UCLN(a,b);
}

phanso operator + (phanso a, phanso b){
	phanso temp = new phanso();
	//mau so chung
	int msc = BCNN(a.getMauso(),b.getMauso());
	temp.setMauso(msc);
	//thuc hien cong tren tu so
	temp.setTuso(msc/a.getMauso()*a.getTuso()+msc/b.getMauso()*b.getTuso());
	
	return temp;	
}
phanso operator - (phanso a, phanso b){
	//doi dau phan so b
	b.setTuso(-b.getTuso());
	return tong(a,b);
}

//tich
phanso operator *(phanso a, phanso b){
	phanso temp = new phanso();
	//nhan 2 phan so
	temp.setTuso(a.getTuso()*b.getTuso());
	temp.setMauso(a.getMauso()*b.getMauso());
	//tim UCLN cua tu va mau
	int ucln= UCLN(temp.getTuso(), temp.getMauso());
	//rut gon phan so
	temp.setTuso(temp.getTuso()/ucln);
	temp.setMauso(temp.getMauso()/ucln);
	
	return temp;
}

//chia 
phanso operator /(phanso a, phanso b){
	phanso temp = new phanso();
	//phan so c la nghich dao cua phan so b
	phanso c = new phanso(b.getMauso(), b.getTuso());
	temp = a*c;
	return temp;
}
int main(){
	
	
	
}


