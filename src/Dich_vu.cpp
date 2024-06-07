#include <iostream>
#include <string>
#include <iomanip>
#include "DICHVU.h"
#include "BOSUNG.h"

using namespace std;

//Khởi tạo dịch vụ
void InitDV(DSDV& dsdv){
    dsdv = NULL;
    dsdv->TongtienDV = 0;
}
//Kiểm tra danh sách dịch vụ có trống không?
int emptyDV(DSDV S) {
    return S == NULL;
}
//Tạo node dịch vụ
DVNODE makenodeDV(Dich_vu T1) {
    DVNODE node = new NODEDV;
    node->DV = T1;
    node->nextDV = NULL;
    return node;
}
//Tiềm kiếm dịch vụ theo tên DV
DVNODE FindDV(DSDV S, string name) {
    DVNODE p = S;
    while (p != NULL) {
        if(p->DV.Ten_DV == name){
            return p;
        }
        p = p->nextDV;
    }
    return NULL;
}
//Xóa dịch vụ khỏi danh sách
void DeleteDV(DSDV& S, string name) {
    if (emptyDV(S)) {
        cout << "Danh Sach Rong" << endl;
        return;
    }
    DVNODE P = FindDV(S, name);
    if (P == NULL) {
        cout << "Khong co dich vu: " << name << " trong danh sach" << endl;
        return;
    }

    if (S == P) {
        S = S->nextDV;
        delete P;
    }
    else {
        DVNODE R = S;
        while (R->nextDV != P) R = R->nextDV;
        R->nextDV = P->nextDV;
        delete P;
    }
}
//Thêm dịch vụ
void InsertDV(DSDV &dsdv, Dich_vu DV) {
    DVNODE P = new NODEDV;
    P->DV = DV;
    P->nextDV = NULL;
    if (dsdv == NULL || dsdv->DV.Ten_DV >= P->DV.Ten_DV) {
        P->nextDV = dsdv;
        dsdv = P;
    } else {
        DVNODE Q = dsdv;
        while (Q->nextDV != NULL && Q->nextDV->DV.Ten_DV < Q->DV.Ten_DV) {
            Q = Q->nextDV;
        }
        P->nextDV = Q->nextDV;
        Q->nextDV = P;
    }
}
//Sửa đổi thông tin dịch vụ.
void FixDV(DSDV& S, string name, long newPrice) {
    if (emptyDV(S)) {
        cout << "Danh Sach Rong" << endl;
        return;
    }
    DVNODE p = FindDV(S, name);
    if (p == NULL) {
        cout << "Khong co dich vu: " << name << " trong danh sach" << endl;
        return;
    }
    p->DV.Gia_DV = newPrice;
    cout << "Da thay doi gia dich vu." << endl;
}
//Nhập dịch vụ và thêm dịch vụ
void NhapDichVu(DSDV& S) {
    int x = 1;
    while (x == 1) {
        cin.ignore();
        Dich_vu DV;
        cout << "Nhap ten dich vu: ";
        getline(cin, DV.Ten_DV);
        cout << "Nhap gia dich vu: ";
        cin >> DV.Gia_DV;
        InsertDV(S, DV);
        cout << "Ban co muon nhap tiep khong (0. Khong, 1. Nhap tiep )" << endl;
        cin >> x;
        while (x != 1 && x != 0) {
            cout << "Nhap lai: ";
            cin >> x;
        }
    }
}
//Hiển thị danh sách dịch vụ
void DisplayDV(DSDV S) {
    cout << left << setw(20) << "Ten dich vu" 
         << setw(20) << "Gia dich vu" 
         << endl;
    DVNODE temp = S;
    while (temp != nullptr) {
        cout << left << setw(25) << temp->DV.Ten_DV
             << setw(10) << temp->DV.Gia_DV
             << endl;
        temp = temp->nextDV;
    }
}
//Tính tổng tiền dịch vụ bệnh nhân sử dụng
long SumDV(DSDV S){
	long a = 0;
	DSDV p = S;
	while(p != NULL){
		a += p->DV.Gia_DV;
		p = p->nextDV;
	}
	return a;
}
//In dịch vụ theo danh sách
void printfDV(DSDV S) {
     if(S == NULL){
        cout<<"Danh sach dich vu rong"<<endl;
        return;
    }
    S->TongtienDV = SumDV(S);
    int n = 0;
    DVNODE P = S;
    while (P != NULL) {
        P = P->nextDV;
        n++;
    }
    DVNODE R = S;
    string arr[100][3];
    arr[0][0] = "STT";
    arr[0][1] = "Ten";
    arr[0][2] = "Thanh tien";
    for (int i = 1; i <= n; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = R->DV.Ten_DV;
        arr[i][2] = to_string(R->DV.Gia_DV);
        R = R->nextDV;
    }
    // Printing the array
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k < 3; k++) {
            cout << arr[j][k] << "\t";
        }
        cout << endl;
    }
    cout << "Tong tien dich vu la: " << SumDV(S) << endl;
}
//Chọn dịch vụ
Dich_vu Select_Service(DSDV dsdv){
    DisplayDV(dsdv);
    cout << "Nhap ten dich vu ban muon chon: ";
    string name;
    cin >> name;
    DVNODE k = FindDV(dsdv, name);
    return k->DV;
}