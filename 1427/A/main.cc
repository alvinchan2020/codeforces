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

        int a[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        if (sum == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;

            sort(a, a + n);

            if (sum > 0)
                reverse(a, a + n);

            for (int i = 0; i < n; i++)
            {
                cout << a[i];
                if (i != n - 1)
                    cout << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
