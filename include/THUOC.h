#ifndef THUOC_H
#define THUOC_H

#include <string>
#include <iostream>
using namespace std;

typedef struct THUOC {
    string Ten_thuoc;
    long Ma_thuoc;
    long  Gia_thuoc;
    int so_luong;
} THUOC;

struct NODET {
    THUOC T;
    long TongtienT;
    NODET* nextT;
};

typedef NODET* NodeT;
typedef NODET* DSThuoc;

//Khai báo nguyên mẫu hàm Thuoc
void InitT(DSThuoc &T);
int emptyT(DSThuoc T);
NodeT makenodeT(THUOC T1);
NodeT FindT(DSThuoc &T, int Ma_thuoc);
void DeleteT(DSThuoc &T, int Ma_thuoc);
void FixT(DSThuoc T, int Ma_thuoc);
void ArrangeT(DSThuoc &T, THUOC T1);
long tonggiaT(THUOC);
void Hien_Thi_Thuoc(DSThuoc Thuoc);
void NhapT(DSThuoc &T);

#endif 