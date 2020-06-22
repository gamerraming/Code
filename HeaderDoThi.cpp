#include <iostream>
using namespace std;

//MAXV: số đỉnh tối đa
const int MAXV = 20;

//MAXE: số cạnh tối đa
const int MAXE = MAXV * MAXV;

//Cau truc hang doi
typedef int TYPEINFO;
struct Queue
{
	TYPEINFO ds[MAXV];
	int n;
};

//VERTEX: Kiểu của một đỉnh
typedef int VERTEX;

//EDGE: Kiểu của một cạnh
struct EDGE
{
	VERTEX org; //Origin
	VERTEX des; //Destination
	int wei; //weight
};

//ArrayVertex: danh sách đỉnh
struct ArrayVertex
{
	VERTEX ds[MAXV];
	int count;
};

//ArrayEdge: danh sách cạnh
struct ArrayEdge
{
	EDGE ds[MAXE];
	int count;
};

//Ma trận kề của đồ thị (Adjacency-matrix)
struct AdjacencyMatrix
{
	int mt[MAXV][MAXV];
	int n;
};

//Xuất đỉnh v ra màn hình
void printVertex(VERTEX v);

//Xuất cạnh e ra màn hình
void printEdge(EDGE e);

//Xuất danh sách đỉnh ra màn hình
void printArrayVertex(ArrayVertex av);

//Xuất danh sách cạnh ra màn hình
void printArrayEdge(ArrayEdge ae);

//Đọc một ma trận kề từ file văn bản.
int Read(char* filename, AdjacencyMatrix& g);

//Ghi một ma trận kề lên file văn bản.
int Write(char* filename, AdjacencyMatrix g);

//Hàm xuất ma trận kề ra màn hình
void Xuat(AdjacencyMatrix g);

//Hàm tính bậc vào đồ thị có hướng
int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh);

//Hàm trả về tập cạnh của đồ thị có hướng
ArrayEdge TapCanhDTCH(AdjacencyMatrix g);

//ham tinh bac ra cua do thi co huong
int TinhBacRaDTCoHuong(AdjacencyMatrix g, int dinh);
//Bac cua mot dinh
int BacCuaMotDinh(AdjacencyMatrix g, int dinh);

//ham tra ve tap canh do thi vo huong
ArrayEdge TapCanhDTVH(AdjacencyMatrix g);

//nhap canh
void NhapCanh(VERTEX &dau, VERTEX &cuoi, int &trso);
//Nhap danh sach canh
void NhapDSCanh(ArrayEdge &ae);
//cho dinh va cac canh tra ve ma tran ke(do thi vo huong)
AdjacencyMatrix TraVeMaTranKeVoHuong(int dinh, ArrayEdge e);

//xuat ma tran ke
void xuatMaTran(AdjacencyMatrix mt);

//cho dinh va cac canh tra ve ma tran ke (do thi co huong)
AdjacencyMatrix TraVeMaTranKeCoHuong(int dinh, ArrayEdge e);

//tim dinh ke dinh u co trong so nho nhat
VERTEX timDinhKeUCoTSMin(AdjacencyMatrix mt, VERTEX u);

//cho ma tran ke G tao ra ma tran G' bang cach doi huong tat ca cac canh cua G
AdjacencyMatrix DoiHuongMaTranKe(AdjacencyMatrix g);

// duyet theo chieu rong BFS
void BFS(AdjacencyMatrix mt, VERTEX s);

//Cac ham ho tro QUEUE
void InitQueue(Queue &q);
void PushQueue(Queue &q, TYPEINFO a);
void PopQueue(Queue &q, TYPEINFO &a);
int IsEmptyQueue(Queue q);
int IsFullQueue(Queue q);