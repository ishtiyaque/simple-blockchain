#include "utils.h"

void init(const char * filename) {
	FILE *fp;
	char ip[16];
	int i, portno, my_sock;
	double ignore;
	
	struct sockaddr_in addr;
	
	srand (time(NULL));

	if(!(fp = fopen(filename, "r"))) {
		printf("config.txt NOT FOUND\n");
		exit(1);
	}
	fscanf(fp,"%d",&num_client);
	
	client_list = new unsigned int[num_client + 1];
	
	timetable = new unsigned int *[num_client + 1]; //Using 1 based indexing
	for(int i = 1; i <= num_client;i++) {
		timetable[i] = new unsigned int[num_client + 1];
	}
	//bzero((char *) timetable, sizeof(unsigned int)*(num_client + 1) * (num_client + 1));
		
	client_sockets = new int[num_client + 1];
	init_balance = new double[num_client + 1];
	
	for(int i = 1; i < my_id; i++) {
		client_list[i] = i;
		bzero((char *) &addr, sizeof(addr));
		fscanf(fp,"%s%d%lf",ip, &portno, &init_balance[i]);
		addr.sin_family = AF_INET;
    	addr.sin_addr.s_addr = inet_addr(ip);
    	addr.sin_port = htons(portno);		
		client_sockets[i] = socket(AF_INET, PROTOCOL, 0);		
		while(connect(client_sockets[i],(struct sockaddr *) &addr,sizeof(addr)) < 0)
			continue;
		//printf("Connected with port %d\n",portno);

	}
	
	client_list[my_id] = my_id;
	bzero((char *) &addr, sizeof(addr));
	fscanf(fp,"%s%d%lf",ip, &portno, &init_balance[my_id]);
	my_sock = socket(AF_INET, PROTOCOL, 0);
	
	addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(portno);
	bind(my_sock, (struct sockaddr *) &addr, sizeof(addr));
	
	for(i = my_id + 1; i <= num_client; i++) {
		fscanf(fp,"%s%d%lf",ip, &portno, &init_balance[i]);
	}	

	listen(my_sock, 10);

	
	for(i = my_id + 1; i <= num_client; i++) {
		client_list[i] = i;
		client_sockets[i] = accept(my_sock,0,0);
		//printf("Received connction\n");
	}	
	fflush(stdout);
	fclose(fp);
	return;

}	

void print_time_table() {
	for(int i = 1; i <= num_client;i++) {
		for(int j = 1; j <= num_client; j++) {
			printf("%d\t",timetable[i][j]);
		}
		printf("\n");
	}
}

void my_sleep() {
	sleep(2 + (rand() % SLEEP_TIME));
}