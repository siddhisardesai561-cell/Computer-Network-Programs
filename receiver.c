#include <stdio.h>
#include <string.h>

int main()
{
    char stuffedData[200], originalData[200];
    int i, j = 0, count = 0;

    printf("Enter the stuffed data bits: ");
    scanf("%s", stuffedData);

    for(i = 0; stuffedData[i] != '\0'; i++)
    {
        originalData[j++] = stuffedData[i];

        if(stuffedData[i] == '1')
        {
            count++;

            if(count == 5)
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

    originalData[j] = '\0';

    printf("Stuffed Data  : %s\n", stuffedData);
    printf("Original Data : %s\n", originalData);

    return 0;
}
