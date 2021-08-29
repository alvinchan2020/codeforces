#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            if (j % 3 == 0)
                cout << 'a';
            if (j % 3 == 1)
                cout << 'b';
            if (j % 3 == 2)
                cout << 'c';
        }

        cout << endl;
    }

    return 0;
}