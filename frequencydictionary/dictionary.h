#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <windows.h>
#include <map>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::map;
using std::ifstream;
using std::ofstream;
using std::_Node_handle;
using std::vector;
using std::endl;
using std::cout;
using std::cin;

void check(string&a)
{
	char* p=new char[a.size()];
	strcpy(p,a.c_str());
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a.c_str()[i] == ',' && a.c_str()[i] == '.' && a.c_str()[i] == '(' && a.c_str()[i] == ')' && a.c_str()[i] == '<' && a.c_str()[i] == '>' && a.c_str()[i] == '_' && a.c_str()[i] == '!' && a.c_str()[i] == '?' && a.c_str()[i] == '{' && a.c_str()[i] == '}' && a.c_str()[i] == '[' && a.c_str()[i] == ']')
		{
			for (size_t j = i; j < a.size(); j++)
			{
				p[j] = a.c_str()[j + 1];
			}
		}
	}
	a = string(p);
}
class freqdict
{
	map<string, int> dict;
public:
	freqdict(string&& where)
	{
		ifstream in(where);
		if (in.is_open())
		{
			string t;
			while (!in.eof())
			{
				getline(in, t);
				check(t);
				dict[t]++;
			}
		}
		in.close();
	}
	void load_checked(string&& where)
	{
		dict.clear();
		ifstream in(where);
		string s;
		int a;
		while (!in.eof())
		{
			in >> s;
			in >> a;			
			dict.insert(dict.begin(), std::pair<string, int>(s, a));
		}
		in.close();
	}
	void print()
	{
		for (auto i = dict.begin(); i != dict.end(); i++)
		{
			cout << i->first << " --- " << i->second << endl;
		}
	}
	string most_frequent()
	{
		string t;
		int a;
		for (auto i = dict.begin(); i != dict.end(); i++)
		{
			if (i->second > a)
			{
				a = i->second;
				t = i->first;
			}
		}
		cout << t << " --- " << a;
		return t;
	}
	void save(string&& where)
	{
		ofstream out(where);
		for (auto i = dict.begin(); i != dict.end(); i++)
		{
			out << i->first << endl << i->second << endl;
		}
		out.close();
	}
	~freqdict() { save("1.txt"); dict.clear(); }
};