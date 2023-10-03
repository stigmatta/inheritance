#include <iostream>
using namespace std;
class Person
{
protected:
	char* name;
	int age;
public:
	Person() = default;
	Person(const char* name, int age) :age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void print()
	{
		cout << "Name: " << name << endl << "Age: " << age << endl;
	}
	void input()
	{
		char buff[20];
		cout << "Enter name:" << endl;
		cin.getline(buff, 20);
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age: " << endl;
		cin >> age;
	}
	~Person()
	{
		delete[]name;
	}
};
class Student: public Person
{
	char* university;
public:
	Student()
	{
		Person::Person();
		university = nullptr;
	}
	Student(const char* name, int age, const char* university) :Person(name, age)
	{
		this->university = new char[strlen(university) + 1];
		strcpy_s(this->university, strlen(university) + 1, university);
	}
	~Student()
	{
		delete[]university;
	}
	void print()
	{
		Person::print();
		cout << "University: " << university << endl;
	}
};
class Teacher:public Person
{
	string school;
	int salary;
public:
	Teacher()
	{
		Person::Person();
		school = " ";
		salary = 0;
	}
	Teacher(const char* name, int age, string school, int salary) :Person(name, age)
	{
		this->school = school;
		this->salary = salary;
	}
	void input(string school, int salary)
	{
		Person::input();
		this->school = school;
		this->salary = salary;
	}
	void print()
	{
		Person::print();
		cout << "School: " << school << endl << "Salary: " << salary << endl;
	}
};
class Driver:public Person
{
	string licence_number,auto_number;
public:
	Driver()
	{
		Person::Person();
		licence_number = auto_number = " ";
	}
	Driver(const char* name, int age, string licence_num, string auto_num):Person(name, age)
	{
		licence_number = licence_num;
		auto_number = auto_num;
	}
	void input(string licence_num, string auto_num)
	{
		Person::input();
		licence_number = licence_num;
		auto_number = auto_num;
	}
	void print()
	{
		Person::print();
		cout << "Licence number: " << licence_number << endl << "Auto number: " << auto_number << endl;
	}
};
class Doctor:public Person
{
	string specialty;
	int exp_years; //experience
	bool family_doctor;
public:
	Doctor()
	{
		Person::Person();
		specialty = " ";
		exp_years = 0;
		family_doctor = false;
	}
	Doctor(const char* name, int age, string specialty, int exp_years, bool family_doctor) :Person(name, age)
	{
		this->specialty = specialty;
		this->exp_years = exp_years;
		this->family_doctor = family_doctor;
	}
	void input(string specialty, int exp_years, bool family_doctor)
	{
		Person::input();
		this->specialty = specialty;
		this->exp_years = exp_years;
		this->family_doctor = family_doctor;
	}
	void print()
	{
		Person::print();
		cout << "Specialty: " << specialty << endl << "Experience years: " << exp_years << endl << "Is a family doctor: " << boolalpha << family_doctor << endl;
	}

};
int main()
{
	Person a("baba", 23);
	Student b("adsa", 25, "dasd");
	b.print();
	Teacher c("asdas", 26, "school", 2687);
	c.print();
	Driver d("hfgh", 27, "3123123", "2312sd");
	d.print();
	Doctor e("dasd", 28, "sdasd", 23, true);
	e.print();
}