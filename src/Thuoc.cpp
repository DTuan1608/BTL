
//Hà Hữu An
#include "THUOC.h"
#include <iomanip>

using namespace std;
//Khởi tạo danh sách thuốc
void InitT(DSThuoc &T){
    T = NULL;
    T->TongtienT = 0;
}
//Kiểm tra danh sách trống
int emptyT(DSThuoc T) {
    return T == NULL;
}
//Tạo node thuốc mới
NodeT makenodeT(THUOC T1) {
    NodeT node = new NODET;
    node->T = T1;
    node->nextT = NULL;
    return node;
}
//Tìm kiếm thuốc theo mã thuốc
NodeT FindT(DSThuoc& T, string Ma_thuoc) {
    NodeT p = T;
    while (p != NULL && p->T.Ma_thuoc != Ma_thuoc) {
        p = p->nextT;
    }
    if (p == NULL) {
        cout << "Khong co thuoc voi ma thuoc: " << Ma_thuoc << " trong danh sach" << endl;
        return NULL;
    } else {
        return p;
    }
}
//Xóa Thuốc có mã Ma_thuoc khỏi danh sách
void DeleteT(DSThuoc& T, string Ma_thuoc) {
    if (emptyT(T)) {
        cout << "Danh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT P = FindT(T, Ma_thuoc);
    if (P == NULL) return;

    if (T == P) {
        T = T->nextT;
        delete P;
    } else {
        NodeT R = T;
        while (R->nextT != P) R = R->nextT;
        R->nextT = P->nextT;
        delete P;
    }
}
//Chỉnh sửa thông tin thuốc
void FixT(DSThuoc T, string Ma_thuoc) {
    if (emptyT(T)) {
        cout << "\tDanh Sach Thuoc Rong" << endl;
        return;
    }
    NodeT p = FindT(T, Ma_thuoc);
    if (p == NULL) return;

    long x;
    cout << "Nhap gia thay doi: ";
    cin >> x;
    p->T.Gia_thuoc = x;
    cout << "Da thay doi gia thuoc" << endl;
}
//Thêm thuốc dùng cho hàm nhập
void InsertT_nhap(DSThuoc& T, THUOC T1) {
    NodeT P = makenodeT(T1);
    if (emptyT(T)) {
        T = P;
    } else {
        if (P->T.Ten_thuoc[0] <= 'A') {
            P->nextT = T;
            T = P;
        } else {
            NodeT R = T;
            while (R->nextT != NULL && R->nextT->T.Ten_thuoc[0] < P->T.Ten_thuoc[0])
                R = R->nextT;
            P->nextT = R->nextT;
            R->nextT = P;
        }
    }
}

//Hiển thị danh sách thuốc
void hienThiDanhSachThuoc(DSThuoc danhSachThuoc) {
    cout << left << setw(10) << "Ma_thuoc" 
         << setw(10) << "So_luong" 
         << setw(20) << "Ten_thuoc" 
         << setw(10) << "Gia_thuoc" 
         << endl;
    NodeT temp = danhSachThuoc;
    while (temp != nullptr) {
        cout << left << setw(10) << temp->T.Ma_thuoc
             << setw(10) << temp->T.so_luong 
             << setw(30) << temp->T.Ten_thuoc 
             << setw(10) << temp->T.Gia_thuoc 
             << endl;
        temp = temp->nextT;
    }
}

//Nhập Thuốc
void NhapT(DSThuoc& S){
    cout << "------------NHAP THUOC-------------\n";
    int x = 1;
    while (x == 1) {
        THUOC T1;
        cout << "Ma thuoc: "; cin >> T1.Ma_thuoc;
        cout << "Ten thuoc: ";
        cin.ignore(); // Xóa b? d?m d? tránh l?i nh?p chu?i
        getline(cin, T1.Ten_thuoc);
        
        cout << "Don gia: "; cin >> T1.Gia_thuoc;
        cout << "So luong: "; cin >> T1.so_luong;
        InsertT_nhap(S, T1);
        cout << "----------------------\n" << "0.Thoat\n" << "1.Nhap tiep\n";
        cin >> x;
        while (x != 0 && x != 1) {
            cout << "Nhap lai: "; cin >> x;
        }
    }
}
//Thành tiền thuốc
long tonggiaT(THUOC S) {
    return S.Gia_thuoc * S.so_luong;
}
//Tổng thuốc của danh sách
long sumT(DSThuoc S) {
    long total = 0;
    NodeT p = S;
    while (p != NULL) {
        total += p->T.Gia_thuoc * p->T.so_luong;
        p = p->nextT;
    }
    return total;
}
//In thuoc theo danh sách -> Bệnh nhân
void printfT(DSThuoc S) {
    if(S == NULL){
        cout<<"DS Thuoc rong"<<endl;
        return;
    }
    int n = 0;
    NodeT P = S;
    while (P != NULL) {
        P = P->nextT;
        n++;
    }
    NodeT R = S;
    string arr[100][6];
    arr[0][0] = "STT";
    arr[0][1] = "Ma";
    arr[0][2] = "Ten";
    arr[0][3] = "Gia";
    arr[0][4] = "So luong";
    arr[0][5] = "Thanh tien";
    for (int i = 1; i <= n; i++) {
        arr[i][0] = to_string(i);
        arr[i][1] = R->T.Ma_thuoc;
        arr[i][2] = R->T.Ten_thuoc;
        arr[i][3] = to_string(R->T.Gia_thuoc);
        arr[i][4] = to_string(R->T.so_luong);
        arr[i][5] = to_string(tonggiaT(R->T));
        R = R->nextT;
    }
    cout << "\tDanh Sach Thuoc" << endl;
    for (int j = 0; j <= n; j++) {
        for (int k = 0; k < 6; k++) {
            cout << arr[j][k] << "\t";
        }
        cout << endl;
    }
}
