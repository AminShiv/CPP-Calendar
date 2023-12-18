#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int Startday = 0;

void PrintMonthName(int month)
{
    if (month == 1)
    {
        cout << "January";
    }
    else if (month == 2)
    {
        cout << "February";
    }
    else if (month == 3)
    {
        cout << "March";
    }
    else if (month == 4)
    {
        cout << "April";
    }
    else if (month == 5)
    {
        cout << "May";
    }
    else if (month == 6)
    {
        cout << "June";
    }
    else if (month == 7)
    {
        cout << "July";
    }
    else if (month == 8)
    {
        cout << "August";
    }
    else if (month == 9)
    {
        cout << "September";
    }
    else if (month == 10)
    {
        cout << "October";
    }
    else if (month == 11)
    {
        cout << "November";
    }
    else if (month == 12)
    {
        cout << "December";
    }
    else
    {
        cout << "  ";
    }
}

bool LeapYear (int fullyear)
{
    if ((fullyear % 4 == 0 && fullyear % 100 != 0) || (fullyear % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int daysinmonth (int month, int fullyear)
{
    int day;
    if (month == 1 || month == 3|| month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        day=31;
    }
    else if (month == 2)
    {
        if ((LeapYear(fullyear)==1))
        {
            day = 29;
        }
        else
        {
            day = 28;
        }
    }
    else
    {
        day=30;
    }
    return day;
}

int firstdaymonth (int month, int fullyear)
{
    int year=fullyear %100;
    int hundred = floor(fullyear / 100);
    Startday = (floor(year / 4));
    Startday = Startday + 1;

    if (month == 1 || month == 10)
    {
        Startday = Startday + 1;
    }
    else if (month == 5)
    {
        Startday = Startday + 4;
    }
    else if (month == 6)
    {
        Startday = Startday + 5;
    }
    else if (month == 8)
    {
        Startday = Startday + 3;
    }
    else if (month == 9 || month == 12)
    {
        Startday = Startday + 6;
    }
    else
    {
        Startday = Startday;
    }

    if(LeapYear(fullyear)==1)
    {
        if (month == 1 || month == 2)
        {
            Startday = Startday - 1;
        }
    }

    if(hundred == 20)
    {
        Startday = Startday + 6;
    }
    else if (hundred == 17)
    {
        Startday = Startday + 4;
    }
    else if (hundred == 18)
    {
        Startday = Startday + 2;
    }
    else if (hundred == 19)
    {
        Startday = Startday;
    }
    else
    {
        Startday = Startday + (Startday * 400);
    }
    Startday = Startday + year;

    Startday = Startday %7;
    if(Startday==0)
    {
        Startday = 7;
    }
    return Startday;

}

void printmonth(int month, int fullyear)
{
    int day = daysinmonth(month, fullyear);
    int Startday = firstdaymonth(month, fullyear);
    int weekday = Startday;
    PrintMonthName(month);
    cout << fullyear <<endl;
    cout << "  S  M Tu  W Th  F  S" <<endl;

    for(int i=1; i<Startday; i++)
    {
        cout<< "   ";
    }
    
    
    for(int i=1; i<=day; i++)
    {
        if (i<10)
        {
            cout << "  " <<i;
        }
        else
        {
            cout << " "<<i;
        }

        if (weekday == 7)
        {
            cout << endl;
            weekday = 1;
        }
        else
        {
            weekday ++;
        }
    }
    cout << endl;

}

void printyear (int fullyear)
{
    printmonth(1, fullyear);
    printmonth(2, fullyear);
    printmonth(3, fullyear);
    printmonth(4, fullyear);
    printmonth(5, fullyear);
    printmonth(6, fullyear);
    printmonth(7, fullyear);
    printmonth(8, fullyear);
    printmonth(9, fullyear);
    printmonth(10, fullyear);
    printmonth(11, fullyear);
    printmonth(12, fullyear);
}

int main()
{
    int year;
    int fullyear;
    int month;
    cout << "Enter a year:" << endl;
    cin >> fullyear;
    cout << "Enter a month or press (0) for the whole year:" <<endl;
    cin >> month;

    if (month == 0)
    {
        printyear(fullyear);
    }
    else
    {
        printmonth(month, fullyear);
    }
    return 0;
    
}