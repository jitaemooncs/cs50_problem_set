#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    // Check the prompt of the user
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    // Check if the key is valid
    else
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");

            return 1;
        }
    }

    string plaintext = get_string("plaingtext: ");

    int length = strlen(plaintext);

    int key[26];

    // Put alphabets in the array of key
    for (int i = 0; i < 26; i++)
    {
        key[i] = i + 65;
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (tolower(plaintext[i]) == tolower(key[j]))
            {
                if (plaintext[i] > 'A' && plaintext[i] < 'Z')
                {
                    plaintext[i] = toupper(argv[1][j]);
                }
                else
                {
                    plaintext[i] = tolower(argv[1][j]);
                }

                // If there's no break it will check repeatedly and prints the wrong alphabet ex) HELLO -> BELLO not VELLO
                break;
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);

    return 0;
}