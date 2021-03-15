/**
  * StudentID: 2059005 - Nguyen Tiet Ngoc Chau
  * Created at: 27/11/2020
 **/

#include <iostream>
#include <string>
using namespace std;

struct nhanvien {
  string maso;
  string hoten;
  float luong;
};
typedef struct nhanvien NHANVIEN;

void Nhap(NHANVIEN &);
void Nhap(NHANVIEN[], int&);

void Xuat(NHANVIEN);
void Xuat(NHANVIEN[], int);

float TongLuong(NHANVIEN[], int);

int main() {
  NHANVIEN test[100];
  int n;

  Nhap(test ,n);
  Xuat(test, n);
  cout << "\tTong Luong = "<< TongLuong(test, n) << endl;

  return 0;
}

void Nhap(NHANVIEN &nv) {
  cout << "Nhap Ma So: ";
  cin.ignore();
  getline(cin, nv.maso);

  cout << "Nhap Ho Ten: ";
  getline(cin, nv.hoten);

  cout << "Nhap Luong: ";
  cin >> nv.luong;
}

void Nhap(NHANVIEN a[], int &n) {
  cout << "Nhap so luong phan tu: n = ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    Nhap(a[i]);
  }
}

void Xuat(NHANVIEN nv) {
  cout << "\n----------------------------\n";
  cout << "\t" << "Ma So: " << nv.maso << endl;
  cout << "\t" << "Ho Ten: " << nv.hoten << endl;
  cout << "\t" << "Luong: " << nv.luong << endl;
  cout << "----------------------------\n";
}

void Xuat(NHANVIEN a[], int n) {
  for (int i = 0; i < n; i++) {
    Xuat(a[i]);
  }
}

float TongLuong(NHANVIEN a[], int n) {
  float sum = 0;

  for (int i = 0; i < n; i++) {
    sum += a[i].luong;
  }

  return sum;
}

