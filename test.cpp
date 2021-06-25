#include<iostream>
using namespace std;
//虚析构和纯虚析构
//解决的问题：如果子函数中有空间开辟到了堆区，则在使用多态的时候，父类指针在释放时无法调用到子类的析构函数
//代码展示
//#include<string>
//class animal
//{
//public:
//	virtual void speak() = 0;
//	animal()
//	{
//		cout << "animal构造函数调用" << endl;
//	}
//	~animal()
//	{
//		cout << "animal析构函数调用" << endl;
//	}
//};
//class Cat:public animal
//{
//public:
//	virtual void speak()
//	{
//		cout <<*m_name<< "小猫在说话" << endl;
//	}
//	Cat(string name)
//	{
//		cout << "Cat的构造函数调用" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat的析构函数调用" << endl;
//		if (m_name != NULL)
//		{
//			delete m_name;
//			m_name = NULL;
//		}
//	}
//	string* m_name;
//};
//void test()
//{
//	animal* abc = new Cat("tom");
//	abc->speak();
//	delete abc;
///*
//输出内容：
//animal构造函数调用
//Cat的构造函数调用
//tom小猫在说话
//animal析构函数调用
//缺少了Cat函数的析构，也就是说m_name没有被释放掉，可能会导致内存泄露  
//要解决此问题，需用到虚析构或纯虚析构
//*/
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//利用虚析构或纯虚析构改进代码
//#include<string>
//class animal
//{
//public:
//	virtual void speak() = 0;
//	animal()
//	{
//		cout << "animal构造函数调用" << endl;
//	}
//	//virtual ~animal()//加一个virtual关键字，这个时虚析构，加了之后，发生多态时子类中的析构也能被调用  这样可以
//	//{
//	//	cout << "animal析构函数调用" << endl;
//	//}
//	virtual ~animal() = 0;//这个是纯虚析构  需要在类外实现  否则会报错 使用了纯虚析构后这个类也属于抽象类  不可声明变量
//};
//animal::~animal()
//{
//	cout << "animal析构函数调用" << endl;//这样就可以了  注：虚析构和纯虚析构其中之一即可
//}
//class Cat :public animal
//{
//public:
//	virtual void speak()
//	{
//		cout << *m_name << "小猫在说话" << endl;
//	}
//	Cat(string name)
//	{
//		cout << "Cat的构造函数调用" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat的析构函数调用" << endl;
//		if (m_name != NULL)
//		{
//			delete m_name;
//			m_name = NULL;
//		}
//	}
//	string* m_name;
//};
//void test()
//{
//	animal* abc = new Cat("tom");
//	abc->speak();
//	delete abc;
//	
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//多态的案例展示—电脑的组装
//class CPU
//{
//public:
//	virtual void func() = 0;
//};
//class Videocard
//{
//public:
//	virtual void func() = 0;
//};
//class memory
//{
//public:
//	virtual void func() = 0;
//};
////intel厂商
//class intelCPU :public CPU
//{
//public:
//	virtual void func()
//	{
//		cout << "intelCUP开始计算" << endl;
//	}
//};
//class intelVideocard :public Videocard
//{
//public:
//	virtual void func()
//	{
//		cout << "intel的显卡开始显示了" << endl;
//	}
//};
//class intelmemory :public memory
//{
//public:
//	virtual void func()
//	{
//		cout << "intel内存条开始储存了" << endl;
//	}
//};
////联想厂商
//class LenevoCPU :public CPU//联想英文单词写错了 应该为Lenovo但已经写了好多 不方便改
//{
//public:
//	virtual void func()
//	{
//		cout << "LenevoCUP开始计算" << endl;
//	}
//};
//class LenevoVideocard :public Videocard
//{
//public:
//	virtual void func()
//	{
//		cout << "Lenevo的显卡开始显示了" << endl;
//	}
//};
//class Lenevomemory :public memory
//{
//public:
//	virtual void func()
//	{
//		cout << "Lenevo内存条开始储存了" << endl;
//	}
//};
//class computer
//{
//public:
//	computer(CPU* cp,Videocard* vc,memory* mem)
//	{
//		m_cpu = cp;
//		m_vc = vc;
//		m_mem = mem;
//	}
//	~computer()
//	{
//		cout << "computer的析构函数调用" << endl;//释放堆区成员
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//		}
//		if (m_vc != NULL)
//		{
//			delete m_vc;
//		}
//		if (m_mem != NULL)
//		{
//			delete m_mem;
//		}
//	}
//	void dowork()
//	{
//		m_cpu->func();
//		m_vc->func();
//		m_mem->func();
//	}
//	CPU* m_cpu;
//	Videocard* m_vc;
//	memory* m_mem;
//};
//void test()
//{
//	//创建一台联想电脑
//	cout << "---------------------------" << endl;
//	cout << "联想电脑的创建" << endl;
//	computer* p=new computer(new LenevoCPU, new LenevoVideocard, new Lenevomemory);
//	p->dowork();
//	delete p;
//	//创建一台intel电脑
//	cout << "---------------------------" << endl;
//	cout << "intel电脑的创建" << endl;
//	computer* p1 = new computer(new intelCPU, new intelVideocard, new intelmemory);
//	p1->dowork();
//	delete p1;
//	//创建一台混合电脑
//	cout << "---------------------------" << endl;
//	cout << "混合电脑的创建" << endl;
//	computer* p2 = new computer(new intelCPU, new LenevoVideocard, new intelmemory);
//	p2->dowork();
//	delete p2;
//}
//int main()
//{
//	test();
//	return 0;
//}
//文件操作
//写文件
//#include<fstream>
//void test()
//{
//	//分为五个步骤
//	//1.引头文件（fstream）
//	//2.创建流文件
//	ofstream abc;
//	//3.打卡指定方式
//	abc.open("test.txt", ios::out);
//	/*
//	一些文件打开方式
//	ios::in:为读文件而打开文件
//	ios::out:为写文件而打开文件
//	ios::app:追加方式写文件
//	ios::trunc:如果文件存在，先删除，再创建新的文件
//	ios::binary以二进制方式写文件
//	*/
//	//4.写内容
//	abc << "姓名：张三" << endl;//endl在文件操作中仍然有效
//	abc << "性别：男" << endl;
//	abc << "年龄：18" << endl;
//	//5.关闭文件
//	abc.close();//运行后可以在相应的路径下看到创建的test.txt文本文件  和c语言的效果差不多
//}
//int main()
//{
//	test();
//	return 0;
//}
//读文件
//#include<fstream>
//#include<string>
//void test()
//{
//	//1.引头文件
//	//2.创建流对象
//	ifstream ifs;
//	//3.打开文件并判断文件是否打开成功
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
	//4.读数据（四种方法选择一种）
	//方法一
	//char arr[1000];
	//while (ifs >> arr)//一行一行读取，直到没有数据
	//{
	//	cout << arr << endl;//成功
	//}
	//方法二
	//char arr[1000];
	//while (ifs.getline(arr, sizeof(arr)))
	//{
	//	cout << arr << endl;//成功
	//}
	//方法三
	//string arr;
	//while (getline(ifs, arr))
	//{
	//	cout << arr << endl;//成功（个人选择这种吧）
	//}
	//法四（不推荐，速度比较慢）
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;//成功
	//}
	//5.关闭文件
//	ifs.close();
//}
//int main()
//{
//	test();
//	return 0;
//}
//以二进制的方式写文件
//#include<fstream>
//class people
//{
//public:
//	char m_name[20];
//	int m_age;
//};
//void test()
//{
//	people p = { "张三", 18 };//类还能这样初始化
//	//1.引头文件
//	//2.创建输出流对象
//	ofstream ofs;
//	//3.打开文件
//	ofs.open("people.txt", ios::out | ios::binary);//用|隔离两个命令
//	//4.写文件
//	ofs.write((const char*)&p, sizeof(p));//由于write的需要，&p要转为const char* 类型 此处的const还可以保证在传输过程中不改变原数据
//	//关闭文件
//	ofs.close();//在相应路径下可以找到相应的二进制文件
//		
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//以二进制的形式读文件
//#include<fstream>
//class people
//{
//public:
//	char m_name[20];
//	int m_age;
//};
//void test()
//{
//	//1.引头文件
//	//2.创建流对象
//	ifstream ifs;
//	//3.打开文件
//	ifs.open("people.txt", ios::in | ios::binary);//如果people换成people1则打印"文件打开失败"因为没有这个文件
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//	//4.读数据
//	people p;
//	ifs.read((char*)&p, sizeof(p));//这里就不要加const了
//	cout << "姓名：" << p.m_name << "年龄：" << p.m_age << endl;
//	//5.关闭文件
//	ifs.close();
//}
//int main()
//{
//	test();
//	return 0;
//}





