/////////////////////////////////////////////////////////////////////////////
// Name:        Main.c
// Encoding:	  UTF-8
// Target       Commodore 64(C64), MOS6502 compatibles.
// Compiler:    CC65
// Purpose:     My first CC65 program! A learning ground for getting acustomed
//              To the hardware and various APIs CC65 exposes.
//              Most of this is suprisingly similar to a regular C PC program.
// Author:      Erik Welander (mail@erikwelander.se)
// Modified:    2016-08-21
// Copyright:   Erik Welander
// Licence:     Creative Commons "by-nc-nd"
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>

long time_sec_count;
long time_sec_start;

void set_screen_options(void)
{
  clrscr();
  bordercolor(0);   //Black border
  bgcolor(0);       //Black background
}

void print_initial(void)
{
  char str[40] = "Screen memory and timer playground\0";
  textcolor(4);    //Violet text color
  cputsxy(20-strlen(str)/2, 8, str);
  textcolor(8);    //Orange text color
  strcpy(str, "By Erik Welander\0");
  cputsxy(20-strlen(str)/2, 14, str);
  strcpy(str, "2016-08-21\0");
  cputsxy(20-strlen(str)/2, 15, str);
  strcpy(str, "@See git.erikwelander.se\0");
  cputsxy(20-strlen(str)/2, 16, str);
  textcolor(13);  //Green text color
}

void set_time(void)
{
  char str[40] = "Set start time in seconds: \0";
  cputsxy(20-strlen(str)/2, 10, str);
  while(scanf("%d", &time_sec_count) != 1)
  {
      strcpy(str, "Invalid input!");
      cputsxy(20-strlen(str)/2, 24, str);
  }
  cputsxy(0, 10, "                                         ");  //Clear line
  cputsxy(0, 11, "                                         ");  //Clear line
  time_sec_start = time_sec_count;
}

void loop(void)
{
  int hours = (time_sec_count/3600)%24;
  int minutes = (time_sec_count/60)%60;
  int seconds = time_sec_count%60;
  int runtime = time_sec_count-time_sec_start;
  char output[20] = " ";
  char time_str[8];
  strcpy(output, "Time: ");
  sprintf(time_str, "%d", hours);
  if(strlen(time_str) < 2)
  {
      strcat(output, "0");
  }
  strcat(output, time_str);
  strcat(output, "H ");

  sprintf(time_str, "%d", minutes);
  if(strlen(time_str) < 2)
  {
      strcat(output, "0");
  }
  strcat(output, time_str);
  strcat(output, "M ");

  sprintf(time_str, "%d", seconds);
  if(strlen(time_str) < 2)
  {
      strcat(output, "0");
  }
  strcat(output, time_str);
  strcat(output, "S\0");

  cputsxy(20-strlen(output)/2, 10, output);

  sprintf(time_str, "%d", runtime);
  strcpy(output, "Runtime ");
  strcat(output, time_str);
  strcat(output, "s\0");

  cputsxy(20-strlen(output)/2, 11, output);
}

int main(void)
{
  set_screen_options();
  print_initial();
  set_time();
  while(1)
  {
      loop();
      time_sec_count++;
      sleep(1);
  }
  return EXIT_SUCCESS;
}
