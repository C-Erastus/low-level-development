#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_SET_MSG _IOR('k', 1, char *)

int main()
{
	int fd; 
	char message[] = "New message from user space";

	fd = open("/dev/ioctl_example", O_RDWR);
}
