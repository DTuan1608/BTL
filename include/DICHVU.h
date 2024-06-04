#ifndef DICHVU_H
#define DICHVU_H

#include <string>
//#include "BOSUNG.h"

using namespace std;

struct Dich_vu {
    string Ten_DV;
    long Gia_DV;
};

struct NODEDV { 
    Dich_vu DV;
    long TongtienDV;
    NODEDV* nextDV;
};

typedef NODEDV* DVNODE;
typedef NODEDV* DSDV;


//Khai báo nguyên mẫu hàm dịch vụ
void InitDV(DSDV& dsdv);
int emptyDV(DSDV S);
DVNODE makenodeDV(Dich_vu T1);
void DeleteDV(DSDV& S, string name);
DVNODE FindDV(DSDV S, string name);
void ArrangeDV(DSDV& S, Dich_vu T1);
void InsertDV(DSDV &dsdv, DVNODE P);
void FixDV(DSDV& S, string name, long newPrice);
void NhapDichVu(DSDV& S);
void DisplayDV(DSDV S);
#endif 