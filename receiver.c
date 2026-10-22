
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string stuffedData, originalData = "";
    int count = 0;

    cout << "Enter the stuffed data bits: ";
    cin >> stuffedData;

    for (int i = 0; i < stuffedData.length(); i++)
    {
        originalData += stuffedData[i];

        if (stuffedData[i] == '1')
        {
            count++;

            if (count == 5)
            {
                i++;          // Skip the stuffed 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    cout << "Stuffed Data  : " << stuffedData << endl;
    cout << "Original Data : " << originalData << endl;

    return 0;
}
*/
Enter the stuffed data bits: 011111010
Stuffed Data  : 011111010
Original Data : 01111110
*/