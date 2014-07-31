/*
 ID: ShiehShieh
 PROG: calfflac
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;


string myReplace(string input, int forIndex[10000]) {
    string resultString;
    int j = 0;
    for (int i = 0; i < input.size(); ++i)
    {
        if (isalpha(input[i]))
        {
            resultString += input[i];
            forIndex[j++] = i;
        }
    }

    return resultString;
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


int newCheckout(ostream& ouf, int index, string& newContent, int& start, int& backEnd) {
    int maxR = index > newContent.length() / 2 ? (newContent.length() - index) : (index);
    int result = 0;
    int i = 1;
    for (; i < maxR; ++i)
    {
        if (newContent[index] == newContent[index + 1])
        {
            if (newContent[index - i] == newContent[index + 1 + i])
            {
                result = i * 2 + 2;
                start = index - i;
                backEnd = index + 1 + i;
                ouf << start << endl;
                ouf << newContent.substr(index - i, i * 2 + 1) << endl;
                continue;
            }else {
                return result;
            }
        }

        if (index != 0 && newContent[index - 1] == newContent[index])
        {
            if (newContent[index - 1 - i] == newContent[index + i])
            {
                result = i * 2 + 2;
                start = index - i - 1;
                backEnd = index + i;
                ouf << start << endl;
                ouf << newContent.substr(index - i, i * 2 + 1) << endl;
                continue;
            }else {
                return result;
            }
        }

        if (newContent[index - i] == newContent[index + i])
        {
//            ouf << newContent[index - i] << ' ' << newContent[index + i] << endl;
//            ouf << index << newContent[index] << endl;
            start = index - i;
            backEnd = index + i;
            ouf << start << endl;
            ouf << newContent.substr(index - i, i * 2 + 1) << endl;
            result = i * 2 + 1;
        }else {
            return result;
        }
    }

    return result;
}


int main(int argc, char *argv[])
{
	ifstream inf("calfflac.in");
	ofstream ouf("calfflac.out");
    int forIndex[10000];    //记录索引。
    string str, content, newContent;
    int bestInt = 0;
    vector<string> v;
    vector<pair<int, string>> bestString;

    for (char a[90]; inf.getline(&a[0], 90); ) {
        v.push_back(a);
    }

    inf.close();

    for(string str : v) {
        content += str;
    }

    v.clear();

    newContent = myReplace(content, forIndex);
    transform(newContent.begin(),newContent.end(),newContent.begin(), ::tolower);
    int newContentL = newContent.length();
    string subContent;
    int max = 0;
    int start = 0;
    int backEnd = 0;

    for (int i = 0; i < newContentL; ++i)
    {
        max = newCheckout(ouf, i, newContent, start, backEnd);
        if (max > bestInt)
        {
            bestInt = max;
            cout << content.substr(forIndex[start], forIndex[start] - forIndex[backEnd]) << endl;
        }
    }

    ouf << bestInt << endl;

    cout << start << endl;
    cout << forIndex[start] << endl;
    cout << content.substr(forIndex[start], forIndex[bestInt]) << endl;

    exit(0);

    for (int i = 0; i < newContentL; ++i)
    {
        for (int j = 1; j < newContentL - i + 1; ++j)
        {
            subContent = newContent.substr(i, j);
            if (!checkout(subContent))
            {
                if (subContent.length() + newContent.length() - i - j < bestInt)
                {
                    break;
                }
                continue;
            }else if(subContent.length() > bestInt)
            {
                bestInt = subContent.length();
                bestString.push_back(make_pair(bestInt, subContent));
//                cout << bestInt << '\n' << subContent << endl;
            }
        }
    }

    for(pair<int, string> p : bestString) {
        if (p.first == bestInt)
        {
            cout << p.first << ' ' << p.second << endl;
            break;
        }
    }


	return 0;
}
