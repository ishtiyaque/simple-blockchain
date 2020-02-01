#include "block_handler.h"

void *handle_block(void *ignore) {
	
	Block *block;
	
	while(1) {
		block = block_queue.remove();
		chain.append(block);
	}

}