
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
    string data, generator;

    cout << "Enter data: ";
    cin >> data;

    cout << "Enter generator: ";
    cin >> generator;

    int r = generator.length() - 1;

    // Append zeros
    string appendedData = data + string(r, '0');

    // CRC division
    string result = crcDivision(appendedData, generator);

    // Get CRC remainder
    string crc = result.substr(result.length() - r);

    // Codeword
    string codeword = data + crc;

    cout << "\n--- SENDER SIDE ---\n";
    cout << "Original Data : " << data << endl;
    cout << "CRC           : " << crc << endl;
    cout << "Codeword      : " << codeword << endl;

    return 0;
}

//Outout 
Enter data: 1101011011
Enter generator: 10011

--- SENDER SIDE ---
Original Data : 1101011011
CRC           : 1110
Codeword      : 11010110111110
//
