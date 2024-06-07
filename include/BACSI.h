#ifndef BACSI_H
#define BACSI_H

#include <string>
#include "BENHNHAN.h"
#include "DICHVU.h"
#include "THUOC.h"
//#include "BOSUNG.h"

// Cấu trúc dữ liệu về bác sĩ
struct Bac_si {
    string Ho_tenBS;
    string Chuc_vu;
    long Gia_kham;
};

struct NODEBS {
    Bac_si BS;
    NODEBS* nextBS; 
};

typedef NODEBS* BSNODE; 
typedef NODEBS* DSBS; 


// Khai báo nguyên mẫu hàm BS
void InitBS(DSBS& H);
void InsertBSS(DSBS &H, Bac_si K);
void InsertBS(DSBS &H);
void DeleteBS(DSBS &H, string hotenBS);
BSNODE FINDBS(DSBS H, string hotenBS);
void FixBS(DSBS &H, BSNODE BSBF, BSNODE BSAF) ;
void PrintBS(DSBS &H);
#endif 