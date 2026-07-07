#include "Header.h"
//int read(const char* filename, ADJ& g) {
//	FILE* f;
//	fopen_s(&f, filename, "rt");
//	if (f == NULL) return 0;
//	fscanf_s(f, "%d", &g.n);
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			fscanf_s(f, "%d", &g.ds[i][j]);
//		}
//	}
//	fclose(f);
//	return 1;
//}
//
//void xuatMaTran(ADJ g) {
//	cout << "\n" << g.n << endl;
//	for (int i = 0; i < g.n; i++) {
//		for (int j = 0; j < g.n; j++) {
//			cout << g.ds[i][j] << "\t";
//		}
//		cout << endl;
//	}
//}
int read(const char* filename, ADJ& g) {
	FILE* f;
	fopen_s(&f, filename, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &g.n);
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			fscanf_s(f, "%d", &g.ds[i][j]);
		}
	}
	fclose(f);
	return 1;
}
void xuatMaTran(ADJ g) {
	cout << "\n" << g.n << endl;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			cout << g.ds[i][j] << "\t";
		}
		cout << endl;
	}
}
void xuatArrV(AV av) {
	for (int i = 0; i < av.n; i++) {
		cout << av.ds[i] << endl;
	}
}
void xuatEDGE(EDGE e) {
	cout << "\n(" << e.org << "-" << e.des << "," << e.wei << ")";

}
void xuatArrE(AE ae) {
	for (int i = 0; i < ae.n; i++) {
		xuatEDGE(ae.ds[i]);
	}
}
int bacRaCuaDinh(ADJ g, int dinh) {
	int dem = 0;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			dem++;
		}
	}
	return dem;
}
int bacCuaDinhDTVH(ADJ g, int dinh) {
	int dem = 0;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			dem++;
		}
	}
	return dem;
}
AE traVeTapCanhDTVH(ADJ g) {
	AE ae;
	ae.n = 0;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0 && i < j) {
				EDGE e;
				e.org = i;
				e.des = j;
				e.wei = g.ds[i][j];
				ae.ds[ae.n] = e;
				ae.n++;
			}
		}
	}
	return ae;
}
void nhapTapCanh(AE& ae, int soDinh) {
	EDGE e;
	ae.n = 0;
	do {
		cout << "\nNhap org: ";
		cin >> e.org;
		cout << "\nNhap des: ";
		cin >> e.des;
		cout << "\nNhap wei: ";
		cin >> e.wei;
		if (e.org > soDinh || e.des > soDinh)  break;
		ae.ds[ae.n] = e;
		ae.n++;
	} while (1);
}
ADJ maTranKeDTVH(AE& ae, int soDinh) {
	ADJ g;
	g.n = soDinh;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			g.ds[i][j] = 0;
		}
	}
	for (int i = 0; i < ae.n; i++) {
		g.ds[ae.ds[i].org][ae.ds[i].des] = ae.ds[i].wei;
		g.ds[ae.ds[i].des][ae.ds[i].org] = ae.ds[i].wei;
	}
	return g;
}
ADJ maTranKeDTCH(AE& ae, int soDinh) {
	ADJ g;
	g.n = soDinh;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			g.ds[i][j] = 0;
		}
	}
	for (int i = 0; i < ae.n; i++) {
		g.ds[ae.ds[i].org][ae.ds[i].des] = ae.ds[i].wei;
	}
	return g;
}
VERTEX dinhKeCoTrongSoLonNhat(ADJ g, int dinh) {
	int dinhv = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			if(dinhv == -1 || g.ds[dinh][j] < g.ds[dinh][dinhv])
			dinhv = j;
		}
	}
	return dinhv;
}
ADJ maTranDao(ADJ g) {
	ADJ g1;
	g1.n = g.n;
	for (int i = 0; i < g1.n; i++) {
		for (int j = 0; j < g1.n; j++) {
			if (g1.ds[i][j] != 0) {
				int temp = g1.ds[i][j];
				g1.ds[i][j] = g.ds[j][i];
				g.ds[j][i] = temp;
			}
		}
	}
	return g1;
}
int bacVaoCuaDinh(ADJ g, int dinh) {
	int dem = 0;
	for (int i = 0; i < g.n; i++) {
		if (g.ds[i][dinh] != 0) {
			dem++;
		}
	}
	return dem;
}
void xuatDinhKeCuaDinh(ADJ g, int dinh) {
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			cout << j << " ";
		}
	}
}
int tongBacRaDTCH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		tong += bacRaCuaDinh(g, i);
	}
	return tong;
}
int tongBacVaoDTCH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		tong += bacVaoCuaDinh(g, i);
	}
	return tong;
}
int tongBacCuaDTVH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		tong += bacCuaDinhDTVH(g, i);
	}
	return tong;
}
bool ktrDinhCoLap(ADJ g, int dinh) {
	if (bacRaCuaDinh(g, dinh) == 0 && bacVaoCuaDinh(g, dinh) == 0)
		return true;
	return false;
}
int demDinhCoLap(ADJ g) {
	int dem = 0;
	for (int i = 0; i < g.n; i++) {
		if (ktrDinhCoLap(g, i)) dem++;
	}
	return dem;
}
int demSoCanhDTCH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		tong += bacRaCuaDinh(g, i);
	}
	return tong;
}
int demSoCanhDTVH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (i < j && g.ds[i][j] != 0) {
				tong++;
			}
		}
	}
	return tong;
}

EDGE canhCoTrongSoLonNhat(ADJ g) {
	EDGE e;
	e.wei = -1;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0 && g.ds[i][j] > e.wei) {
				e.org = i;
				e.des = j;
				e.wei = g.ds[i][j];
			}
		}
	}
	return e;
}
EDGE canhCoTRongSoNhoNhat(ADJ g) {
	EDGE e;
	e.wei = -1;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0) {
				if (e.wei == -1 || g.ds[i][j] < e.wei) {
					e.org = i;
					e.des = j;
					e.wei = g.ds[i][j];
				}
			}
		}
	}
	return e;
}
EDGE canhCoTrongSoLonNhatDTVH(ADJ g) {
	EDGE e;
	e.wei = -1;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if(g.ds[i][j] != 0 && g.ds[i][j] > e.wei && i < j) {
				e.org = i;
				e.des = j;
				e.wei = g.ds[i][j];
			}
		}
	}
	return e;
}
EDGE canhCoTrongSoNhoNhatDTVH(ADJ g) {
	EDGE e;
	e.wei = -1;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0 && i < j) { 
				if (e.wei == -1 || g.ds[i][j] < e.wei) {
					e.org = i;
					e.des = j;
					e.wei = g.ds[i][j];
				}
			}
		}
	}
	return e;
}
int tongTrongSoCacCanhDTCH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0) {
				tong += g.ds[i][j];
			}
		}
	}
	return tong;
}
int tongTrongSoCacCanhDTVH(ADJ g) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0 && i < j) {
				tong += g.ds[i][j];
			}
		}
	}
	return tong;
}

EDGE canhDiVaoCoTrongSoLonNhat(ADJ g, int dinh) {
	EDGE e;
	e.wei = -1;
	for (int i = 0; i < g.n; i++) {
		if (g.ds[i][dinh] != 0 && g.ds[i][dinh] > e.wei) {
			e.org = i;
			e.des = dinh;
			e.wei = g.ds[i][dinh];
		}
	}
	return e;
}
EDGE canhDiVaoCoTrongSoNhoNhat(ADJ g, int dinh) {
	EDGE e;
	e.wei = -1;
	for (int i = 0; i < g.n; i++) {
		if (g.ds[i][dinh] != 0) {
			if (e.wei == -1 || g.ds[i][dinh] < e.wei) {
				e.org = i;
				e.des = dinh;
				e.wei = g.ds[i][dinh];
			}
		}
	}
	return e;
}
EDGE canhDiRaCoTrongSoLonNhat(ADJ g, int dinh) {
	EDGE e;
	e.wei = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0 && g.ds[dinh][j] > e.wei) {
			e.org = dinh;
			e.des = j;
			e.wei = g.ds[dinh][j];
		}
	}
	return e;
}
EDGE canhDiRaCoTrongSoNhoNhat(ADJ g, int dinh) {
	EDGE e;
	e.wei = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			if (e.wei == -1 || g.ds[dinh][j] < e.wei) {
				e.org = dinh;
				e.des = j;
				e.wei = g.ds[dinh][j];
			}
		}
	}
	return e;
}
void daoHuongMotCanh(ADJ& g, int o, int d) {
	int temp = g.ds[o][d];
	g.ds[o][d] = g.ds[d][o];
	g.ds[d][o] = temp;
}
void daoHuongTatCa(ADJ& g) {
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (i < j)
				daoHuongMotCanh(g, i, j);
		}
	}
}
AE traVeTapCanhDTCH(ADJ g) {
	AE ae;
	ae.n = 0;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0) {
				EDGE e;
				e.org = i;
				e.des = j;
				e.wei = g.ds[i][j];
				ae.ds[ae.n] = e;
				ae.n++;
			}
		}
	}
	return ae;
}
//DANHSACHKE maTranSangDanhSachKe(ADJ g) {
//	DANHSACHKE dsk;
//	dsk.n = g.n;
//	for (int i = 0; i < g.n; i++) {
//		dsk.dsk[i] = NULL;
//		for (int j = 0; j < g.n; j++) {
//			if (g.ds[i][j] != 0) {
//				NODE* p = new NODE();
//				p->dinhke = j;
//				p->trongso = g.ds[i][j];
//				p->link = dsk.dsk[i];
//				dsk.dsk[i] = p;
//			}
//		}
//	}
//	return dsk;
//}
//void xuatDSK(DANHSACHKE x) {
//	cout << endl;
//	for (int i = 0; i < x.n; i++) {
//		cout << endl;
//		NODE* p = x.dsk[i];
//		cout << i << ": ";
//		while (p != NULL) {
//			cout << " (" << p->dinhke << "," << p->trongso << ")";
//			p = p->link;
//		}
//	}
//}
DANHSACHKE maTranSangDanhSachKe(ADJ g) {
	DANHSACHKE dsk;
	dsk.n = g.n;
	for (int i = 0; i < dsk.n; i++) {
		dsk.dsk[i] = NULL;
	}
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if(g.ds[i][j] != 0) {
				NODE* p = new NODE();
				p->dinhke = j;
				p->trongso = g.ds[i][j];
				p->link = dsk.dsk[i];
				dsk.dsk[i] = p;
			}
		}
	}
	return dsk;
}

void xuatDSK(DANHSACHKE x) {
	cout << "\n" << x.n << endl;
	for (int i = 0; i < x.n; i++) {
		cout << i << ": ";
		NODE* p = x.dsk[i];
		while (p) {
			cout << "( " << p->dinhke << ", " << p->trongso << ") ";
			p = p->link;
		}
		cout << endl;
	}
}

int dinhCoBacRaLonNhat(ADJ g) {
	int maxBac = -1;
	int dinh = -1;
	for (int i = 0; i < g.n; i++) {
		if (bacRaCuaDinh(g, i) > maxBac) {
			dinh = i;
			maxBac = bacRaCuaDinh(g, i);
		}
	}
	return dinh;
}
int dinhCoBacRaNhoNhat(ADJ g) {
	int maxBac = -1;
	int dinh = -1;
	for (int i = 0; i < g.n; i++) {
		if (dinh == -1 || bacRaCuaDinh(g, i) < maxBac) {
			dinh = i;
			maxBac = bacRaCuaDinh(g, i);
		}
	}
	return dinh;
}
int dinhCoBacVaolonNhat(ADJ g);
int dinhCoBacVaoNhoNhat(ADJ g);
int dinhKeCoBacRaLonNhat(ADJ g, int dinh, int& dinhKe) {
	int bacRa = -1;
	for (int i = 0; i < g.n; i++) {
		if (g.ds[dinh][i] != 0) {
			if (bacRaCuaDinh(g, i) > bacRa) {
				bacRa = bacRaCuaDinh(g, i);
				dinhKe = i;
			}
		}
	}
	if (bacRa != -1)
		return 1;
	return 0;
}
int dinhKeCoBacRaNhoNhat(ADJ g, int dinh, int& dinhKe) {
	int bacRa = -1;
	for (int i = 0; i < g.n; i++) {
		if (g.ds[dinh][i] != 0) {
			if (bacRa == -1 ||bacRaCuaDinh(g, i) < bacRa) {
				bacRa = bacRaCuaDinh(g, i);
				dinhKe = i;
			}
		}
	}
	if (bacRa != -1)
		return 1;
	return 0;
}
int timCanhCoTrongSoLonNhat(ADJ g, EDGE& canhMax) {
	int wei = -1;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0) {
				if (g.ds[i][j] > wei) {
					canhMax.org = i;
					canhMax.des = j;
					canhMax.wei = g.ds[i][j];
					wei = g.ds[i][j];
				}
			}
		}
	}
	if (wei != -1)
		return 1;
	return 0;
}
int timCanhCoTrongSoNhoNhat(ADJ g, EDGE& canhMin) {
	int wei = -1;
	for (int i = 0; i < g.n; i++) {
		for (int j = 0; j < g.n; j++) {
			if (g.ds[i][j] != 0) {
				if (wei == -1 ||g.ds[i][j] < wei) {
					canhMin.org = i;
					canhMin.des = j;
					canhMin.wei = g.ds[i][j];
					wei = g.ds[i][j];
				}
			}
		}
	}
	if (wei != -1)
		return 1;
	return 0;
}
int tongTrongSoCacCanhRa(ADJ g, int dinh) {
	int tong = 0;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			tong += g.ds[dinh][j];
		}
	}
	return tong;
}
int tongTrongSoCacCanhVao(ADJ g, int dinh) {
	int tong = 0;
	for (int i = 0; i < g.n; i++) {
		if (g.ds[i][dinh] != 0) {
			tong += g.ds[i][dinh];
		}
	}
	return tong;
}
int canhCoTrongSoLonNhatKeDinh(ADJ g, int dinh, EDGE& canhKeMax) {
	int wei = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			if (g.ds[dinh][j] > wei) {
				wei = g.ds[dinh][j];
				canhKeMax.org = dinh;
				canhKeMax.des = j;
				canhKeMax.wei = g.ds[dinh][j];
			}
		}
	}
	if (wei != -1)
		return 1;
	return 0;
}
int canhCoTrongSoNhoNhatKeDinh(ADJ g, int dinh, EDGE& canhKeMin) {
	int wei = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			if (wei == -1 ||g.ds[dinh][j] < wei) {
				wei = g.ds[dinh][j];
				canhKeMin.org = dinh;
				canhKeMin.des = j;
				canhKeMin.wei = g.ds[dinh][j];
			}
		}
	}
	if (wei != -1)
		return 1;
	return 0;
}
int dinhKeRaCoTrongSoLonNhat(ADJ g, int dinh, int& dinhKe) {
	int wei = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			if (g.ds[dinh][j] > wei) {
				dinhKe = j;
				wei = g.ds[dinh][j];
			}
		}
	}
	if (wei != -1)
		return 1;
	return 0;
}
int dinhKeRaCoTrongSoNhoNhat(ADJ g, int dinh, int& dinhKe) {
	int wei = -1;
	for (int j = 0; j < g.n; j++) {
		if (g.ds[dinh][j] != 0) {
			if (wei == -1 ||g.ds[dinh][j] < wei) {
				dinhKe = j;
				wei = g.ds[dinh][j];
			}
		}
	}
	if (wei != -1)
		return 1;
	return 0;
}




