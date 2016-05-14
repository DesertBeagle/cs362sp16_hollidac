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

unittestresults.out:
	make unittest1 
	./unittest1 >> unittestresults.out
	echo "GCOV AFTER 1 TEST" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #test 1
	make clean
	make unittest2 
	./unittest2 >> unittestresults.out
	echo "GCOV AFTER 2 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #test 2
	make clean
	make unittest3 
	./unittest3 >> unittestresults.out
	echo "GCOV AFTER 3 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #test 3
	make clean
	make unittest4 
	./unittest4 >> unittestresults.out
	echo "GCOV AFTER 4 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #test 4
	make clean
	make cardtest1 
	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER 5 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #card 1
	make clean
	make cardtest2 
	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER 6 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #card 2
	make clean
	make cardtest3 
	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER 7 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #card 3
	make clean
	make cardtest4 
	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER 7 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #card 4
	make clean
	make playdom
	./playdom 3 >> unittestresults.out
	echo "GCOV AFTER 1 PLAY" >> unittestresults.out
	gcov dominion.c >> unittestresults.out #game
	make clean

randomtestadventurer:
	gcc -o randomtestadventurer randomtestadventurer.c dominion.c rngs.c interface.c $(CFLAGS)

randomtestcard1:
	gcc -o randomtestcard1 randomtestcard1.c dominion.c rngs.c interface.c $(CFLAGS)

randomtestcard2:
	gcc -o randomtestcard2 randomtestcard2.c dominion.c rngs.c interface.c $(CFLAGS)

randomtestadventurer.out:
	make randomtestadventurer
	./randomtestadventurer 42 >> randomtestadventurer.out
	echo "GCOV AFTER 1 TEST" >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out #test 1
randomtestcard1.out:
	make randomtestcard1
	./randomtestcard1 42 >> randomtestcard1.out
	echo "GCOV AFTER 1 TEST" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out #test 1
randomtestcard2.out:
	make randomtestcard2
	./randomtestcard2 42 >> randomtestcard2.out
	echo "GCOV AFTER 1 TEST" >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out #test 1

clean:
	rm -f *.o randomtestadventurer randomtestcard1 randomtestcard2 playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcda *.gcno *.so *.a *.dSYM
