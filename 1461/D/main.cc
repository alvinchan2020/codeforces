#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ull;

// generate all the possible totalings
void generate_totalings(vector<int> &a, vector<ull> &totalings)
{
    if (a.size() == 0)
    {
        return;
    }
    else if (a.size() == 1)
    {
        totalings.push_back(a[0]);
        return;
    }
    else if (a.size() > 1)
    {
        //calculate totaling
        ull totaling = 0;
        for (int v : a)
            totaling += v;
        totalings.push_back(totaling);

        //if a are all same number, a is unsplitable
        bool same_number_flag = true;
        for (int v : a)
        {
            if (v != a[0])
                same_number_flag = false;
        }
        if (same_number_flag == true)
            return;

        //slice array
        int max_array = *max_element(a.begin(), a.end());
        int min_array = *min_element(a.begin(), a.end());
        int mid = (max_array + min_array) / 2;

        vector<int> a_left(0);
        vector<int> a_right(0);
        for (int v : a)
        {
            if (v <= mid)
                a_left.push_back(v);
            else
                a_right.push_back(v);
        }

        //recursion
        generate_totalings(a_left, totalings);
        generate_totalings(a_right, totalings);
        return;
    }
}

int solve(vector<int> a, vector<int> s)
{
    vector<ull> totalings(0);
    generate_totalings(a, totalings);

    //sort totalings
    sort(totalings.begin(), totalings.end());

    for (int si : s)
    {
        //use binary search to determine wether si in totalings
        if (binary_search(totalings.begin(), totalings.end(), si))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

int main()
{
    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> s(q);
        for (int i = 0; i < q; i++)
            cin >> s[i];

        solve(a, s);
    }
    return 0;
}
