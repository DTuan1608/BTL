#include "BENHNHAN.h"
#include "BACSI.h"
#include "DICHVU.h"
#include "THUOC.h"
#include "BOSUNG.h"

int main() {
    DSHD dshd = NULL;
    DSBN dsbn = NULL;
    DSDV dsdv = NULL;
    DSThuoc T = NULL;
    DSBS dsbs = NULL;
    Bac_si BS1 = {"Nguyen Van A", "Bac si tim mach", 300000};
    Bac_si BS2 = {"Nguyen Van B", "Tien si tim mach", 2000000};
    Bac_si BS3 = {"Nguyen Van C" , "Bac si nha khoa", 400000};
    Bac_si BS4 = {"Nguyen Van D", "Thac si da lieu", 1000000};
    Bac_si BS5 = {"Hoang Van A", "Tien si dinh duong", 2000000};
    Bac_si BS6 = {"Hoang Van B", "Bac si tai mui hong", 200000};
    Bac_si BS7 = {"Hoang Van C" , "Tien si tai mui hong", 1000000};
    Bac_si BS8 = {"Hoang Van D", "Bac si da lieu", 200000};
    Bac_si BS9 = {"Duong Van A" , "Pho giam doc benh vien", 4000000};
    Bac_si BS10 = {"Duong Van B", "Giam doc benh vien", 5000000};
    THUOC T1 = {"Thuoc da lieu", "DL01", 20000, 1000};
    THUOC T2 = {"Thuoc nha khoa", "NK01", 30000, 1000};
    THUOC T3 = {"Thuoc tim mach", "TM01", 50000, 1000};
    THUOC T4 = {"Thuoc ho", "TMH01", 70000, 1000};
    THUOC T5 = {"Thuoc bo sung Ca", "DD01", 100000, 1000};
    THUOC T6 = {"Thuoc xit mui", "TMH02", 50000, 1000};
    THUOC T7 = {"Thuoc nho mui", "TMH03", 20000, 1000};
    THUOC T8 = {"Hop chi nha khoa", "NK02", 40000, 1000};
    THUOC T9 = {"Thuoc bo sung Sat", "DD02", 100000, 1000};
    THUOC T10 = {"Thuoc chua dau tim", "TM02", 100000, 1000};
    Dich_vu DV1 = {"Kham tai - mui - hong", 800000};
    Dich_vu DV2 = {"Kham da lieu", 500000};
    Dich_vu DV3 = {"Sieu am", 100000};
    Dich_vu DV4 = {"Chup X-Quang", 600000};
    Dich_vu DV5 = {"Kham tim mach", 600000};
    Dich_vu DV6 = {"Sinh thiet te bao ung thu", 2000000};
    Dich_vu DV7 = {"Chup MRI", 800000};
    Dich_vu DV8 = {"Kham dinh duong", 700000};
    Dich_vu DV9 = {"Xet nghiem mau", 200000};
    Dich_vu DV10 = {"Kham nha khoa", 400000};
    //Tạo danh sách bác sĩ
    InsertBSS(dsbs, BS1);
    InsertBSS(dsbs, BS2);
    InsertBSS(dsbs, BS3);
    InsertBSS(dsbs, BS4);
    InsertBSS(dsbs, BS5);
    InsertBSS(dsbs, BS6);
    InsertBSS(dsbs, BS7);
    InsertBSS(dsbs, BS8);
    InsertBSS(dsbs, BS9);
    InsertBSS(dsbs, BS10);
    //Tạo danh sach thuốc
    InsertT_nhap(T, T1);
    InsertT_nhap(T, T2);
    InsertT_nhap(T, T3);
    InsertT_nhap(T, T4);
    InsertT_nhap(T, T5);
    InsertT_nhap(T, T6);
    InsertT_nhap(T, T7);
    InsertT_nhap(T, T8);
    InsertT_nhap(T, T9);
    InsertT_nhap(T, T10);
    //Tạo danh sách dịch vụ
    InsertDV(dsdv, DV1);
    InsertDV(dsdv, DV2);
    InsertDV(dsdv, DV3);
    InsertDV(dsdv, DV4);
    InsertDV(dsdv, DV5);
    InsertDV(dsdv, DV6);
    InsertDV(dsdv, DV7);
    InsertDV(dsdv, DV8);
    InsertDV(dsdv, DV9);
    InsertDV(dsdv, DV10);

    InitBN(dsbn);
    Dapung(dsbn, T, dsdv, dsbs, dshd);
    return 0;
}