CFLAGS = -Wall -fpic -coverage -lm > compile 2>&1

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player

test:
	gcc -o unittest1 unittest1.c dominion.c rngs.c interface.c $(CFLAGS)
	gcc -o unittest2 unittest2.c dominion.c rngs.c interface.c $(CFLAGS)
	gcc -o unittest3 unittest3.c dominion.c rngs.c interface.c $(CFLAGS)
	gcc -o unittest4 unittest4.c dominion.c rngs.c interface.c $(CFLAGS)
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c interface.c $(CFLAGS)

results.out: unittest1 playdom
	./unittest1 >> results.out
	echo "GCOV AFTER 1 TEST" >> results.out
	gcov dominion.c >> results.out
	./playdom 3 >> results.out
	echo "GCOV AFTER 1 PLAY" >> results.out
	gcov dominion.c >> results.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
