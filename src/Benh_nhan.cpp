//Nguyễn Nhật Hoàng Anh
#include "BENHNHAN.h"
#include "BOSUNG.h"
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
//Khởi tạo danh sách bệnh nhân
void InitBN(DSBN &dsbn){
    dsbn = NULL;
}
//Kiểm tra danh sách trống
int IsEmpty(DSBN dsbn) {
    return (dsbn == NULL);
}
// Tao ra 1 NODE moi bang cach nhap tu ban phim vao
Benh_nhan Create(DSThuoc S, DSDV dsdv) {
    Benh_nhan A;
    cout << "Ho va ten:";
    cin.ignore();
    getline(cin, A.Ho_tenBN);
    cout << "Tuoi:";        cin >> A.Tuoi;
    cout << "Gioi tinh:";   cin >> A.Gioi_tinh;
    cin.ignore();
    cout << "Que quan: ";   getline(cin, A.Que);
    cout << "So CCCD: ";    cin >> A.CCCD;
    cout << "SDT:";         cin >> A.SDT;
    cout << "BHYT (1. Co, 0. Khong):" << endl;
    cin >> A.Bao_hiem;
    return A;
}
BNNODE Create1(DSThuoc S, DSDV dsdv){
    BNNODE Q = new NODEBN;
    cout << "Ho va ten:";
    cin.ignore();
    getline(cin, Q->BN.Ho_tenBN);
    cout << "Tuoi:";        cin >> Q->BN.Tuoi;
    cout << "Gioi tinh:";   cin >> Q->BN.Gioi_tinh;
    cin.ignore();
    cout << "Que quan: ";   getline(cin, Q->BN.Que);
    cout << "So CCCD: ";    cin >> Q->BN.CCCD;
    cout << "SDT:";         cin >> Q->BN.SDT;
    cout << "BHYT (1. Co, 0. Khong):" << endl;
    cin >> Q->BN.Bao_hiem;
    Q->Hoa_don = NULL;
    return Q;
}
//Thêm bệnh nhận vào danh sách
void InsertBN(DSBN& dsbn, DSThuoc S,DSDV dsdv) {
    int check;
    do{
        cout << "\t" << "Nhap thong tin benh nhan" << endl;
        BNNODE P = Create1(S,dsdv);
        P->nextBN = dsbn;
        dsbn = P;
        cout << "Ban co muon nhap benh nhan tiep? (1: Co, 0: Khong): ";
        cin >> check;
        cin.ignore();
    } while (check);    
}
// Tim benh nhan voi so cccd cho truoc 
BNNODE FindBN(DSBN dsbn, string cccd) {
    BNNODE R = dsbn;
    while (R != NULL) {
        if (R->BN.CCCD == cccd) return R;
        R = R->nextBN;
    }
    cout << "Khong tim thay BN" << endl;
    return NULL;
}
// Tim BN o truoc benh nhan voi so cccd cho truoc 
BNNODE FindBNBefore(DSBN dsbn, string cccd) {
    BNNODE R = dsbn;
    while (R != NULL) {
        if (R->nextBN->BN.CCCD == cccd) return R;
        R = R->nextBN;
    }
    cout << "Khong tim thay BN" << endl;
    return NULL;
}

// Xoa 1 BN voi so cccd cho truoc 
void DeleteBN(DSBN& dsbn, string cccd) {
    BNNODE P = FindBNBefore(dsbn, cccd);
    BNNODE Q = FindBN(dsbn, cccd);
    if (P == NULL) return;
    if (dsbn == Q) dsbn = dsbn->nextBN;
    P->nextBN = Q->nextBN;
    delete Q;
}

// Sua thong tin benh nhan 
void FixBN(DSBN& dsbn, string cccd) {
    BNNODE P = FindBN(dsbn, cccd);
    
    if (P != NULL) {
        cout << "\n\tNhap thong tin moi cho benh nhan" << endl;
        cout << "Ho va ten: ";
        getline(cin, P->BN.Ho_tenBN);
        cout << "Tuoi: ";
        cin >> P->BN.Tuoi;
        cout << "Gioi tinh: ";
        cin >> P->BN.Gioi_tinh; 
        cout << "Que: ";
        getline(cin, P->BN.Que);
        cout << "CCCD: ";
        cin >> P->BN.CCCD;
        cout << "SDT:"; cin >> P->BN.SDT;
        cout << "BHYT (1. Co, 0. Khong): ";
        cin >> P->BN.Bao_hiem;
        cout << "Thong tin thay doi thanh cong!" << endl;
        cin.ignore();
    } else {
        return; 
    }
}

// sap xep BN 
void ArrangeBN(DSBN& dsbn) {
    if (dsbn == NULL) return;
    
    int check;
    do {
        check = 0;
        BNNODE mid = dsbn;
        BNNODE last = NULL;
        BNNODE next = dsbn->nextBN;

        while (next != NULL) {
            if (mid->BN.Ho_tenBN > next->BN.Ho_tenBN) {
                if (last == NULL) {
                    dsbn = next;
                } else {
                    last->nextBN = next;
                }
                mid->nextBN = next->nextBN;
                next->nextBN = mid;
                check = 1;
                mid = next;
                next = mid->nextBN;
            } else {
                last = mid;
                mid = next;
                next = next->nextBN;
            }
        }
    } while (check);
}
//In bệnh nhân ....
void printfBN(DSBN S) {
    cout << "\n\tThong tin benh nhan:" << endl;
    if (S == NULL) {
        cout << "Danh sach benh nhan rong." << endl;
        return;
    }
    BNNODE R = S;
    const int numRows = 3;
    const int numCols = 2;
    while (R != NULL) {
        string arr[numRows][numCols];
        arr[0][0] = "Ho ten: " + R->BN.Ho_tenBN;
        arr[0][1] = "Gioi tinh: " + R->BN.Gioi_tinh;
        arr[1][0] = "Tuoi: " + to_string(R->BN.Tuoi);
        arr[1][1] = "CCCD: " + R->BN.CCCD;
        arr[2][0] = "SDT: " + R->BN.SDT;
        arr[2][1] = "Que: " + R->BN.Que;

        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numCols; k++) {
                cout << arr[j][k] << "\t";
            }
            cout << endl;
        }
        cout << "Bao hiem: " << R->BN.Bao_hiem << endl;
        cout << "\tDanh Sach Dich Vu\n";
        if(R->Hoa_don->HD.DVBN == NULL){
            cout << "Khong co dich vu duoc chon" << endl;
        }
        else printfDV(R->Hoa_don->HD.DVBN);
        if(R->Hoa_don->HD.TBN == NULL) {
           cout << "Danh sach thuoc cua benh nhan rong.";
        }
        else printfT1(R->Hoa_don->HD.TBN);
        cout << "Tong vien phi: " <<  SumBN(R->Hoa_don->HD.DVBN, R->Hoa_don->HD.TBN) << endl;
        if(R->BN.Bao_hiem == 1){
        	cout << "Phai tra: " << (SumBN(R->Hoa_don->HD.DVBN, R->Hoa_don->HD.TBN)*60)/100;
		}else{
			cout << "Phai tra: " << SumBN(R->Hoa_don->HD.DVBN, R->Hoa_don->HD.TBN);
		}
        R = R->nextBN;
    }
    cout << endl;
}
void printfBN2(DSBN dsbn){
    string cccd;
    BNNODE R = nullptr;
    do{
        cout << "Nhap cccd cua BN: "; cin >> cccd;
        R = FindBN(dsbn, cccd);
        
    }while (R == NULL);
    const int numRows = 3;
    const int numCols = 2;
    string arr[numRows][numCols];
        arr[0][0] = "Ho ten: " + R->BN.Ho_tenBN;
        arr[0][1] = "Gioi tinh: " + R->BN.Gioi_tinh;
        arr[1][0] = "Tuoi: " + to_string(R->BN.Tuoi);
        arr[1][1] = "CCCD: " + R->BN.CCCD;
        arr[2][0] = "SDT: " + R->BN.SDT;
        arr[2][1] = "Que: " + R->BN.Que;

        for (int j = 0; j < numRows; j++) {
            for (int k = 0; k < numCols; k++) {
                cout << arr[j][k] << "\t";
            }
            cout << endl;
        }
        cout << "Bao hiem: " << R->BN.Bao_hiem << endl;
        cout << "\tDanh Sach Dich Vu\n";
        if(R->Hoa_don->HD.DVBN == NULL){
            cout << "Khong co dich vu duoc chon" << endl;
        }
        else printfDV(R->Hoa_don->HD.DVBN);
        if(R->Hoa_don->HD.TBN == NULL) {
           cout << "Danh sach thuoc cua benh nhan rong.";
        }
        else printfT1(R->Hoa_don->HD.TBN);
        long totalCost = sumT(R->Hoa_don->HD.TBN) + SumDV(R->Hoa_don->HD.DVBN);
        cout << "Tong vien phi: " << totalCost << endl;
        if (R->BN.Bao_hiem) {
            cout << "Phai tra: " << (totalCost * 60) / 100 << endl;
        } else {
            cout << "Phai tra: " << totalCost << endl;
        }
}
//Sửa - xóa Bệnh nhân.
void SuaxoaBN(DSBN &S){
    int check ;
    do{
	    string a;
	    cout << "Nhap cccd cua BN muon duoc sua: " ; cin >> a;
	    BNNODE p = NULL;
	    while(p == NULL){
		    cout << "Nhap lai cccd: " ; cin >> a;
		    p = FindBN(S,a);
        }
	    int x;
	    cout << "0.Xoa\n1.Thong tin\n2.Dich vu\n3.Thuoc\n";
	    cin >> x; 
	    while(x < 0 || x > 3){
		    cout << "Nhap lai: "; cin >> x;
	    }
	    switch(x){
		    case 0: {
			    DeleteBN(S,a);
			    break;
		    }
		    case 1:{
			    FixBN(S,a);
			    break;
		    }
		    case 2:{
//			cout << "0."
			    break;
		    }
		    case 3:{
			    int a;
			    while(a == 1){
			    string i;
			    cout << "Nhap ma thuoc: "; cin >> i;
			    NodeT r = NULL;
			    while(r == NULL){
				    cout << "Nhap lai ma: " ; cin >> i;
				    r = FindT(p->Hoa_don->HD.TBN, i);
			    }
			    int y;
			    cout << "0.Xoa\n1.Sua\n"; cin >> y;
			    while(y != 0 && y != 1){
				    cout << "Nhap lai: "; cin >>y;
		    	}
			    switch(y){
			    	case 0:{
				    	DeleteT(p->Hoa_don->HD.TBN,i);
				    	break;
			    	}
				    case 1:{
					    FixT(p->Hoa_don->HD.TBN,i);
				    	break;
				    }
			    }
			    cout << "0.khong\n1.\nSua tiep\n"; cin >> x;
			    while(x != 0 && x != 1){
				    cout << "Nhap lai: "; cin >> x;
			    }
			    }
			    break;
		    }
        }
        cout << "\n\tThong tin benh nhan sau khi sua:" << endl;
        printfBN(S);
        cout << "Co tiep tuc sua nua khong:(1. Co , 2. Khong)"<<endl;
        cin >> check;
	} while (check);	
}
//Tổng tiền cho bệnh nhân S.
long SumBN(DSDV dsdv, DSThuoc dst){
	return dsdv->TongtienDV + dst->TongtienT;
}
