#include <stdio.h>
#include <math.h>

typedef struct IntErr {
    int _;
    int err;
} IntErr;

IntErr f(int x, int a, int b, int c){
    if ( x + a < 0 && c == 0) {
        return 
        (IntErr){
            (c / ( a * x )) - b,
            0
        };
    } else if (x + a > 0 && c != 0) {
        const int d = c * sin(x);
        if (d == 0) {
            return (IntErr){-1, -1};
        }
        return (IntErr){
            (x - a) / d,
            0
        };
    }
    return (IntErr){
        ( 10 * x ) / 6,
        0
    };
}

int main(void) {
    int x = 0, a = 0, b = 0, c = 0;

    

    printf("X: ");
    scanf("%d", &x);
    printf("A: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);
    printf("C: ");
    scanf("%d", &c);
    const IntErr result = f(x, a, b, c);
    if (result.err == -1) {
        printf("Error: Division by zero\n");
        return -1;
    }
    printf("F(x) = %d\n",result._);
    

    return 0;
}