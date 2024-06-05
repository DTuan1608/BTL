#include <string>
#include "BOSUNG.h"

using namespace std;
//Tạo node hóa đơn.
HDNODE Creat_hoa_don(DSDV dsdv, DSThuoc dst){
    HDNODE P = new NODEHD;
    cout << "Nhap ma hoa don" << endl;
    cin >> P->HD.Ma_HD;
    cout << "Nhap ngay/Thang/Nam" << endl;
    cin >> P->HD.dd; cout << "/" ; cin >> P->HD.mm; cout << "/"; cin >> P->HD.yy;
    DVNODE Dichvu = NULL;
    NodeT Thuoc = NULL;
    P->HD.DVBN = NULL;
    P->HD.TBN = NULL;
    addServiceToInvoice(P->HD, Dichvu, dsdv);
    addMedicineToInvoice(P->HD, Thuoc, dst);
    P->nextHD = NULL;
    return P;
}
//Thêm hóa đơn cho bệnh nhân.
void add_HoaDon_to_Benhnhan(BNNODE BN, HDNODE HD){
    if (BN->Hoa_don == nullptr) {
        BN->Hoa_don = HD;
    } else {
        HDNODE temp = BN->Hoa_don;
        while (temp->nextHD != nullptr) {
            temp = temp->nextHD;
        }
        temp->nextHD = HD;
    }
}
//Tìm hóa đơn
HDNODE find_Hoadon(DSHD dshd, string ma_hd) {
    HDNODE temp = dshd;
    while (temp != nullptr) {
        if (temp->HD.Ma_HD == ma_hd) {
            return temp;
        }
        temp = temp->nextHD;
    }
    return nullptr;
}
//Thêm dịch vụ cho hóa đơn
void addServiceToInvoice(Hoa_don& hd, DVNODE dv, DSDV dsdv) {
    DisplayDV(dsdv);
    int x;
    do{
        cout << "Nhap dich vu ban muon chon." << endl; 
        string name;
        cin >> name;
        DVNODE Dichvu = FindDV(dsdv, name);
        if (hd.DVBN == nullptr) {
            hd.DVBN = dv;
        } else {
            DVNODE temp = hd.DVBN;
            while (temp->nextDV != nullptr) {
                temp = temp->nextDV;
            }
            temp->nextDV = dv;
        }
        cout << "Ban co muon chon them dich vu khong?" << endl;
        cout << "Chon 1. Co hoac 0.Khong" << endl;
        cin >> x;
    }while(x);
}
//Thêm thuốc cho hóa đơn
void addMedicineToInvoice(Hoa_don& hd, NodeT t, DSThuoc dst) {
    Hien_Thi_Thuoc(dst);
    int x;
    do{
        cout << "Nhap thuoc ban muon chon." << endl; 
        string Ma_thuoc;
        cin >> Ma_thuoc;
        NodeT t = FindT(dst, Ma_thuoc);
        if (hd.TBN == nullptr) {
            hd.TBN = t;
        } else {
            NodeT temp = hd.TBN;
            while (temp->nextT != nullptr) {
                temp = temp->nextT;
            }
            temp->nextT = t;
        }
        cout << "Ban co muon chon them thuoc khong?" << endl;
        cout << "Chon 1. Co hoac 0.Khong" << endl;
        cin >> x;
    }while(x);
}
//Hiển thị
void Hienthi(){
    cout << "\n\t Chon cac chuc nang " << endl;
    cout << "1. Benh nhan" << endl;
    cout << "2. Danh sach dich vu" << endl;
    cout << "3. Danh sach bac si" << endl;
    cout << "4. Danh sach thuoc" << endl;
    return;
}
void Hienthi1(){
    cout << "\n\tChon cac thao tac" << endl;
    cout << "1. Nhap thong tin benh nhan" << endl;
    cout << "2. Sua thong tin benh nhan" << endl;
    cout << "3. Tao hoa don cho benh nhan" << endl;
    cout << "4. In ra thong tin benh nhan" << endl;
    //cout << "5. In ra hoa don cua benh nhan" << endl;
    return;
}
void Hienthi2(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem danh sach dich vu"<<endl;
    cout<<"2. Nhap them dich vu "<<endl;
    return;
}
void Hienthi3(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem Danh sach bac si"<<endl;
    cout<<"2. Nhap them bac si(Private)"<<endl;
    return;
}
void Hienthi4(){
    cout<<"\n\tChon cac thao tac"<<endl;
    cout<<"1. Xem danh sach thuoc"<<endl;
    cout<<"2. Nhap them thuoc"<<endl;
    return;
}
void Dapung(DSBN& dsbn, DSThuoc T, DSDV dsdv, DSBS dsbs, DSHD dshd){
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
                        NodeT Thuoc = NULL;
                        DVNODE Dichvu = NULL;
                        BNNODE P = FindBN(dsbn, cccd);
                        HDNODE Q = Creat_hoa_don(dsdv, T);
                        add_HoaDon_to_Benhnhan(P, Q);
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
            case 4:{
                int y;
                Hienthi4();
                cin >> y;
                switch(y){
                    case 1:printfT(T);break;
                    case 2:NhapT(T);break;
                }
                break;
            }
        }
    } while(1);
}