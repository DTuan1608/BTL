
#ifndef BOSUNG_H
#define BOSUNG_H

#include <string>
#include <iostream>
#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
using namespace std;
// Cấu trúc dữ liệu về viện phí

struct Benh_nhan;
struct NODEBN;
typedef NODEBN* BNNODE;
typedef NODEBN* DSBN;

struct Bac_si;
struct NODEBS;
typedef NODEBS* BSNODE; 
typedef NODEBS* DSBS; 

struct Hoa_don{
    DSDV DVBN;
    DSThuoc TBN;
};
struct NODEHD{
    Hoa_don HD;
    NODEHD* nextHD;
};
typedef NODEHD* DSHD;
typedef NODEHD* HDNODE;

//Them
long SumBN(Benh_nhan BN);
long SumDV(DSDV dsdv);
long tonggiaT(THUOC S);
long sumT(DSThuoc S);
void printfDV(DSDV dsdv);
void printfT(DSThuoc S);
//void printfBN(DSBN S);
void SuaxoaBN(DSBN &S);
void Hienthi();//Các dánh sách quan lý
void Hienthi1();//Các thao tác đối với danh sách
void Hienthi2();
void Hienthi3();
void Dapung(DSBN& dsbn, DSThuoc S, DSDV dsdv, DSBS dsbs);
#endif
