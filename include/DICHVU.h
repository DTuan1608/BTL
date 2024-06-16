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
DVNODE FindDV(DSDV S, string name);
void DeleteDV(DSDV& S, string name);
void InsertDV(DSDV &dsdv, Dich_vu DV);
void FixDV(DSDV& S, DVNODE P,long newPrice);
void NhapDichVu(DSDV& S);
long SumDV(DSDV S);
void printfDV(DSDV S);
void DisplayDV(DSDV S);
Dich_vu Select_Service(DSDV dsdv);
#endif 