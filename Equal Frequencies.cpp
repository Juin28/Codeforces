#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5 + 10;

char str[MAX_N];
int frequency[26], order[26];  

void balance() {
    int n;
    cin >> n;
    cin >> str;

    memset(frequency, 0, sizeof(frequency));

    for (int i = 0; i < n; i++) {
        frequency[str[i] - 'a']++;        // count the size of each character
    }

    iota(order , order + 26, 0);            // initialize array p to [0, 1, 2, ...., 25]
    sort(order , order + 26, [&](int i, int j) { return frequency[i] > frequency[j]; });     // sort array p follow the size of each character in descending order

    int min_changes = n, optimal_num_char;         
    for (int i = 1; i <= 26; i++) 
    {    
        if (n % i == 0) {           // check if i is a factor of len (i is the number of distinct characters)
            int size = n / i, num_of_diff = 0;  
            for (int j = 0; j < i; j++) {    
                num_of_diff += abs(frequency[order[j]] - size);    // count the number of differences between current_size and ideal_size for i number of distinct characters
            }
            for (int j = i; j < 26; j++) {   
                num_of_diff += frequency[order[j]];             // count the number of differences between current_size and ideal_size for len - i number of remaining characters    
            }
            if (num_of_diff/2 < min_changes)
            {
                min_changes = num_of_diff / 2;          // MOST IMPORTANT !!!!!!!!!!
                optimal_num_char = i;                   // Because the upper bound of number of changes required is number of differences/2
            }  
        }
    }
    for (int i = 0; i < optimal_num_char; i++) 
    {
        frequency[order[i]] -= n / optimal_num_char;    // subtract the ideal_size from the actual_size for optimal number of characters
    }
    for (int i = 0, j = optimal_num_char - 1; i < n; i++) 
    {
        while (j >= 0 && frequency[order[j]] >= 0) 
        {    
            j--;        // loop through the array p (order) until found one with (actual_size - ideal_size) < 0
        }
        if (frequency[str[i] - 'a'] > 0)          // loop for the original string until found one with (actual_size - ideal_size) > 0
        {    
            frequency[str[i] - 'a']--;        // the size of the character with (actual_size - ideal_size) > 0 --
            frequency[order[j]]++;                // the size of the character with (actual_size - ideal_size) < 0 ++ 
            str[i] = order[j] + 'a';        // replace [the character with (actual_size - ideal_size) > 0] with [character with (actual_size - ideal_size) < 0]
        }
    }
    cout << min_changes << endl;
    cout << str << endl;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; i++)
    {
        balance();
    }
    
    return 0;
}