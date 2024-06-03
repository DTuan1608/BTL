#ifndef BENHNHAN_H
#define BENHNHAN_H

#include <iostream>
#include <string>
#include "BOSUNG.h"
#include "DICHVU.h"
#include "THUOC.h"
using namespace std;

struct Benh_nhan{
    string Ho_tenBN;
    long Tuoi;
    string Gioi_tinh;
    string Que;
    string CCCD;
    string SDT;
	int DK, MK, YK; // Ngày bệnh nhân đi khám
    DSHD HD;
    int Bao_hiem; 
};
struct NODEBN{
	Benh_nhan BN;
	NODEBN* nextBN;
};
typedef NODEBN* BNNODE;
typedef NODEBN* DSBN;

//Khai báo nguyên mẫu hàm BN
void InitBN(DSBN &dsbn);
int IsEmpty(DSBN dsbn);
Benh_nhan Create(DSThuoc S,DSDV dsdv);//Tạo 1NODE mới bằng cách nhập từ bàn phím vào
void NhapThuoc(DSBN& dsbn,DSThuoc S,DSDV dsdv,BNNODE A);
void InsertBN(DSBN& dsbn, DSThuoc S,DSDV dsdv);
BNNODE FindBN(DSBN dsbn,string cccd);
BNNODE FindBNBefore(DSBN dsbn,string cccd);
void DeleteBN(DSBN& dsbn, string cccd);
void FixBN(DSBN& dsbn, string cccd);
void ArrangeBN(DSBN& dsbn);
Dich_vu Select_Service(DSDV dsdv);
void printfBN(DSBN S);
#endif