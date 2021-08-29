#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ull unsigned long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ull> barrels(n);
        for (int i = 0; i < n; i++)
        {
            cin >> barrels[i];
        }

        ull max_water = 0;

        make_heap(barrels.begin(), barrels.end());
        max_water += barrels.front();

        pop_heap(barrels.begin(), barrels.end());
        barrels.pop_back();

        //cout << max_water << endl;

        while (k--)
        {
            max_water += barrels.front();

            pop_heap(barrels.begin(), barrels.end());
            barrels.pop_back();
        }

        cout << max_water << endl;
    }
    return 0;
}