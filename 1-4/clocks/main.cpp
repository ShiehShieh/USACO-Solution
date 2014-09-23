/*
 ID: ShiehShieh
 PROG: clocks
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;
/*
1        ABDE
2        ABC
3        BCEF
4        ADG
5        BDEFH
6        CFI
7        DEGH
8        GHI
9        EFHI
 */


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
    if (word.length() == 0)
    {
        /* code */
        return;
    }
    for (j = 0, i = word.size() - 1; j < i; --i, ++j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
}


void rotation(int scheme, vector<int>& matrix) {
    if (scheme == 1)
    {
        /* code */
        matrix[0] = (matrix[0] + 1) % 4;
        matrix[1] = (matrix[1] + 1) % 4;
        matrix[3] = (matrix[3] + 1) % 4;
        matrix[4] = (matrix[4] + 1) % 4;
    }
    if (scheme == 2)
    {
        /* code */
        matrix[0] = (matrix[0] + 1) % 4;
        matrix[1] = (matrix[1] + 1) % 4;
        matrix[2] = (matrix[2] + 1) % 4;
    }
    if (scheme == 3)
    {
        /* code */
        matrix[1] = (matrix[1] + 1) % 4;
        matrix[2] = (matrix[2] + 1) % 4;
        matrix[4] = (matrix[4] + 1) % 4;
        matrix[5] = (matrix[5] + 1) % 4;
    }
    if (scheme == 4)
    {
        /* code */
        matrix[0] = (matrix[0] + 1) % 4;
        matrix[3] = (matrix[3] + 1) % 4;
        matrix[6] = (matrix[6] + 1) % 4;
    }
    if (scheme == 5)
    {
        /* code */
        matrix[1] = (matrix[1] + 1) % 4;
        matrix[3] = (matrix[3] + 1) % 4;
        matrix[4] = (matrix[4] + 1) % 4;
        matrix[5] = (matrix[5] + 1) % 4;
        matrix[7] = (matrix[7] + 1) % 4;
    }
    if (scheme == 6)
    {
        /* code */
        matrix[2] = (matrix[2] + 1) % 4;
        matrix[5] = (matrix[5] + 1) % 4;
        matrix[8] = (matrix[8] + 1) % 4;
    }
    if (scheme == 7)
    {
        /* code */
        matrix[3] = (matrix[3] + 1) % 4;
        matrix[4] = (matrix[4] + 1) % 4;
        matrix[6] = (matrix[6] + 1) % 4;
        matrix[7] = (matrix[7] + 1) % 4;
    }
    if (scheme == 8)
    {
        /* code */
        matrix[6] = (matrix[6] + 1) % 4;
        matrix[7] = (matrix[7] + 1) % 4;
        matrix[8] = (matrix[8] + 1) % 4;
    }
    if (scheme == 9)
    {
        /* code */
        matrix[4] = (matrix[4] + 1) % 4;
        matrix[5] = (matrix[5] + 1) % 4;
        matrix[7] = (matrix[7] + 1) % 4;
        matrix[8] = (matrix[8] + 1) % 4;
    }

}


bool checkout(string name1, vector<int> matrix) {
    int number = 0;
    vector<int> localMatrix = matrix;

    for (int i = 8; i >= 0; --i)
    {
        /* code */
        number = name1[i] - '0';

        for (int j = 0; j < number; ++j)
        {
            /* code */
            rotation(i + 1, localMatrix);
        }
    }

    for (int i = 0; i < 9; ++i)
    {
        /* code */
        if (localMatrix[i] == 0)
        {
            /* code */
            continue;
        }else {
            return false;
        }
    }

    return true;
}


void create(ostream& ouf, string name, vector<char>& N, int index, vector<int>& matrix, vector<string>& result) {
    string name1;

    for (int i = 0; i < 4; ++i)
    {
        name1 = name;
        if (index == 9)
        {
            if (checkout(name1, matrix))
            {
                int number = 0;
                string output;
                for (int e = 0; e < 9; ++e)
                {
                    /* code */
                    number = name1[e] - '0';
                    for (int d = 0; d < number; ++d)
                    {
                        /* code */
                        output += e + '1';
                        output += ' ';
                    }
                }
                output = output.substr(0, output.length() - 1);
                ouf << output << endl;
                exit(0);
                return;
            }
        }
        if (index < 9)
        {
            name1 += N[i];
            create(ouf, name1, N, index + 1, matrix, result);
        }
    }
}



int main(int argc, char *argv[])
{
	ifstream inf("clocks.in");
	ofstream ouf("clocks.out");
    map<int, int> encry;
    vector<int> matrix;
    vector<string> result;
    vector<char> N;
    int k = 0, d = 0;

    encry[3] = 1;
    encry[6] = 2;
    encry[9] = 3;
    encry[12] = 0;

    N.push_back('0');
    N.push_back('1');
    N.push_back('2');
    N.push_back('3');

    inf >> k;
    while(inf) {
        matrix.push_back(encry[k]);
        inf >> k;
    }

    string empty;
    create(ouf, empty, N, 0, matrix, result);

	return 0;
}
