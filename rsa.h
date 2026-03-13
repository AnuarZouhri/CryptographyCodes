#include <gmp.h>

#ifndef RSA_H
#define RSA_H

/**
 * @brief Runs the full RSA key generation, encryption and decryption pipeline.
 */
void compute_rsa();

/**
 * @brief Prompts the user to insert two prime numbers p and q.
 * @param p First prime number (secret).
 * @param q Second prime number (secret).
 */
void insert_primes(mpz_t p, mpz_t q);

/**
 * @brief Computes Euler's totient function: t = (p-1) * (q-1).
 * @param t Output — the totient value.
 * @param p First prime number.
 * @param q Second prime number.
 */
void compute_totient(mpz_t t, mpz_t p, mpz_t q);

/**
 * @brief Computes the RSA modulus: N = p * q.
 * @param N Output — the modulus.
 * @param p First prime number.
 * @param q Second prime number.
 */
void compute_modulo(mpz_t N, mpz_t p, mpz_t q);

/**
 * @brief Computes the private exponent d as the modular inverse of e mod t.
 * @param d Output — the private exponent.
 * @param e Public exponent.
 * @param t Euler's totient value.
 */
void compute_d_exponent(mpz_t d, mpz_t e, mpz_t t);

/**
 * @brief Prompts the user to choose a valid public exponent e,
 *        coprime with the totient t.
 * @param e Output — the public exponent.
 * @param t Euler's totient value.
 */
void choose_e_exponent(mpz_t e, mpz_t t);

/**
 * @brief Verifies whether a number is prime using a probabilistic test.
 * @param prime The number to test.
 * @return 0 if not prime, 1 if probably prime, 2 if certainly prime.
 */
int verify_prime(mpz_t prime);

/**
 * @brief Verifies whether e is a valid public exponent, i.e. gcd(e, t) == 1.
 * @param e The public exponent candidate.
 * @param t Euler's totient value.
 * @return 1 if valid (coprime), 0 otherwise.
 */
int verify_e_exponent(mpz_t e, mpz_t t);

/**
 * @brief Prompts the user to insert the message to encrypt.
 * @param m Output — the message as a big integer.
 */
void choose_mess(mpz_t m);

/**
 * @brief Encrypts a message using RSA: enc = m^e mod N.
 * @param m   Plaintext message.
 * @param e   Public exponent.
 * @param N   RSA modulus.
 * @param enc Output — the encrypted message.
 */
void encrypt(mpz_t m, mpz_t e, mpz_t N, mpz_t enc);

/**
 * @brief Decrypts a message using RSA: dec = enc^d mod N.
 * @param enc Encrypted message.
 * @param d   Private exponent.
 * @param N   RSA modulus.
 * @param dec Output — the decrypted message.
 */
void decrypt(mpz_t enc, mpz_t d, mpz_t N, mpz_t dec);

#endif