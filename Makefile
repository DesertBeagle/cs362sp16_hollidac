CFLAGS = -g -Wall -fpic -coverage -lm > compile 2>&1

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

test: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittest1:
	gcc -o unittest1 unittest1.c dominion.c rngs.c interface.c $(CFLAGS)
unittest2:
	gcc -o unittest2 unittest2.c dominion.c rngs.c interface.c $(CFLAGS)
unittest3:
	gcc -o unittest3 unittest3.c dominion.c rngs.c interface.c $(CFLAGS)
unittest4:
	gcc -o unittest4 unittest4.c dominion.c rngs.c interface.c $(CFLAGS)
cardtest1:
	gcc -o cardtest1 cardtest1.c dominion.c rngs.c interface.c $(CFLAGS)
cardtest2:
	gcc -o cardtest2 cardtest2.c dominion.c rngs.c interface.c $(CFLAGS)
cardtest3:
	gcc -o cardtest3 cardtest3.c dominion.c rngs.c interface.c $(CFLAGS)
cardtest4:
	gcc -o cardtest4 cardtest4.c dominion.c rngs.c interface.c $(CFLAGS)

results.out: unittest1 playdom
	./unittest1 >> results.out
	echo "GCOV AFTER 1 TEST" >> results.out
	gcov dominion.c >> results.out
	./playdom 3 >> results.out
	echo "GCOV AFTER 1 PLAY" >> results.out
	gcov dominion.c >> results.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
