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
		
	client_sockets = new int[num_client - 1];
	for(int i = 1; i < my_id; i++) {
		bzero((char *) &addr, sizeof(addr));
		fscanf(fp,"%s%d%lf",ip, &portno, &ignore);
		addr.sin_family = AF_INET;
    	addr.sin_addr.s_addr = inet_addr(ip);
    	addr.sin_port = htons(portno);		
		client_sockets[i-1] = socket(AF_INET, PROTOCOL, 0);		
		while(connect(client_sockets[i-1],(struct sockaddr *) &addr,sizeof(addr)) < 0)
			continue;
		printf("Connected with port %d\n",portno);

	}
	
	bzero((char *) &addr, sizeof(addr));
	fscanf(fp,"%s%d%lf",ip, &portno, &ignore);
	my_sock = socket(AF_INET, PROTOCOL, 0);
	
	addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(portno);
	bind(my_sock, (struct sockaddr *) &addr, sizeof(addr));

	listen(my_sock, 10);

	
	for(i = my_id + 1; i <= num_client; i++) {
		client_sockets[i - 2] = accept(my_sock,0,0);
		printf("Received connction\n");
	}	
	fflush(stdout);
	fclose(fp);
	return;

}	



void my_sleep() {
	sleep(2 + (rand() % SLEEP_TIME));
}