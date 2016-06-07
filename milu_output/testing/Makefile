CFLAGS = -g -Wall -fpic -coverage -lm > compile 2>&1

testdominion: testdominion.c 
	clang -lm -o testdominion testdominion.c -g  dominion.c rngs.c interface.c $(CFLAGS)

clean:
	rm -f *.o randomtestadventurer testdominion randomtestcard1 randomtestcard2 playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcda *.gcno *.so *.a *.dSYM 
