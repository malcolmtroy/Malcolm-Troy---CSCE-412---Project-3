all: main.o load_balancer.o request.o webserver.o
	g++ -Wall -std=c++11 main.o load_balancer.o request.o webserver.o -o load_balancer.out

main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp

load_balancer.o: load_balancer.cpp load_balancer.h
	g++ -Wall -std=c++11 -c load_balancer.cpp

request.o: request.cpp request.h
	g++ -Wall -std=c++11 -c request.cpp

webserver.o: webserver.cpp webserver.h
	g++ -Wall -std=c++11 -c webserver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.hgch *#
	rm -f *~ *.h.gch *#

val:
	valgrind ./load_balancer.out

run:
	./load_balancer.out