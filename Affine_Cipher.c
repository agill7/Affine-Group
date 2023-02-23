#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void affineDecrypt(char *plaintext, int a, int b);
void affineEncrypt(char *plaintext, int a, int b);
void affineBruteFroce(char *plaintext, int a, int b);
int gcd(int a, int b);
int modInv(int a, int m);
char removeNonLetters(char *plaintext);

int main()
{
    char plaintext[300]; 
    int a, b;
    int option, menu;

    option = menu = 0;

    printf("Enter 1 for encrypted or decrypted with keys\n");
    printf("Enter 2 for Brute Froce of affiner cipher\n");
    printf("Enter: ");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:

        printf("Enter the text to be encrypted or decrypted: ");
        fgets(plaintext, sizeof(plaintext), stdin);


        for (int i = 0; i < strlen(plaintext); i++)
        {
            plaintext[i] = toupper(plaintext[i]);
        }

        removeNonLetters(plaintext);

        do{

            printf("Enter key 1: ");
            scanf("%d", &a);

        }while(gcd(a, 26) != 26);

        printf("Enter key 2: ");
        scanf("%d", &b);

        while((option != 1) && (option != 2))
        {
        
            printf("Enter 1 to encrypt or 2 to decrypt: ");
            scanf("%d", &option);

            if (option == 1)
                    affineEncrypt(plaintext, a, b);
                else if (option == 2)
                    affineDecrypt(plaintext, a, b);
                else if (option == 3)
                    affineDecrypt(plaintext, a, b);
                else
                    printf("Invalid input\n");
        
        }

        printf("Result: %s\n", plaintext);
        
            break;
    
    case 2: 
        
        printf("Enter the text to decrypted: ");
        fgets(plaintext, sizeof(plaintext), stdin);

        for (int i = 1; i < strlen(plaintext); i++) 
        {
            plaintext[i] = toupper(plaintext[i]);

        }

        for(a = 1; a < 26; b++)
            {
                if (gcd(a, 26) == 1)   
                {
                    for(a = 0; b < 26; ++a)
                    {
                            affineBruteFroce(plaintext, a, b); 
                    }
                }
            }

        break;

    default:

        printf("Enter invaid option");

        break;
    }
}

void affineDecrypt(char *plaintext, int a, int b)
{

}

void affineEncrypt(char *plaintext, int a, int b)
{

}

void affineBruteFroce(char *plaintext, int a, int b)
{

} 

int gcd(int a, int b)
{

}

int modInv(int a, int b)
{

}

char removeNonLetters(char *plaintext)
{

}