1 rem Ladder Kattis solution
2 rem By: Eril Welander
3 rem Date: 2016-08-22
6 rem Purpose: Calculate the minimum appropriate length of a ladder
7 rem for reaching a target.
100 rem ====Start program====
110 gosub 8000:rem Initialize variables
120 gosub 9000:rem Set screen options
130 pokefc,4:rem Violet font color
140 st$="Ladder calculator"
150 pokecx,20-(len(st$)/2):print st$
155 print
160 pokefc,8:rem Orange font color
170 st$="By: Erik Welander"
180 pokecx,20-(len(st$)/2):print st$
190 st$="2016-08-22"
200 pokecx,20-(len(st$)/2):print st$
210 st$="@See git.erikwelander.se"
220 pokecx,20-(len(st$)/2):print st$
1000 rem ====Main loop====
1010 pokefc,13:rem Light green font color
1019 rem Make sure that the rows beneth us are clear
1020 pokecy,8:print:pokecx,0:printer$
1030 pokecy,9:print:pokecx,0:printer$
1040 pokecy,10:print:pokecx,0:printer$
1050 pokecy,11:print:pokecx,0:printer$
1060 pokecy,12:print:pokecx,0:printer$
1065 rem Store cursor XY pos
1066 rem All further output will start from this line
1070 st%=20-(len(st$)/2)
1080 pokecy,8:print:pokecx,st%
1090 input "Enter height H cm: ";lh:print
1100 pokecy,9:print:pokecx,st%
1110 input "Enter degrees V: ";ld:print
1120 gosub 7000:rem perform calculations
1130 st$="Minimum ladder length: "+str$(re)
1140 pokecy,10:print:pokecx,st%:print st$
1150 pokecy,12:print:pokecx,st%
1160 input "Go again? (y/n): ";a$:print
1170 if a$="y"then goto 1000
1180 print "Bye!"
1190 end
7000 rem ====Input calculations====
7009 rem Convert degrees to radians
7010 ra=ld*pi/180.0
7020 re=sin(ra)
7030 re=1/(re/lh)
7038 rem There is no Math.ceil bulilt into C64 basic :(
7039 rem We can howoer early replicate the desired behaviour easily
7040 if not re=int(re)then re=int(re)+1 
7999 return
8000 rem ====Variable declarations====
8010 bo=53280:rem Border
8020 fc=646:rem Font color
8030 cy=214:rem Cursur Y control
8040 cx=211:rem Cursur X control
8050 er$="                                       ":rem empty row 
8060 pi=3.14159265358979323846
8999 return
9000 rem ====Set screen options====
9010 print chr$(147):rem Clear the screen
9020 poke 53272,23 :rem Lower/Upper case mode
9030 pokebo,0:rem Black border
9040 pokebo+1,0:rem Black background
9050 poke19,65:rem Turn off input question mark
9999 return