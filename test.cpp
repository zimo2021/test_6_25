#include<iostream>
using namespace std;
//�������ʹ�������
//��������⣺����Ӻ������пռ俪�ٵ��˶���������ʹ�ö�̬��ʱ�򣬸���ָ�����ͷ�ʱ�޷����õ��������������
//����չʾ
//#include<string>
//class animal
//{
//public:
//	virtual void speak() = 0;
//	animal()
//	{
//		cout << "animal���캯������" << endl;
//	}
//	~animal()
//	{
//		cout << "animal������������" << endl;
//	}
//};
//class Cat:public animal
//{
//public:
//	virtual void speak()
//	{
//		cout <<*m_name<< "Сè��˵��" << endl;
//	}
//	Cat(string name)
//	{
//		cout << "Cat�Ĺ��캯������" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat��������������" << endl;
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
//������ݣ�
//animal���캯������
//Cat�Ĺ��캯������
//tomСè��˵��
//animal������������
//ȱ����Cat������������Ҳ����˵m_nameû�б��ͷŵ������ܻᵼ���ڴ�й¶  
//Ҫ��������⣬���õ���������������
//*/
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//�������������������Ľ�����
//#include<string>
//class animal
//{
//public:
//	virtual void speak() = 0;
//	animal()
//	{
//		cout << "animal���캯������" << endl;
//	}
//	//virtual ~animal()//��һ��virtual�ؼ��֣����ʱ������������֮�󣬷�����̬ʱ�����е�����Ҳ�ܱ�����  ��������
//	//{
//	//	cout << "animal������������" << endl;
//	//}
//	virtual ~animal() = 0;//����Ǵ�������  ��Ҫ������ʵ��  ����ᱨ�� ʹ���˴��������������Ҳ���ڳ�����  ������������
//};
//animal::~animal()
//{
//	cout << "animal������������" << endl;//�����Ϳ�����  ע���������ʹ�����������֮һ����
//}
//class Cat :public animal
//{
//public:
//	virtual void speak()
//	{
//		cout << *m_name << "Сè��˵��" << endl;
//	}
//	Cat(string name)
//	{
//		cout << "Cat�Ĺ��캯������" << endl;
//		m_name = new string(name);
//	}
//	~Cat()
//	{
//		cout << "Cat��������������" << endl;
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
//��̬�İ���չʾ�����Ե���װ
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
////intel����
//class intelCPU :public CPU
//{
//public:
//	virtual void func()
//	{
//		cout << "intelCUP��ʼ����" << endl;
//	}
//};
//class intelVideocard :public Videocard
//{
//public:
//	virtual void func()
//	{
//		cout << "intel���Կ���ʼ��ʾ��" << endl;
//	}
//};
//class intelmemory :public memory
//{
//public:
//	virtual void func()
//	{
//		cout << "intel�ڴ�����ʼ������" << endl;
//	}
//};
////���볧��
//class LenevoCPU :public CPU//����Ӣ�ĵ���д���� Ӧ��ΪLenovo���Ѿ�д�˺ö� �������
//{
//public:
//	virtual void func()
//	{
//		cout << "LenevoCUP��ʼ����" << endl;
//	}
//};
//class LenevoVideocard :public Videocard
//{
//public:
//	virtual void func()
//	{
//		cout << "Lenevo���Կ���ʼ��ʾ��" << endl;
//	}
//};
//class Lenevomemory :public memory
//{
//public:
//	virtual void func()
//	{
//		cout << "Lenevo�ڴ�����ʼ������" << endl;
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
//		cout << "computer��������������" << endl;//�ͷŶ�����Ա
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
//	//����һ̨�������
//	cout << "---------------------------" << endl;
//	cout << "������ԵĴ���" << endl;
//	computer* p=new computer(new LenevoCPU, new LenevoVideocard, new Lenevomemory);
//	p->dowork();
//	delete p;
//	//����һ̨intel����
//	cout << "---------------------------" << endl;
//	cout << "intel���ԵĴ���" << endl;
//	computer* p1 = new computer(new intelCPU, new intelVideocard, new intelmemory);
//	p1->dowork();
//	delete p1;
//	//����һ̨��ϵ���
//	cout << "---------------------------" << endl;
//	cout << "��ϵ��ԵĴ���" << endl;
//	computer* p2 = new computer(new intelCPU, new LenevoVideocard, new intelmemory);
//	p2->dowork();
//	delete p2;
//}
//int main()
//{
//	test();
//	return 0;
//}
//�ļ�����
//д�ļ�
//#include<fstream>
//void test()
//{
//	//��Ϊ�������
//	//1.��ͷ�ļ���fstream��
//	//2.�������ļ�
//	ofstream abc;
//	//3.��ָ����ʽ
//	abc.open("test.txt", ios::out);
//	/*
//	һЩ�ļ��򿪷�ʽ
//	ios::in:Ϊ���ļ������ļ�
//	ios::out:Ϊд�ļ������ļ�
//	ios::app:׷�ӷ�ʽд�ļ�
//	ios::trunc:����ļ����ڣ���ɾ�����ٴ����µ��ļ�
//	ios::binary�Զ����Ʒ�ʽд�ļ�
//	*/
//	//4.д����
//	abc << "����������" << endl;//endl���ļ���������Ȼ��Ч
//	abc << "�Ա���" << endl;
//	abc << "���䣺18" << endl;
//	//5.�ر��ļ�
//	abc.close();//���к��������Ӧ��·���¿���������test.txt�ı��ļ�  ��c���Ե�Ч�����
//}
//int main()
//{
//	test();
//	return 0;
//}
//���ļ�
//#include<fstream>
//#include<string>
//void test()
//{
//	//1.��ͷ�ļ�
//	//2.����������
//	ifstream ifs;
//	//3.���ļ����ж��ļ��Ƿ�򿪳ɹ�
//	ifs.open("test.txt", ios::in);
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
	//4.�����ݣ����ַ���ѡ��һ�֣�
	//����һ
	//char arr[1000];
	//while (ifs >> arr)//һ��һ�ж�ȡ��ֱ��û������
	//{
	//	cout << arr << endl;//�ɹ�
	//}
	//������
	//char arr[1000];
	//while (ifs.getline(arr, sizeof(arr)))
	//{
	//	cout << arr << endl;//�ɹ�
	//}
	//������
	//string arr;
	//while (getline(ifs, arr))
	//{
	//	cout << arr << endl;//�ɹ�������ѡ�����ְɣ�
	//}
	//���ģ����Ƽ����ٶȱȽ�����
	//char c;
	//while ((c = ifs.get()) != EOF)
	//{
	//	cout << c;//�ɹ�
	//}
	//5.�ر��ļ�
//	ifs.close();
//}
//int main()
//{
//	test();
//	return 0;
//}
//�Զ����Ƶķ�ʽд�ļ�
//#include<fstream>
//class people
//{
//public:
//	char m_name[20];
//	int m_age;
//};
//void test()
//{
//	people p = { "����", 18 };//�໹��������ʼ��
//	//1.��ͷ�ļ�
//	//2.�������������
//	ofstream ofs;
//	//3.���ļ�
//	ofs.open("people.txt", ios::out | ios::binary);//��|������������
//	//4.д�ļ�
//	ofs.write((const char*)&p, sizeof(p));//����write����Ҫ��&pҪתΪconst char* ���� �˴���const�����Ա�֤�ڴ�������в��ı�ԭ����
//	//�ر��ļ�
//	ofs.close();//����Ӧ·���¿����ҵ���Ӧ�Ķ������ļ�
//		
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//�Զ����Ƶ���ʽ���ļ�
//#include<fstream>
//class people
//{
//public:
//	char m_name[20];
//	int m_age;
//};
//void test()
//{
//	//1.��ͷ�ļ�
//	//2.����������
//	ifstream ifs;
//	//3.���ļ�
//	ifs.open("people.txt", ios::in | ios::binary);//���people����people1���ӡ"�ļ���ʧ��"��Ϊû������ļ�
//	if (!ifs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//	//4.������
//	people p;
//	ifs.read((char*)&p, sizeof(p));//����Ͳ�Ҫ��const��
//	cout << "������" << p.m_name << "���䣺" << p.m_age << endl;
//	//5.�ر��ļ�
//	ifs.close();
//}
//int main()
//{
//	test();
//	return 0;
//}





