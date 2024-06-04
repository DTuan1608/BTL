#include <iostream>
#include <string>
#include "DICHVU.h"
#include "BOSUNG.h"

using namespace std;

//Khởi tạo dịch vụ
void InitDV(DSDV& dsdv){
    dsdv = NULL;
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
Dich_vu FindDV(DSDV S, string name) {
    DVNODE p = S;
    while (p != NULL) {
        if(p->DV.Ten_DV == name){
            return p->DV;
        }
        p = p->nextDV;
    }
    Dich_vu Q;
    Q.Ten_DV = "";
    Q.Gia_DV = 0;
    return Q;
}
//Xóa dịch vụ khỏi danh sách
void DeleteDV(DSDV& S, string name) {
    if (emptyDV(S)) {
        cout << "Danh Sach Rong" << endl;
        return;
    }
    Dich_vu Q = FindDV(S, name);
    DVNODE P = makenodeDV(Q);
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
//Thêm dịch vụ -> Dành cho hàm nhập
void InsertDV_nhap(DSDV& S, Dich_vu T1) {
    DVNODE P = makenodeDV(T1);
    if (emptyDV(S)) {
        S = P;
    }
    else {
        if (P->DV.Ten_DV[0] <= 'A') {
            P->nextDV = S;
            S = P;
        }
        else {
            DVNODE R = S;
            while (R->nextDV != NULL && R->nextDV->DV.Ten_DV < P->DV.Ten_DV) R = R->nextDV;
            P->nextDV = R->nextDV;
            R->nextDV = P;
        }
    }
}
//Thêm dịch vụ - Dành cho hóa đơn thêm.
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
    Dich_vu Q = FindDV(S, name);
    DVNODE p = makenodeDV(Q);
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
        InsertDV_nhap(S, DV);
        cout << "0. Khong, 1. Nhap tiep: ";
        cin >> x;
        while (x != 1 && x != 0) {
            cout << "Nhap lai: ";
            cin >> x;
        }
    }
}
//Hiển thị danh sách dịch vụ
void DisplayDV(DSDV S) {
    if (emptyDV(S)) {
        cout << "Danh Sach Rong" << endl;
        return;
    }
    DVNODE p = S;
    while (p != NULL) {
        cout << "Ten dich vu: " << p->DV.Ten_DV << ", Gia dich vu: " << p->DV.Gia_DV << endl;
        p = p->nextDV;
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
    DSDV P = S;
    while (P != NULL) {
        P = P->nextDV;
        n++;
    }

    DSDV R = S;
    string arr[100][3];

    // Assigning headers to the array
    arr[0][0] = "STT";
    arr[0][1] = "Ten";
    arr[0][2] = "Thanh tien";

    // Assigning values to the array
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
    cout << "Tong tien: " << S->TongtienDV << endl;
}

//Chọn dịch vụ
/*Dich_vu Select_Service(DSDV dsdv){
    cout << "Chon dich vu: ";
    int x;
    printfDV(dsdv);
    cin >> x;
    switch (x)
    {
    case 1:
        return (dsdv->DV);
        break;
    default:
        break;
    }
}*/