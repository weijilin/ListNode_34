#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// ����̳з�ʽ
class B
{
public:
	int _b;
};

class D : virtual public B
{
public:
	int _d;
};


// ����̳к���ͨ�ĵ��̳���ʲô����

int main()
{
	cout << sizeof(D) << endl;

	D d;
	d._b = 1;
	d._d = 2;
	return 0;
}
#endif

#if 0
// ��������̳�
class B
{
public:
	void TestFunc()
	{}

public:
	int _b;
};

class C1 : virtual public B
{
public:
	int _c1;
};

class C2 : virtual public B
{
public:
	int _c2;
};


class D : public C1, public C2
{
public:
	int _d;
};

int main()
{
	cout << sizeof(D) << endl;

	D  d;

	// C1��B�м̳�һ��_b, C2��B�м̳�һ��_b
	// D: ��C1�м̳�һ��_b, ��C2�м̳�һ��_b
	// D�о�������_b
	// ���ֱ��ͨ��������������_b,�������Ͳ�֪�������Ǹ�_b
	// ����ʱ�������ʲ���ȷ
	// ���Ͼ������μ̳�ȱ��---���μ̳еĶ���������
	//d._b = 1;
	//d.TestFunc();

	// ����ͨ�����룺�÷�����ȷ
	// 1. ��_bǰ���ӻ��������
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	d.C1::TestFunc();
	d.C2::TestFunc();

	// 2. �ܷ����������Ա(B)��D����ֻ����һ��
	// ����---��������̳�
	d._b = 0;
	d.TestFunc();
	return 0;
}
#endif
