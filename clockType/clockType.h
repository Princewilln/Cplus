#ifndef H_CLOCKTYPE
#define H_CLOCKTYPE

#include <string>
using namespace std;

class clockType
{
public:
    void setTime(int hours, int minutes, int seconds);
    void getTime(int& hours, int& minutes, int& seconds) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const clockType& otherClock) const;

    clockType(int hours, int minutes, int seconds);
    clockType();

private:
    int hr;  // variable to store the hours
    int min; // variable to store the minutes
    int sec; // variable to store the seconds
};

class extClockType : public clockType
{
public:
    extClockType(int hours, int minutes, int seconds, const string& timeZone);
    extClockType();  // Default constructor

    void setTime(int hours, int minutes, int seconds, const string& timeZone);
    void printTime() const;

private:
    string zone; // Variable to store the time zone
};

#endif // H_CLOCKTYPE
