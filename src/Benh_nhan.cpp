
//Nguyễn Nhật Hoàng Anh
#include "BENHNHAN.h"
#include "BOSUNG.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

void InitBN(DSBN &dsbn){
    dsbn = NULL;
}

int IsEmpty(DSBN dsbn) {
    return (dsbn == NULL);
}

// Tao ra 1 NODE moi bang cach nhap tu ban phim vao
Benh_nhan Create(DSThuoc S, DSDV dsdv) {
    Benh_nhan A;
    cout << "Ho va ten:";
    cin.ignore();
    getline(cin, A.Ho_tenBN);
    cout << "Tuoi:";        cin >> A.Tuoi;
    cout << "Gioi tinh:";   cin >> A.Gioi_tinh;
    cin.ignore();
    cout << "Que quan: ";   getline(cin, A.Que);
    cout << "So CCCD: ";    cin >> A.CCCD;
    cout << "SDT:";         cin >> A.SDT;
    cout << "BHYT (1. Co, 0. Khong):" << endl;
    cin >> A.Bao_hiem;
    NhapDV(A, S, dsdv);
    NhapThuoc(A, S, dsdv);
    return A;
}
void NhapThuoc(Benh_nhan A, DSThuoc S,DSDV dsdv){    
    int x;
    cout << "Co mua thuoc hay khong ? \n";
    cout << "0. Khong\n1. Co lay thuoc\n" ; cin >> x;
    while(x !=1 &&x != 0){
    	cout << "Nhap lai: "; cin >> x;
	}
	if(x==1 ){
	    NhapT(A.Hoa_don->HD.TBN);
	}
    else{
		A.Hoa_don->HD.TBN = NULL;
	}
    return;
}

void NhapDV(Benh_nhan A, DSThuoc T, DSDV dsdv){    
    DisplayDV(dsdv);
    cout << "Chon dich vu ban muon \n";
    NhapDichVu(A.Hoa_don->HD.DVBN);
    cout << "Ban co muon chon dich vu nao khac khong?" << endl;
    cout << "Chon 1. Co, 0. Khong" << endl;
    int x; cin >> x;
    while(x != 1 && x != 0){
    cout << "Nhap lai: "; cin >> x;
    }
    if(x==1 ){
        NhapT(A.Hoa_don->HD.TBN);
    }
    else{
        A.Hoa_don->HD.TBN = NULL;
    }
    return;
}

void InsertBN(DSBN& dsbn, DSThuoc S,DSDV dsdv) {
    int check;
    do{
        cout << "\t" << "Nhap thong tin benh nhan" << endl;
        BNNODE P = new NODEBN;
        P->BN = Create(S,dsdv);
        P->nextBN = dsbn;
        dsbn = P;
        cout << "Ban co muon nhap benh nhan tiep? (1: Co, 0: Khong): ";
        cin >> check;
        cin.ignore();
    } while (check);    
}

// Tim benh nhan voi so cccd cho truoc 
BNNODE FindBN(DSBN dsbn, string cccd) {
    BNNODE R = dsbn;
    while (R != NULL) {
        if (R->BN.CCCD == cccd) return R;
        R = R->nextBN;
    }
    cout << "Khong tim thay BN" << endl;
    return NULL;
}

// Tim BN o truoc benh nhan voi so cccd cho truoc 
BNNODE FindBNBefore(DSBN dsbn, string cccd) {
    BNNODE R = dsbn;
    while (R != NULL) {
        if (R->nextBN->BN.CCCD == cccd) return R;
        R = R->nextBN;
    }
    cout << "Khong tim thay BN" << endl;
    return NULL;
}

// Xoa 1 BN voi so cccd cho truoc 
void DeleteBN(DSBN& dsbn, string cccd) {
    BNNODE P = FindBNBefore(dsbn, cccd);
    BNNODE Q = FindBN(dsbn, cccd);
    if (P == NULL) return;
    if (dsbn == Q) dsbn = dsbn->nextBN;
    P->nextBN = Q->nextBN;
    delete Q;
}

// Sua thong tin benh nhan 
void FixBN(DSBN& dsbn, string cccd) {
    BNNODE P = FindBN(dsbn, cccd);
    
    if (P != NULL) {
        cout << "\n\tNhap thong tin moi cho benh nhan" << endl;
        cout << "Ho va ten: ";
        getline(cin, P->BN.Ho_tenBN);
        cout << "Tuoi: ";
        cin >> P->BN.Tuoi;
        cout << "Gioi tinh: ";
        cin >> P->BN.Gioi_tinh; 
        cout << "Que: ";
        getline(cin, P->BN.Que);
        cout << "CCCD: ";
        cin >> P->BN.CCCD;
        cout << "SDT:"; cin >> P->BN.SDT;
        cout << "BHYT (1. Co, 0. Khong): ";
        cin >> P->BN.Bao_hiem;
        cout << "Thong tin thay doi thanh cong!" << endl;
        cin.ignore();
    } else {
        return; 
    }
}

// sap xep BN 
void ArrangeBN(DSBN& dsbn) {
    if (dsbn == NULL) return;
    
    int check;
    do {
        check = 0;
        BNNODE mid = dsbn;
        BNNODE last = NULL;
        BNNODE next = dsbn->nextBN;

        while (next != NULL) {
            if (mid->BN.Ho_tenBN > next->BN.Ho_tenBN) {
                if (last == NULL) {
                    dsbn = next;
                } else {
                    last->nextBN = next;
                }
                mid->nextBN = next->nextBN;
                next->nextBN = mid;
                check = 1;
                mid = next;
                next = mid->nextBN;
            } else {
                last = mid;
                mid = next;
                next = next->nextBN;
            }
        }
    } while (check);
}

void printfBN(DSBN S) {
    cout << "\n\tThong tin benh nhan:" << endl;
    if (S == NULL) {
        cout << "Danh sach benh nhan rong." << endl;
        return;
    }
    
    DSBN R = S;
    const int numRows = 3;
    const int numCols = 2;

    while (R != NULL) {
        string arr[numRows][numCols];
        arr[0][0] = "Ho ten: " + R->BN.Ho_tenBN;
        arr[0][1] = "Gioi tinh: " + R->BN.Gioi_tinh;
        arr[1][0] = "Tuoi: " + to_string(R->BN.Tuoi);
        arr[1][1] = "CCCD: " + R->BN.CCCD;
        arr[2][0] = "SDT: " + R->BN.SDT;
        arr[2][1] = "Que: " + R->BN.Que;

        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numCols; k++) {
                cout << arr[j][k] << "\t";
            }
            cout << endl;
        }
        cout << "Bao hiem: " << R->BN.Bao_hiem << endl;
        cout << "\tDanh Sach Dich Vu\n";
        printfDV(R->BN.Hoa_don->HD.DVBN);
        if(R->BN.Hoa_don->HD.TBN == NULL) {
           cout << "Danh sach thuoc cua benh nhan rong.";
        }
        else printfT(R->BN.Hoa_don->HD.TBN);
        cout << "Tong vien phi: " << SumBN(R->BN) << endl;
        if(R->BN.Bao_hiem == 1){
        	cout << "Phai tra: " << (SumBN(R->BN)*60)/100;
		}else{
			cout << "Phai tra: " << SumBN(R->BN);
		}
        R = R->nextBN;
    }
}
Dich_vu Select_Service(DSDV dsdv){
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
}
