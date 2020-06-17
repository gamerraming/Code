//Xuất đỉnh v ra màn hình
void printVertex(VERTEX v)
{
	cout << v;
}

//Xuất cạnh e ra màn hình
void printEdge(EDGE e)
{
	cout << "(" << e.org << "," << e.des << ")";
}

//Xuất danh sách đỉnh ra màn hình
void printArrayVertex(ArrayVertex av)
{
	for (int i = 0; i < av.count; i++)
	{
		cout << "\t";
		printVertex(av.ds[i]);
	}
}

//Xuất danh sách cạnh ra màn hình
void printArrayEdge(ArrayEdge ae)
{
	for (int i = 0; i < ae.count; i++)
	{
		cout << "\t";
		printEdge(ae.ds[i]);
	}
}

//Đọc một ma trận kề từ file văn bản.
int Read(char* filename, AdjacencyMatrix& g)
{
	FILE *f;
	fopen_s(&f, filename, "rt");
	if (f == NULL) return 0;
	fscanf_s(f, "%d", &g.n);
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			fscanf_s(f, "%d", &g.mt[i][j]);
	fclose(f);
	return 1;
}

//Ghi một ma trận kề lên file văn bản.
int Write(char* filename, AdjacencyMatrix g)
{
	FILE *f;
	fopen_s(&f, filename, "wt");
	if (f == NULL) return 0;
	fprintf(f, "%d", g.n);
	for (int i = 0; i < g.n; i++)
	{
		fprintf(f, "\n");
		for (int j = 0; j < g.n; j++)
			fprintf(f, "%d\t", g.mt[i][j]);
	}
	fclose(f);
	return 1;
}

//Hàm xuất ma trận kề ra màn hình
void Xuat(AdjacencyMatrix g)
{
	cout << "\n Gia tri trong file la: ";
	cout << "\n" << g.n << "\n";
	for (int i = 0; i < g.n; i++)
	{
		for (int j = 0; j < g.n; j++)
			cout << g.mt[i][j] << " ";
		cout << "\n";
	}
}

//Hàm tính bậc vào đồ thị có hướng
int TinhBacVaoDTCoHuong(AdjacencyMatrix g, int dinh)
{
	int dem = 0;
	for (int i = 0; i < g.n; i++)
	{
		if (g.mt[i][dinh] != 0)
			dem++;
	}
	return dem;
}

//Hàm trả về tập cạnh của đồ thị có hướng
ArrayEdge TapCanhDTCH(AdjacencyMatrix g)
{
	ArrayEdge tapcanh;
	tapcanh.count = 0;
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			if (g.mt[i][j] != 0)
			{
				EDGE e;
				e.org = i;
				e.des = j;
				e.wei = g.mt[i][j];
				tapcanh.ds[tapcanh.count] = e;
				tapcanh.count++;
			}
	return tapcanh;
}
//ham tinh bac ra do thi co huong
int TinhBacRaDTCoHuong(AdjacencyMatrix g, int dinh)
{
	int dem = 0;
	for (int i = 0; i < g.n; i++)
	{
		if (g.mt[dinh][i] != 0)
			dem++;
	}
	return dem;
}
//Bac cua mot dinh
int BacCuaMotDinh(AdjacencyMatrix g, int dinh)
{
	int dem = 0;
	for (int i = 0; i < g.n; i++)
	{
		if (g.mt[dinh][i] != 0)
			dem++;
	}
	return dem;
}
//ham tra ve tap canh do thi vo huong
ArrayEdge TapCanhDTVH(AdjacencyMatrix g)
{
	ArrayEdge tapcanh;
	tapcanh.count = 0;
	for (int i = 0; i < g.n; i++)
		for (int j = 0; j < g.n; j++)
			if (g.mt[i][j] != 0 && i < j )//hoac i>j
			{
				EDGE e;
				e.org = i;
				e.des = j;
				e.wei = g.mt[i][j];
				tapcanh.ds[tapcanh.count] = e;
				tapcanh.count++;
			}
	return tapcanh;
}
//nhap canh
void NhapCanh(VERTEX &dau, VERTEX &cuoi, int &trso)
{
	cout << "\nNhap dinh dau:";
	cin >> dau;
	cout << "\nNhap dinh cuoi:";
	cin >> cuoi;
	cout << "\nNhap trong so:";
	cin >> trso;
}
//Nhap danh sach canh
void NhapDSCanh(ArrayEdge &ae)
{
	ae.count = 0;
	char lenh;
	int i = 0;
	while (1)
	{
		cout << "\nBan muon tiep tuc? (Y/N)";
		cin >> lenh;
		if (lenh == 'n' or lenh == 'N')
			break;
		NhapCanh(ae.ds[i].org, ae.ds[i].des, ae.ds[i].wei);
		ae.count++;
		i++;
	}
}
//cho dinh va cac canh tra ve ma tran ke
AdjacencyMatrix TraVeMaTranKe(int dinh, ArrayEdge e)
{
	AdjacencyMatrix am;
	am.n = dinh;
	for (int i = 0; i < dinh; i++)
		for (int j = 0; j < dinh; j++)
			am.mt[i][j] = 0;
	for (int i = 0; i < e.count; i++)
		am.mt[e.ds[i].org][e.ds[i].des] = e.ds[i].wei;
	return am;
}
//xuat ma tran ke
void xuatMaTran(AdjacencyMatrix mt)
{
	for (int i = 0; i < mt.n; i++)
	{
		for (int j = 0; j < mt.n; j++)
			cout << mt.mt[i][j] << "\t";
		cout << endl;
	}
}