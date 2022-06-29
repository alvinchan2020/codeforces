#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n;i++){
            cin >> a[i];
        }

        int n_too_tall = 0;

        for (int i = 1; i < n-1;i++){
            if(a[i] > a[i-1] + a[i+1])
                n_too_tall++;
        }

        if(k==1)
            n_too_tall = (n-1) / 2;

        cout << n_too_tall << endl;
    }

    return 0;
}