//Dương Đức Tuấn
#include <iostream>
#include <string>
#include <iomanip>
#include "BACSI.h"

using namespace std;

//Dữ liệu về bác sĩ
void InitBS(DSBS &H) {
    H = NULL;
}
// Thêm Bác sĩ tạo danh sách
void InsertBSS(DSBS &H, Bac_si K) {
    BSNODE Q = new NODEBS;
    Q->BS = K;
    Q->nextBS = NULL;
    if (H == NULL || H->BS.Ho_tenBS >= Q->BS.Ho_tenBS) {
        Q->nextBS = H;
        H = Q;
    } else {
        BSNODE P = H;
        while (P->nextBS != NULL && P->nextBS->BS.Ho_tenBS < Q->BS.Ho_tenBS) {
            P = P->nextBS;
        }
        Q->nextBS = P->nextBS;
        P->nextBS = Q;
    }
}
//Thêm bác sĩ bằng cách nhập và sắp xếp bác sĩ
void InsertBS(DSBS &H) {
    int check;
    do{
        Bac_si k;
        cin.ignore();
        cout << "\tNhap thong tin bac si can them nhu sau:" << endl;
        cout << "Ho ten BS: ";
        getline(cin, k.Ho_tenBS);
        cout << "Chuc vu: ";
        getline(cin, k.Chuc_vu);
        cout << "Gia kham: ";
        cin >> k.Gia_kham;
        cout << "Ma BS: ";
        cin >> k.MaBS;
        cin.ignore();
        BSNODE Q = new NODEBS;
        Q->BS = k;
        Q->nextBS = NULL;

        if (H == NULL || H->BS.Ho_tenBS >= Q->BS.Ho_tenBS) {
            Q->nextBS = H;
            H = Q;
        } else {
            BSNODE P = H;
            while (P->nextBS != NULL && P->nextBS->BS.Ho_tenBS < Q->BS.Ho_tenBS) {
                P = P->nextBS;
            }
             Q->nextBS = P->nextBS;
            P->nextBS = Q;
        }
        cout<<"Tiep tuc nhap tiep khong:(1.Co , 0. Khong)"<<endl;
        cin >> check;
    }while(check);
}
//Xóa bác sĩ không còn công tác
void DeleteBS(DSBS &H, string hotenBS) {
    if (H == NULL) {
        cout << "Khong co gi de xoa:" << endl;
        return;
    } else if (H->BS.Ho_tenBS == hotenBS) {
        BSNODE temp = H;
        H = H->nextBS;
        delete temp;
        return;
    } else {
        BSNODE Q = H;
        while (Q->nextBS != NULL && Q->nextBS->BS.Ho_tenBS != hotenBS) {
            Q = Q->nextBS;
        }
        if (Q->nextBS != NULL) {
            BSNODE temp = Q->nextBS;
            Q->nextBS = temp->nextBS;
            delete temp;
        }
    }
}
//Tìm kiếm bác sĩ theo tên
BSNODE FINDBS(DSBS H, string hotenBS) {
    BSNODE Q = H;
    while (Q != NULL) {
        if (Q->BS.Ho_tenBS == hotenBS) {
            return Q;
        }
        Q = Q->nextBS;
    }
    return NULL;
}
//Tìm kiếm bác sĩ theo mã
BSNODE FINDBS1(DSBS H, string maBS) {
    BSNODE Q = H;
    while (Q != NULL) {
        if (Q->BS.MaBS == maBS) {
            return Q;
        }
        Q = Q->nextBS;
    }
    return NULL;
}
//Chỉnh sửa bác sĩ
void FixBS(DSBS& dsbs, string maBS) {
    BSNODE P = FINDBS1(dsbs, maBS);
    if (P != NULL) {
        cin.ignore();
        cout << "\n\tNhap thong tin moi cho bac si" << endl;
        cout << "Ho va ten: ";
        getline(cin, P->BS.Ho_tenBS);
        cout << "Nhap chuc vu: ";
        getline(cin,P->BS.Chuc_vu);
        cout << "Nhap ma BS: ";
        cin >> P->BS.MaBS;
        cout << "Thong tin thay doi thanh cong!" << endl;
        cin.ignore();
    } else {
        return; 
    }
}
//In bác sĩ ra màn hình
void PrintBS(DSBS H) {
    if (H == nullptr) {
        cout << "Khong co gi de in ra man hinh" << endl;
    } else {
        BSNODE Q = H;
        cout << left << setw(20) << "Ho ten BS"
             << setw(20) << "Chuc vu"
             << setw(15) << "Gia kham"
             << setw(15) << "Ma BS"
             << endl;
        
        while (Q != nullptr) {
            cout << left << setw(20) << Q->BS.Ho_tenBS
                 << setw(20) << Q->BS.Chuc_vu
                 << setw(15) << Q->BS.Gia_kham
                 << Q->BS.MaBS << endl;
            Q = Q->nextBS;
        }
    }
}