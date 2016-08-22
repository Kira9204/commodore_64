/////////////////////////////////////////////////////////////////////////////
// Name:        Main.c
// Encoding:	  UTF-8
// Target       Commodore 64(C64), MOS6502 compatibles.
// Compiler:    CC65
// Purpose:     Reverses the bitstram  of an integer. 11 will for example be 13.
// Author:      Erik Welander (mail@erikwelander.se)
// Modified:    2016-08-21
// Copyright:   Erik Welander
// Licence:     Creative Commons "by-nc-nd"
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void set_screen_options(void)
{
  clrscr();
  bordercolor(0);   //Black border
  bgcolor(0);       //Black background
  textcolor(8);     //Orange text color
}

void print_initial(void)
{
    char str[20] = "Number bit reverser\0";
    textcolor(4);    //Violet text color
    cputsxy(20-strlen(str)/2, 4, str);
    strcpy(str, "By Erik Welander\0");
    textcolor(8);    //Orange text color
    cputsxy(20-strlen(str)/2, 18, str);
    strcpy(str, "2016-08-21\0");
    cputsxy(20-strlen(str)/2, 19, str);
    strcpy(str, "@See git.erikwelander.se\0");
    cputsxy(20-strlen(str)/2, 20, str);
    textcolor(13);  //Green text color
}

void close_program(int status)
{
  char str[5] = "Bye!\0";
  clrscr();
  cputsxy(20-strlen(str)/2, 12, str);
  exit(status);
}


int bit_reversed(int input)
{
  int backwardBits = input;
  int forwardBits = 0;
  while(backwardBits > 0)
  {
      forwardBits <<= 1;
      forwardBits |= backwardBits &1;
      backwardBits >>= 1;
  }
  return forwardBits;
}

int main(void)
{
  char str[20] = " ";
  char num_str[10] = " ";
  int num_in = 0;
  int num_out = 0;
  set_screen_options();
  print_initial();

  while(1)
  {
    cputsxy(0, 10, "                                         ");  //Clear line
    strcpy(str, "Number to reverse: \0");
    cputsxy(20-strlen(str)/2, 10, str);
    if(scanf("%d", &num_in) == 1)
    {
      num_out = bit_reversed(num_in);
      sprintf(num_str, "%d", num_in);
      strcpy(str, num_str);
      strcat(str, " reversed is: ");
      sprintf(num_str, "%d", num_out);
      strcat(str, num_str);
      strcat(str, "\0");
      cputsxy(20-strlen(str)/2, 11, str);
    }
    else
    {
      close_program(EXIT_SUCCESS);
    }
  }
  return EXIT_SUCCESS;
}
