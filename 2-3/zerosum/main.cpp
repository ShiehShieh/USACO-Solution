/*
 ID: ShiehShieh
 PROG: zerosum
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;


vector<char> operation;
set<string> resultSet;


int to_num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


void dps(int index, int sum, char last, char first, vector<int> allNumber, string result) {
	int tem;
	string resultString;
	vector<int> localVector;

	if (index == allNumber.size())
	{
		/* code */
		if (sum == 0)
		{
			/* code */
			resultSet.insert(result);
		}

		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		/* code */
		tem = sum;
		localVector = allNumber;
		resultString = result;

		if (operation[i] == '+')
		{
			/* code */
			tem += localVector[index];
			resultString += "+";
			resultString += localVector[index] + '0';
			dps(index + 1, tem, '+', first, localVector, resultString);
		}else if (operation[i] == '-')
		{
			/* code */
			tem -= localVector[index];
			resultString += "-";
			resultString += localVector[index] + '0';
			dps(index + 1, tem, '-', first, localVector, resultString);
		}else if (operation[i] == ' ')
		{
			/* code */
//			string temString;
			int temInt = 0;

			resultString += " ";
			resultString += localVector[index] + '0';

			if (last == ' ')
			{
				/* code */
				if (first == '+')
				{
					/* code */
					tem -= localVector[index - 1];
					temInt = localVector[index - 1] * 10 + localVector[index];
					tem += temInt;
					localVector.erase(localVector.begin() + index - 1, localVector.begin() + index + 1);
					localVector.insert(localVector.begin() + index - 1, temInt);
					dps(index, tem, ' ', '+', localVector, resultString);
				}
				if (first == '-')
				{
					/* code */
					tem += localVector[index - 1];
					temInt = localVector[index - 1] * 10 + localVector[index];
					tem -= temInt;
					localVector.erase(localVector.begin() + index - 1, localVector.begin() + index + 1);
					localVector.insert(localVector.begin() + index - 1, temInt);
					dps(index, tem, ' ', '-', localVector, resultString);
				}
			}
			if (last == '+')
			{
				/* code */
				tem -= localVector[index - 1];
				temInt = localVector[index - 1] * 10 + localVector[index];
				tem += temInt;
				localVector.erase(localVector.begin() + index - 1, localVector.begin() + index + 1);
				localVector.insert(localVector.begin() + index - 1, temInt);
				dps(index, tem, ' ', '+', localVector, resultString);
			}
			if (last == '-')
			{
				/* code */
				tem += localVector[index - 1];
				temInt = localVector[index - 1] * 10 + localVector[index];
				tem -= temInt;
				localVector.erase(localVector.begin() + index - 1, localVector.begin() + index + 1);
				localVector.insert(localVector.begin() + index - 1, temInt);
				dps(index, tem, ' ', '-', localVector, resultString);
			}

		}
	}

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("zerosum.in");
	ofstream ouf("zerosum.out");
	vector<int> allNumber;
	int N = 0, sum = 0;;
	string result;

	inf >> N;

	for (int i = 1; i <= N; ++i)
	{
		/* code */
		allNumber.push_back(i);
	}

	operation.push_back('+');
	operation.push_back('-');
	operation.push_back(' ');

	sum = allNumber[0];

	result += sum + '0';

	dps(1, sum, '+', '+', allNumber, result);

	for(string str : resultSet) {
		ouf << str << endl;
	}

	return 0;
}
