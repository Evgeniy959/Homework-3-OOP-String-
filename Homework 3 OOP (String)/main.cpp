#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class String
{
	char* str; // Указатель на строку динамической памяти 
	int size; // Размер строки 
public:

	const char* get_str()const
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}
	void set_str(char* str)
	{
		this->str = str;
	}
	void set_size(int size)
	{
		this->size = size;
	}
	//            Conctructors

	explicit String(int size = 70)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy_s(this->str, size, str);// копируем строку (string copy)
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy_s(this->str, size, other.str);
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
	}

	//            Methods:
	void print()const
	{
		cout << "str: " << tab << str << endl;
		cout << "size: " << tab << size << endl;
	}
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
	String str;
	str.print();
	
	String str2(7);
	str2.print();
	
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;
	
	String str4 = str3; // CopyConstructor 
	cout << "Str4 - " << str4 << endl;
}

