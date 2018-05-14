CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtest: randomtestcard1 randomtestcard2 randomtestadventurer
	./randomtestcard1 > ./randomtestcard1.out
	./randomtestcard2 > randomtestcard2.out
	./randomtestadventurer > randomtestadventurer.out
	gcov ./dominion.gcno >> ./randomtestcard1.out
	gcov ./dominion.gcno >> ./randomtestcard2.out
	gcov ./dominion.gcno >> ./randomtestadventurer.out

    # make randomtestcard1
	# ./randomtestcard1 > randomtestcard1.out
	# gcov -abcfu dominion.c >> randomtestcard1.out

	# make randomtestcard2
	# ./randomtestcard2 > randomtestcard2.out
	# gcov -abcfu dominion.c >> randomtestcard2.out

	# make randomtestadventurer
	# ./randomtestadventurer > randomtestadventurer.out
	# gcov -abcfu dominion.c >> randomtestadventurer.out




test_utils.o: test_utils.c
	gcc -o test_utils.o -c test_utils.c

# randomtestadventurer: randomtestadventurer.c dominion.c rngs.o
# 	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.o test_utils.o dominion.o rngs.o
	gcc -o randomtestadventurer $(CFLAGS) randomtestadventurer.o\
                                              test_utils.o dominion.o rngs.o

randomtestcard1: randomtestcard1.o test_utils.o dominion.o rngs.o
	gcc -o randomtestcard1 $(CFLAGS) randomtestcard1.o\
                                              test_utils.o dominion.o rngs.o

randomtestcard2: randomtestcard2.o test_utils.o dominion.o rngs.o
	gcc -o randomtestcard2 $(CFLAGS) randomtestcard2.o\
                                              test_utils.o dominion.o rngs.o

randomtestadventurer.o: randomtestadventurer.c
	gcc -o randomtestadventurer.o -c randomtestadventurer.c

randomtestcard1.o: randomtestcard1.c
	gcc -o randomtestcard1.o -c randomtestcard1.c

randomtestcard2.o: randomtestcard2.c
	gcc -o randomtestcard2.o -c randomtestcard2.c

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f ./*.o ./*.exe ./*.gcov ./*.gcda ./*.gcno ./*.so ./*.out\
        ./playdom ./player ./testDrawCard ./testBuyCard ./badTestDrawCard\
        ./randomtestcard1 ./randomtestcard2 ./randomtestadventurer	
