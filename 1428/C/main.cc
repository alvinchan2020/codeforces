#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string bomb(string str)
{
    string new_str;

    for (char c : str)
    {
        if (new_str.size() > 0)
        {
            if (new_str.back() == 'A' && c == 'B')
                new_str.pop_back();
            else if (new_str.back() == 'B' && c == 'B')
                new_str.pop_back();
            else
                new_str.push_back(c);
        }
        else
            new_str.push_back(c);
    }

    return new_str;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;

        while (true)
        {
            string new_str = bomb(str);

            if (new_str.size() == str.size())
                break;
            else
                str = new_str;

            if (new_str.size() == 0 || new_str.size() == 1)
                break;
        }

        cout << str.size() << endl;
    }
    return 0;
}