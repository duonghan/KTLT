#include<iostream>
using namespace std;

/*
class Time{
	private:
		int hour;
		int minute;
		int second;
	public:
		 Time(){
			hour=minute=second=0;
		}
		 Time(int hour, int minute, int second){
			
			this->hour = hour+(minute + second/60)/60;
			this->minute = (minute + second/60)%60;
			this->second = second%60;
		}
		void setHour(int hour){
			this->hour = hour;
		}
		void setMinute(){
			this->minute = minute;
		}
		void setSecond(){
			this->second = second;
		}
		
		void display(){
			cout<<this->hour<<":"<<this->minute<<":"<<this->second;
		}
	
	//nhap chong toan tu + de cong 2 doi tuong time
	Time operator+(const Time& t){
		Time time;
		time.hour = this->hour + t.hour;
		time.minute = this->minute + t.minute;
		time.second = this->second + t.second;
		return time;
	}
};

int main(){
	
	int h,m,s;
	cout<<"nhap thoi gian cua t1: ";
	cin>>h>>m>>s;
	
	Time t1 = new Time(&h,&m,&s);
	cout<<"Hien thi thoi gian cua t1:  "<<t1.display();
	/*cout<<"nhap thoi gian cua t2: ";
	cin>>h>>m>>s;
	t2 = new Time(h,m,s);*/
	


