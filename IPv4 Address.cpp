#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string ip;
    int a, b, c, d;
    char dot1, dot2, dot3, extra;

    cout << "Enter IPv4 address in decimal form: ";
    cin >> ip;

    stringstream ss(ip);

    // Check IPv4 format
    if (!(ss >> a >> dot1 >> b >> dot2 >> c >> dot3 >> d) ||
        dot1 != '.' || dot2 != '.' || dot3 != '.' ||
        (ss >> extra))
    {
        cout << "Invalid IPv4 Address!" << endl;
        return 0;
    }

    // Validate each octet
    if (a < 0 || a > 255 ||
        b < 0 || b > 255 ||
        c < 0 || c > 255 ||
        d < 0 || d > 255)
    {
        cout << "Invalid IPv4 Address!" << endl;
        return 0;
    }

    cout << "\nIPv4 Address: "
         << a << "." << b << "." << c << "." << d << endl;

    cout << "Valid IPv4 Address!" << endl;

    // Class A
    if (a >= 1 && a <= 126)
    {
        cout << "Class: A" << endl;
        cout << "Default Subnet Mask: 255.0.0.0" << endl;
        cout << "Network ID: " << a << endl;
        cout << "Host ID: " << b << "." << c << "." << d << endl;
    }

    // Class B
    else if (a >= 128 && a <= 191)
    {
        cout << "Class: B" << endl;
        cout << "Default Subnet Mask: 255.255.0.0" << endl;
        cout << "Network ID: " << a << "." << b << endl;
        cout << "Host ID: " << c << "." << d << endl;
    }

    // Class C
    else if (a >= 192 && a <= 223)
    {
        cout << "Class: C" << endl;
        cout << "Default Subnet Mask: 255.255.255.0" << endl;
        cout << "Network ID: " << a << "." << b << "." << c << endl;
        cout << "Host ID: " << d << endl;
    }

    // Class D
    else if (a >= 224 && a <= 239)
    {
        cout << "Class: D (Multicasting)" << endl;
        cout << "No default subnet mask." << endl;
    }

    // Class E
    else if (a >= 240 && a <= 255)
    {
        cout << "Class: E (Experimental)" << endl;
        cout << "No default subnet mask." << endl;
    }

    else
    {
        cout << "Reserved IPv4 Address!" << endl;
    }

    return 0;
}
output....
Enter IPv4 address in decimal form: 10.20.30.40

IPv4 Address: 10.20.30.40
Valid IPv4 Address!
Class: A
Default Subnet Mask: 255.0.0.0
Network ID: 10
Host ID: 20.30.40