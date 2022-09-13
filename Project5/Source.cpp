#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
	char* str; // ��������� �� ������
	int length; // ����� ������
	static int obj_count;
public:
	MyString();
	MyString(const char*);
	MyString(const MyString &);
	~MyString();
	static void ObjCount();
	void Init();
	void Print();
	void MyStrcpy(const MyString& obj);
	bool MyStrStr(const char* Substr);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(const MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(const MyString& b);
};
int MyString::obj_count = 0;

MyString::MyString()
{
	length = 80;
	str[length];
	obj_count++;
}

MyString::MyString(const char* text)
{
	str = new char[strlen(text) + 1];
	strcpy_s(str, strlen(text) + 1, text);
	length = strlen(text);
	obj_count++;
}
MyString::MyString(const MyString& obj)
{
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = strlen(obj.str);
	obj_count++;
}

MyString::~MyString()
{
	cout << "\nDESTRUCTOR\n";
	delete[]str;
}

void MyString::Print()
{
	cout << "Str: " << str << "\tLenght: " << length << "\n";
}

void MyString::Init()
{
	char* text = new char[length];
	cout << "Enter str -> ";
	cin >> text;
	if (str != nullptr)
	{
		delete[]str;
	}
	str = new char[strlen(text) + 1];
	strcpy_s(str, strlen(text) + 1, text);
	length = strlen(str);
	obj_count++;
	delete[]text;
}

void MyString::MyStrcpy(const MyString& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = strlen(obj.str);
}

bool MyString::MyStrStr(const char* Substr)
{
	return strstr(str, Substr);
}

int MyString::MyChr(char c)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
			cout << i << " ";
		else
			continue;
	}
	return 0;
}

int MyString::MyStrLen()
{
	return strlen(str);
}

void MyString::MyStrCat(const MyString& b)
{
	strcat_s(str, strlen(str) + strlen(b.str) + 1, b.str);
	length = strlen(str);
}

void MyString::MyDelChr(char c)
{
	int count = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
			continue;
		else
			count++;
	}
	count++;
	char* buff = new char[count];
	int count2 = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
			continue;
		else
		{
			buff[count2] = str[i];
			count2++;
		}
	}
	delete[]str;
	str = new char[count];
	strcpy_s(str, strlen(buff) + 1, buff);
	length = strlen(str);
	delete[]buff;
}

int MyString::MyStrCmp(const MyString& b)
{
	if (strlen(str) > strlen(b.str))
		return 1;
	else if (strlen(str) < strlen(b.str))
		return -1;
	else
		return 0;
}

void MyString::ObjCount()
{
	cout << "Obj count = " << obj_count << endl;
}

int main()
{
	MyString obj1("Hello");
	MyString obj2("World!!!");
	obj1.Print();
	obj2.Print();
	MyString::ObjCount();
}