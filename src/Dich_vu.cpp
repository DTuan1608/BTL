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
//Tìm kiếm dịch vụ theo ma DV
DVNODE FindDV(DSDV S, string Ma) {
    DVNODE p = S;
    while (p != NULL) {
        if(p->DV.Ma_DV == Ma){
            return p;
        }
        p = p->nextDV;
    }
    return NULL;
}
//Xóa dịch vụ khỏi danh sách
void DeleteDV(DSDV& S, string Ma) {
    if (emptyDV(S)) {
        cout << "Danh Sach Rong" << endl;
        return;
    }
    DVNODE P = FindDV(S, Ma);
    if (P == NULL) {
        cout << "Khong co dich vu: " << Ma << " trong danh sach" << endl;
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
void FixDV(DSDV& S, DVNODE P, long newPrice) {
    if (emptyDV(S) || P == NULL ) {
        cout << "Khong the thay doi thong tin" << endl;
        return;
    }
    P->DV.Gia_DV = newPrice;
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
        cout << "Ma dich vu: ";
        cin >> DV.Ma_DV;
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
    cout << left << setw(30) << "Ten dich vu" 
         << setw(15) << "Ma dich vu" 
         << setw(10) << "Gia dich vu" 
         << endl;
    DVNODE temp = S;
    while (temp != nullptr) {
        cout << left << setw(30) << temp->DV.Ten_DV
             << setw(15) << temp->DV.Ma_DV
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
    if (emptyDV(S)) {
        cout << "Danh sach dich vu rong" << endl;
        return;
    }
    int n = 0;
    DVNODE P = S;
    while (P != nullptr) {
        P = P->nextDV;
        n++;
    }
    string arr[100][4]; 
    arr[0][0] = "STT";
    arr[0][1] = "Ten";
    arr[0][2] = "Ma";
    arr[0][3] = "Thanh tien";
    DVNODE R = S;
    for (int i = 1; i <= n; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = R->DV.Ten_DV;
        arr[i][2] = R->DV.Ma_DV;
        arr[i][3] = to_string(R->DV.Gia_DV);
        R = R->nextDV;
    }
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k < 4; k++) {
            cout << setw(30) << left << arr[j][k];
        }
        cout << endl;
    }
    cout << "Tong tien dich vu la: " << SumDV(S) << endl;
}
void DeleteDV1(DSDV dsdv){
    DisplayDV(dsdv);
    int x;
    DVNODE Dichvu;
    string name;
    do{
        while(true){
            cout << "Nhap ma dich vu ban muon xoa." << endl; 
            cin >> name;
            Dichvu = FindDV(dsdv, name);
            if(Dichvu != NULL){
                cout << "Ban se sua dich vu sau: " << Dichvu->DV.Ten_DV << " co gia " << Dichvu->DV.Gia_DV << endl;
                break;
            }
            else {
                cout << "Dich vu ban muon sua khong co, moi ban nhap lai. " << endl;
                continue;
            }
        }
        DeleteDV(dsdv, name);
        cout << "Da xoa thanh cong dich vu co ma: " << name << endl;
        cout << "Ban co muon xoa dich vu tiep khong?";
        cout << "( 1. Co , 0.Khong)" << endl;
        cin >> x;
    }while(x);
}

void FixDV1(DSDV dsdv) {
    DisplayDV(dsdv);
    int x;
    DVNODE Dichvu;
    long gia_moi;
    do{
        while(true){
            cout << "Nhap ma dich vu ban muon sua." << endl; 
            string name;
            cin >> name;
            Dichvu = FindDV(dsdv, name);
            if(Dichvu != NULL){
                cout << "Ban se sua dich vu sau: " << Dichvu->DV.Ten_DV << " co gia " << Dichvu->DV.Gia_DV << endl;
                cout << "Gia moi cua dich vu: ";
                cin >> gia_moi;
                FixDV(dsdv, Dichvu, gia_moi);
                break;
            }
            else {
                cout << "Dich vu ban muon sua khong co, moi ban nhap lai. " << endl;
                continue;
            }
        }
        cout << "Ban co muon sua dich vu tiep khong?";
        cout << "( 1. Co , 0.Khong)" << endl;
        cin >> x;
    }while(x);
}