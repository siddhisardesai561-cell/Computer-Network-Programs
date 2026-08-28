#include <iostream>
#include <string>
using namespace std;

string xorOperation(string a, string b)
{
    string result = "";

    for (int i = 0; i < b.length(); i++)
    {
        if (a[i] == b[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

string crcDivision(string data, string generator)
{
    int n = generator.length();

    for (int i = 0; i <= data.length() - n; i++)
    {
        if (data[i] == '1')
        {
            string part = data.substr(i, n);
            string x = xorOperation(part, generator);

            for (int j = 0; j < n; j++)
                data[i + j] = x[j];
        }
    }

    return data;
}

int main()
{
    string received, generator;

    cout << "Enter received codeword: ";
    cin >> received;

    cout << "Enter generator: ";
    cin >> generator;

    // CRC division
    string result = crcDivision(received, generator);

    int r = generator.length() - 1;

    // Get remainder
    string remainder = result.substr(result.length() - r);

    cout << "\n--- RECEIVER SIDE ---\n";
    cout << "Received Data : " << received << endl;
    cout << "Remainder     : " << remainder << endl;

    // Check error
    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error detected!" << endl;
    else
        cout << "No error detected." << endl;

    return 0;
}

//Output
Enter received codeword: 11010110111110
Enter generator: 10011

--- RECEIVER SIDE ---
Received Data : 11010110111110
Remainder     : 0000
No error detected.
