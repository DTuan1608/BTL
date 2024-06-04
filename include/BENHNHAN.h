#ifndef BENHNHAN_H
#define BENHNHAN_H

#include <iostream>
#include <string>
#include "BOSUNG.h"
#include "DICHVU.h"
#include "THUOC.h"
using namespace std;

struct Hoa_don;
struct NODEHD;
typedef NODEHD* DSHD;

struct Benh_nhan{
    string Ho_tenBN;
    long Tuoi;
    string Gioi_tinh;
    string Que;
    string CCCD;
    string SDT;
	int DK, MK, YK; // Ngày bệnh nhân đi khám
    DSHD Hoa_don;
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
//void NhapThuoc(Benh_nhan A, DSThuoc S,DSDV dsdv);
//void InsertDVforBN(Benh_nhan A, DSThuoc T, DSDV DSDV);
void InsertBN(DSBN& dsbn, DSThuoc S,DSDV dsdv);
BNNODE FindBN(DSBN dsbn,string cccd);
BNNODE FindBNBefore(DSBN dsbn,string cccd);
void DeleteBN(DSBN& dsbn, string cccd);
void FixBN(DSBN& dsbn, string cccd);
void ArrangeBN(DSBN& dsbn);
long SumBN(Benh_nhan S);
void printfBN(DSBN S);
void SuaxoaBN(DSBN &S);
#endif