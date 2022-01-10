#pragma once;
#include <string>
#include "Date.h"

class NV {
  private:
    int IDNV;
    string NameNV;
    Date dateStart;
    bool type;
  public:
    NV();
    NV(int, string, int, int, int);
    NV(NV&);
    ~NV();
    int getIDNV();
    void setIDNV(int);
    string getNameNV();
    void setNameNV(string);
    Date getDateStart();
    bool getType();
    void setType(bool);
    void setDateStart(int, int, int);
    friend ostream& operator<<(ostream&, NV&);
    friend istream& operator>>(istream&, NV&);
    virtual double getSalary();
};

NV::NV() {
  this->IDNV = 0;
  this->NameNV = "None";
  this->dateStart = Date();
  this->type = -1;
}

NV::NV(int IDNV, string NameNV, int year, int month, int day) {
  this->IDNV = IDNV;
  this->NameNV = NameNV;
  this->dateStart = Date(year, month, day);
}

NV::NV(NV& n) {
  this->IDNV = n.IDNV;
  this->NameNV = n.NameNV;
  this->dateStart = n.dateStart;
  this->type = n.type;
}

NV::~NV() {}

int NV::getIDNV() {
  return this->IDNV;
}

void NV::setIDNV(int IDNV) {
  this->IDNV = IDNV;
}

string NV::getNameNV() {
  return this->NameNV;
}

void NV::setNameNV(string NameNV) {
  this->NameNV = NameNV;
}

Date NV::getDateStart() {
  return this->dateStart;
}

void NV::setDateStart(int year, int month, int day) {
  this->dateStart = Date(year, month, day);
}

bool NV::getType() {
  return this->type;
}

void NV::setType(bool type) {
  this->type = type;
}

ostream& operator<<(ostream& o, NV& n) {
  o << "IDNV: " << n.IDNV << ", NameNV: " << n.NameNV <<  "," << " Ngay lam viec: " << n.dateStart << endl;
  return o;
}

istream& operator>>(istream& i, NV& n) {
  cout << "Nhap IDNV: ";
  i >> n.IDNV;
  cout << endl;
  cout << "Nhap NameNV: ";
  string name;
  i.ignore();
  getline(i, name);
  n.NameNV = name;
  cout << endl;
  cout << "Nhap nam vao lam viec: ";
  int year;
  cin >> year;
  cout << endl;
  cout << "Nhap thang vao lam viec: ";
  int month;
  cin >> month;
  cout << endl;
  int day;
  cout << "Nhap ngay vao lam viec: ";
  cin >> day;
  cout << endl;
  n.dateStart = Date(year, month, day);
  return i;
}
