#pragma once;
#include "NV.h"

class NVHD : public NV {
  double dateSalary;
  int dateOfWorks;
  public:
    NVHD();
    NVHD(int, string, int, int, int, double, int);
    ~NVHD();
    double getDateSalary();
    void setDateSalary(double);
    int getDateOfWorks();
    void setDateOfWorks();
    double getSalary();
    friend ostream& operator<<(ostream&, NVHD&);
};

NVHD::NVHD() {
  this->dateOfWorks = 0;
  this->dateSalary = 0;
  this->setType(1);
}

NVHD::NVHD(int IDNV, string nameNV, int year, int month, int day, double dateSalary, int dateOfWorks)
 : NV(IDNV, NameNV, year, month, day), dateSalary(dateSalary), dateOfWorks(dateOfWorks) {
   this->setType(1);
 }

double NVHD::getDateSalary() {
  return this->dateSalary;
}

void NVHD::setDateSalary(double dateSalary) {
  this->dateSalary = dateSalary;
} 

int NVHD::getDateOfWorks() {
  return this->dateOfWorks;
}

void NVHD::setDateOfWorks(int dateOfWorks) {
  this->dateOfWorks = dateOfWorks;
}

double NVHD::getSalary() {
  return this->dateSalary * this->dateOfWorks;
}

ostream& operator<<(ostream& o, NVHD& n) {
  o << "IDNV: " << n.getIDNV() << ", NameNV: " << n.getNameNV() <<  "," << " Ngay lam viec: " 
  << n.getDateStart() << ", Luong Cong Nhat: " << n.dateSalary << ", So ngay lam viec: " 
  << n.dateOfWorks << ", Luong: " << n.getSalary() << endl;
  return o;
}
