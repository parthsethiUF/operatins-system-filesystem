#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <lib.h>
#include "fs.h"
#include "fproc.h"
#include <errno.h>
int do_class() {
	message m;
	int fd    = m_in.m1_i1;  // the file descriptor sent
	int value = m_in.m1_i2;   // initiation of newValue from the message m that we passed in our function call
	int i3    = m_in.m1_i3;    // extra variable used to know if function called was get_tag or set_tag as there are 2 function calls but 1 system call
  	int ui    = fp->fp_effuid; // et effective uid
	int classss;
	if(i3 == 3)
	{
    		m.m1_i1 = fd;  // set first integer of message to PID
		m.m1_i2 = value; // set second integer of message to newValue
		m.m1_i3 = 0;   // initiation of newValue from the message m that we passed in our function call 
		_taskcall(PM_PROC_NR, 69, &m);	//call settag
		//classss = do_getnode(fd,value,0);
	}
//--------------------------------------------------------------
	if (fd < 0)
		{ return -1; errno = -1;} //for error if fd is negative
	if(i3==1)//get classification
	{
		classss = do_getnode(fd,value,2); // call getnode function in read.c
		//printf("classification = %d\n",classss);		
	
	}

	else if(i3 == 0 && ui == 0)//set classification
	{
		classss = do_getnode(fd,value,1);  // call getnode function in read.c
    		if(value < 0) //error for negative value
		{
			classss = -1;	
			errno = -19;
		}
	}   

return classss;
}
