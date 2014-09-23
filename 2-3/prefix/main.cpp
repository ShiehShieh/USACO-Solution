/*
 ID: ShiehShieh
 PROG: prefix
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


set<string> allComponent;
vector<int> result;
string S;


void work(int start, int& min, int& max) {
	int tem = 0;

	if (start == -1)
	{
		/* code */
		return;
	}

	if (start + min > S.length())
	{
		/* code */
		work(start - 1, min, max);

		return;
	}

	for (int i = start + 1; i < start + max + 5 && i < S.length(); ++i)
	{
		/* code */
		if (result[i] + i - start > tem)
		{
			/* code */
			if (allComponent.find(S.substr(start, i - start)) != allComponent.end())
			{
				/* code */
//				cout << result[i] << ' ' << i << ' ' << start << endl;
				tem = result[i] + i - start;
			}
		}
	}

	result[start] = tem;

	work(start - 1, min, max);

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("prefix.in");
	ofstream ouf("prefix.out");
	int min = 20, max = 0;
	string tem;

	inf >> tem;

	while(tem != ".") {
		if (tem.length() < min)
		{
			/* code */
			min = tem.length();
		}
		if (tem.length() > max)
		{
			/* code */
			max = tem.length();
		}
		allComponent.insert(tem);
		inf >> tem;
	}

	inf >> tem;

	while(inf) {
		S += tem;
		inf >> tem;
	}

	result.resize(S.length());

	if (allComponent.find(S.substr(S.length() - 1, 1)) != allComponent.end())
	{
		/* code */
		result[S.length() - 1] = 1;
	}else {
		result[S.length() - 1] = 0;
	}

	work(S.length() - 2, min, max);
/*
	for(int i : result) {
		cout << i << endl;
	}
*/
	ouf << result[0] << endl;
/*
	for(int i : result) {
		cout << i << endl;
	}
*/
/*
	for(string str : allComponent) {
		cout << str << endl;
	}

	cout << S << endl;
*/
	return 0;
}

/*

#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


vector<string> allComponent;
set<int> result;
string S;


void work(int start, int& max) {
	int index;

	for(string str : allComponent) {
		index = max + str.length();

		if (index > S.length())
		{
			continue;
		}

		if (str == S.substr(start, str.length()))
		{
			work(start + str.length(), index);
			result.insert(index);
		}
	}

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("prefix.in");
	ofstream ouf("prefix.out");
	string tem;

	inf >> tem;

	while(tem != ".") {
		allComponent.push_back(tem);
		inf >> tem;
	}

	inf >> tem;

	while(inf) {
		S += tem;
		inf >> tem;
	}

	tem.clear();

	int k = 0;

	work(0, k);

	for(int i : result) {
		cout << i << endl;
	}

	if (result.empty())
	{
		ouf << 0 << endl;
	}else {
		ouf << *(--result.end()) << endl;
	}

	for(string str : allComponent) {
		cout << str << endl;
	}

	cout << S << endl;

	return 0;
}

 */
