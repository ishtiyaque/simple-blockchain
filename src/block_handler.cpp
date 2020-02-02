#include "block_handler.h"

void *handle_block(void *ignore) {
	
	Block *block;
	
	while(1) {
		block = block_queue.remove();
		if(block->get_timestamp() > timetable[my_id][block->get_sndr()]) {
			chain.append(block);
			timetable[my_id][block->get_sndr()] = block->get_timestamp();
		} else {
			delete block;
		}
	}

}