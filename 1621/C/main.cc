#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> p = vector<int>(n);
        //vector<int>

        int query = 1, position = 1;
        int result;

        int i = 0;
        while (i < 2 * n)
        {
            if (i == 0)
            {

                cout << "? 1" << endl;
                i++;
                cin >> result;
            }
            else if (p[position - 1] == 0)
            {
                cout << "? " << query << endl;
                i++;
                cin >> result;

                p[position - 1] = result;
                position = result;
            }
            else
            {
                bool query_complete = true;

                for (int j = 0; j < n; j++)
                {
                    if (p[j] == 0)
                    {
                        position = j + 1;
                        query = j + 1;
                        query_complete = false;
                        break;
                    }
                }

                if (query_complete)
                    break;

                while (true)
                {
                    cout << "? " << query << endl;
                    i++;
                    cin >> result;

                    if (result == position)
                    {
                        break;
                    }
                }
            }
        }

        cout << "! ";
        for (int e : p)
        {
            cout << e << ' ';
        }
        cout << endl;
    }

    return 0;
}