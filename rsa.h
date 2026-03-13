#include <gmp.h>

#ifndef RSA_H
#define RSA_H


void compute_rsa();
void insert_primes(mpz_t p, mpz_t q);
void compute_totient(mpz_t t, mpz_t p, mpz_t q);
void compute_modulo(mpz_t N, mpz_t p, mpz_t q);
void compute_d_exponent(mpz_t d, mpz_t e, mpz_t t);
void choose_e_exponent(mpz_t e, mpz_t t);
int  verify_e_exponent();
void choose_mess(mpz_t m);
void encrypt(mpz_t m, mpz_t e, mpz_t N, mpz_t enc);
void decrypt(mpz_t enc, mpz_t d, mpz_t N, mpz_t dec);


#endif