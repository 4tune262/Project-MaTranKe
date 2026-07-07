#include "Header.h"
int main() {
	ADJ g;
	int dinh, chon, dinhKe;
	AE ae;
	EDGE e;
	do {
		cout << "\n1.Doc file DTVH";
		cout << "\n2.Doc file DTCH";
		cout << "\n3.Tinh bac ra cua dinh";
		cout << "\n4.Tinh bac cua dinh DTVH";
		cout << "\n5.Tra ve tap canh DTVH";
		cout << "\n6.Ma tran ke DTVH sau khi co tap canh va dinh";
		cout << "\n7.Ma tran ke DTCH sau khi co tap canh va dinh";
		cout << "\n8.Dinh ke co trong so nho nhat";
		cout << "\n9.Ma tran dao";
		cout << "\n10.Bac vao cua dinh DTCH";
		cout << "\n11.Xuat cac dinh ke cua dinh";
		cout << "\n12.Tong bac ra cua DTCH";
		cout << "\n13.Tong bac vao cua DTCH";
		cout << "\n14.Tong bac cua DTVH";
		cout << "\n15.Kiem tra dinh co lap";
		cout << "\n16.Dem dinh co lap";
		cout << "\n17.Dem so canh cua dtch";
		cout << "\n18.Tong so canh DTVH";
		cout << "\n19.Canh co trong so lon nhat DTCH";
		cout << "\n20.Canh co trong so nho nhat DTCH";
		cout << "\n21.Canh co trong so lon nhat DTVH";
		cout << "\n22.Canh co trong so nho nhat DTVH";
		cout << "\n23.Tong trong so cac canh DTCH";
		cout << "\n24.Tong trong so cac canh DTVH";
		cout << "\n25.Canh di vao co trong so lon nhat DTCH";
		cout << "\n26.Canh di vao co trong so nho nhat DTCH";
		cout << "\n27.Canh di ra co trong so lon nhat DTCH";
		cout << "\n28.Canh di ra co trong so nho nhat DTCH";
		cout << "\n29.Dao huong 1 canh";
		cout << "\n30.Dao huong tat ca canh";
		cout << "\n31.Tra ve tap canh DTCH";
		cout << "\n32.Ma tran ke sang Danh Sach Ke";
		cout << "\n33.Dinh co bac ra lon nhat";
		cout << "\n34.Dinh co bac ra nho nhat";
		cout << "\n35.Dinh ke co bac ra lon nhat";
		cout << "\n36.Dinh ke co bac ra nho nhat";
		cout << "\n37.Canh co trong so Lon nhat";
		cout << "\n38.Canh co trong so Nho nhat";
		cout << "\n39.Tong trong so cac canh ra cua dinh";
		cout << "\n40.Tong trong so cac canh vao cua dinh";
		cout << "\n41.Canh ke ra co trong so lon nhat cua dinh";
		cout << "\n42.Canh ke ra co trong so nho nhat cua dinh";
		cout << "\n43.Dinh ke ra co trong so lon nhat cua dinh";
		cout << "\n44.Dinh ke ra co trong so nho nhat cua dinh";
		cout << "\nMoi ban chon: ";
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
			if (read("dothi1.txt", g) == 0) {
				cout << "\nDoc that bai!";
			}
			else {
				cout << "\nDoc file thanh cong";
				xuatMaTran(g);
			}
			break;
		case 2:
			if (read("dothi2.txt", g) == 0) {
				cout << "\nDoc that bai!";
			}
			else {
				cout << "\nDoc file thanh cong";
				xuatMaTran(g);
			}
			break;
		case 3:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nBac ra la: " << bacRaCuaDinh(g, dinh);
			break;
		case 4:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nBac cua dinh la: " << bacCuaDinhDTVH(g, dinh);
			break;
		case 5:
			cout << "\nTap canh cua dtvh: ";
			xuatArrE(traVeTapCanhDTVH(g));
			break;
		case 6:
			cout << "\nNhap vao so dinh: ";
			cin >> dinh;
			cout << "\nNhap vao tap canh: ";
			nhapTapCanh(ae, dinh);
			cout << "\nMa tran la: ";
			xuatMaTran(maTranKeDTVH(ae, dinh));
			break;
		case 7:
			cout << "\nNhap vao so dinh: ";
			cin >> dinh;
			cout << "\nNhap vao tap canh: ";
			nhapTapCanh(ae, dinh);
			cout << "\nMa tran la: ";
			xuatMaTran(maTranKeDTCH(ae, dinh));
			break;
		case 8: 
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nDinh ke co trong so lon nhat la: " << dinhKeCoTrongSoLonNhat(g, dinh);
			break;
		case 9:
			cout << "\nMa tran dao la: ";
			xuatMaTran(maTranDao(g));
			break;
		case 10:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nBac vao cua dinh: " << bacVaoCuaDinh(g, dinh);
			break;
		case 11:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nCac dinh ke: ";
			xuatDinhKeCuaDinh(g, dinh);
			break;
		case 12:
			cout << "\nTong bac ra cua dtch: " << tongBacRaDTCH(g);
			break;
		case 13:
			cout << "\nTong bac vao cua dtch: " << tongBacVaoDTCH(g);
			break;
		case 14:
			cout << "\nTong bac cua dtvh: " << tongBacCuaDTVH(g);
			break;
		case 15:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (ktrDinhCoLap(g, dinh)) {
				cout << "\nDinh co lap";
			}
			else {
				cout << "\nDinh ko co lap";
			} 
			break;
		case 16:
			cout << "\nSo dinh co lap: " << demDinhCoLap(g);
			break;
		case 17:
			cout << "\nTong so canh: " << demSoCanhDTCH(g);
			break;
		case 18:
			cout << "\nTong so canh dtvh: " << demSoCanhDTVH(g);
			break;
		case 19:
			cout << "\nCanh co trong so lon nhat DTCH: ";
			xuatEDGE(canhCoTrongSoLonNhat(g));
			break;
		case 20:
			cout << "\nCanh co trong so nho nhat DTCH: ";
			xuatEDGE(canhCoTRongSoNhoNhat(g));
			break;
		case 21:
			cout << "\nCanh co trong so lon nhat DTVH: ";
			xuatEDGE(canhCoTrongSoLonNhatDTVH(g));
			break;
		case 22:
			cout << "\nCanh co trong so nho nhat DTVH: ";
			xuatEDGE(canhCoTrongSoNhoNhatDTVH(g));
			break;
		case 23:
			cout << "\nTong trong so cac canh DTCH: " << tongTrongSoCacCanhDTCH(g);
			break;
		case 24:
			cout << "\nTong trong so cac canh DTVH: " << tongTrongSoCacCanhDTVH(g);
			break;
		case 25:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nCanh di vao co trong so lon nhat DTCH: ";
			xuatEDGE(canhDiVaoCoTrongSoLonNhat(g, dinh));
			break;
		case 26:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nCanh di vao co trong so nho nhat DTCH: ";
			xuatEDGE(canhDiVaoCoTrongSoNhoNhat(g, dinh));
			break;
		case 27:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nCanh di ra co trong so lon nhat DTCH: ";
			xuatEDGE(canhDiRaCoTrongSoLonNhat(g, dinh));
			break;
		case 28:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nCanh di ra co trong so nho nhat DTCH: ";
			xuatEDGE(canhDiRaCoTrongSoNhoNhat(g, dinh));
			break;
		case 29:
			int o, d;
			cout << "\nNhap vao o: ";
			cin >> o;
			cout << "\nNhap vao d: ";
			cin >> d;
			daoHuongMotCanh(g, o, d);
			xuatMaTran(g);
			break;
		case 30:
			cout << "\nMa tran sau khi doi huong tat ca: ";
			daoHuongTatCa(g);
			xuatMaTran(g);
			break;
		case 31:
			cout << "\nTap canh dtch: ";
			xuatArrE(traVeTapCanhDTCH(g));
			break;
		case 32:
			cout << "\nMa tran sang danh sach ke: ";
			xuatDSK(maTranSangDanhSachKe(g));
			break;
		case 33:
			cout << "\nDinh co bac ra lon nhat: " << dinhCoBacRaLonNhat(g);
			break;
		case 34:
			cout << "\nDinh co bac ra nho nhat: " << dinhCoBacRaNhoNhat(g);
			break;
		case 35:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (dinhKeCoBacRaLonNhat(g, dinh, dinhKe)) {
				cout << "\nTim thay la: " << dinhKe;
			}
			else {
				cout << "\nTim ko ra";
			}
			break;
		case 36:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (dinhKeCoBacRaNhoNhat(g, dinh, dinhKe)) {
				cout << "\nTim thay la: " << dinhKe;
			}
			else {
				cout << "\nTim ko ra";
			}
			break;
		case 37:
			EDGE canhMax;
			if (timCanhCoTrongSoLonNhat(g, canhMax)) {
				cout << "\nTim thay: ";
				xuatEDGE(canhMax);
			}
			else {
				cout << "\nKhong thay";
			} break;
		case 38:
			EDGE canhMin;
			if (timCanhCoTrongSoNhoNhat(g, canhMin)) {
				cout << "\nTim thay: ";
				xuatEDGE(canhMin);
			}
			else {
				cout << "\nKhong thay";
			} break;
		case 39:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nTong la: " << tongTrongSoCacCanhRa(g, dinh);
			break;
		case 40:
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			cout << "\nTong la: " << tongTrongSoCacCanhVao(g, dinh);
			break;
		case 41:
			EDGE canhKeMax;
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (canhCoTrongSoLonNhatKeDinh(g, dinh, canhKeMax)) {
				cout << "\nTim thay: ";
				xuatEDGE(canhKeMax);
			}
			else {
				cout << "\nKhong co";
			}
			break;
		case 42:
			EDGE canhKeMin;
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (canhCoTrongSoNhoNhatKeDinh(g, dinh, canhKeMin)) {
				cout << "\nTim thay: ";
				xuatEDGE(canhKeMin);
			}
			else {
				cout << "\nKhong co";
			}
			break;
		case 43:
			int dinhMax;
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (dinhKeRaCoTrongSoLonNhat(g, dinh, dinhMax)) {
				cout << "\Dinh la: " << dinhMax;
			}
			else {
				cout << "\nKhong co";
			}
			break;
		case 44:
			int dinhMin;
			cout << "\nNhap vao dinh: ";
			cin >> dinh;
			if (dinhKeRaCoTrongSoNhoNhat(g, dinh, dinhMin)) {
				cout << "\Dinh la: " << dinhMin;
			}
			else {
				cout << "\nKhong co";
			}
			break;
		default:
			break;
		}
	} while (chon != 0);
	return 0;
}