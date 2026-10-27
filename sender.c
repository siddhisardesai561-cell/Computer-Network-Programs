#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, stuffedData = "";
    int count = 0;

    cout << "Enter the data bits: ";
    cin >> data;

    for (int i = 0; i < data.length(); i++)
    {
        stuffedData += data[i];

        if (data[i] == '1')
        {
            count++;

            if (count == 5)
            {
                stuffedData += '0';  // Stuff a 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    cout << "Original Data : " << data << endl;
    cout << "Stuffed Data  : " << stuffedData << endl;

    return 0;
}
*/
Enter the data bits: 11111011111
Original Data : 11111011111
Stuffed Data  : 1111100111110
*/