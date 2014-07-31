/*
 ID: ShiehShieh
 PROG: milk3
 LANG: C++11
 */
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>


using namespace std;


string to_str(int number)
{
    stringstream s;
    s << number;
    string str = s.str();

    return str;
}


void create(vector<int> capcity, int index, set<int>& result, vector<int>& maxC, vector<pair<int, int>> seen) {
    vector<int> localCapcity;

    if (index == 12)
    {
        /* code */
        return;
    }

    if (index == 0)
    {
        /* code */
        for (int i = 0; i < 2; ++i)
        {
            localCapcity = capcity;
            /* code */
            if (maxC[i] >= maxC[2])
            {
                /* code */
                localCapcity[i] = maxC[2];
                localCapcity[2] = 0;
            }else {
                localCapcity[i] = maxC[i];
                localCapcity[2] -= maxC[i];
            }
            if (localCapcity[0] == 0)
            {
                /* code */
                result.insert(localCapcity[2]);
            }
            seen.push_back(make_pair(2, i));
            create(localCapcity, index + 1, result, maxC, seen);
//            seen.push_back(make_pair(2, i));
//            seen.pop_back();
        }
    }else {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (i == j)
                {
                    /* code */
                    continue;
                }
                pair<int, int> p = seen.back();
                if (p.first == j && p.second == i)
                {
                    /* code */
                    continue;
                }
                localCapcity = capcity;
                int diff = maxC[j] - localCapcity[j];
                if (diff >= localCapcity[i])
                {
                    /* code */
                    localCapcity[j] += localCapcity[i];
                    localCapcity[i] = 0;
                }else {
                    localCapcity[j] = maxC[j];
                    localCapcity[i] -= diff;
                }
                if (localCapcity[0] == 0)
                {
                    /* code */
                    result.insert(localCapcity[2]);
                }
                seen.push_back(make_pair(i, j));
                create(localCapcity, index + 1, result, maxC, seen);
                seen.pop_back();
            }
        }
    }

}


int main(int argc, char *argv[])
{
	ifstream inf("milk3.in");
	ofstream ouf("milk3.out");
    vector<int> maxC;
    vector<int> scheme;
    set<int> result;
    vector<int> capcity;
    vector<pair<int, int>> seen;
    int k = 0;

    inf >> k;
    while(inf) {
        maxC.push_back(k);
        inf >> k;
    }

    capcity.push_back(0);
    capcity.push_back(0);
    capcity.push_back(maxC[2]);

//    for(int i : maxC) {
//        cout << i << endl;
//    }

    create(capcity, 0, result, maxC, seen);

    string str;

    for(int i : result) {
        str += to_str(i) + ' ';
    }

    ouf << str.substr(0, str.length() - 1) << endl;

	return 0;
}
