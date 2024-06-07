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
    P->HD.DVBN = NULL;
    NodeT Thuoc = NULL;
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
    DVNODE Dichvu;
    do{
        while(true){
            cout << "Nhap dich vu ban muon chon." << endl; 
            string name;
            getline(cin, name);
            Dichvu = FindDV(dsdv, name);
            if(Dichvu != NULL){
                InsertDV(hd.DVBN, Dichvu->DV);
                break;
            }
            else {
                cout << "Dich vu ban chon khong co, moi ban nhap lai. " << endl;
                continue;
            }
        }
        cout << "Ban co muon chon them dich vu khong?";
        cout << "( 1. Co , 0.Khong)" << endl;
        cin >> x;
    }while(x);
}
//Thêm thuốc cho hóa đơn
void addMedicineToInvoice(Hoa_don& hd, NodeT t, DSThuoc dst) {
    hienThiDanhSachThuoc(dst);
    int x;
    do{
        cout << "Nhap thuoc ban muon chon." << endl; 
        while(true){
            string Ma_thuoc;
            cin >> Ma_thuoc;
            NodeT t = FindT(dst, Ma_thuoc);
            if(t != NULL){
                while(true){
                    int Soluong;
                    cout << "So luong thuoc co ma " << t->T.Ma_thuoc << " la: ";
                    cout << t->T.so_luong << endl;
                    cout << "Nhap so luong thuoc" << endl;
                    cin >> Soluong;
                    if (Soluong <= t->T.so_luong && Soluong > 0) {
                        THUOC selectedThuoc = t->T;
                        selectedThuoc.so_luong = Soluong;
                        t->T.so_luong -= Soluong;
                        InsertT_nhap(hd.TBN, selectedThuoc);
                        break;
                    }
                    else{
                         cout << "Nhap lai so luong thuoc ban lay." << endl;
                        cout << "Vui long nhap so luong hop le (1 den " << t->T.so_luong << ")." << endl;
                    }
                }
                break;
            }
            else{
                cout << "Ma thuoc ban tim khong co." << endl;
                cout << "Nhap lai ma thuoc." << endl;   
            }
        }
        cout << "Ban co muon chon them thuoc khong?" << endl;
        cout << "Chon 1. Co hoac 0.Khong" << endl;
        cin >> x;
    }while(x);
}
//Hiển thị
void Hienthi(){
    cout << "\n\t Chon cac chuc nang " << endl;
    cout << "1. Thao tac voi benh nhan" << endl;
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
    cout << "4. In hoa don cho benh nhan" << endl;
    return;
}
void Hienthihoadon(){
    cout << "\n\tChon thao tac" << endl;
    cout << "1.Nhap dich vu cho benh nhan" << endl;
    cout << "2.Nhap thuoc cho benh nhan" << endl;
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
                        NodeT Thuoc = NULL;
                        DVNODE Dichvu = NULL;
                        BNNODE P;
                        do{
                            cout <<"Vui long nhap ma cccd cua benh nhan: ";
                            cin >> cccd;
                            P = FindBN(dsbn, cccd);
                        }while(P == NULL);
                        HDNODE Q = Creat_hoa_don(dsdv, T);
                        add_HoaDon_to_Benhnhan(P, Q);
                        break;
                    }
                    case 4: printfBN2(dsbn);break;
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