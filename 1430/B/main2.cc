#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        sort(array, array + n);

        unsigned long long sum = 0;
        for (int i = 0; i <= k; i++)
        {
            sum += array[n - 1 - i];
        }

        cout << sum << endl;
    }

    return 0;
}