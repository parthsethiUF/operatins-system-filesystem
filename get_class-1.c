#include <lib.h>      // provides _syscall and message
#include <unistd.h>   // provides function prototype 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
int get_class(FILE* fd) {
	message m;
	int f;
	if(fd)
	f = fileno(fd);
	else{
		errno = -1;
		return -1;
	}
	m.m1_i1 = f;
	//printf("\nfd in get_class=%d\n",f);
	m.m1_i3 = 1;

        return _syscall(VFS_PROC_NR, CLASS, &m);
}


 