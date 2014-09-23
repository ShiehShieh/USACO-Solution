/*
 ID: ShiehShieh
 PROG: palsquare
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

map<int, char> dic;

string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}

int to_num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}

void myReverse(std::string &word)
{
	char temp;
	size_t i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j) {
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
}

void work(int now, vector<string>& result, int N, string str) {
	int carry = now % N;
	int i = now / N;
	string strin;
	strin = dic[carry];
	str += strin;
	if (i >= N)
	{
		work(i, result, N, str);
	}else if(i >= 0){
		str += to_str(i);
		myReverse(str);
		result.push_back(str);
	}
}

void checkout(ofstream& ouf, string number, int counter, vector<string> final) {
	string str = number;
	int middle = (str.size() / 2) + 1;
	string left = str.substr(0, middle);
	myReverse(str);
	string right = str.substr(0, middle);
	if (left == right)
	{
		ouf << final[counter] << ' ' << number << endl;
	}
}

int main(int argc, char const *argv[])
{
	ifstream inf("palsquare.in");
	ofstream ouf("palsquare.out");
	vector<string> result;
	vector<string> final;
	int N = 0;
	dic[1] = '1';
	dic[2] = '2';
	dic[3] = '3';
	dic[4] = '4';
	dic[5] = '5';
	dic[6] = '6';
	dic[7] = '7';
	dic[8] = '8';
	dic[9] = '9';
	dic[10] = 'A';
	dic[11] = 'B';
	dic[12] = 'C';
	dic[13] = 'D';
	dic[14] = 'E';
	dic[15] = 'F';
	dic[16] = 'G';
	dic[17] = 'H';
	dic[18] = 'I';
	dic[19] = 'J';

	inf >> N;

	for (int i = 1; i < 301; ++i)
	{
		int now = i * i;
		string str;
		work(now, result, N, str);
		work(i, final, N, str);
	}

	int counter = 0;
	for(string i : result) {
		checkout(ouf, i, counter, final);
		++counter;
	}

	return 0;
}
