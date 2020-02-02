CXX = g++
LIBS = -lpthread

client.out : block.o blockchain.o block_handler.o client_receiver.o dispatcher.o main.o message.o sync_queue.o utils.o
	$(CXX) -o client.out *.o $(LIBS)

sync_queue.o: sync_queue.h
%.o: %.h %.cpp

.PHONY: clean
clean:
	rm -f client.out *.o