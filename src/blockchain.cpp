#include "blockchain.h"
#include "globals.h"

Blockchain::Blockchain(){
	head = tail = 0;
	pthread_mutex_init(&lock, NULL);
}

bool Blockchain::append(Block *blk) {
	blk->prev = blk->next = 0;
	pthread_mutex_lock (&lock);
	if(!head) {
		head = tail = blk;
	}else {
		blk->prev = tail;
		tail->next = blk;
		tail = blk;
	}
	pthread_mutex_unlock (&lock);
	return true;
}

double Blockchain::get_balance(Clientid id) {
	double bal = 0.0;
	pthread_mutex_lock (&lock);
	for(Block *temp = tail; temp; temp = temp->prev) {
		if(temp->get_sndr() == id) {
			bal -= temp->get_amount();
		} else if(temp->get_rcvr() == id) {
			bal += temp->get_amount();
		}
	}
	pthread_mutex_unlock (&lock);
	return bal;
}

bool Blockchain::make_transaction(Clientid sndr, Clientid rcvr, double amount) {
	if(sndr && get_balance(sndr) < amount)
		return false;
	Block *blk = new Block(sndr, rcvr, amount, 0);
	return append(blk);
}

Blockchain::~Blockchain() {
	pthread_mutex_destroy(&lock);
}

void Blockchain::print() {
	pthread_mutex_lock (&lock);
	for(Block *tmp = head;tmp;tmp = tmp->next)
		printf("%d -> %d\t%lf\n",tmp->get_sndr(), tmp->get_rcvr(), tmp->get_amount());
	pthread_mutex_unlock (&lock);
}

vector<Block *> Blockchain::get_log(Clientid id) {
	vector<Block *> log;
	pthread_mutex_lock (&lock);
	for(Block * temp = head; temp; temp = temp->next) {
		if(temp->get_timestamp() > timetable[id][temp->get_sndr()]) {
			log.push_back(temp);
		}
	}
	pthread_mutex_unlock (&lock);
	return log;

}