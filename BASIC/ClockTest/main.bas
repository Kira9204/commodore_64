1 rem Screen memory and timer playground
2 rem By: Eril Welander
3 rem Date: 2016-08-20
6 rem Purpose:
7 rem Playground for gaining a basic understanding of screen memory
8 rem as well as string manipulation and timers.
100 rem ====Start program====
110 gosub 8000:rem Initialize variables
120 gosub 9000:rem Set screen options
130 st$="Erik Welander"
140 pokecy,14:print:pokecx,20-(len(st$)/2):print st$
150 st$="2016-08-20"
160 pokecx,20-(len(st$)/2):print st$
170 st$="@See git.erikwelander.se"
180 pokecx,20-(len(st$)/2):print st$
190 ti$="185540":rem Set internal clock
200 ts=ti
1000 rem ====Main loop====
1010 pokefc,4:rem Violet font color
1020 st$="Screen memory and timer playground"
1030 pokecy,8:print:pokecx,20-(len(st$)/2):print st$
1040 rem Set a start time and display a clock.
1041 rem The format of the time variable is HHMMSS as a single int.
1042 rem "ti"" alwars refer to the current time
1050 ct$=ti$:rem Current time string
1060 st$=mid$(ct$,1,2)+"H "
1070 st$=st$+mid$(ct$,3, 2)+"M "
1080 st$=st$+mid$(ct$,5, 2)+"S"
1090 pokefc,5:rem Green font color
1100 print:pokecx,20-(len(st$)/2):print st$
1110 st$="Powered on for: "+str$(int((ti-ts)/60))+"s"
1120 pokecx,20-(len(st$)/2):print st$
1150 goto 1000
8000 rem ====Variable declarations====
8010 bo=53280:rem Border
8020 fc=646:rem Font color
8030 cy=214:rem Cursur Y control
8040 cx=211:rem Cursur X control
8050 return
9000 rem ====Set screen options====
9010 print chr$(147):rem Clear the screen
9020 poke 53272,23 :rem Lower/Upper case mode
9030 pokebo,0:rem Black border
9040 pokebo+1,0:rem Black background
9050 pokefc,10:rem Red font color
9060 return