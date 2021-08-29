#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <assert.h>

using namespace std;

bool is_hill_or_valley(vector<int> &a, int index)
{
    assert(0 < index && index < a.size() - 1);
    if ((a[index - 1] < a[index]) && (a[index] > a[index + 1]))
        return true;
    else if ((a[index - 1] > a[index]) && (a[index] < a[index + 1]))
        return true;
    else
        return false;
}

int solve(vector<int> a)
{
    int maximum_intimidation_reduced = 0;

    //travel through hill indexes, try to reduce intimidation
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (is_hill_or_valley(a, i))
        {
            // calculate partial intimidation
            int partial_intimidation = 0;
            if ((0 < i - 1) && is_hill_or_valley(a, i - 1))
                partial_intimidation++;
            if (is_hill_or_valley(a, i))
                partial_intimidation++;
            if ((i + 1 < a.size() - 1) && is_hill_or_valley(a, i + 1))
                partial_intimidation++;

            int temp = a[i];

            //try reduce intimidation
            a[i] = a[i - 1];

            int temp1_partial_intimidation = 0;
            if ((0 < i - 1) && is_hill_or_valley(a, i - 1))
                temp1_partial_intimidation++;
            if (is_hill_or_valley(a, i))
                temp1_partial_intimidation++;
            if ((i + 1 < a.size() - 1) && is_hill_or_valley(a, i + 1))
                temp1_partial_intimidation++;

            int temp1_intimidation_reduced = partial_intimidation - temp1_partial_intimidation;
            if (temp1_intimidation_reduced > maximum_intimidation_reduced)
                maximum_intimidation_reduced = temp1_intimidation_reduced;

            //try reduce intimidation
            a[i] = a[i + 1];

            int temp2_partial_intimidation = 0;
            if ((0 < i - 1) && is_hill_or_valley(a, i - 1))
                temp2_partial_intimidation++;
            if (is_hill_or_valley(a, i))
                temp2_partial_intimidation++;
            if ((i + 1 < a.size() - 1) && is_hill_or_valley(a, i + 1))
                temp2_partial_intimidation++;

            int temp2_intimidation_reduced = partial_intimidation - temp2_partial_intimidation;
            if (temp2_intimidation_reduced > maximum_intimidation_reduced)
                maximum_intimidation_reduced = temp2_intimidation_reduced;

            a[i] = temp;
        }
    }

    //calculate intimidation
    int intimidation = 0;
    for (int i = 1; i < a.size() - 1; i++)
    {
        if (is_hill_or_valley(a, i))
            intimidation++;
    }

    int result = intimidation - maximum_intimidation_reduced;
    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];

        int result = solve(a);
        cout << result << endl;
    }

    return 0;
}
