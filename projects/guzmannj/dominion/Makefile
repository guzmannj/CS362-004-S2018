# CFLAGS = -Wall -fpic -coverage -lm

# rngs.o: rngs.h rngs.c
# 	gcc -c rngs.c -g  $(CFLAGS)

# dominion.o: dominion.h dominion.c rngs.o
# 	gcc -c dominion.c -g  $(CFLAGS)

# playdom: dominion.o playdom.c
# 	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
# #To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
# testDrawCard: testDrawCard.c dominion.o rngs.o
# 	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

# badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
# 	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

# testBuyCard: testDrawCard.c dominion.o rngs.o
# 	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

# testAll: dominion.o testSuite.c
# 	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

# interface.o: interface.h interface.c
# 	gcc -c interface.c -g  $(CFLAGS)

# runtests: testDrawCard 
# 	./testDrawCard &> unittestresult.out
# 	gcov dominion.c >> unittestresult.out
# 	cat dominion.c.gcov >> unittestresult.out


# player: player.c interface.o
# 	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

# all: playdom player 

# clean:
# 	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe



# # Tests
# unittest1:
# 	gcc -std=c99 unittest1.c dominion.c rngs.c TestHelp.h -o unittest1

#*****************************************************************************







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

test_utils.o: test_utils.c
	gcc -o test_utils.o -c test_utils.c

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

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3\
       cardtest4
	./unittest1 > unittestresults.out
	./unittest2 >> unittestresults.out
	./unittest3 >> unittestresults.out
	./unittest4 >> unittestresults.out
	./cardtest1 >> unittestresults.out
	./cardtest2 >> unittestresults.out
	./cardtest3 >> unittestresults.out
	./cardtest4 >> unittestresults.out
	gcov dominion.gcno >> unittestresults.out

test_utils.o: test_utils.c
	gcc -o test_utils.o -c test_utils.c

unittest1: unittest1.o dominion.o rngs.o test_utils.o
	gcc -o unittest1 -g $(CFLAGS) test_utils.o unittest1.o dominion.o rngs.o

unittest2: unittest2.o dominion.o rngs.o test_utils.o
	gcc -o unittest2 -g $(CFLAGS) test_utils.o unittest2.o dominion.o rngs.o

unittest3: unittest3.o dominion.o rngs.o test_utils.o
	gcc -o unittest3 -g $(CFLAGS) test_utils.o unittest3.o dominion.o rngs.o

unittest4: unittest4.o dominion.o rngs.o test_utils.o
	gcc -o unittest4 -g $(CFLAGS) test_utils.o unittest4.o dominion.o rngs.o

cardtest1: cardtest1.o dominion.o rngs.o test_utils.o
	gcc -o cardtest1 -g $(CFLAGS) test_utils.o cardtest1.o dominion.o rngs.o

cardtest2: cardtest2.o dominion.o rngs.o test_utils.o
	gcc -o cardtest2 -g $(CFLAGS) test_utils.o cardtest2.o dominion.o rngs.o

cardtest3: cardtest3.o dominion.o rngs.o test_utils.o
	gcc -o cardtest3 -g $(CFLAGS) test_utils.o cardtest3.o dominion.o rngs.o

cardtest4: cardtest4.o dominion.o rngs.o test_utils.o
	gcc -o cardtest4 -g $(CFLAGS) test_utils.o cardtest4.o dominion.o rngs.o

unittest1.o: unittest1.c
	gcc -g $(CFLAGS) -c unittest1.c

unittest2.o: unittest2.c
	gcc -g $(CFLAGS) -c unittest2.c

unittest3.o: unittest3.c
	gcc -g $(CFLAGS) -c unittest3.c

unittest4.o: unittest4.c
	gcc -g $(CFLAGS) -c unittest4.c

cardtest1.o: cardtest1.c
	gcc -g $(CFLAGS) -c cardtest1.c

cardtest2.o: cardtest2.c
	gcc -g $(CFLAGS) -c cardtest2.c

cardtest3.o: cardtest3.c
	gcc -g $(CFLAGS) -c cardtest3.c

cardtest4.o: cardtest4.c
	gcc -g $(CFLAGS) -c cardtest4.c

clean:
	rm -f ./*.o ./*.exe ./*.gcov ./*.gcda ./*.gcno ./*.so ./*.out\
        ./playdom ./player ./testDrawCard ./testBuyCard ./badTestDrawCard\
	unittest[1234] cardtest[1234]\
        ./randomtestcard1 ./randomtestcard2 ./randomtestadventurer	

