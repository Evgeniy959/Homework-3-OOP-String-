#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n---------------------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//Размер строки в Байтах
	char* str;	//Указатель на строку динамической памяти 
public:
	int get_size()const
	{
		return size;
	}
	/* v возвращает константный указатель (нельзя изменить значение по адресу)*/
	const char* get_str()const//Показывает, что это константный указатель
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//			Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80 ? "Default" : "Size") << "Constructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;//Указатель на ноль (NULL pointer) - указатель в никуда.
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveAssignment:\t\t" << this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	const char& operator[](int i) const
	{
		return this -> str[i];
	}
	char& operator[](int i) 
	{
		return this->str[i];
	}

	//			Methods:
	void print() const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);	//-1 убирает лишний ноль на конце
	for (int i = 0; i < left.get_size(); i++)
		//*(result.get_str() + i) = *(left.get_str() + i);
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;
}

/*------------------------------------------------------------*/
bool operator==(const String& left, const String& right)
{	
	return left.get_size() == right.get_size();
}

bool operator!=(const String& left, const String& right)
{
	return left.get_size() != right.get_size();
}

bool operator<=(const String& left, const String& right)
{
	return left.get_size() <= right.get_size();
}

bool operator>=(const String& left, const String& right)
{
	return left.get_size() >= right.get_size();
}

bool operator<(const String& left, const String& right)
{
	return left.get_size() < right.get_size();
}

bool operator>(const String& left, const String& right)
{
	return left.get_size() > right.get_size();
}

//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	String str;		//Default constructor
	str.print();

	String str1 = "Hello";	//Single argument constructor
	str1.print();
	cout << "str1:" << str1 << endl;
	String str2 = str1;		//Copy constructor
	cout << "str2:" << str2 << endl;

	str = str2;		//Copy assignment
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	str1.print();
	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;

	int a = 2;
	a = a;
	cout << a << endl;
#endif // ASSIGNMENT_CHECK

	/*String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2;//Operator + будет выполнять конкатенацию строк (слияние, объединение) строк
	cout << delimiter << endl;
	cout << str3 << endl;*/

	//cout << delimiter << endl;
	//str1 += str2;
	//cout << delimiter << endl;
	//cout << str1 << endl;
	//String str3 = str1;//Copy constructor
	//String str4;
	//str4 = str2;	//Operator=

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;

	String str4 = "Hello";
	String str5 = "World";
	cout << "str4 = " << str4 << tab << "str5 = " << str5 << endl;
	cout << "(str4 == str5) равно : " << (str4 == str5) << endl;
	cout << "( str4 != str5 ) равно : " << (str4 != str5) << endl;
	cout << "( str4 <= str5 ) равно : " << (str4 <= str5) << endl;
	cout << "( str4 >= str5 ) равно : " << (str4 >= str5) << endl;
	cout << "( str4 < str5 ) равно : " << (str4 < str5) << endl;
	cout << "( str4 > str5 ) равно : " << (str4 > str5) << endl;
}