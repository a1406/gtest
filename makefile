all: gtest

clean:
	rm -rf *.a *.o


gtest: gtest-all.o
	ar -rv libgtest.a gtest-all.o

gtest-all.o: src/gtest-all.cc
	g++ -isystem ./include -I.   -pthread -c ./src/gtest-all.cc

