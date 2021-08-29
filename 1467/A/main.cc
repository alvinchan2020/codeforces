#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;

        if (n == 1)
            cout << "9" << endl;
        else if (n == 2)
            cout << "98" << endl;
        else
        {
            cout << "98";
            n -= 2;
            int p = 8;
            while (n-- > 0)
            {
                p += 1;
                if (p == 10)
                    p = 0;
                cout << p;
            }
            cout << endl;
        }
    }
    return 0;
}
