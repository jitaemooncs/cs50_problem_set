#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check the argc of prompt is 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");

        return 1;
    }

    // Getting key of the ciphertext
    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");

    int length = strlen(plaintext);

    for (int i = 0; i < length; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            plaintext[i] = plaintext[i] - 65;
            plaintext[i] = (plaintext[i] + key) % 26;
            plaintext[i] += 65;
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            plaintext[i] -= 97;
            plaintext[i] = (plaintext[i] + key) % 26;
            plaintext[i] += 97;
        }
    }

    printf("ciphertext: %s\n", plaintext);

    return 0;
}