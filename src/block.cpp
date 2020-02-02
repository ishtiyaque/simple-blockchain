#include "block.h"

Block::Block(Clientid s, Clientid r, double a, unsigned int t) {
	sndr = s;
	rcvr = r;
	amount = a;
	timestamp = t;
	prev = next = 0;
}

void Block::print() {
	printf("%d -> %d\t%lf\n",sndr, rcvr, amount);
}