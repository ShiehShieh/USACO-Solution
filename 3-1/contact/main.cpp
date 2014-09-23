/*
 ID: ShiehShieh
 PROG: contact
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cstring>


using namespace std;


int result[20][10000];


string myReverse(std::string word)
{
    char temp;
    size_t i, j;
    for (j = 0, i = word.size() - 1; j < i; --i, ++j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }

    return word;
}


int binaryToDecimal(string str) {
	int result = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '1')
		{
			result += pow(2, str.length() - i - 1);
		}
	}

	return result;
}


string decimalToBinaryStirng(int input, int count) {
	int carry = 0, output = 0;
	string result;

	output = input % 2;
	carry = input / 2;
	while(carry) {
		result += output + '0';
		output = carry % 2;
		carry = carry / 2;
	}
	result += output + '0';

	while(result.length() < count) {
		result += '0';
	}

	return myReverse(result);
}


struct lex_compare {
	bool operator()(const pair<int, string> p1, const pair<int, string> p2) const{
		if (p1.first < p2.first)
		{
			return true;
		}else if (p1.first == p2.first && p1.second.length() > p2.second.length())
		{
			return true;
		}else if (p1.first == p2.first && p1.second > p2.second)
		{
			return true;
		}else {
			return false;
		}
	}
};


int main(int argc, char const *argv[])
{
	ifstream inf("contact.in");
	ofstream ouf("contact.out");
	int A = 0, B = 0, N = 0, k = 0;
	string theString, str;
	set<pair<int, string>, lex_compare> all;

	for (int i = 0; i < 20; ++i)
	{
		memset(result[i], 0, 10000);
	}

	inf >> A >> B >> N;

	inf >> str;
	while(inf) {
		theString += str;
		inf >> str;
	}

	int start = 0;
	int endPoint = theString.length() - B + 2;

	for (int i = B; i >= A; --i)
	{
		if (i > theString.length())
		{
			continue;
		}
		if (i == B)
		{
			for (start = 0; start < endPoint - 1 && start >= 0; ++start)
			{
				str = theString.substr(start, B);
				++result[i][binaryToDecimal(str)];
			}
		}else {
			k = pow(2, i + 1);

			for (int j = 0; j < k; ++j)
			{
				result[i][j] = result[i + 1][j * 2] + result[i + 1][j * 2 + 1];
				if (binaryToDecimal(theString.substr(theString.length() - i, i)) == j)
				{
					++result[i][j];
				}
			}
		}
	}

	for (int i = A; i <= B; ++i)
	{
		for (int j = 0; j < 10000; ++j)
		{
			all.insert(make_pair(result[i][j], decimalToBinaryStirng(j, i)));
		}
	}

	int q = 0, counter = 0;
	k = (*(all.rbegin())).first;
	str.clear();
	ouf << k << endl;
	for (auto i = all.rbegin(); i != all.rend(); ++i)
	{
		if ((*i).first == 0)
		{
			ouf << str.substr(0, str.length() - 1) << endl;

			break;
		}
		if ((*i).first == k)
		{
			if (counter == 6)
			{
				counter = 0;
				str[str.length() - 1] = '\n';
			}
			str += (*i).second + " ";
			++counter;
		}else {
			counter = 0;
			ouf << str.substr(0, str.length() - 1) << endl;
			str.clear();
			++q;
			if (q == N)
			{
				break;
			}
			k = (*i).first;
			ouf << k << endl;
			str += (*i).second + " ";
			++counter;
		}
	}

	return 0;
}
