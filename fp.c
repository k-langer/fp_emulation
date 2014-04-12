#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int fraction:23;
    unsigned int exp:8;
    unsigned int sign:1; 
} fp_32; 
fp_32 add(fp_32 a, fp_32 b); 
fp_32 mul(fp_32 a, fp_32 b); 

int main(int argc, char * argv[]) {
    float i; 
    if (argc > 1) {
        i = atof(argv[1]);
    } else {
        return 0;
    }
    fp_32 *d = (fp_32*) &i;
    printf("%d %d %d\n",d->sign,d->exp,d->fraction);  
    fp_32 c = mul(*d, *d); 
    printf("%d %d %d\n",c.sign,c.exp,c.fraction);  

    return 0;
}

fp_32 mul(fp_32 a, fp_32 b) {
    fp_32 c; 
    //c.sign = a.sign ^ b.sign;
    int ex  = a.exp+b.exp; 
    printf("dec %d\n",a.exp+b.exp-127);
    c.exp = a.exp;
    c.fraction = a.fraction;
    return c; 
}
