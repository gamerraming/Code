//Source AVLTree

void InitAVL(NODEAVL &t)
{
	t = NULL;
}
NODEAVL createNode(TYPEINFO a)
{
	NODEAVL p = new NodeAVL();
	p->height = 1;
	p->info = a;
	p->left = NULL;
	p->right = NULL;
	return p;
}
int doCao(NODEAVL t)
{
	if (t == NULL)
		return 0;
	int lef = 1 + doCao(t->left);
	int rig = 1 + doCao(t->right);
	int aws = lef >= rig ? lef : rig;
	return aws;
}
int Max(int a, int b)
{
	return (a > b) ? a : b;
}
int height(NODEAVL T)
{
	if (T == NULL)
		return 0;
	else
		return 1 + Max(height(T->left), height(T->right));
}
NODEAVL insertNode(NODEAVL &t, TYPEINFO a)
{
	NODEAVL result;
	if (t == NULL)
	{
		t = createNode(a);
		return t;
	}
	else if (t->info == a)
		return NULL;
	else if (t->info > a)
		result = insertNode(t->left, a);
	else
		result = insertNode(t->right, a);
	t->height = height(t);
	int hieu = height(t->left) - height(t->right);
	if (hieu > 1 || hieu < -1)
	{
		if (hieu > 1)
		{
			if (height(t->left->left) > height(t->left->right))
				rotateRight(t);
			else
				rotateLeftRight(t);
		}
		else
		{
			if (height(t->right->left) > height(t->right->right))
				rotateRightLeft(t);
			else
				rotateLeft(t);
		}
	}
	return result;
}
void nhapCayAVL(NODEAVL &t)
{
	TYPEINFO x;
	while (1)
	{
		cout << "\nNhap node cho cay: (-99 de thoat)";
		cin >> x;
		if (x == -99)
			break;
		insertNode(t, x);
	}
}
void duyetNLR(NODEAVL t)
{
	if (t != NULL)
	{
		cout << t->info << "\t";
		duyetNLR(t->left);
		duyetNLR(t->right);
	}
}
void rotateLeft(NODEAVL &t)
{
	NODEAVL t1 = t->right;
	t->right = t1->left;
	t1->left = t;
	t->height = doCao(t);
	t1->height = doCao(t1);
	t = t1;
}
void rotateRight(NODEAVL &t)
{
	NODEAVL t1 = t->left;
	t->left = t1->right;
	t1->right = t;
	t->height = doCao(t);
	t1->height = doCao(t1);
	t = t1;
}
void rotateLeftRight(NODEAVL &t)
{
	rotateLeft(t->left);
	rotateRight(t);
}
void rotateRightLeft(NODEAVL &t)
{
	rotateRight(t->right);
	rotateLeft(t);
}
NODEAVL minValue(NODEAVL t)
{
	NODEAVL p = t;
	while (p->left!=NULL)
		p = p->left;
	return p;
}
int deleteNode(NODEAVL &t, TYPEINFO a)
{
	int result = 1;
	if (t == NULL)
		return 0;
	else
	{
		if (t->info > a)
			result = deleteNode(t->left, a);
		else if (t->info < a)
			result = deleteNode(t->right, a);
		else
		{
			NODEAVL p = t;
			if (p->left == NULL)
			{
				t = t->right;
				delete p;
			}
			else if (p->right == NULL)
			{
				t = t->left;
				delete p;
			}
			else
			{
				NODEAVL q = minValue(t->right);
				t->info = q->info;
				result = deleteNode(t->right, q->info);
			}
		}
	}
	if (t != NULL)
	{
		t->height = height(t);
		int hieu = height(t->left) - height(t->right);
		if (hieu > 1 || hieu < -1)
		{
			if (hieu > 1)
			{
				if (height(t->left->left) < height(t->left->right))
					rotateLeftRight(t);
				else
					rotateRight(t);
			}
			else
			{
				if (height(t->right->left) > height(t->right->right))
					rotateRightLeft(t);
				else
					rotateLeft(t);
			}
		}
	}
	return result;
}
int sLuongBoiX(NODEAVL t, int x)
{
	int dem = 0;
	if (t == NULL)
		return dem;
	else
	{
		if (t->info%x == 0)
			dem++;
		return dem + sLuongBoiX(t->right, x) + sLuongBoiX(t->left, x);
	}
}
int sum(NODEAVL T)
{
	if (T == NULL)
		return 0;
	else
		return T->data + sum(T->left) + sum(T->right);
}
int demSoKhoa(NODEAVL t)
{
	int dem = 0;
	if (t == NULL)
		return dem;
	else
		return 1+ demSoKhoa(t->left)+demSoKhoa(t->right);
}
float avSum(NODEAVL t)
{
	return (float)sum(t) / demSoKhoa(t);
}
bool ktraSNT(int n)
{
	if (n < 2)
		return false;
	else
	{
		if (n == 2)
			return true;
		else
		{
			for (int i = 2; i <= n / 2; i++)
				if (n%i == 0)
					return false;
			return true;
		}
	}
}
bool ktraSHT(int n)
{
	if (n <= 0)
		return false;
	else
	{
		int sum = 0;
		for (int i = 1; i <= n / 2; i++)
			sum += i;
		if (sum == n)
			return true;
		else
			return false;
	}
}
bool ktraSCP(int n)
{
	int cannguyen = sqrt(n);
	if (cannguyen*cannguyen == n)
		return true;
	else
		return false;
}
int demCacKhoaSNT(NODEAVL t)
{
	int dem = 0;
	if (t == NULL)
		return dem;
	else
	{
		if (ktraSNT(t->data) == true)
			dem++;
		return dem + demCacKhoaSNT(t->left) + demCacKhoaSNT(t->right);
	}

}
int demCacKhoaSHT(NODEAVL t)
{
	int dem = 0;
	if (t == NULL)
		return dem;
	else
	{
		if (ktraSHT(t->data) == true)
			dem++;
		return dem + demCacKhoaSHT(t->left); +demCacKhoaSHT(t->right);
	}
}
int demCacKhoaSCP(NODEAVL t)
{
	int dem = 0;
	if (t == NULL)
		return dem;
	else
	{
		if (ktraSCP(t->data) == true)
			dem++;
		return dem + demCacKhoaSCP(t->left); +demCacKhoaSCP(t->right);
	}
}
void xuatCacNodeSNT(NODEAVL t)
{
	if (t == NULL)
		return;
	else
	{
		if (ktraSNT(t->data) == true)
			cout << t->data << "\t";
		xuatCacNodeSNT(t->left);
		xuatCacNodeSNT(t->right);
	}
}