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
#include <cmath>


using namespace std;


int main(int argc, char const *argv[])
{
	ifstream inf("palsquare.in");
	ofstream ouf("palsquare.out");

	return 0;
}


bool isPrime(int x)
{
	int e = (int)sqrt(x);
	if (x == 1)
	{
		/* code */
		return false;
	}
	for(int i = 2; i <= e; ++i)
	{
		if((x % i) == 0) {
			return false;
		}
	}

	return true;
}


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


bool checkout(string input) {
    string changed;
    changed = myReverse(input);
    if (input == changed)
    {
        return true;
    }

    return false;
}


void createFirst(string name, vector<char>& N, int index, vector<string>& result) {
	string name1 = name;

	for (int i = 0; N[i] != '0'; ++i)
	{
		if (index < 3)
		{
			name1[index] = N[i];
			createFirst(name1, N, index + 1, result);
		}else if(index == 3)
		{
			result.push_back(name1);
			break;
		}
	}
}


int knapsack(int n, int w, int** triangle, int** result) {
	if (n == R - 1)
	{
		/* code */
		return 0;
	}

	if (result[n][w] != 0) return result[n][w];

	return result[n][w] = max(
		knapsack(n + 1, w, triangle, result) + triangle[n + 1][w],
		knapsack(n + 1, w + 1, triangle, result) + triangle[n + 1][w + 1]
	);
}


int max(int a, int b) {

	if (a < b) {

		return b;

	}else {

		return a;

	}
}


clock_t start_time = clock();
clock_t end_time = clock();

cout << "Running time is: " << static_cast<double>(end_time-start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
