/*
 ID: ShiehShieh
 PROG: namenum
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void create(string name, vector<char> N, int index, vector<string>& result, map<char, char*> dict) {
	string name1 = name;
	string name2 = name;
	string name3 = name;
	if (N[index] != '1' && index < N.size())
	{
		name1 += dict[N[index]][0];
		name2 += dict[N[index]][1];
		name3 += dict[N[index]][2];
		create(name1, N, index + 1, result, dict);
		create(name2, N, index + 1, result, dict);
		create(name3, N, index + 1, result, dict);
	}else {
		result.push_back(name);
	}
}

int main(int argc, char const *argv[])
{
	ifstream inf("namenum.in");
	ofstream ouf("namenum.out");
	ifstream dicFile("dict.txt");
	char k;
	string str;
    vector<char> N;
    string name;
    map<string, bool> vaildName;
    vector<string> result;
    vector<string> final;
    map<char, char*> dict;
    char a[3] = {'A', 'B', 'C'};
    char d[3] = {'D', 'E', 'F'};
    char g[3] = {'G', 'H', 'I'};
    char j[3] = {'J', 'K', 'L'};
    char m[3] = {'M', 'N', 'O'};
    char p[3] = {'P', 'R', 'S'};
    char t[3] = {'T', 'U', 'V'};
    char w[3] = {'W', 'X', 'Y'};
    dict['2'] = a;
    dict['3'] = d;
    dict['4'] = g;
    dict['5'] = j;
    dict['6'] = m;
    dict['7'] = p;
    dict['8'] = t;
    dict['9'] = w;

    k = inf.get();
    while(inf) {
    	N.push_back(k);
	    k = inf.get();
    }

    N.push_back('1');

    dicFile >> str;
    while(dicFile) {
    	vaildName[str] = true;
	    dicFile >> str;
    }

    dicFile.close();

    create(name, N, 0, result, dict);

    for(string stri : result) {
	    if (vaildName[stri])
	    {
	    	final.push_back(stri);
	    }
    }

	sort(final.begin(), final.end());

	for (string str : final) {
		ouf << str << endl;
	}

	inf.close();
	ouf.close();

	return 0;
}
