#include <iostream>
#include <string>
using namespace std;

// Check whether the IPv4 binary address is valid
bool isValid(string ip)
{
    // Format: 8 bits.8 bits.8 bits.8 bits = 35 characters
    if (ip.length() != 35)
        return false;

    int bits = 0;
    int dots = 0;

    for (int i = 0; i < ip.length(); i++)
    {
        if (ip[i] == '0' || ip[i] == '1')
        {
            bits++;
        }
        else if (ip[i] == '.')
        {
            dots++;

            // Every octet must have exactly 8 bits
            if (bits != 8)
                return false;

            bits = 0;
        }
        else
        {
            return false;
        }
    }

    return (bits == 8 && dots == 3);
}

// Convert 8-bit binary string to decimal
int binaryToDecimal(string binary)
{
    int decimal = 0;

    for (int i = 0; i < 8; i++)
    {
        decimal = decimal * 2 + (binary[i] - '0');
    }

    return decimal;
}

// Add dots after every 8 bits
string addDots(string binary)
{
    string result = "";

    for (int i = 0; i < 32; i++)
    {
        result += binary[i];

        if ((i + 1) % 8 == 0 && i != 31)
            result += '.';
    }

    return result;
}

// Convert 32-bit binary address to dotted decimal
string binaryToDottedDecimal(string binary)
{
    string result = "";

    for (int i = 0; i < 4; i++)
    {
        string octet = binary.substr(i * 8, 8);

        result += to_string(binaryToDecimal(octet));

        if (i != 3)
            result += '.';
    }

    return result;
}

int main()
{
    string ip;

    cout << "Enter IPv4 address in binary form:" << endl;
    cout << "Example: 11000000.10101000.00000001.00000001" << endl;

    cin >> ip;

    // Check validity
    if (!isValid(ip))
    {
        cout << "\nInvalid IPv4 Address!" << endl;
        return 0;
    }

    // Extract four octets
    string octet[4];
    int pos = 0;

    for (int i = 0; i < 4; i++)
    {
        octet[i] = ip.substr(pos, 8);
        pos += 9;
    }

    // Get first octet in decimal
    int firstOctet = binaryToDecimal(octet[0]);

    string ipClass;
    string defaultMask;
    int networkBits;

    // Identify IPv4 class
    if (firstOctet >= 1 && firstOctet <= 126)
    {
        ipClass = "Class A";
        defaultMask = "255.0.0.0";
        networkBits = 8;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        ipClass = "Class B";
        defaultMask = "255.255.0.0";
        networkBits = 16;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        ipClass = "Class C";
        defaultMask = "255.255.255.0";
        networkBits = 24;
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "\nValid IPv4 Address" << endl;
        cout << "Class: Class D" << endl;
        cout << "Used for Multicast" << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
        return 0;
    }
    else
    {
        cout << "\nValid IPv4 Address" << endl;
        cout << "Class: Class E" << endl;
        cout << "Reserved for Experimental Use" << endl;
        cout << "Network ID and Host ID are not applicable." << endl;
        return 0;
    }

    // Create 32-bit binary address without dots
    string binaryIP = "";

    for (int i = 0; i < 4; i++)
    {
        binaryIP += octet[i];
    }

    string netID = "";
    string hostID = "";

    // Calculate Network ID and Host ID
    for (int i = 0; i < 32; i++)
    {
        if (i < networkBits)
        {
            // Network part remains same, host part becomes 0
            netID += binaryIP[i];
            hostID += '0';
        }
        else
        {
            // Network part becomes 0, host part remains same
            netID += '0';
            hostID += binaryIP[i];
        }
    }

    // Display results
    cout << "\n========== OUTPUT ==========" << endl;

    cout << "\nIPv4 Address (Binary): "
         << ip << endl;

    cout << "IPv4 Address (Decimal): "
         << binaryToDottedDecimal(binaryIP) << endl;

    cout << "\nIP Class: "
         << ipClass << endl;

    cout << "Default Subnet Mask: "
         << defaultMask << endl;

    // Network ID
    cout << "\nNetwork ID:" << endl;

    cout << "Binary  : "
         << addDots(netID) << endl;

    cout << "Decimal : "
         << binaryToDottedDecimal(netID) << endl;

    // Host ID
    cout << "\nHost ID:" << endl;

    cout << "Binary  : "
         << addDots(hostID) << endl;

    cout << "Decimal : "
         << binaryToDottedDecimal(hostID) << endl;

    return 0;
}