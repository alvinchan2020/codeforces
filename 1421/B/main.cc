#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        char map[n][n + 1];
        for (int i = 0; i < n; i++)
        {
            cin >> map[i];
        }

        // we only care top left 5 values
        // two posible way

        // first 0 / 1
        int diff_1 = 0;
        if (map[0][1] != '0')
            diff_1++;
        if (map[1][0] != '0')
            diff_1++;
        if (map[0][2] != '1')
            diff_1++;
        if (map[1][1] != '1')
            diff_1++;
        if (map[2][0] != '1')
            diff_1++;

        // second 1 / 0
        int diff_2 = 0;
        if (map[0][1] != '1')
            diff_2++;
        if (map[1][0] != '1')
            diff_2++;
        if (map[0][2] != '0')
            diff_2++;
        if (map[1][1] != '0')
            diff_2++;
        if (map[2][0] != '0')
            diff_2++;

        // we are gonna flip twice anyway
        int fliped = 0;
        cout << 2 << endl;

        // chose way to flip
        if (diff_1 < diff_2)
        {
            if (map[0][1] != '0')
            {
                cout << 1 << ' ' << 2 << endl;
                fliped++;
            }
            if (map[1][0] != '0')
            {
                cout << 2 << ' ' << 1 << endl;
                fliped++;
            }
            if (map[0][2] != '1')
            {
                cout << 1 << ' ' << 3 << endl;
                fliped++;
            }
            if (map[1][1] != '1')
            {
                cout << 2 << ' ' << 2 << endl;
                fliped++;
            }
            if (map[2][0] != '1')
            {
                cout << 3 << ' ' << 1 << endl;
                fliped++;
            }

            if (fliped == 0)
            {
                cout << 2 << ' ' << 3 << endl;
                cout << 3 << ' ' << 2 << endl;
            }
            if (fliped == 1)
            {
                cout << 2 << ' ' << 3 << endl;
            }
        }
        else
        {
            if (map[0][1] != '1')
            {
                cout << 1 << ' ' << 2 << endl;
                fliped++;
            }
            if (map[1][0] != '1')
            {
                cout << 2 << ' ' << 1 << endl;
                fliped++;
            }
            if (map[0][2] != '0')
            {
                cout << 1 << ' ' << 3 << endl;
                fliped++;
            }
            if (map[1][1] != '0')
            {
                cout << 2 << ' ' << 2 << endl;
                fliped++;
            }
            if (map[2][0] != '0')
            {
                cout << 3 << ' ' << 1 << endl;
                fliped++;
            }

            if (fliped == 0)
            {
                cout << 2 << ' ' << 3 << endl;
                cout << 3 << ' ' << 2 << endl;
            }
            if (fliped == 1)
            {
                cout << 2 << ' ' << 3 << endl;
            }
        }
    }

    return 0;
}
