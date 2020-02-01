CXX = g++
LIBS = -lpthread

client.out : block.o blockchain.o main.o utils.o
	$(CXX) -o client.out *.o $(LIBS)

%.o: %.cpp %.h

.PHONY: clean
clean:
	rm -f client.out *.o