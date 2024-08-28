/*

  Harjoitus 2

  Optimoi näyttömuistin käsittely ("scrollaus"). Älä muuta kääntäjäoptioita.
  Älä käytä valmiita kirjastofunktiota tai assembleria. Pidä ohjelma
  yksisäikeisenä.

  Vertaa alkuperäistä ja optimoitua versiota:

  - kuinka paljon enemmän muistia optimoitu versio kuluttaa?
  - kuinka paljon nopeammin optimoitu versio toimii?

  Käännös: gcc scroll.c -o scroll

*/

#include <stdio.h>
#include <time.h>
#include <string.h>  // Sisältää memmove-funktion

#define ITERATIONS 10000000
#define ROWS 25
#define COLS 40
char screen_mem[ROWS][COLS];

inline void scroll_up();

int main()
{
    clock_t t1, t2;
    int i;

    t1 = clock();
    for (i = 0; i < ITERATIONS; ++i)
    {
        scroll_up();
    }
    t2 = clock();
    printf("%.1fs\n", (t2 - t1) / (float)CLOCKS_PER_SEC);

    return 0;
}


inline void scroll_up()
{
    
    memmove(screen_mem[0], screen_mem[1], (ROWS - 1) * COLS);
}