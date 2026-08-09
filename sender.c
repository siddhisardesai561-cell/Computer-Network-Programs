#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], stuffedData[200];
    int i, j = 0, count = 0;

    printf("Enter the data bits: ");
    scanf("%s", data);

    for(i = 0; data[i] != '\0'; i++)
    {
        stuffedData[j++] = data[i];

        if(data[i] == '1')
        {
            count++;

            if(count == 5)
            {
                stuffedData[j++] = '0';   // Stuff a 0
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    stuffedData[j] = '\0';

    printf("Original Data : %s\n", data);
    printf("Stuffed Data  : %s\n", stuffedData);

    return 0;
}
