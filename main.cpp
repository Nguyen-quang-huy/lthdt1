#pragma once;
#include "QLNV.h"

bool ascending(double a, double b) { 
   return a < b;
}

bool descending(double a, double b) { 
   return a > b;
}

int main() {
  NVBC n1(1, "Le Trong Hoang Minh", 2022, 1, 10, 100, 1, "Chu tich HDQT", 100.0);
  NVHD n2(2, "Nguyen Van Hoang Nhen", 2020, 1, 22, 5, 20);
  NVBC n3(3, "Nguyen Thanh Thyyy", 2021, 2, 12, 50, 3, "Vehicles Security", 5.0);
  NVHD n4(4, "Tran Anh Ho", 2021, 2, 23, 10, 22);
  NVBC n5(5, "Mai Jay Chou", 2022, 1, 05, 40, 4, "Driver of President", 1.0);
  NVHD n6(6, "Hoang Tien Luan", 2018, 5, 12, 6, 15);
  NVBC n7(7, "Nguyen Viet chovbeovkieu", 2021, 1, 10, 30, 4, "Chu be dan", 10.0);

  QLNV q;
  q.insertTail(n1);
  q.insertHead(n2);
  q.insertTail(n3);
  q.insertIndex(n4, 1);
  q.insertTail(n5);
  q.insertHead(n6);
  q.insertIndex(n7, 2);

  q.deleteHead(0);
  q.deleteTail(1);

  q.search("Minh", 0);

  q.sort(ascending, 0);
  cout << q;
}