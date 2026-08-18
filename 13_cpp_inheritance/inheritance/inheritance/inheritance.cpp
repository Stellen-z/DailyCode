#include <iostream>
#include <vector>

using namespace std;

//class Person
//{
//public:
//	// 进入校园/图书馆/实验室刷二维码等身份认证​
//	void identity()
//	{
//		cout << "identity()" << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名​
//	string _address; // 地址​
//	string _tel; // 电话​
//	int _age = 18; // 年龄​
//};
//
//
//class Student : public Person
//{
//public:
//	//学习
//	void study()
//	{
//		identity();
//	}
//
//protected:
//	string _stuid; //学号
//};
//
//
//class Teacher : public Person
//{
//public:
//	//授课
//	void teaching()
//	{
//		identity();
//	}
//protected:
//	string title;
//};

//void test1()
//{
//	Student s;
//	Teacher t;
//
//	s.study();
//	t.teaching();
//}


namespace stl
{
	//继承类模板
	//继承stack
	template<class T>
	class stack : public std::vector<T>
	{
	public:
		void push(const T& x) { vector<T>::push_back(x); }
		void pop() { vector<T>::pop_back(); }
		const T& top() const { return vector<T>::back(); }
		const size_t size() const { return vector<T>::size(); }
		const bool empty() const { return vector<T>::empty(); }
	};

	void test2()
	{
		stack<int> st;

		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
		cout << endl;
	}

}

class Person
{
public:
	//1.默认构造函数
	Person(const char* name = "peter")
		:_name(name)
	{
		cout << "Person()" << endl;
	}

	//2.拷贝构造函数
	Person(const Person& per)
		:_name(per._name)
	{
		cout << "Person(const Person& per)" << endl;
	}

	//3.赋值重载
	Person& operator=(const Person& per)
	{
		cout << "Person& operator=(const Person& per)" << endl;
		if (&per != this)
		{
			_name = per._name;
		}

		return *this;
	}

	//4.析构函数
	~Person()
	{
		cout << "~Person()" << endl;
	}

protected:
	string _name; // 姓名​
};


class Student : public Person
{
public:
	//如果不想使用父类的默认值，就需要显示调用父类的默认构造
	//1.默认构造
	Student(const char* name,const string stuid = "1111")
		:Person(name)
		,_stuid(stuid)
	{
		cout << "Student()" << endl;
	}


	//2.拷贝构造
	Student(const Student& stu)
		:Person(stu)
		,_stuid(stu._stuid)
	{
		cout << "Student(const Student& stu)" << endl;
	}

	//3.赋值重载
	Student& operator=(const Student& stu)
	{
		if (&stu != this)
		{
			//同名函数,显示调用
			Person::operator=(stu);
			cout << "Student& operator=(const Student& stu)" << endl;
			_stuid = stu._stuid;
		}

		return *this;
	}

	//4.析构函数
	//父类有析构函数，就不需要显示调用
	~Student()
	{
		cout << "~Student()" << endl;
	}

protected:
	string _stuid;
};

void test3()
{
	Student s1("zhangsan", "111");
	Student s2("lisi", "222");
	Student s3(s1);

	s3 = s2;

}




int main()
{
	//stl::test2();
	test3();

	return 0;
}

