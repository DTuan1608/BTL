
//Hà Hữu An
#include "THUOC.h"

using namespace std;

void InitT(DSThuoc &T){
    T = NULL;
}
int emptyT(DSThuoc T) {
    return T == NULL;
}

NodeT makenodeT(THUOC T1) {
    NodeT node = new NODET;
    node->T = T1;
    node->nextT = NULL;
    return node;
}

NodeT FindT(DSThuoc& T, int Ma_thuoc) {
    NodeT p = T;
    while (p != NULL && p->T.Ma_thuoc != Ma_thuoc) {
        p = p->nextT;
    }
    if (p == NULL) {
        cout << "Khong co thuoc voi ma thuoc: " << Ma_thuoc << " trong danh sach" << endl;
        return NULL;
    } else {
        return p;
    }
}

void DeleteT(DSThuoc& T, int Ma_thuoc) {
    if (emptyT(T)) {
        cout << "Danh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT P = FindT(T, Ma_thuoc);
    if (P == NULL) return;

    if (T == P) {
        T = T->nextT;
        delete P;
    } else {
        NodeT R = T;
        while (R->nextT != P) R = R->nextT;
        R->nextT = P->nextT;
        delete P;
    }
}

void FixT(DSThuoc T, int Ma_thuoc) {
    if (emptyT(T)) {
        cout << "\tDanh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT p = FindT(T, Ma_thuoc);
    if (p == NULL) return;

    long x;
    cout << "Nhap gia thay doi: ";
    cin >> x;
    p->T.Gia_thuoc = x;
    cout << "Da thay doi gia thuoc" << endl;
}

void ArrangeT(DSThuoc& T, THUOC T1) {
    NodeT P = makenodeT(T1);
    if (emptyT(T)) {
        T = P;
    } else {
        if (P->T.Ten_thuoc[0] <= 'A') {
            P->nextT = T;
            T = P;
        } else {
            NodeT R = T;
            while (R->nextT != NULL && R->nextT->T.Ten_thuoc[0] < P->T.Ten_thuoc[0])
                R = R->nextT;
            P->nextT = R->nextT;
            R->nextT = P;
        }
    }
}
void Hien_Thi_Thuoc(DSThuoc Thuoc){
    cout << "Ten thuoc: ";      cout << Thuoc->T.Ten_thuoc << endl;
    cout << "Ma thuoc: ";       cout << Thuoc->T.Ma_thuoc << endl;
    cout << "So luong thuoc: "; cout << Thuoc->T.so_luong << endl;
    cout << "Gia thuoc: ";      cout << Thuoc->T.Gia_thuoc << endl;
}

void NhapT(DSThuoc& S) {
    cout << "------------NHAP THUOC-------------\n";
    int x = 1;
    while (x == 1) {
        THUOC T1;
        cout << "Ma thuoc: "; cin >> T1.Ma_thuoc;
        cout << "Ten thuoc: ";
        cin.ignore(); // Xóa b? d?m d? tránh l?i nh?p chu?i
        getline(cin, T1.Ten_thuoc);
        
        cout << "Don gia: "; cin >> T1.Gia_thuoc;
        cout << "So luong: "; cin >> T1.so_luong;
        ArrangeT(S, T1);
        cout << "----------------------\n" << "0.Thoat\n" << "1.Nhap tiep\n";
        cin >> x;
        while (x != 0 && x != 1) {
            cout << "Nhap lai: "; cin >> x;
        }
    }
}
