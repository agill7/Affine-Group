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
    char *plaintext; 
    int a, b;
    int option;

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

    if (option == 1)
            affineEncrypt(plaintext, a, b);
        else if (option == 2)
            affineDecrypt(plaintext, a, b);
        else
            printf("Invalid input\n");
    

    printf("Result: %s\n", plaintext);

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