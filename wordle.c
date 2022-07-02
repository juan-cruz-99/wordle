#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_RESET "\x1b[0m"
#define WRONG_WORD_POINTS -500
#define CORRECT_LETTER_POINTS 50
#define CORRECT_POSITION_POINTS 100
#define WIN_POINTS 2000
#define FIRST_TRY_WIN_POINTS 5000

void printGreen(char);
void printYelow(char);
bool hasLetter(char, char *);

void main()
{
  char secret[6] = "disco";
  int points, round;
  char correctLetters[6], correctPositions[6];
  int x, i, z, countLetters, countPositions;
  char tries[6][6];

  int nextGame;

  do
  {
    points = 5000;
    countLetters = 0;
    countPositions = 0;
    for (x = 0; x < 5; x++)
    {
      correctLetters[x] = ' ';
      correctPositions[x] = ' ';
    }
    for (x = 0; x < 6; x++)
    {
      printf("Ingrese una palabra de 5 letras\n");
      scanf("%s", tries[x]);

      if (strcmp(secret, tries[x]) == 0)
      {
        points += x == 0 ? FIRST_TRY_WIN_POINTS : WIN_POINTS;

        printf("Ganaste. %s es la palabra correcta \n", tries[x]);
        printf("Puntos: %d \n", points);

        break;
      }

      points += WRONG_WORD_POINTS;

      for (z = 0; z <= x; z++)
      {
        for (i = 0; i < 5; i++)
        {
          if (hasLetter(tries[z][i], secret))
          {
            if (tries[z][i] == secret[i])
            {
              if (!hasLetter(tries[z][i], correctPositions))
              {
                correctPositions[countPositions] = tries[z][i];
                countPositions++;
                points += CORRECT_POSITION_POINTS;
              }
              printGreen(tries[z][i]);
            }
            else
            {
              if (!hasLetter(tries[z][i], correctLetters) && !hasLetter(tries[z][i], correctPositions))
              {
                correctLetters[countLetters] = tries[z][i];
                countLetters++;
                points += CORRECT_LETTER_POINTS;
              }
              printYelow(tries[z][i]);
            }
          }
          else
          {
            printf("%c", tries[z][i]);
          }
        }

        printf("\n");
        printf("----- \n");
      };
      if (x == 5)
      {
        printf("Perdiste. La palabra correcta era %s \n", secret);
        printf("Puntos: 0 \n");
      }
    }

    printf("Para seguir jugando precione un numero distinto de 0 \n");
    scanf("%i", &nextGame);

  } while (nextGame != 0);
}

bool hasLetter(char leter, char word[])
{
  int i;
  size_t size = sizeof &word / sizeof word[0];
  for (i = 0; i < size; i++)
  {
    if (leter == word[i])
    {
      return true;
    }
  }
  return false;
}

void printGreen(char letter)
{
  printf(COLOR_GREEN "%c", letter);
  printf(COLOR_RESET);
}
void printYelow(char letter)
{
  printf(COLOR_YELLOW "%c", letter);
  printf(COLOR_RESET);
}