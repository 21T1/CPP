/*
Viet chuong trinh thuc hien 1 so phuong thuc xu ly ngay thang
1. Kiem tra nam nhuan
2. Tra ve so ngay trong thang
3. So ngay den thoi diem hien tai
4. Khoang cach giua 2 ngay bat ky
5. Chuyen ngay qua thu
*/

#include <iostream>
#include <cmath>
using namespace std;

struct NgayThang {
	int Ngay;
	int Thang;
	int Nam;
}NT, HT;

int Nhuan(int Nam) {
	if ((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0))
		return 1;
	return 0;
}
int soNgayTrongThang(int Thang,int Nam) {
	switch (Thang) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:	
		return 28 + Nhuan(Nam); break;
	default:
		return -1;
	}
}
void nhapThang(NgayThang &NT){
	do {
		cout << "Nhap thang: "; cin >> NT.Thang;
	} while (NT.Thang <= 0 || NT.Thang > 12);
}
void nhapNam(NgayThang &NT){
	do {
		cout << "Nhap nam: "; cin >> NT.Nam;
	} while (NT.Nam <= 0);
}
void nhapNT(NgayThang &NT) {
	do {
		cout << "Nhap ngay: "; cin >> NT.Ngay;
		nhapThang(NT);
		nhapNam(NT);
	} while (NT.Ngay <= 0 || NT.Ngay > soNgayTrongThang(NT.Thang,NT.Nam));
}
void xuatNT(NgayThang NT){
	cout<<NT.Ngay<<"/"<<NT.Thang<<"/"<<NT.Nam<<" ";
}
int soNgay(NgayThang HT){
	int s=0;
	for(int i=1;i<HT.Nam;i++)
		s+=365+Nhuan(i);
	for(int i=1;i<HT.Thang;i++)
		s+=soNgayTrongThang(i,HT.Nam);
	s+=(HT.Ngay-1);
	return s;
}
void khoangCach(){
	nhapNT(NT);
	nhapNT(HT);
	xuatNT(NT);
	cout<<"- ";
	xuatNT(HT);
	cout<<": "<<abs(soNgay(HT) - soNgay(NT))<<" ngay"<<endl;
}
void chuyenDoi(int n){
	xuatNT(HT);
	cout<<"la ";
	switch(n%7){
		case 0: cout<<"Thu Bay"; break;
		case 1: cout<<"Chu Nhat"; break;
		case 2: cout<<"Thu Hai"; break;
		case 3: cout<<"Thu Ba"; break;
		case 4: cout<<"Thu Tu"; break;
		case 5: cout<<"Thu Nam"; break;
		case 6: cout<<"Thu Sau"; break;
		default: break;
	}
	cout<<endl;
}
void chuyenNgaySangThu(){
	NT = {1,1,2000};
	nhapNT(HT);
	chuyenDoi(abs(soNgay(HT)-soNgay(NT)));
}

void Menu() {
	cout << "MOT SO PHUONG THUC XU LI NGAY THANG" << endl;
	cout << "1. Kiem tra nam nhuan" << endl;
	cout << "2. Tra ve so ngay trong thang" << endl;
	cout << "3. So ngay den thoi diem hien tai" << endl;
	cout << "4. Khoang cach giua 2 ngay bat ky" << endl;
	cout << "5. Chuyen ngay qua thu" << endl;
}
void XuLy(int LC) {
	switch (LC) {
	case 1:
		nhapNam(NT);
		cout<<NT.Nam;
		if (Nhuan(NT.Nam)==1)
			cout << " la nam nhuan";
		else
			cout << " khong phai nam nhuan";
		cout << endl;
		break;
	case 2:
		nhapThang(NT);
		if(NT.Thang==2)
			nhapNam(NT);
		cout << "Thang " << NT.Thang << " co " << soNgayTrongThang(NT.Thang,NT.Nam) << " ngay"<< endl;
		break;
	case 3:
		HT = {27,4,2022};
		cout<<"1/1/1 - ";
		xuatNT(HT);
		cout<<": "<<soNgay(HT)<<" ngay"<<endl; break;
	case 4:
		khoangCach(); break;
	case 5:
		chuyenNgaySangThu(); break;
	case 0: cout<<"Ket thuc chuong trinh";
	default: break;
	}
}
int main() {
	Menu();
	int LC;
	do {
		cout << "Nhap lua chon: "; cin >> LC;
		XuLy(LC);
	} while (LC != 0);
	return 0;
}
