#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int len;
    cin >> len;

    vector<long long> input(len);

    for (int i = 0; i < len; i++)
    {
        cin >> input[i];
        input[i] = abs(input[i]);
    }

    sort(input.begin(), input.end());

    long long num_correct_pairs = 0;
    for (int i = 0; i < len; i++) {
        int j = upper_bound(input.begin(), input.end(), input[i] * 2) - input.begin();
        num_correct_pairs += (j - i - 1); 
    }

    cout << num_correct_pairs << endl;

    return 0;
}
