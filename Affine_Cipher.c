#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Prototype function
void affineDecrypt(char *plaintext, int a, int b);
void affineEncrypt(char *plaintext, int a, int b);
void affineBruteFroce(char *plaintext, int a, int b);
int gcd(int a, int b);
int modInv(int a, int m);
char removeNonLetters(char *plaintext);

int main()
{
    char plaintext[300]; // stores the user input text 
    int a, b; // keys 
    int option, menu; 

    /* 
    options = used for Case 1 to let the use choose to 
    encrypted or decrypted 
     
    menu = Lets the user choose between case 1 and case 2.
    */

    option = menu = 0;

    
    // Get user input to know if they want to brute force or encrypted/decrypted
    printf("Enter 1 for encrypted or decrypted with keys\n");
    printf("Enter 2 for Brute Froce of affiner cipher\n");
    printf("Enter: ");
    scanf("%d", &menu);

    /* 
    Case 1 is for encrypted or decrypted with keys when the keys are known to the user
    also can be used to encryt a text. User can give thier own keys.

    Case 2 is for brute forece, used for when the keys are unknown. 
    Group cipher text =  RILTOEAQGEQDPOJOESPQW
    */

    switch(menu)
    {

    /*--------------------------------Encrytion/Decryption-------------------------------------------*/
    case 1:

        // Getting user input
        printf("Enter the text to be encrypted or decrypted: ");
        scanf("%s", &plaintext);

        // Changing input to upper case
        for (int i = 0; i < strlen(plaintext); i++)
        {
            plaintext[i] = toupper(plaintext[i]);
        }

        // Remove numbers and symbolsfrom string
        removeNonLetters(plaintext);

        // Getting the keys
        printf("Enter key 1 (1 < 26): ");
        scanf("%d", &a);

        // If the key is not relatively prime to 26 loop until input it is
        // GCD number are 1,3,5,7,9,11,15,17,19,23,25,
        while((gcd(a, 26) != 1) || (a >= 26))
        {
            printf("Invalid value of a. Enter a one value that is relatively prime to 26: ");
            scanf("%d", &a);
        }

        printf("Enter key 2 (0 < 25): : ");
        scanf("%d", &b);

        // Letting the user Choose if they want to decrypt or encrypt
        // If 1 Entered Encryption 
        // If 2 Entered Decrypt
        while((option != 1) && (option != 2))
        {
        
            printf("Enter 1 to encrypt or 2 to decrypt: ");
            scanf("%d", &option);

            if (option == 1)
                    affineEncrypt(plaintext, a, b);
                else if (option == 2)
                    affineDecrypt(plaintext, a, b);
                else
                    printf("Invalid input\n");
        
        }

        printf("Result: %s\n", plaintext);
        
            break;
    

/*------------------------------------Brute Force------------------------------------------------*/

    case 2: 
        
        printf("Enter the text to decrypted: ");
        scanf("%s", &plaintext);

        for (int i = 1; i < strlen(plaintext); i++) 
        {
            plaintext[i] = toupper(plaintext[i]);

        }

        // Looping though the keys for brutefroce
        for(a = 1; a < 26; a++)
            {
                // Checking keys so only those that are relatively prime to 26
                if (gcd(a, 26) == 1)   
                {
                    for(b= 0; b < 26; ++b)
                    {
                            // Calls function
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

// Function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b==0){ // checking if the second input is equal to zero
        return a;
    }
    else {
        return gcd(b, a % b); // return a in which the gcd is stored 
    }
}

// Function to calculate the modular multiplicative inverse 
int modInv(int a, int m)
{
int x, y;
for (int i = 1; i < m; i++)
{
if ((a * i) % m == 1)
{
return i;
}
}
return -1;
}
    

// Function to remove numbers and symbols from string
char removeNonLetters(char *plaintext)
{
    int j, i;

    for (i = 0, j = 0; plaintext[i] != '\0'; i++)
     {
        if (!isspace(plaintext[i]) && !isalpha(plaintext[i]))
        {
            continue;   
        }
        plaintext[j++] = plaintext[i];
    }
    plaintext[j] = '\0';
    
}

// Function to implement the Brute Force
void affineBruteFroce(char *plaintext, int a, int b)
{
    int i, modInvCheck, decryt, lengh;
    lengh = strlen(plaintext);

    char character, text[lengh];

    // Check to to see if CoefficientOne is inverted
    modInvCheck = modInv(a, 26);
        if(modInvCheck == 0)
        {
            return;
        }


    // Replace each letter with the corresponding letter
    // decrypted using the affine cipher
    for (i = 0; i < strlen(plaintext); i++)
    {
        // Stores a letter from the cipher text in character
        // The decrypts the text with the keys
        character = plaintext[i];
        decryt = (modInvCheck * (character - 'A' - b)) % 26;

        // If number is less then 0 add 26 to get a number that is in the alphabet 
        if(decryt < 0)
            decryt += 26;

        // Add A for the ASCCI conversion  
        text[i] = 'A' + decryt;
    }

    text[lengh] = '\0';

    printf("Keys: a = %d, b = %d \tDecryption: %s\n", a, b, text);
}

// Function to implement the affine cipher for encryption
void affineEncrypt(char *plaintext, int a, int b)
{
    for (int i = 0; i < strlen(plaintext); i++)
        {
            plaintext[i] = (the logic) % 26 + 'A';
        }
}

// Function to implement the affine cipher for decryption
void affineDecrypt(char *plaintext, int a, int b)
{
    plaintext[i] = (modInv(plaintext[i] - 'A') % 26 +'A';
    decryt = (modInvCheck * (character - 'A' - b)) % 26;

}
