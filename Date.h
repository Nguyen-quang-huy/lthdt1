#pragma once;
#include <ctime>
#include <iostream>


using namespace std;

class Date {
  int year;
  int month;
  int day;
  public:
    Date();
    Date(int, int, int);
    ~Date();
    int getYear();
    int getMonth();
    int getDay();
    static int getCurrentYear();
    friend ostream& operator<<(ostream &,Date&);
};

Date::Date() {
  this->year = 2022;
  this->month = 1;
  this->day = 10;
}

Date::Date(int year, int month, int day) {
  this->year = year;
  this->month = month;
  this->day = day;
}

Date::~Date() {}

int Date::getDay() {
  return this->day;
}

int Date::getMonth() {
  return this->month;
}

int Date::getYear() {
  return this->year;
}

int Date::getCurrentYear() {
  std::time_t t = std::time(nullptr);
  std::tm *const pTInfo = std::localtime(&t);
  return pTInfo->tm_year + 1900;
}

ostream& operator<<(ostream& o, Date& date) {
  o << date.day << '/' << date.month << '/' << date.year;
  return o;
}
