#include <stdio.h>
#include <gmp.h>




int main() {
    mpz_t a, b, c;
    mpz_init(a);
    mpz_init(b);
    mpz_init(c);

    mpz_set_str(a, "123456789012345678901234567890", 10);
    mpz_set_str(b, "987654321098765432109876543210", 10);

    mpz_add(c, a, b);

    gmp_printf("The sum is: %Zd\n", c);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(c);

    return 0;
} 