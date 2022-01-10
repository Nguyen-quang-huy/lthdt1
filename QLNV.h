#pragma once;
#include "NVBC.h"
#include "NVHD.h"

class QLNV {
  private:
    NV** DSNV;
    int nNVBC;
    int nNVHD;
  public:
    QLNV();
    QLNV(NVBC*, NVHD*, int, int);
    ~QLNV();
    friend ostream& operator<<(ostream&, QLNV&);
    void insertHead(NV&);
    void insertTail(NV&);
    void insertIndex(NV&, int);
    void deleteHead(int);
    void deleteTail(int);
    void deleteIndex(int, int);
    int indexOf(int, int);
    void search(string, int);
    void swap(int, int, int);
    void sort(bool (*)(double, double), int);
};

QLNV::QLNV() {
  this->nNVBC = 0;
  this->nNVHD = 0;
  this->DSNV = nullptr;
}

QLNV::QLNV(NVBC* DSNVBC, NVHD* DSNVHD, int nNVBC, int nNVHD) {
  this->nNVBC = nNVBC;
  this->nNVHD = nNVHD;
  this->DSNV = new NV*[2];
  this->DSNV[0] = new NVBC[nNVBC];
  this->DSNV[1] = new NVHD[nNVHD];
  for (int i = 0; i < nNVBC; i++) {
    this->DSNV[0][i] = DSNVBC[i];
  }

  for (int i = 0; i < nNVHD; i++) {
    this->DSNV[1][i] = DSNVHD[i];
  }
}

QLNV::~QLNV() {

}

ostream& operator<<(ostream& o, QLNV& q) {
  cout << "Danh sach nhan vien: " << endl;
  cout << "Danh sach nhan vien bien che: " << endl;
  for (int i = 0; i < q.nNVBC; i++) {
    o << q.DSNV[0][i];
  }
  cout << "Danh sach nhan vien hop dong: " << endl;
  for (int i = 0; i < q.nNVHD; i++) {
    o << q.DSNV[1][i];
  }
  return o;
}

void QLNV::insertHead(NV& n) {
  if (n.getType() == 0) {
    if (this->nNVBC == 0) {
      this->nNVBC = 1;
      this->DSNV[0] = new NVBC[1];
      this->DSNV[0][0] = n;
      return;
    }

    NV* temp = new NVBC[this->nNVBC + 1];
    temp[0] = n;
    this->nNVBC = this->nNVBC + 1;

    for (int i = 1; i < this->nNVBC; i++) {
      temp[i] = DSNV[0][i - 1];
    }

    delete[] this->DSNV[0];
    this->DSNV[0] = new NVBC[this->nNVBC];
    for (int i = 0; i < this->nNVBC; i++) {
      this->DSNV[0][i] = temp[i];
    }

    delete[] temp;
  } else {
    if (this->nNVHD == 0) {
      this->nNVHD = 1;
      this->DSNV[1] = new NVHD[1];
      this->DSNV[1][0] = n;
      return;
    }

    NV* temp = new NVHD[this->nNVHD + 1];
    temp[0] = n;
    this->nNVHD = this->nNVHD + 1;

    for (int i = 1; i < this->nNVHD; i++) {
      temp[i] = DSNV[1][i - 1];
    }

    delete[] this->DSNV[1];
    this->DSNV[1] = new NVHD[this->nNVHD];
    for (int i = 0; i < this->nNVHD; i++) {
      this->DSNV[1][i] = temp[i];
    }

    delete[] temp;
  }

}

void QLNV::insertTail(NV& n) {
  if (n.getType() == 0) {
    if (this->nNVBC == 0) {
      this->nNVBC = 1;
      this->DSNV[0] = new NVBC[this->nNVBC];
      this->DSNV[0][0] = n;
      return;
    }

    NV* temp = new NVBC[this->nNVBC + 1];
    temp[this->nNVBC] = n;
    this->nNVBC = this->nNVBC + 1;

    for (int i = 0; i < this->nNVBC - 1; i++) {
      temp[i] = DSNV[0][i];
    }

    delete[] this->DSNV[0];
    this->DSNV[0] = new NVBC[this->nNVBC];
    for (int i = 0; i < this->nNVBC; i++) {
      this->DSNV[0][i] = temp[i];
    }

    delete[] temp;
  } else {
    if (this->nNVHD == 0) {
      this->nNVHD = 1;
      this->DSNV[1] = new NVHD[this->nNVHD];
      this->DSNV[1][0] = n;
      return;
    }

    NV* temp = new NVHD[this->nNVHD + 1];
    temp[this->nNVHD] = n;
    this->nNVHD = this->nNVHD + 1;

    for (int i = 0; i < this->nNVHD - 1; i++) {
      temp[i] = DSNV[1][i];
    }

    delete[] this->DSNV[1];
    this->DSNV[1] = new NVHD[this->nNVHD];
    for (int i = 0; i < this->nNVHD; i++) {
      this->DSNV[1][i] = temp[i];
    }

    delete[] temp;
  }
} 

void QLNV::insertIndex(NV& n, int index) {
  if (n.getType() == 0) {
    if (index > this->nNVBC || index < 0) {
      cout << "Index out of range";
      exit(1);
    }
    
    NV* temp = new NVBC[this->nNVBC + 1];
    for (int i = 0; i < index; i++) {
      temp[i] = this->DSNV[0][i];
    }
    temp[index] = n;
    for (int i = index + 1; i < this->nNVBC + 1; i++) {
      temp[i] = this->DSNV[0][i - 1];
    }

    delete[] this->DSNV[0];
    this->nNVBC = this->nNVBC + 1;
    this->DSNV[0] = new NVBC[this->nNVBC];
    for (int i = 0; i < this->nNVBC; i++) {
      this->DSNV[0][i] = temp[i];
    }

    delete[] temp;
  } else {
    if (index > this->nNVHD || index < 0) {
      cout << "Index out of range";
      exit(1);
    }
    
    NV* temp = new NVHD[this->nNVHD + 1];
    for (int i = 0; i < index; i++) {
      temp[i] = this->DSNV[1][i];
    }
    temp[index] = n;
    for (int i = index + 1; i < this->nNVHD + 1; i++) {
      temp[i] = this->DSNV[1][i - 1];
    }

    delete[] this->DSNV[1];
    this->nNVHD = this->nNVHD + 1;
    this->DSNV[1] = new NVHD[this->nNVHD];
    for (int i = 0; i < this->nNVHD; i++) {
      this->DSNV[1][i] = temp[i];
    }

    delete[] temp;
  }

}

void QLNV::deleteHead(int type) {
  if (type == 0) {
    NV* temp = new NVBC[this->nNVBC - 1];
    for (int i = 0; i < this->nNVBC - 1; i++) {
      temp[i] = this->DSNV[0][i + 1];
    }
    delete[] this->DSNV[0];
    this->nNVBC = this->nNVBC - 1;

    this->DSNV[0] = new NVBC[this->nNVBC];
    for (int i = 0; i < this->nNVBC; i++) {
      this->DSNV[0][i] = temp[i];
    }

    delete[] temp;
  } else {
    NV* temp = new NVHD[this->nNVHD - 1];
    for (int i = 0; i < this->nNVHD - 1; i++) {
      temp[i] = this->DSNV[1][i + 1];
    }
    delete[] this->DSNV[1];
    this->nNVHD = this->nNVHD - 1;

    this->DSNV[1] = new NVHD[this->nNVHD];
    for (int i = 0; i < this->nNVHD; i++) {
      this->DSNV[1][i] = temp[i];
    }

    delete[] temp;
  }
}

void QLNV::deleteTail(int type) {
  if (type == 0) {
    NV* temp = new NVBC[this->nNVBC - 1];
    for (int i = 0; i < this->nNVBC - 1; i++) {
      temp[i] = this->DSNV[0][i];
    }
    delete[] this->DSNV[0];
    this->nNVBC = this->nNVBC - 1;

    this->DSNV[0] = new NVBC[this->nNVBC];
    for (int i = 0; i < this->nNVBC; i++) {
      this->DSNV[0][i] = temp[i];
    }
    delete[] temp;
  } else {
    NV* temp = new NVHD[this->nNVHD - 1];
    for (int i = 0; i < this->nNVHD - 1; i++) {
      temp[i] = this->DSNV[1][i];
    }
    delete[] this->DSNV[1];
    this->nNVHD = this->nNVHD - 1;

    this->DSNV[1] = new NVHD[this->nNVHD];
    for (int i = 0; i < this->nNVHD; i++) {
      this->DSNV[1][i] = temp[i];
    }
    delete[] temp;
  }
}

void QLNV::deleteIndex(int index, int type) {
  if (type == 0) {
    if (index < 0 || index >= this->nNVBC) {
      cout << "Index out of range";
      exit(1);
    }

    NV* temp = new NVBC[this->nNVBC - 1];
    for (int i = 0; i < index; i++) {
      temp[i] = this->DSNV[0][i];
    }
    for (int i = index + 1; i < this->nNVBC; i++) {
      temp[i - 1] = this->DSNV[0][i]; 
    }
    this->nNVBC = this->nNVBC - 1;
    delete[] this->DSNV[0];

    this->DSNV[0] = new NVBC[this->nNVBC];
    for (int i = 0; i < this->nNVBC; i++) {
      this->DSNV[0][i] = temp[i];
    }

    delete[] temp;
  } else {
    if (index < 0 || index >= this->nNVHD) {
      cout << "Index out of range";
      exit(1);
    }

    NV* temp = new NVHD[this->nNVHD - 1];
    for (int i = 0; i < index; i++) {
      temp[i] = this->DSNV[1][i];
    }
    for (int i = index + 1; i < this->nNVHD; i++) {
      temp[i - 1] = this->DSNV[1][i]; 
    }
    this->nNVHD = this->nNVHD - 1;
    delete[] this->DSNV[1];

    this->DSNV[1] = new NVHD[this->nNVHD];
    for (int i = 0; i < this->nNVHD; i++) {
      this->DSNV[1][i] = temp[i];
    }

    delete[] temp;
  }
}

int QLNV::indexOf(int IDNV, int type) {
  if (type == 0) {
    int index = -1;
    for (int i = 0; i < this->nNVBC; i++) {
      if (this->DSNV[0][i].getIDNV() == IDNV) {
        index = i;
        break;
      }
    }
    return index;
  } else {
    int index = -1;
    for (int i = 0; i < this->nNVHD; i++) {
      if (this->DSNV[1][i].getIDNV() == IDNV) {
        index = i;
        break;
      }
    }
  }
}

void QLNV::search(string NameNV, int type) {
  cout << "Search result: " << endl;
  if (type == 0){
    for (int i = 0; i < this->nNVBC; i++) {
      if (this->DSNV[0][i].getNameNV().find(NameNV) != -1) {
        cout << this->DSNV[0][i];
      }
    }
  } else {
    for (int i = 0; i < this->nNVHD; i++) {
      if (this->DSNV[1][i].getNameNV().find(NameNV) != -1) {
        cout << this->DSNV[1][i];
      }
    }
  }
}

void QLNV::swap(int index1, int index2, int type) {
  if (type == 0) { 
    NV temp = this->DSNV[0][index1];
    this->DSNV[0][index1] = this->DSNV[0][index2];
    this->DSNV[0][index2] = temp;
  } else {
    NV temp = this->DSNV[1][index1];
    this->DSNV[1][index1] = this->DSNV[1][index2];
    this->DSNV[1][index2] = temp;
  }
}

void QLNV::sort(bool (*compare)(double, double), int type) {
  if (type == 0){
    for (int i = 0; i < this->nNVBC - 1; i++) {
      cout << i << endl;
      for (int j = 0; j < this->nNVBC - i - 1; j++) {
        cout << j << endl;
        if (compare(this->DSNV[0][i].getSalary(), this->DSNV[0][j].getSalary())) {
          this->swap(i, j, 0);
        }
      }
    }
  } else {
     for (int i = 0; i < this->nNVHD - 1; i++) {
      cout << i << endl;
      for (int j = 0; j < this->nNVHD - i - 1; j++) {
        cout << j << endl;
        if (compare(this->DSNV[1][i].getSalary(), this->DSNV[1][j].getSalary())) {
          this->swap(i, j, 1);
        }
      }
    }
  }
}
