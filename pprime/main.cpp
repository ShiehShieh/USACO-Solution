/*
 ID: ShiehShieh
 PROG: pprime
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;


int to_num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}


bool isPrime(int x)
{
	int e = (int)sqrt(x);
	for(int i = 2; i <= e; i++)
	{
		if((x % i) == 0) {
			return false;
		}
	}

	return true;
}


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


void work(string name, int input, vector<string>& left, bool first) {
	string name1;

	if (input == 0)
	{
		/* code */
		left.push_back(name);

		return;
	}

	if (first == true)
	{
		/* code */
		for (int i = 1; i < 10; ++i)
		{
			/* code */
			if (i == 2 || i == 4 || i == 5 || i == 6 || i == 8)
			{
				/* code */
				continue;
			}
			name1 = name;
			name1 += i + '0';
			work(name1, input - 1, left, false);
		}

	}else {
		for (int i = 0; i < 10; ++i)
		{
			/* code */
			name1 = name;
			name1 += i + '0';
			work(name1, input - 1, left, false);
		}

	}

	return;
}


void createPrime(int start, int end, vector<int>& allPossible) {
	int k = 0;
	string name;
	vector<string> left;

	for (int i = 1; i < 4; ++i)
	{
		/* code */
		work(name, i, left, true);
	}

	for(string str : left) {
		for (int i = 0; i < 10; ++i)
		{
			/* code */
			k = to_num(str + char(i + '0') + myReverse(str));
			if (k >= start && k <= end)
			{
				/* code */
				allPossible.push_back(k);
			}
		}
	}

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("pprime.in");
	ofstream ouf("pprime.out");
	vector<int> allPossible;
	int start = 0;
	int end = 0;
	inf >> start >> end;

	allPossible.push_back(5);
	allPossible.push_back(7);
	allPossible.push_back(11);

	createPrime(start, end, allPossible);

	if (start > 11)
	{
		/* code */
		allPossible.erase(allPossible.begin(), allPossible.begin() + 3);
	}else if (start > 7)
	{
		/* code */
		allPossible.erase(allPossible.begin(), allPossible.begin() + 2);
	}else if (start > 5)
	{
		/* code */
		allPossible.erase(allPossible.begin());
	}

	for(int i : allPossible) {
		if (isPrime(i))
		{
			/* code */
			ouf << i << endl;
		}
	}

//	for(int i : allPossible) {
//		cout << i << endl;
//	}

	return 0;
}
