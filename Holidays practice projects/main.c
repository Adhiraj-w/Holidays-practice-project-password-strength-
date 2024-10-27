#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkPasswordStrength(const char *password) {
    long length = strlen(password);
    int Upper = 0, Lower = 0, Digit = 0, Special = 0;

    if (length < 8) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) Upper = 1;
        else if (islower(password[i])) Lower = 1;
        
        else if (isdigit(password[i])) Digit = 1;
        
        else if (ispunct(password[i])) Special = 1;
    }

    
    if (Upper && Lower && Digit && Special) {
        return 3;
        }
    else if ((Upper || Lower) && Digit && (Special || length >= 10)) {
        return 2;
    }
    else {
        return 1;
    }
}

int main(void) {
    char password[50];
    printf("Enter your password: ");
    scanf("%49s", password);

    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 3:
            printf("Password strength: Strong\n");
            break;
            
        case 2:
            printf("Password strength: Moderate\n");
            break;
            
        case 1:
            default:
            
            printf("Password strength: Weak\n");
            break;
    }

    return 0;
}
