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
    string Ma_HD;
    int dd, mm, yy;
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
HDNODE Creat_hoa_don(string mahd, int dd, int mm, int yy);
void add_HoaDon_to_Benhnhan(BNNODE BN, HDNODE HD, DSThuoc dst, DSDV dsdv);
HDNODE find_Hoadon(DSHD dshd, string ma_hd);
void addServiceToInvoice(Hoa_don& hd, DVNODE dv);
void addMedicineToInvoice(Hoa_don& hd, NodeT t);
void InsertDSDV_Hoadon(DSHD &dshd, DSDV dsdv);
void InsertDST_Hoadon(DSHD &dshd, DSThuoc dst);
void Hienthi();//Các dánh sách quan lý
void Hienthi1();//Các thao tác đối với danh sách
void Hienthi2();
void Hienthi3();
void Hienthi4();
void Dapung(DSBN& dsbn, DSThuoc S, DSDV dsdv, DSBS dsbs, DSHD dshd);

#endif
