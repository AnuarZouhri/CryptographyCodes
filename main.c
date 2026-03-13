#include <stdio.h>
#include <gmp.h>
#include "rsa.h"


int main() {

    int choice;

    do{

        printf("What do you want to do:?");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 5:
            compute_rsa();
            break;
        
        default:
            break;
        }
    }while(choice != 0);


    return 0;
} 
