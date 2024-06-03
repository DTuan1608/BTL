#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

int main() {
    DSBN dsbn = NULL;
    DSDV dsdv = NULL;
    DSThuoc T = NULL;
    DSBS dsbs = NULL;
    THUOC T1 = {"Hoang Anh", 141, 1, 1};
    THUOC T2 = {"Hoang Anh1", 142, 2, 1};
    THUOC T3 = {"Hoang Anh2", 143, 1, 2};
    THUOC T4 = {"Hoang Anh3", 144, 2, 1};
    THUOC T5 = {"Hoang Anh4", 145, 1, 2};
    THUOC T6 = {"Hoang Anh5", 146, 2, 1};
    Bac_si A = {"Hoang Anh","Bac si",10000};
    Bac_si B = {"Tuan","Bac si",10000};
    Bac_si C = {"An" ,"Bac si",10000};
    Bac_si D = {"Can","Bac si",10000};
    Dich_vu DV1 = {"An", 10000};
    Dich_vu DV2 = {"An1", 20000};
    Dich_vu DV3 = {"An2", 20000};
    Dich_vu DV4 = {"An3", 20000};
    InsertBSS(dsbs,A);
    InsertBSS(dsbs,B);
    InsertBSS(dsbs,C);
    InsertBSS(dsbs,D);
    ArrangeT(T, T1);
    ArrangeT(T, T2);
    ArrangeT(T, T3);
    ArrangeT(T, T4);
    ArrangeT(T, T5);
    ArrangeT(T, T6);
    ArrangeDV(dsdv, DV1);
    ArrangeDV(dsdv, DV2);
    ArrangeDV(dsdv, DV3);
    ArrangeDV(dsdv, DV4);
    InitBN(dsbn);
    Dapung(dsbn, T, dsdv, dsbs);
    return 0;
}