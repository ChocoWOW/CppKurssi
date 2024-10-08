
#include <stdio.h>
#include <time.h>
#include <math.h>

#define DEG_TO_RAD(A) (A / 57.296)
#define ITERATIONS 1000000

int main()
{
    
    clock_t t1, t2;
    unsigned i, a;
    double val;
    double sin_values[360];  
    
    for (a = 0; a < 360; ++a) {
        sin_values[a] = sin(DEG_TO_RAD(a));
    }

    t1 = clock();
    for (i = 0; i < ITERATIONS; ++i)
    {
        for (a = 0; a < 360; ++a)
        {
            
            val = sin_values[a];
        }
    }
    t2 = clock();
    printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);

    return 0;
}