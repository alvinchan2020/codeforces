#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> ones_counter = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            ones_counter[i] = (s[i] == '1' ? 1 : 0);
        else
            ones_counter[i] = ones_counter[i - 1] + (s[i] == '1' ? 1 : 0);
    }

    if (k == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    int prev_left = -1, prev_right = -1;
    int left = 0, right = 0;
    int ones;
    int result = 0;

    auto combination = [](int length, int ones)
    {
        if (ones == 0)
            return 0;

        auto factor = [](int x, int y)
        {
            int result = 1;
            for (int i = 0; i < y; i++)
            {
                result *= x - i;
            }
            return result;
        };

        int result = factor(length, ones) / factor(ones, ones);

        return result - 1;
    };

    while (true)
    {
        if (right == n - 1)
            break;

        // seek right pointer
        while (true)
        {
            if (right < left)
                right = left;

            // calc ones
            if (left == 0)
                ones = ones_counter[right];
            else
                ones = ones_counter[right] - ones_counter[left - 1];

            // seek right pointer
            if (right < n - 1 && ones < k)
            {
                right++;
                continue;
            }
            else if (right < n - 1 && ones == k && s[right + 1] == '0')
            {
                right++;
                continue;
            }
            else
                break;
        }

        // calc ones
        if (left == 0)
            ones = ones_counter[right];
        else
            ones = ones_counter[right] - ones_counter[left - 1];

        if (ones < k)
            break;
        else if (ones > k)
            throw ones;
        else
        {
            // ones == k, right pointer positioned
            // calc combinations
            result += combination(right - left + 1, ones);

            // substract redundent
            if (prev_left != -1 && prev_right >= left)
            {
                result -= combination(prev_right - left + 1, ones_counter[prev_right] - ones_counter[left - 1]);
            }

            prev_left = left;
            prev_right = right;

            // seek left pointer
            while (true)
            {
                if (left == n - 1)
                    break;

                if (s[left] == '1')
                {
                    left++;
                    break;
                }
                else
                    left++;
            }
        }
    }

    cout << result + 1 << endl;

    return 0;
}