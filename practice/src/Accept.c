
#include "my_header.h"


J Join(struct Complex_Number cnum)
{
    J out =  c.real + c.imag*I;
    return out;
}

struct Complex_Number Split(J cnum)
{
    struct Complex_Number out;
    z.real = creal(cnum);
    z.imag = cimag(cnum);
    return out;
}

J Accept()
{
    struct Complex_Number c;
    printf("Enter real part.\n");
    scanf("%ld", &c.real);
    
    printf("Enter imaginary part.\n");
    scanf("%ld", &c.imag);

    J out = Join(c);
    c.real = 0;
    c.imag = 0;
    return out;
}
