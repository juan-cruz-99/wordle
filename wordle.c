#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char word[6];
    char secret[6] = "cupon";
    int nextGame;

    do
    {
        printf("Ingrese una palabra de 5 letras\n");
        scanf("%s", word);

        if (strcmp(secret, word) == 0)
        {

            printf("Ganaste. %s es la palabra correcta \n", word);
        }
        else
        {
            printf("Palabra ingresada %s, palabra correcta %s \n", word, secret);
        };

        printf("Para seguir jugando precione un numero distinto de 0 \n");
        scanf("%i", &nextGame);

    } while (nextGame != 0);
}