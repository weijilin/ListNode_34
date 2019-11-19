#define _CRT_SECURE_NO_WARNINGS 1
#if 0
// 虚拟继承方式
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


// 虚拟继承和普通的单继承有什么区别？

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
// 菱形虚拟继承
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

	// C1从B中继承一个_b, C2从B中继承一个_b
	// D: 从C1中继承一个_b, 从C2中继承一个_b
	// D中就有两份_b
	// 如果直接通过派生类对象访问_b,编译器就不知道访问那个_b
	// 编译时报错：访问不明确
	// 以上就是菱形继承缺陷---菱形继承的二义性问题
	//d._b = 1;
	//d.TestFunc();

	// 代码通过编译：让访问明确
	// 1. 在_b前增加基类的名称
	d.C1::_b = 1;
	d._c1 = 2;

	d.C2::_b = 3;
	d._c2 = 4;

	d._d = 5;

	d.C1::TestFunc();
	d.C2::TestFunc();

	// 2. 能否让最顶层基类成员(B)在D类中只保存一份
	// 可以---菱形虚拟继承
	d._b = 0;
	d.TestFunc();
	return 0;
}
#endif
