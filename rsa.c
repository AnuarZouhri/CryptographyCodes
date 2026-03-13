#include "rsa.h"
#include <stdio.h>

void compute_rsa(){
     
    mpz_t p, q;
    mpz_t N;
    mpz_t toz;
    mpz_t e, d;
    mpz_t mess;
    mpz_t enc;
    mpz_t dec;

    mpz_init(p);
    mpz_init(q);
    mpz_init(N);
    mpz_init(toz);
    mpz_init(e);
    mpz_init(d);
    mpz_init(mess);
    mpz_init(enc);
    mpz_init(dec);


    insert_primes(p,q);
    compute_modulo(N,p,q);
    compute_totient(toz, p, q);
    choose_e_exponent(e, toz);
    compute_d_exponent(d,e,toz);
    choose_mess(mess);
    encrypt(mess, e, N, enc);
    decrypt(enc, d, N, dec);


    if (mpz_cmp(mess, dec) == 0) printf("Lo scambio ha avuto successo\n");



    mpz_clear(p);
    mpz_clear(q);
    mpz_clear(N);
    mpz_clear(toz);
    mpz_clear(e);
    mpz_clear(d);
    mpz_clear(mess);
    mpz_clear(enc);
    mpz_clear(dec);



}


void insert_primes(mpz_t p, mpz_t q){

    printf("Choose the first secret exponent (p). Insert a prime number:");
    gmp_scanf("%Zd", p);
    
    printf("Choose the first secret exponent (q). Insert a prime number:");
    gmp_scanf("%Zd", q);



    return;
}

void compute_modulo(mpz_t N, mpz_t p, mpz_t q){

    mpz_mul(N, p, q);

    gmp_printf("N is: %Zd\n", N);

    return;

}

void compute_totient(mpz_t t, mpz_t p, mpz_t q){

    mpz_t var1, var2, var3;

    mpz_init(var1);
    mpz_init(var2);


    mpz_sub_ui(var1, p, 1);
    mpz_sub_ui(var2, q, 1);

    mpz_mul(t, var1, var2);

    gmp_printf("t = : %Zd\n", t);

    mpz_clear(var1);
    mpz_clear(var2);

    return;

}

void choose_e_exponent(mpz_t e, mpz_t t){

    printf("Choose the public exponent (e). Insert a coprime number with phi(N):");
    gmp_scanf("%Zd", e);
}


void compute_d_exponent(mpz_t d, mpz_t e, mpz_t t){

    mpz_invert(d,e,t);

    
    gmp_printf("d = : %Zd\n", d);


}

void choose_mess(mpz_t m){

    printf("Choose the message to send (m): ");
    gmp_scanf("%Zd", m);

}

void encrypt(mpz_t m, mpz_t e, mpz_t N, mpz_t enc){

    mpz_powm(enc,m,e,N);


}
void decrypt(mpz_t enc, mpz_t d, mpz_t N, mpz_t dec){

    mpz_powm(dec,enc,d,N);
}