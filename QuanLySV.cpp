/*
Viet chuong trinh quan ly sinh vien bao gom cac chuc nang sau:
1. Nhap DS SV.
2. Xuat DS SV.
3. Sap xep DS SV theo ho.
4. Sap xep DS SV theo diem.
5. Tim SV có diem cao nhat.
6. Tim SV có diem thap nhat.
7. Tinh diem trung bình cua SV nam/nu.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int n=0;

struct Ngaythang{
	int Ngay;
	int Thang;
	int Nam;
};
struct SinhVien{
	string HoTen;
	Ngaythang NS;
	int GT;
	float Diem;
}DS[100];

bool kt(SinhVien DS[],int n){
	if(n==0)
		return true;
	for(int i=0;i<n;i++)
		if(DS[i].HoTen==DS[n].HoTen)
			return false;
	return true;
}
void XuatDS(SinhVien DS[],int n){
	cout<<"STT"<<setw(7)<<left<<' '<<setw(20)<<left<<"Ho va ten"<<setw(20)<<right<<"Ngay sinh"<<setw(20)<<right<<"Gioi tinh"<<setw(10)<<right<<"Diem"<<endl;
	cout<<setfill('-');
	cout<<setw(80)<<"-"<<endl;
	cout<<setfill(' ');
	for(int i=0;i<n;i++){
		cout<<setw(3)<<right<<i+1<<setw(7)<<left<<' '<<setw(20)<<left<<DS[i].HoTen<<setw(10)<<right<<DS[i].NS.Ngay<<"/"<<DS[i].NS.Thang<<"/"<<DS[i].NS.Nam<<setw(20)<<right<<DS[i].GT<<setw(10)<<right<<DS[i].Diem<<endl;
	}
}
void NhapDS(SinhVien DS[],int &n){
	do{
		cout<<"Nhap ho ten: "; 
		fflush(stdin); getline(cin,DS[n].HoTen);
	}while(!kt(DS,n));
	cout<<"Nhap ngay sinh: "; cin>>DS[n].NS.Ngay>>DS[n].NS.Thang>>DS[n].NS.Nam;
	cout<<"Nhap gioi tinh: "; cin>>DS[n].GT;
	cout<<"Nhap diem: "; cin>>DS[n].Diem;
	n++;
}

void SapXepTheoHo(SinhVien DS[],int n){
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(DS[i].HoTen>DS[j].HoTen){
				SinhVien SV=DS[i];
				DS[i]=DS[j];
				DS[j]=SV;
			}
}
void SapXepTheoDiem(SinhVien DS[],int n){
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			if(DS[i].Diem>DS[j].Diem){
				SinhVien SV=DS[i];
				DS[i]=DS[j];
				DS[j]=SV;
			}
}
void Max(SinhVien DS[],int n){
	int max=DS[0].Diem;
	for(int i=1;i<n;i++)
		if(max<DS[i].Diem)
			max=DS[i].Diem;
	int count=0;
	for(int i=0;i<n;i++)
		if(DS[i].Diem==max)	
			count++;	
	cout<<"Sinh vien cao diem nhat la: ";
	for(int i=0;i<n;i++)
		if(DS[i].Diem==max){
			cout<<DS[i].HoTen<<;
		}
}
void Min(SinhVien DS[],int n){
	int min=DS[0].Diem;
	for(int i=1;i<n;i++)
		if(min>DS[i].Diem)
			min=DS[i].Diem;
	cout<<"Sinh vien thap diem nhat la: ";
	for(int i=0;i<n;i++)
		if(DS[i].Diem==min)
			cout<<DS[i].HoTen;
	cout<<endl;
}
void DTB(SinhVien DS[],int n){
	int nam=0, nu=0;
	float SNam=0, SNu=0;
	for(int i=0;i<n;i++)
		if(DS[i].GT==1){
			SNam+=DS[i].Diem;
			nam++;
		}else{
			SNu+=DS[i].Diem;
			nu++;
		}
	cout<<"DTB cua SV nam: "<<fixed<<setprecision(1)<<SNam/nam<<endl;
	cout<<"DTB cua SV nu: "<<fixed<<setprecision(1)<<SNu/nu<<endl;
}
void Menu(){
	cout<<"CHUONG TRINH QUAN LY SINH VIEN"<<endl;
	cout<<"";
	cout<<"1. Nhap danh sach sinh vien"<<endl;
	cout<<"2. Xuat danh sach sinh vien"<<endl;
	cout<<"3. Sap xep sinh vien theo ho"<<endl;
	cout<<"4. Sap xep sinh vien theo diem"<<endl;
	cout<<"5. Tim sinh vien diem cao nhat"<<endl;
	cout<<"6. Tim sinh vien diem thap nhat"<<endl;
	cout<<"7. Diem trung binh cua sinh vien nam va nu"<<endl;
}
void XuLyLC(int LC){
	switch(LC){
		case 1:	NhapDS(DS,n); break;
		case 2: XuatDS(DS,n); break;
		case 3: SapXepTheoHo(DS,n);
				XuatDS(DS,n);
		 		break;
		case 4: SapXepTheoDiem(DS,n);
				XuatDS(DS,n);
				break; 
		case 5: Max(DS,n); break; 
		case 6: Min(DS,n); break;
		case 7: DTB(DS,n); break;
		case -1: Menu(); break;
		case 0:
		default: break;
	}
}
int main(){
	Menu();
	int LC=-1;
	while(LC!=0){
		cout<<"Lua chon thao tac: ";
		cin>>LC;
		XuLyLC(LC);
	}
	return 0;
}
