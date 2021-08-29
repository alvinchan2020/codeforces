#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        char temp_str[n + 1];
        cin >> temp_str;

        list<char> str(temp_str, temp_str + n);

        int operation = 0;

        list<char>::iterator it_head = str.begin();
        list<char>::iterator it_del = str.begin();
        bool it_del_is_invalid = false;

        while (true)
        {
            operation++;

            // find next node to delete
            if (it_del_is_invalid)
            {
                it_del = str.begin();
                it_del_is_invalid = false;
            }

            if (it_del == str.end())
                it_del = prev(it_del);

            while (next(it_del) != str.end() && *it_del != *next(it_del))
            {
                it_del = next(it_del);
            }

            // delete the node
            it_del = str.erase(it_del);

            // check break
            if (str.size() == 0)
                break;

            // delete prefix
            it_head = str.begin();
            char temp_char = *it_head;

            while (it_head != str.end() && *it_head == temp_char)
            {
                if (it_head == it_del)
                    it_del_is_invalid = true;
                it_head = str.erase(it_head);
            }

            // check break
            if (str.size() == 0)
                break;
        }

        cout << operation << endl;
    }

    return 0;
}