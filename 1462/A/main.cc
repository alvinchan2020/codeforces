#include <iostream>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        list<int> seq;
        for (int j = 0; j < n; j++)
        {
            int b;
            cin >> b;
            seq.push_back(b);
        }

        // solve
        for (int j = 0; j < n; j++)
        {
            if (((j + 1) % 2) == 1)
            {
                cout << seq.front() << ' ';
                seq.pop_front();
            }
            else
            {
                cout << seq.back() << ' ';
                seq.pop_back();
            }
        }
        cout << endl;
    }

    return 0;
}
