/*
 ID: ShiehShieh
 PROG: packrec
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


void createFour(vector<int> name, vector<vector<int>>& allPossible, vector<int>& indexV, int index) {
    vector<int> name1(4);
    name1 = name;

    for (int i = 0; i < 4; ++i)
    {
        if (index < 4)
        {
            name1[index] = indexV[i];
            createFour(name1, allPossible, indexV, index + 1);
        }else if(index == 4)
        {
            for (vector<int>::iterator e1 = name1.begin(); e1 != name1.end(); ++e1)
            {
                for (vector<int>::iterator e2 = e1 + 1; e2 != name1.end(); ++e2)
                {
                    if (*e1 == *e2)
                    {
                        return;
                    }
                }
            }
            allPossible.push_back(name1);
            break;
        }
    }
}


void situationOne(int lenght, int weight, int ottf, vector<pair<int, int>>& all, vector<pair<int, int>>& allResult) {
    int localLenght = lenght;
    int localWeight = weight;

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
            weight += all[ottf].second;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(lenght, weight));
                continue;
            }
            situationOne(lenght, weight, ottf + 1, all, allResult);
        }else if(i == 1) {
            localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
            localWeight += all[ottf].first;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(localLenght, localWeight));
                continue;
            }
            situationOne(localLenght, localWeight, ottf + 1, all, allResult);
        }

    }
}


void situationTwo(int lenght, int weight, int ottf, vector<pair<int, int>>& all, vector<pair<int, int>>& allResult) {
    int localLenght = lenght;
    int localWeight = weight;

    if (ottf == 3)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (i == 0)
            {
                /* code */
                lenght += all[ottf].first;
                weight = weight > all[ottf].second ? weight : all[ottf].second;
                allResult.push_back(make_pair(lenght, weight));
            }else if(i == 1) {
                localLenght += all[ottf].second;
                localWeight = localWeight > all[ottf].first ? localWeight : all[ottf].first;
                allResult.push_back(make_pair(localLenght, localWeight));
                return;
            }
        }
    }

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
            weight += all[ottf].second;
            situationTwo(lenght, weight, ottf + 1, all, allResult);
        }else if(i == 1) {
            localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
            localWeight += all[ottf].first;
            situationTwo(localLenght, localWeight, ottf + 1, all, allResult);
        }

    }
}


void situationThree(int lenght, int weight, int ottf, vector<pair<int, int>>& all, vector<pair<int, int>>& allResult) {
    int localLenght = lenght;
    int localWeight = weight;

    if (ottf == 0 || ottf == 1)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (i == 0)
            {
                lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
                weight += all[ottf].second;
                situationThree(lenght, weight, ottf + 1, all, allResult);
            }else if(i == 1) {
                localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
                localWeight += all[ottf].first;
                situationThree(localLenght, localWeight, ottf + 1, all, allResult);
            }

        }
    }
    if (ottf == 2)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (i == 0)
            {
                /* code */
                lenght += all[ottf].first;
                weight = weight > all[ottf].second ? weight : all[ottf].second;
                situationThree(lenght, weight, ottf + 1, all, allResult);
            }else if(i == 1) {
                localLenght += all[ottf].second;
                localWeight = localWeight > all[ottf].first ? localWeight : all[ottf].first;
                situationThree(lenght, weight, ottf + 1, all, allResult);
            }
        }
    }
    if (ottf == 3)
    {
        for (int i = 0; i < 2; ++i)
        {
            if (i == 0)
            {
                /* code */
                lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
                weight += all[ottf].second;
                allResult.push_back(make_pair(lenght, weight));
            }else if(i == 1) {
                localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
                localWeight += all[ottf].first;
                allResult.push_back(make_pair(localLenght, localWeight));
                return;
            }
        }
    }
}



void situationFour(int lenght, int weight, int ottf, vector<pair<int, int>>& all, vector<pair<int, int>>& allResult) {
    int localLenght = lenght;
    int localWeight = weight;

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
            weight += all[ottf].second;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(lenght, weight));
                continue;
            }
            situationOne(lenght, weight, ottf + 1, all, allResult);
        }else if(i == 1) {
            localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
            localWeight += all[ottf].first;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(localLenght, localWeight));
                continue;
            }
            situationOne(localLenght, localWeight, ottf + 1, all, allResult);
        }

    }
}



void situationFive(int lenght, int weight, int ottf, vector<pair<int, int>>& all, vector<pair<int, int>>& allResult) {
    int localLenght = lenght;
    int localWeight = weight;

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
            weight += all[ottf].second;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(lenght, weight));
                continue;
            }
            situationOne(lenght, weight, ottf + 1, all, allResult);
        }else if(i == 1) {
            localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
            localWeight += all[ottf].first;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(localLenght, localWeight));
                continue;
            }
            situationOne(localLenght, localWeight, ottf + 1, all, allResult);
        }

    }
}



void situationSix(int lenght, int weight, int ottf, vector<pair<int, int>>& all, vector<pair<int, int>>& allResult) {
    int localLenght = lenght;
    int localWeight = weight;

    for (int i = 0; i < 2; ++i)
    {
        if (i == 0)
        {
            lenght = lenght > all[ottf].first ? lenght : all[ottf].first;
            weight += all[ottf].second;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(lenght, weight));
                continue;
            }
            situationOne(lenght, weight, ottf + 1, all, allResult);
        }else if(i == 1) {
            localLenght = localLenght > all[ottf].second ? localLenght : all[ottf].second;
            localWeight += all[ottf].first;
            if (ottf == 3)
            {
                allResult.push_back(make_pair(localLenght, localWeight));
                continue;
            }
            situationOne(localLenght, localWeight, ottf + 1, all, allResult);
        }

    }
}






int main(int argc, char *argv[])
{
	ifstream inf("packrec.in");
	ofstream ouf("packrec.out");
    vector<pair<int, int>> all;
    vector<pair<int, int>> allResult;
    vector<vector<int>> allPossible;
    vector<int> indexV;
    indexV.push_back(0);
    indexV.push_back(1);
    indexV.push_back(2);
    indexV.push_back(3);
    int lenght = 0, weight = 0;
    int mid = 0;

    inf >> lenght >> weight;
    while(inf) {
        if (lenght > weight)
        {
            /* code */
            mid = lenght;
            lenght = weight;
            weight = mid;
        }
        all.push_back(make_pair(lenght, weight));
        inf >> lenght >> weight;
    }

    vector<int> emptyV(4);
    createFour(emptyV, allPossible, indexV, 0);

//    for(vector<int> v1 : allPossible) {
//        for(int i : v1) {
//            cout << i << ' ' << flush;
//        }
//        cout << endl;
//    }

//    situationOne(0, 0, 0, all, allResult);
    situationThree(0, 0, 0, all, allResult);
    for(pair<int, int> p : allResult) {
        cout << p.first << ' ' << p.second << endl;
    }

//    for(pair<int, int> p : all) {
//        cout << p.first << ' ' << p.second << endl;
//    }

	return 0;
}
