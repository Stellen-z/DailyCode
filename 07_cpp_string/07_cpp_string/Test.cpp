#include "string.h"

using namespace std;

void test_string1()
{
	string s("hello world!");

	s.push_back(' ');
	s.push_back('x');

	s.append("kskbl");

	cout << s << endl;

	s += "zdjd";
	s += '\n';

	cout << s << endl;

	s.insert(0, "hello bit ");
	cout << s << endl;
}

void test_string2()
{
	string s = "hello world";

	s.erase(6, 1);

	cout << s << endl;

	s.erase(0, 1);
	cout << s << endl;

	s.erase(--s.end());
	cout << s << endl;

	s.erase(s.size() - 1, 1);
	cout << s << endl;
}


void test_string3()
{
	string s = "hello world hello world!";

	//把空格替换为 %%
	size_t pos = s.find(' ');
	while (pos != string::npos)
	{
		s.replace(pos, 1, "%%");
		//默认从头开始
		//pos = s.find(' ');

		//从pos+2位置开始及替换后的新位置开始
		pos = s.find(' ', pos + 2);
	}
	cout << s << endl;


	//空间换时间
	string tmp = "";
	for (auto ch : s)
	{
		if (ch == ' ') tmp += "%%";
		else tmp += ch;
	}
	cout << tmp << endl;
}

void test_string4()
{
	string file;
	cin >> file;

	FILE* fp = fopen(file.c_str(), "r");
	int ch = fgetc(fp);

	while (ch != EOF)
	{
		cout << (char)ch;
		ch = fgetc(fp);
	}
	cout << endl;

	fclose(fp);
}

void test_string5()
{
	string s = "string.cpp.zip";
	//size_t pos = s.find('.');
	size_t pos = s.rfind('.');


	string tmp = s.substr(pos);
	cout << tmp << endl;
}

void SplitFileName(string& str)
{
	cout << str << endl;
	size_t find = str.find_last_of("/\\");
	
	cout << "path: " << str.substr(0, find) << endl;
	cout << "file: " << str.substr(find + 1) << endl;

}

void test_string6()
{
	string str("Please replace the vowels in this sentence by asterisks");
	cout << str << endl;

	size_t find = str.find_first_of("abcd");
	while (find != string::npos)
	{
		str[find] = '*';
		find = str.find_first_of("abcd");
	}
	cout << str << endl;

	string str1("D:\\DailyCode\\01_cpp_basics");
	string str2("C:\\Program Files (x86)\\cmcm\\Clean Master");

	SplitFileName(str1);
	SplitFileName(str2);

}

void Test01()
{
	string s1("");
	string s2("hello world");
}

void Test02()
{
	string s1("");
	string s2("hello world!");

	cout << s1 << endl;
	cout << s2 << endl;

	s1 += 'x';
	s1 += 'y';
	cout << s1 << endl;

	s2.insert(0, "kakbl");
	cout << s2 << endl;

}



int main()
{
	//test_string1();
	//test_string2(); 
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();

	//Test01();
	Test02();

	return 0;
}