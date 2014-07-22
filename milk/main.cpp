/*
 ID: ShiehShieh
 PROG: milk
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int findMin(vector<pair<int, int>> v) {
    int first = 10000;
    int index = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].first < first)
        {
            first = v[i].first;
            index = i;
        }
    }

    return index;
}

int main(int argc, char *argv[])
{
	ifstream inf("milk.in");
	ofstream ouf("milk.out");
    vector<pair<int, int>> specific;
    int need = 0;
    int man = 0;
    int price = 0;
    int pervide = 0;
    int money = 0;
    inf >> need >> man;
    for (int i = 0; i < man; ++i)
    {
        inf >>price >> pervide;
        specific.push_back(make_pair(price, pervide));
    }

    if (man == 1)
    {
        money = specific[0].first * need;
        ouf << money << endl;
        exit(0);
    }

    while(need) {
        int min = findMin(specific);
        int have = specific[min].second;

        if (have > need)
        {
            money += specific[min].first * need;
            need = 0;
        }else if(have <= need) {
            money += specific[min].first * specific[min].second;
            need -= specific[min].second;
            specific.erase(specific.begin() + min);
        }
    }

    ouf << money << endl;
//    for(pair<int, int> p : specific) {
//        cout << p.first << ' ' << p.second << endl;
//    }

	return 0;
}
