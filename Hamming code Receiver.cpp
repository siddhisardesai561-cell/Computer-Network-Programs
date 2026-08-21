#include <iostream>
using namespace std;

int main()
{
    int n;
    int code[20];

    cout << " RECEIVER SIDE \n";

    cout << "Enter total number of codeword bits: ";
    cin >> n;

    cout << "Enter received codeword: ";

    for (int i = 1; i <= n; i++)
    {
        cin >> code[i];
    }

    // Display received codeword
    cout << "\nReceived Codeword : ";

    for (int i = 1; i <= n; i++)
    {
        cout << code[i];
    }

    cout << endl;

    // Calculate error position
    int errorPosition = 0;
 for (int p = 1; p <= n; p = p * 2)
    {
        int parity = 0;

        for (int i = p; i <= n; i += 2 * p)
        {
            for (int j = i; j < i + p && j <= n; j++)
            {
                parity = parity ^ code[j];
            }
        }

        if (parity != 0)
        {
            errorPosition = errorPosition + p;
        }
    }

    // Display redundant bits
    cout << "\nRedundant Bits:\n";

    for (int i = 1; i <= n; i = i * 2)
    {
        cout << "R" << i << " = " << code[i] << endl;
    }

    // Display error position
    cout << "\nError Position : " << errorPosition << endl;

    // Correct error
    if (errorPosition == 0)
    {
        cout << "No Error Detected." << endl;
    }
    else
    { 
         cout << "Error Detected." << endl;

        code[errorPosition] = code[errorPosition] ^ 1;

        cout << "Error Corrected." << endl;
    }

    // Display corrected codeword
    cout << "\nCorrected Codeword : ";

    for (int i = 1; i <= n; i++)
    {
        cout << code[i];
    }

    cout << endl;

    // Extract original data bits
    cout << "Original Data : ";

    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) != 0)
        {
            cout << code[i];
        }
    }

    cout << endl;

    return 0;
}

/* Outout :

RECEIVER SIDE 
Enter total number of codeword bits: 11
Enter received codeword: 0 0 1 0 1 0 1 0 0 1 1

Received Codeword : 00101010011

Redundant Bits:
R1 = 0
R2 = 0
R4 = 0
R8 = 0

Error Position : 0
No Error Detected.

Corrected Codeword : 00101010011
Original Data : 1101011 *\




