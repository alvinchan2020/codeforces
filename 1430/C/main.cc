#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << 2 << endl;

        int last = n;
        int next;

        for (int i = n - 1; i > 0; i--)
        {
            next = i;
            cout << next << ' ' << last << endl;

            if ((last + next) % 2 == 0)
                last = (last + next) / 2;
            else
                last = (last + next + 1) / 2;
        }
    }
    return 0;
}