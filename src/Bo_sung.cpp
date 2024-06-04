#include <string>
#include "BOSUNG.h"

using namespace std;

void Init_Hoadon(DSHD &dshd){
    dshd->HD.DVBN = NULL;
    dshd->HD.TBN = NULL;
}
void Insert_Hoadon(BNNODE BN1, DSHD &dshd, Hoa_don HDM){
    InsertDSDV_Hoadon(BN1, HDM.DVBN);
}
void InsertDST_Hoadon(BNNODE A, DSThuoc dst){
    int x;
    do{
        THUOC T = Select_Medicine(dst);
        InsertT_nhap(A->Hoa_don->HD.TBN, T);
        cout << "Ban co muon chon thuoc tiep khong?" << endl;
        cout << "1. Co          0. Khong" << endl;
        cout << "Ban chon: ";
        cin >> x;
    }while(x);
}

void InsertDSDV_Hoadon(BNNODE A, DSDV dsdv){
    int x;
    do{
        Dich_vu DV = Select_Service(dsdv);
        InsertDV(A->Hoa_don->HD.DVBN, DV);
        cout << "Ban co muon chon dich vu tiep khong?" << endl;
        cout << "1. Co          0. Khong" << endl;
        cout << "Ban chon: ";
        cin >> x;
    }while(x);
}
void Hienthi(){
    cout<<"\n\tChon cac chuc nang"<<endl;
    cout<<"1. Benh nhan"<<endl;
    cout<<"2. DSDV"<<endl;
    cout<<"3. DSBS"<<endl;
    cout<<"4. DS Thuoc"<<endl;\
    return;
}
void Hienthi1(){
    cout << "\n\tChon cac thao tac" << endl;
    cout << "1. Nhap thong tin benh nhan" << endl;
    cout << "2. Sua thong tin benh nhan" << endl;
    cout << "3. Chon thuoc cho benh nhan" << endl;
    cout << "4. Chon dich vu cho benh nhan" << endl;
    cout << "5. In ra thong tin benh nhan" << endl;
    return;
}
void Hienthi2(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem DS dich vu"<<endl;
    cout<<"2. Nhap them dich vu "<<endl;
    return;
}
void Hienthi3(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem DS bac si"<<endl;
    cout<<"2. Nhap them bac si(Private)"<<endl;
    return;
}
void Dapung(DSBN& dsbn, DSThuoc T, DSDV dsdv, DSBS dsbs){
    int x;
    do{
        Hienthi();
        cin>>x;
        switch(x){
            case 1:{
                int y;
                Hienthi1();
                cin >> y ; 
                switch(y){
                    case 1: InsertBN(dsbn , T, dsdv);break;
                    case 2: SuaxoaBN(dsbn);break;
                    case 3:{
                        string cccd;
                        cout << "Nhap ma cccd Benh nhan: ";
                        cin >> cccd;
                        InsertDST_Hoadon(FindBN(dsbn, cccd), T);
                        break;
                    }
                    case 4:{
                        string cccd;
                        cout << "Nhap ma cccd Benh nhan: ";
                        cin >> cccd; 
                        InsertDSDV_Hoadon(FindBN(dsbn, cccd), dsdv);break;
                    }
                    case 5: printfBN(dsbn);break;
                }
                break;
            }
            case 2:{
                int y;
                Hienthi2();
                cin>> y;
                switch(y){
                    case 1:printfDV(dsdv);break;
                    case 2:NhapDichVu(dsdv);break;
                }
                break;
            }
            case 3:{
                int y;
                Hienthi3();
                cin>>y;
                switch(y){
                    case 1:PrintBS(dsbs);break;
                    case 2:InsertBS(dsbs);break;
                }
            }
            case 4:printfT(T);break;
        }
    } while(1);
}