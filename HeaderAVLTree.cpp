//Code
//Cấu trúc cây AVL và Các hàm hổ trợ
// thiếu thì bổ sung
typedef int TYPEINFO;
struct NodeAVL
{
	NodeAVL* left;
	NodeAVL* right;
	int height;
	TYPEINFO info;
};
typedef NodeAVL* NODEAVL;

void InitAVL(NODEAVL &t);
NODEAVL createNode(TYPEINFO a);
int doCao(NODEAVL t);
int Max(int a, int b);
int height(NODEAVL T);
NODEAVL insertNode(NODEAVL &t, TYPEINFO a);
void nhapCayAVL(NODEAVL &t);
void duyetNLR(NODEAVL t);
void rotateLeft(NODEAVL &t);
void rotateRight(NODEAVL &t);
void rotateLeftRight(NODEAVL &t);
void rotateRightLeft(NODEAVL &t);
NODEAVL minValue(NODEAVL t);
int deleteNode(NODEAVL &t, TYPEINFO a);
int sLuongBoiX(NODEAVL t , int x);
int sum(NODEAVL T);
int demSoKhoa(NODEAVL t);
float avSum(NODEAVL t);
bool ktraSNT(int n);
bool ktraSHT(int n);
bool ktraSCP(int n);
int demCacKhoaSNT(NODEAVL t);
int demCacKhoaSHT(NODEAVL t);
int demCacKhoaSCP(NODEAVL t);
void xuatCacNodeSNT(NODEAVL t);