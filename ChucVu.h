#pragma once;
#include <iostream>
#include <string>

using namespace std;
class ChucVu {
  int IDNV;
  string tenCV;
  double PCCV;
  public:
    ChucVu();
    ChucVu(int, string, double);
    ~ChucVu();
    int getIDNV();
    string getTenCV();
    double getPCCV();
    void setIDNV(int);
    void setTenCV(string);
    void setPCCV(double);
};

ChucVu::ChucVu() {
  this->IDNV = 0;
  this->tenCV = 'None';
  this->PCCV = 0.0;
}

ChucVu::ChucVu(int IDNV, string tenCV, double PCCV) {
  this->IDNV = IDNV;
  this->tenCV = tenCV;
  this->PCCV = PCCV;
}

ChucVu::~ChucVu() {}

int ChucVu::getIDNV() {
  return this->IDNV;
}

string ChucVu::getTenCV() {
  return this->tenCV;
}

double ChucVu::getPCCV() {
  return this->PCCV;
}

void ChucVu::setIDNV(int IDNV) {
  this->IDNV = IDNV;
}

void ChucVu::setTenCV(string tenCV) {
  this->tenCV = tenCV;
}

void ChucVu::setPCCV(double PCCV) {
  this->PCCV = PCCV;
}