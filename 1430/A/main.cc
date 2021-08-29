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

        // 3 5 7
        int a = 0, b = 0, c = 0;

        if (n < 3)
        {
            cout << -1 << endl;
            continue;
        }
        else if (n == 4)
        {
            cout << -1 << endl;
        }
        else if (n % 3 == 0)
        {
            a = n / 3;
            cout << a << ' ' << b << ' ' << c << endl;
        }
        else if ((n - 5) % 3 == 0)
        {
            b = 1;
            a = (n - 5) / 3;
            cout << a << ' ' << b << ' ' << c << endl;
        }
        else if ((n - 7) % 3 == 0)
        {
            c = 1;
            a = (n - 7) / 3;
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }
    return 0;
}