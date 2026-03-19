#include <stdio.h>
#include <gmp.h>
#include "rsa.h"


int main() {

    int choice;

    do{

        printf("What do you want to do?\n");
        printf("0-Esci\n");
        printf("5-RSA cryptosystem\n");
        printf("6-Solve x^e = c mod[N]\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 5:
            compute_rsa();
            break;
        
        case 6:
            break;
        default:
            break;
        }
    }while(choice != 0);


    return 0;
} 
