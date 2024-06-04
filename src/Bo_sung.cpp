#include <string>
#include "BOSUNG.h"

using namespace std;

void Init_Hoadon(DSHD &dshd){
    dshd = NULL;
}
void Insert_Hoadon(Benh_nhan BN1, DSHD &dshd, Hoa_don HDM){
    
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
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Nhap thong tin benh nhan"<<endl;
    cout<<"2. Sua thong tin benh nhan"<<endl;
    cout<<"3. Nhap thuoc cho benh nhan"<<endl;
    cout<<"4. In ra thong tin BN"<<endl;
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
void Dapung(DSBN& dsbn, DSThuoc S, DSDV dsdv, DSBS dsbs){
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
                    case 1: InsertBN(dsbn , S , dsdv);break;
                    case 2: SuaxoaBN(dsbn);break;
                    case 3:{
                        string cccd;
                        cout << "Nhap ma cccd Benh nhan: ";
                        cin >> cccd;
                        //NhapThuoc(FindBN(dsbn, cccd)->BN, S, dsdv);
                        break;
                    }
                    case 4: printfBN(dsbn);break;
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
            case 4:printfT(S);break;
        }
    } while(1);
}