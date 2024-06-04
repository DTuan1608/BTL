#include <iostream>
#include <string>
#include "DICHVU.h"

using namespace std;

void InitDV(DSDV& dsdv){
    dsdv = NULL;
}
int emptyDV(DSDV S) {
    return S == NULL;
}

DVNODE makenodeDV(Dich_vu T1) {
    DVNODE node = new NODEDV;
    node->DV = T1;
    node->nextDV = NULL;
    return node;
}

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

void ArrangeDV(DSDV& S, Dich_vu T1) {
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

void NhapDichVu(DSDV& S) {
    int x = 1;
    while (x == 1) {
        cin.ignore();
        Dich_vu DV;
        cout << "Nhap ten dich vu: ";
        getline(cin, DV.Ten_DV);
        cout << "Nhap gia dich vu: ";
        cin >> DV.Gia_DV;
        ArrangeDV(S, DV);
        cout << "0. Khong, 1. Nhap tiep: ";
        cin >> x;
        while (x != 1 && x != 0) {
            cout << "Nhap lai: ";
            cin >> x;
        }
    }
}

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