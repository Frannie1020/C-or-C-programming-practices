#include <iostream>
using namespace std;
class Clock{
public:
      Clock(int h,int m, int s);
	  void SetAlarm(int h,int m,int s);
	  void run();
	  void ShowTime(){
		  cout<<"Now:"<<hour<<":"<<minute<<":"<<second<<endl;
	  }
private:
	int hour;   //Ê±
	int minute;  //·Ö
	int second;  //Ãë

	int Ahour;   //Ê±£¨ÄÖÖÓ£©
	int Aminute;  //·Ö£¨ÄÖÖÓ£©
	int Asecond;   //Ãë£¨ÄÖÖÓ£©
};
Clock::Clock(int h,int m, int s)
{
	(h>=0&&h<24)?hour=h:hour=0;
	(m>=0&&m<60)?minute=m:minute=0;
	(s>=0&&s<60)?second=s:second=0;	
}
void Clock::SetAlarm(int h,int m, int s)
{
	(h<24)?Ahour=h:Ahour=0;
	(m<60)?Aminute=m:Aminute=0;
	(s<60)?Asecond=s:Asecond=0;	
}
void Clock::run()
{
	second++;
	if(second>59)
	{
		second=0;
		minute++;
	}
	if(minute>59)
	{
		minute=0;
		hour++;
	}
	if(hour>=24)
	hour=0;
	if(hour==Ahour&&minute==Aminute&&second==Asecond)
	cout<<"Plink!plink!plink!..."<<endl;
}
