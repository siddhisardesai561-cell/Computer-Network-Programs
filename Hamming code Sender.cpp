#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, r = 0, n;
    int data[20], code[20];

    cout << " SENDER SIDE \n";

    cout << "Enter number of data bits: ";
    cin >> m;

    cout << "Enter data bits: ";
    for (int i = 0; i < m; i++)
    {
        cin >> data[i];
    }

    // Calculate number of redundant bits
    while (pow(2, r) < m + r + 1)
    {
        r++;
    }

    n = m + r;

    cout << "\nNumber of Data Bits      : " << m;
    cout << "\nNumber of Redundant Bits : " << r;
    cout << "\nTotal Codeword Bits      : " << n << endl;

    // Place data bits
    int j = 0;
for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
        {
            code[i] = 0;
        }
        else
        {
            code[i] = data[j];
            j++;
        }
    }

    // Calculate even parity bits
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

        code[p] = parity;
    }

    // Display redundant bits
    cout << "\nRedundant Bits:\n";

    for (int i = 1; i <= n; i = i * 2)
    {
        cout << "R" << i << " = " << code[i] << endl;
    }
   // Display final codeword
    cout << "\nHamming Codeword : ";

    for (int i = 1; i <= n; i++)
    {
        cout << code[i];
    }

    cout << endl;

    return 0;
}


 /*Output : 
 
SENDER SIDE 
Enter number of data bits: 7
Enter data bits: 1 1 0 1 0 1 1

Number of Data Bits      : 7
Number of Redundant Bits : 4
Total Codeword Bits      : 11

Redundant Bits:
R1 = 0
R2 = 0
R4 = 0
R8 = 0

Hamming Codeword : 00101010011 */





