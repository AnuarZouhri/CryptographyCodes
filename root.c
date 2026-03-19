#include "rsa.h"
#include "root.h"
#include "factorization.h"
#include <stdio.h>


void root_e(){

    mpz_t N;
    mpz_t toz;
    mpz_t e, d;
    mpz_t enc;
    
    mpz_init(N);
    mpz_init(toz);
    mpz_init(e);
    mpz_init(d);
    mpz_init(enc);


    

    

    mpz_clear(N);
    mpz_clear(toz);
    mpz_clear(e);
    mpz_clear(d);

}