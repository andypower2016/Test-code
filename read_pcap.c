#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd = open("test.pcap", O_RDONLY, 0);
	if(fd == -1)
		return 0;

	int readbytes;		 // current read bytes
	int total = 0;  	 // total bytes read
	int size = 1;		 // read one byte a time
	char buffer[size+1]; // read buffer
	int count = 0;		 // count bytes
	do
	{
		readbytes = read(fd, buffer, sizeof(char)*size);
		total += readbytes;
		if(readbytes <= size && readbytes > 0)
		{
			buffer[readbytes]=0;
			printf("%02hhx",buffer[0] & 0xFF);

			lseek(fd, total, SEEK_SET);
		}
		++count;
		if(count%16 == 0)
		{
			printf("\n");
		}
		else if(count%2 == 0)
		{
			printf(" ");
		}		
	} while(readbytes != 0);
	printf("\ntotalread=%d\n", total);
	close(fd);
	return 0;
}
