#ifndef DICHVU_H
#define DICHVU_H

#include <string>
//#include "BOSUNG.h"

using namespace std;

struct Dich_vu {
    string Ten_DV;
    string Ma_DV;
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
DVNODE FindDV(DSDV S, string Ma);
void DeleteDV(DSDV& S, string Ma);
void InsertDV(DSDV &dsdv, Dich_vu DV);
void FixDV(DSDV& S, DVNODE P,long newPrice);
void NhapDichVu(DSDV& S);
long SumDV(DSDV S);
void printfDV(DSDV S);
void DisplayDV(DSDV S);
void FixDV1(DSDV dsdv);
void DeleteDV1(DSDV dsdv);
#endif 