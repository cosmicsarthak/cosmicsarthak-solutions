// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;
#define ll long long
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    vector<int> v(26);
    deque<char> dq;
    for (auto el : str)
    {
        v.at(el - 'A')++;
    }

    int count = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) % 2 != 0)
        {
            ++count;
        }
        if (count > 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    // making the palindrome
    // odd first added
    for (int i = 0; i < v.size(); i++)
    {
        if (v.at(i) % 2 != 0)
        {
            for (int j = 0; j < v.at(i); j++)
            {
                dq.emplace_back(i + 'A');
            }
        }
    }

    // for even
    for (int i = 0; i < v.size(); i++)
    {
        if (!(v.at(i) % 2))
        {
            // emplace_back
            for (int j = 0; j < (v.at(i) / 2); j++)
            {
                dq.emplace_back(i + 'A');
            }

            // emplace_front
            for (int j = 0; j < v.at(i) / 2; j++)
            {
                dq.emplace_front(i + 'A');
            }
        }
    }

    string ans;

    for (auto el : dq)
    {
        ans.push_back(el);
    }

    cout << ans << endl;

    return 0;
}
