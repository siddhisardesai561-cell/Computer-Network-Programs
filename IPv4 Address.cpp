#include <iostream>
#include <string>
using namespace std;

// Convert decimal number to 8-bit binary
string decimalToBinary(int n)
{
    string binary = "";

    for (int i = 7; i >= 0; i--)
    {
        if (n & (1 << i))
            binary += '1';
        else
            binary += '0';
    }

    return binary;
}

// Convert complete IP address to binary
string ipToBinary(int a, int b, int c, int d)
{
    return decimalToBinary(a) + "." +
           decimalToBinary(b) + "." +
           decimalToBinary(c) + "." +
           decimalToBinary(d);
}

// Check whether IPv4 address is valid
bool isValid(int a, int b, int c, int d)
{
    return (a >= 0 && a <= 255 &&
            b >= 0 && b <= 255 &&
            c >= 0 && c <= 255 &&
            d >= 0 && d <= 255);
}

int main()
{
    int a, b, c, d;

    cout << "Enter IPv4 address in decimal form: ";
    cin >> a >> b >> c >> d;

    // Validate IP
    if (!isValid(a, b, c, d))
    {
        cout << "\nInvalid IPv4 Address!" << endl;
        return 0;
    }

    cout << "\nValid IPv4 Address!" << endl;

    // Display decimal IP
    cout << "IPv4 Address (Decimal): "
         << a << "." << b << "." << c << "." << d << endl;

    // Convert to binary
    cout << "IPv4 Address (Binary): "
         << ipToBinary(a, b, c, d) << endl;

    // Class A
    if (a >= 1 && a <= 126)
    {
        cout << "\nIP Class: Class A" << endl;
        cout << "Default Subnet Mask: 255.0.0.0" << endl;

        cout << "Network ID: "
             << a << ".0.0.0" << endl;

        cout << "Host ID: "
             << "0." << b << "." << c << "." << d << endl;
    }

    // Class B
    else if (a >= 128 && a <= 191)
    {
        cout << "\nIP Class: Class B" << endl;
        cout << "Default Subnet Mask: 255.255.0.0" << endl;

        cout << "Network ID: "
             << a << "." << b << ".0.0" << endl;

        cout << "Host ID: "
             << "0.0." << c << "." << d << endl;
    }

    // Class C
    else if (a >= 192 && a <= 223)
    {
        cout << "\nIP Class: Class C" << endl;
        cout << "Default Subnet Mask: 255.255.255.0" << endl;

        cout << "Network ID: "
             << a << "." << b << "." << c << ".0" << endl;

        cout << "Host ID: "
             << "0.0.0." << d << endl;
    }

    // Class D
    else if (a >= 224 && a <= 239)
    {
        cout << "\nIP Class: Class D" << endl;
        cout << "Used for Multicast" << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
    }

    // Class E
    else
    {
        cout << "\nIP Class: Class E" << endl;
        cout << "Reserved for Experimental Use" << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
    }

    return 0;
}
