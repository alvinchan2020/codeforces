#include <iostream>
#include <string>
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

        char belts[n + 1];
        cin >> belts;

        // check clockwise connectivity
        bool clockwise_conn = true;
        bool countclock_conn = true;
        for (int i = 0; i < n; i++)
        {
            if (belts[i] == '<')
                clockwise_conn = false;

            if (belts[i] == '>')
                countclock_conn = false;
        }

        int returnable = 0;

        for (int i = 0; i < n; i++)
        {
            char belt_r, belt_l;

            belt_r = belts[i];
            if (i == 0)
                belt_l = belts[n - 1];
            else
                belt_l = belts[i - 1];

            if (belt_r == '-' || belt_l == '-')
                returnable++;

            else if (clockwise_conn && (belt_r == '>' && belt_l == '>'))
                returnable++;

            else if (countclock_conn && (belt_r == '<' && belt_l == '<'))
                returnable++;
        }

        cout << returnable << endl;
    }
    return 0;
}
