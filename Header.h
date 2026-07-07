
#include <iostream>
using namespace std;
const int MAXV = 20;
const int MAXE = MAXV * MAXV;
typedef int VERTEX;
typedef struct ArrayVertex {
	VERTEX ds[MAXV];
	int n;
}AV;
struct EDGE {
	VERTEX org;
	VERTEX des;
	int wei;
};
typedef struct ArrayEdge {
	EDGE ds[MAXE];
	int n;
}AE;
typedef struct AjencyMatrix {
	int ds[MAXV][MAXV];
	int n;
}ADJ;
//Danh Sach Ke:
const int MAXDSK = 15; //so dinh toi da
const int MAXDSC = MAXDSK * MAXDSK; // so canh toi da
struct NODE {
	int dinhke;
	int trongso = 0;
	NODE* link;
};
struct DANHSACHKE {
	NODE* dsk[MAXDSK];
	int n = 0;//so dinh cua do thi
};

int read(const char* filename, ADJ& g);
void xuatMaTran(ADJ g);
void xuatArrV(AV av);
void xuatEDGE(EDGE e);
void xuatArrE(AE ae);
int bacRaCuaDinh(ADJ g, int dinh);
int bacCuaDinhDTVH(ADJ g, int dinh);
AE traVeTapCanhDTVH(ADJ g);
void nhapTapCanh(AE& ae, int sodinh);
ADJ maTranKeDTVH(AE& ae, int soDinh);
ADJ maTranKeDTCH(AE& ae, int soDinh);
VERTEX dinhKeCoTrongSoLonNhat(ADJ g, int dinh);
ADJ maTranDao(ADJ g);
int bacVaoCuaDinh(ADJ g, int dinh);
void xuatDinhKeCuaDinh(ADJ g, int dinh);
int tongBacRaDTCH(ADJ g);
int tongBacVaoDTCH(ADJ g);
int tongBacCuaDTVH(ADJ g);
bool ktrDinhCoLap(ADJ g, int dinh);
int demDinhCoLap(ADJ g);
int demSoCanhDTCH(ADJ g);
int demSoCanhDTVH(ADJ g);
EDGE canhCoTrongSoLonNhat(ADJ g);
EDGE canhCoTRongSoNhoNhat(ADJ g);
EDGE canhCoTrongSoLonNhatDTVH(ADJ g);
EDGE canhCoTrongSoNhoNhatDTVH(ADJ g);
int tongTrongSoCacCanhDTCH(ADJ g);
int tongTrongSoCacCanhDTVH(ADJ g);
EDGE canhDiVaoCoTrongSoLonNhat(ADJ g, int dinh);
EDGE canhDiVaoCoTrongSoNhoNhat(ADJ g, int dinh);
EDGE canhDiRaCoTrongSoLonNhat(ADJ g, int dinh);
EDGE canhDiRaCoTrongSoNhoNhat(ADJ g, int dinh);
void daoHuongMotCanh(ADJ& g, int o, int d);
void daoHuongTatCa(ADJ& g);
AE traVeTapCanhDTCH(ADJ g);
DANHSACHKE maTranSangDanhSachKe(ADJ g);
void xuatDSK(DANHSACHKE x);
int dinhCoBacRaLonNhat(ADJ g);
int dinhCoBacRaNhoNhat(ADJ g);
int dinhCoBacVaolonNhat(ADJ g);
int dinhCoBacVaoNhoNhat(ADJ g);
int dinhKeCoBacRaLonNhat(ADJ g, int dinh, int& dinhKe);
int dinhKeCoBacRaNhoNhat(ADJ g, int dinh, int& dinhKe);
int timCanhCoTrongSoLonNhat(ADJ g, EDGE& canhMax);
int timCanhCoTrongSoNhoNhat(ADJ g, EDGE& canhMin);
int tongTrongSoCacCanhRa(ADJ g, int dinh);
int tongTrongSoCacCanhVao(ADJ g, int dinh);
int canhCoTrongSoLonNhatKeDinh(ADJ g, int dinh, EDGE& canhKeMax);
int canhCoTrongSoNhoNhatKeDinh(ADJ g, int dinh, EDGE& canhKeMin);
int dinhKeRaCoTrongSoLonNhat(ADJ g, int dinh, int& dinhKe);
int dinhKeRaCoTrongSoNhoNhat(ADJ g, int dinh, int& dinhKe);


