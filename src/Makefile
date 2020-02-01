CXX = g++
LIBS = -lpthread

client.out : block.o blockchain.o main.o sync_queue.o utils.o
	$(CXX) -o client.out *.o $(LIBS)

sync_queue.o: sync_queue.h
%.o: %.h %.cpp

.PHONY: clean
clean:
	rm -f client.out *.o