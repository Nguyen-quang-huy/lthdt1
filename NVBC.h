#pragma once;
#include "NV.h"
#include "ChucVu.h"

class NVBC : public NV {
  double HSLKD;
  double HSL;
  ChucVu cv;
  public:
    NVBC();
    NVBC(int, string, int, int, int, double, int, string, double);
    ~NVBC();
    double getHSLKD();
    void setHSLKD(double);
    double getHSL();
    double getSalary();
    friend ostream& operator<<(ostream&, NVBC&);
};

NVBC::NVBC() {
  this->HSLKD = 0;
  this->HSL = 0;
  this->cv = ChucVu();
  this->setType(0);
}

NVBC::NVBC(int IDNV, string nameNV, int year, int month, int day, double HSLKD, int IDCV, string tenCV, double PCCV) 
: NV(IDNV, nameNV, year, month, day), HSLKD(HSLKD) {
  this->cv = ChucVu(IDCV, tenCV, PCCV);
  this->HSL = this->HSLKD + floor((Date::getCurrentYear() - this->getDateStart().getYear()) / 3) * 0.33;
  this->setType(0);
}

NVBC::~NVBC() {}

double NVBC::getHSLKD() {
  return this->HSLKD;
}

void NVBC::setHSLKD(double HSLKD) {
  this->HSLKD = HSLKD;
} 

double NVBC::getHSL() {
  return this->HSL;
}

double NVBC::getSalary() {
  return this->HSL * 1500000 + this->cv.getPCCV() * 2000000;
}

ostream& operator<<(ostream& o, NVBC& n) {
  o << "IDNV: " << n.getIDNV() << ", NameNV: " << n.getNameNV() <<  "," 
  << " Ngay lam viec: " << n.getDateStart() << ", IDCV: " << n.cv.getIDNV() << ", Ten CV: " 
  << n.cv.getTenCV() << ", PCCV: " << n.cv.getPCCV() << ", HSL: " << n.getHSL() 
  << ", Luong: " << n.getSalary() << endl;
  return o;
}
