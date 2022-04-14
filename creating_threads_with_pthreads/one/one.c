#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_body (void* thread_data){
	for (int i = 0; i < 10; i++) printf("Hello, I'm process №%d\n", syscall(SYS_gettid));
	
	pthread_exit(0);
}

int main(int argc, char* argv[]){
	void* thread_data = NULL;
	pthread_t thread;

	for (int i = 0; i < atoi(argv[1]); i++){
		pthread_create(&thread, NULL, thread_body, thread_data);
	        pthread_join(thread, NULL);	
	}
	
	pthread_exit(0);
	return 0;
}
