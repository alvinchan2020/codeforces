#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<char> s = vector<char>(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];

        sort(s.begin(), s.end());

        int pair_letters = 0;
        int single_letters = 0;

        int i = 0;
        while (true)
        {
            if (i == n)
            {
                break;
            }

            if (i == n - 1)
            {
                single_letters++;
                break;
            }

            if (s[i] == s[i + 1])
            {
                pair_letters += 2;
                i += 2;
            }
            else
            {
                single_letters++;
                i += 1;
            }
        }

        // calc string lengths
        vector<int> length_vector = vector<int>(k);

        // distribute single letters
        for (int i = 0; i < k; i++)
        {
            if (single_letters == 0)
                break;
            else
            {
                single_letters--;
                length_vector[i]++;
            }
        }

        // distribute pair letters
        i = 0;
        while (true)
        {
            if (i == 0)
            {
                if (pair_letters / 2 < k)
                    break;
            }

            if (pair_letters == 0)
                break;
            else
            {
                pair_letters -= 2;
                length_vector[i] += 2;
            }

            i++;
            if (i == k)
            {
                i = 0;
            }
        }

        // check even length
        int even_lengths = 0;
        for (int i = 0; i < k; i++)
        {
            if (length_vector[i] % 2 == 0)
                even_lengths++;
        }

        // distribute extra letters to even length
        for (int i = 0; i < k; i++)
        {
            if (pair_letters == 0)
                break;
            else if (length_vector[i] % 2 == 0)
            {
                pair_letters--;
                length_vector[i]++;
            }
        }

        // find min length
        int min_length = *min_element(length_vector.begin(), length_vector.end());

        if (min_length == 0)
            cout << 1 << endl;
        else
            cout << min_length << endl;
    }

    return 0;
}