/////////////////////////////////////////////////////////////////////////////
// Name:        Main.c
// Encoding:	  UTF-8
// Target       Commodore 64(C64), MOS6502 compatibles.
// Compiler:    CC65
// Purpose:     A colorful solution to the good old FizzBuzz programming test.
// Author:      Erik Welander (mail@erikwelander.se)
// Modified:    2016-08-25
// Copyright:   Erik Welander
// Licence:     Creative Commons "by-nc-nd"
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <c64.h>

void set_screen_options(void)
{
  clrscr();
  bordercolor(COLOR_BLACK);
  bgcolor(COLOR_BLACK);
  textcolor(COLOR_ORANGE);
}

void print_initial(void)
{
    char str[30] = "Fizzbuzz C64 edition\0";
    textcolor(COLOR_VIOLET);
    cputsxy(20-strlen(str)/2, 2, str);
    strcpy(str, "By Erik Welander\0");
    textcolor(COLOR_ORANGE);
    cputsxy(20-strlen(str)/2, 3, str);
    strcpy(str, "2016-08-25\0");
    cputsxy(20-strlen(str)/2, 4, str);
    strcpy(str, "@See git.erikwelander.se\0");
    cputsxy(20-strlen(str)/2, 5, str);
}

void close_program(int status)
{
  clrscr();
  print_initial();
  cputsxy(0, 15, "Bye!");
  exit(status);
}

int main(void)
{
  char str[30] = " ";
  char y_n[1] = "y";
  unsigned int loop_start = 0;
  unsigned int loop_stop = 0;
  unsigned long runtime_secs = 0;
  unsigned int runtime_secs_10 = 0;
  clock_t ct;
  set_screen_options();

  while (1)
  {
    if(y_n[0] == 'y')
    {
      clrscr();
      print_initial();
      strcpy(str, "How high shall i count?: ");
      textcolor(COLOR_GREEN);
      cputsxy(0, 14, str);
      if((scanf("%d", &loop_stop) == 1))
      {
          ct = clock();
          for(loop_start=0; loop_start <= loop_stop; loop_start++)
          {
            if(loop_start % 15 == 0)
            {
              textcolor(COLOR_VIOLET);
              printf("%s", "Fizz");
              textcolor(COLOR_GREEN);
              printf("%s\n", "Buzz");
            }
            else if(loop_start % 5 == 0)
            {
              textcolor(COLOR_VIOLET);
              printf("%s\n", "Fizz");
            }
            else if(loop_start % 3 == 0)
            {
              textcolor(COLOR_GREEN);
              printf("%s\n", "Buzz");
            }
            else
            {
              textcolor(COLOR_LIGHTBLUE);
              printf("%s%d\n", "    ",loop_start);
            }
        }
        textcolor(COLOR_GREEN);
        printf("%s\n", "");
        printf("%s\n", "Done!");
        //Calculate the time in seconds that the loop ran for
        ct = clock() - ct;
        runtime_secs   = (ct * 10) / CLK_TCK;
        runtime_secs_10 = runtime_secs % 10;
        runtime_secs  /= 10;
        printf("Execution time: %lu.%us\n", runtime_secs, runtime_secs_10);
        printf("%s", "New Fizzbuzz?: ");
        scanf("%s", &y_n);
      }
      else
      {
        close_program(EXIT_SUCCESS);
      }
    }
    else
    {
      close_program(EXIT_SUCCESS);
    }
  }
  return EXIT_SUCCESS;
}
