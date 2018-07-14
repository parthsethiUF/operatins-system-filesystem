#include <lib.h>      // provides _syscall and message
#include <unistd.h>   // provides function prototype 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
int set_class(FILE* fd, int newvalue) {
	if(fd){
    	message m;
	m.m1_i1 = fileno(fd);
	m.m1_i2 = newvalue; 
	m.m1_i3 = 0;
	//printf("in se class");
	return _syscall(VFS_PROC_NR, CLASS, &m);
	}
	else{
		errno = -1;
		return -1;
	}

}


 