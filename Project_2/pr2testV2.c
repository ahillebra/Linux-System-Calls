
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include "tagcalls.h"
#include <syscall.h>
#include <sched.h>

#define ARGCNT 3
#define HELPMSG "Usage: gettag <PID>\n"
#define NUMTESTS 28
	
enum TestResult{UNDEFINED,FAILURE,SUCCESS} TestResults[NUMTESTS];
	
void printresults(){
	for(int i = 0; i < NUMTESTS; i++){
		if(TestResults[i] == SUCCESS){
			printf("TEST %d : SUCCESS\n",i);
		}
		else if(TestResults[i] == FAILURE){
			printf("TEST %d : FAILURE\n",i);
		}
		else{
			printf("TEST %d : UNDEFINED\n",i);
		}
	}
}

int main(int argc, char** argv) {
	
	int result;
	
	// 0. Create sets tag to process's tag
	// 1. Errno displays no error
	// 2. FD invalid fails
	// 3. Errno displays error
	// 4. Negative classification fails
	// 5. Errno displays error
	// 6-14. Test read downs and write ups
	// 14-23. Change tag then read down and write up
	// 24-25. Get_class and set_class both work for root
	// 26-27. For user, get_class works, but set_class doesn't
	
	int currentProcessPid = getpid();
	
	

	
	
	
	set_tag(currentProcessPid,8);
	
	FILE* fd = fopen("./log/log.txt","a");
	FILE* fd1 = fopen("./log/log1.txt","a");
	FILE* fd2 = fopen("./log/log2.txt","a");
	FILE* fd3 = fopen("./log/log3.txt","a");
	FILE* fd4 = fopen("./log/log4.txt","a");
	FILE* fd5 = fopen("./log/log5.txt","a");
	
	FILE* failfd = fopen("./log/log6.txt","r");
	errno = 0;
	
	printf("errno init value: %d\n",errno);
	
	result = get_class(fd1);
	
	//1
	if(result == 8){
		TestResults[0] = SUCCESS;
	}
	else{
		TestResults[0] = FAILURE;
		//printf("NOT ==8, result value: %d\n",result);
	}
	
	//2
	if(errno != 0){
		TestResults[1] = FAILURE;
	}
	else{
		printf("NOT !=0, errno value: %d\n",errno);
		TestResults[1] = SUCCESS;
		errno = 0;
	}
	
	result = set_class(failfd,9999);
	
	//3
	if(result == -1){
		TestResults[2] = SUCCESS;
	}
	else{
		//printf("NOT ==-1, result value: %d\n",result);
		TestResults[2] = FAILURE;
	}
	
	//4
	if(errno != 0){
		TestResults[3] = SUCCESS;
		errno = 0;
	}
	else{
		printf("NOT !=0, errno value: %d\n",errno);
		TestResults[3] = FAILURE;
	}
	
	result = set_class(fd1,-99);
	
	
	//5
	if(result == -1){
		TestResults[4] = SUCCESS;
	}
	else{
		//printf("NOT ==-1, result value: %d\n",result);
		TestResults[4] = FAILURE;
	}
	
	//6
	if(errno != 0){
		TestResults[5] = SUCCESS;
		errno = 0;
	}
	else{
		printf("NOT !=0, errno value: %d\n",errno);
		TestResults[5] = FAILURE;
	}
	
	set_tag(currentProcessPid,3);
	
	set_class(fd1,1);
	set_class(fd2,2);
	set_class(fd3,3);
	set_class(fd4,4);
	set_class(fd5,5);
	
	// fclose(fd);
	// fclose(fd1);
	// fclose(fd2);
	// fclose(fd3);
	// fclose(fd4);
	// fclose(fd5);
	
	fd1 = fopen("./log/log1.txt","r");
	
	if(fd1 != NULL){
		TestResults[6] = SUCCESS;
	}
	else{
		//printf("NOT !=0, fd1 value: %d\n",fd1);
		TestResults[6] = FAILURE;
	}
	
	fd1 = fopen("./log/log1.txt","w");
	
	if(fd1 == NULL){
		TestResults[7] = SUCCESS;
	}
	else{
		//printf("NOT == NULL, fd1 value: %d\n",fd1);
		TestResults[7] = FAILURE;
	}
	
	fd1 = fopen("./log/log1.txt","w+");
	
	if(fd1 == NULL){
		TestResults[8] = SUCCESS;
	}
	else{
		//printf("NOT == NULL, fd1 value: %d\n",fd1);
		TestResults[8] = FAILURE;
	}
	
	fd3 = fopen("./log/log3.txt","r");
	
	if(fd3 != NULL){
		TestResults[9] = SUCCESS;
	}
	else{
		//printf("NOT != NULL, fd3 value: %d\n",fd3);
		TestResults[9] = FAILURE;
	}
	
	fd3 = fopen("./log/log3.txt","w");
	
	if(fd3 != NULL){
		TestResults[10] = SUCCESS;
	}
	else{
		//printf("NOT != NULL, fd3 value: %d\n",fd3);
		TestResults[10] = FAILURE;
	}
	
	fd3 = fopen("./log/log3.txt","w+");
	
	if(fd3 != NULL){
		TestResults[11] = SUCCESS;
	}
	else{
		//printf("NOT != NULL, fd3 value: %d\n",fd3);
		TestResults[11] = FAILURE;
	}
	
	fd5 = fopen("./log/log5.txt","r");
	
	if(fd5 == NULL){
		TestResults[12] = SUCCESS;
	}
	else{
		//printf("NOT == NULL, fd5 value: %d\n",fd5);
		TestResults[12] = FAILURE;
	}
	
	fd5 = fopen("./log/log5.txt","w");
	
	if(fd5 != NULL){
		TestResults[13] = SUCCESS;
	}
	else{
		//printf("NOT != NULL, fd5 value: %d\n",fd5);
		TestResults[13] = FAILURE;
	}
	
	fd5 = fopen("./log/log5.txt","w+");
	
	if(fd5 == NULL){
		TestResults[14] = SUCCESS;
	}
	else{
		//printf("NOT == NULL, fd5 value: %d\n",fd5);
		TestResults[14] = FAILURE;
	}
	
	set_tag(currentProcessPid,4);
	
	fd3 = fopen("./log/log3.txt","r");
	
	if(fd3 != NULL){
		TestResults[15] = SUCCESS;
	}
	else{
		TestResults[15] = FAILURE;
	}
	
	fd3 = fopen("./log/log3.txt","w");
	
	if(fd3 == NULL){
		TestResults[16] = SUCCESS;
	}
	else{
		TestResults[16] = FAILURE;
	}
	
	fd3 = fopen("./log/log3.txt","w+");
	
	if(fd3 == NULL){
		TestResults[17] = SUCCESS;
	}
	else{
		TestResults[17] = FAILURE;
	}
	
	
	fd4 = fopen("./log/log4.txt","r");
	
	if(fd4 != NULL){
		TestResults[18] = SUCCESS;
	}
	else{
		TestResults[18] = FAILURE;
	}
	
	fd4 = fopen("./log/log4.txt","w");
	
	if(fd4 != NULL){
		TestResults[19] = SUCCESS;
	}
	else{
		TestResults[19] = FAILURE;
	}
	
	fd4 = fopen("./log/log4.txt","w+");
	
	if(fd4 != NULL){
		TestResults[20] = SUCCESS;
	}
	else{
		TestResults[20] = FAILURE;
	}
	
	fd5 = fopen("./log/log5.txt","r");
	
	if(fd5 == NULL){
		TestResults[21] = SUCCESS;
	}
	else{
		TestResults[21] = FAILURE;
	}
	
	fd5 = fopen("./log/log5.txt","w");
	
	if(fd5 != NULL){
		TestResults[22] = SUCCESS;
	}
	else{
		TestResults[22] = FAILURE;
	}
	
	fd5 = fopen("./log/log5.txt","w+");
	
	if(fd5 == NULL){
		TestResults[23] = SUCCESS;
	}
	else{
		TestResults[23] = FAILURE;
	}
	
	
	if(get_class(fd4) != -1){
		TestResults[24] = SUCCESS;
	}
	else{
		TestResults[24] = FAILURE;
	}
	
	if(set_class(fd4,99) != -1){
		TestResults[25] = SUCCESS;
	}
	else{
		TestResults[25] = FAILURE;
	}
	
	seteuid(99);
	
	if(get_class(fd4) != -1){
		TestResults[26] = SUCCESS;
	}
	else{
		TestResults[26] = FAILURE;
	}
	
	if(set_class(fd4,99) == -1){
		TestResults[27] = SUCCESS;
	}
	else{
		TestResults[27] = FAILURE;
	}
	
	
	
	printresults();
	
	return 0;
}


