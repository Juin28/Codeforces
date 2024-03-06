#include <iostream>
using namespace std;

void merge(int A[], int begin, int mid, int end)
{   
    int B[end-begin+1];

    int LP = begin;
    int RP = mid+1;
    int BP = 0;

    while ( (LP <= mid) || (RP <= end) )
    {
        if ( (RP > end) || ((LP <= mid) && (A[LP] < A[RP])) )
        {
            B[BP] = A[LP];
            BP++;
            LP++;
        }
        else
        {
            B[BP] = A[RP];
            BP++;
            RP++;
        }
    }

    for (int i = begin; i <= end; i++)
    {
        A[i] = B[i-begin];
    }
}

void ms(int A[], int begin, int end)
{
    if (end <= begin)
        return;
    
    int mid = (begin+end)/2;

    ms(A, begin, mid);
    ms(A, mid+1, end);
    merge(A, begin, mid, end);
}

void parity_sort(int array[], int begin, int end)
{
    int original[end-begin+1];

    for (int i = 0; i <= end; i++)
    {
        original[i] = array[i];
    }
    

    int odd[end-begin+1];
    int even[end-begin+1];

    int odd_index[end-begin+1];
    int even_index[end-begin+1];

    int odd_n = 0, even_n = 0;

    for (int i = 0; i <= end; i++)
    {
        if ((array[i] % 2) == 1)
        {
            odd[odd_n] = array[i];
            odd_index[odd_n] = i;
            ++odd_n;
        }
        else
        {
            even[even_n] = array[i];
            even_index[even_n] = i;
            ++even_n;
        }
    }

    ms(odd, 0, odd_n - 1);
    ms(even, 0, even_n - 1);

    for (int i = 0; i < odd_n; i++)
        array[odd_index[i]] = odd[i];
    for (int i = 0; i < even_n; i++)
        array[even_index[i]] = even[i];

    for (int i = 0; i < end; i++)
    {
        if (array[i] > array[i+1])
        {
            cout << "NO" << endl;
            return;
        }
        
    }
    cout << "YES" << endl;
    return;

    

    
}

// int main()
// {
//     // for testing function code

//     int len;
//     cin >> len;

//     int array[len]; /////////////////////////////////////////////////////////////////////////////////

//     for (int j = 0; j < len; j++)
//     {
//         // int array[len];
//         cin >> array[j];

//         // parity_sort(array, 0, len-1);
//     }

//     // /////////////////////////////////////////////////////////////////////////////////
//     // for (int i = 0; i < len; i++)
//     // {
//     //     cout << array[i] << '\t';
//     // }
//     // cout << endl;
//     // /////////////////////////////////////////////////////////////////////////////////


//     parity_sort(array, 0, len-1); /////////////////////////////////////////////////////////////////////////////////
// }

int main()
{
    int num_test_cases;
    cin >> num_test_cases;

    for (int i = 0; i < num_test_cases; i++)
    {
        int len;
        cin >> len;

        int array[len];

        for (int j = 0; j < len; j++)
        {
            cin >> array[j];
        }

        parity_sort(array, 0, len-1);
    }
}
