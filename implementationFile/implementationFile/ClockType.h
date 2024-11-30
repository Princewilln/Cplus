#include <iostream>

using namespace std;

class ClockType
{
public:
	void setTime(int, int, int);
	virtual void printTime();
	
private:
	int hr;
	int min;
	int sec;

};

void ClockType::setTime(int hour, int minute, int second) {
	if (hour >= 0 && 24 > hour)
		hr = hour;
	else
		hr = 0;

	if (minute >= 0 && 60 > minute)
		min = minute;
	else
		min = 0;

	if (second >= 0 && 60 > second)
		sec = second;
	else
		sec = 0;

}

void ClockType::printTime(){
	cout << hr << ":";
	cout << min << ":";
	cout << sec;

}

class extClockType : public ClockType {
public:
	string timeZone;
	extClockType();
	void printTime() override;

	



};

void extClockType::printTime() {
	cout << timeZone;
}
extClockType::extClockType() {
	timeZone = "CST";
}
