#include <stdio.h>
#include <stddef.h>

typedef void (*ptr)(void);
typedef size_t/*int*/ address_type 

int main()
{
	printf("sizeof size_t = %lu\n", sizeof(size_t));
	printf("sizeof int    = %lu\n", sizeof(int));
	printf("sizeof double = %lu\n", sizeof(double));
	printf("sizeof int*   = %lu\n", sizeof(int*));
	printf("sizeof (void *ptr)(void) = %lu\n", sizeof(ptr));
	printf("\n\n\n");

	int data = 64;
	void *pdata = (void*)& data;
	address_type address = (address_type) pdata;
	printf("address of data=%p\n", &data);
	printf("address pointed by pdata=%p\n", pdata);
	printf("address = %p\n",address);
	printf("data = %d\n",*(address_type*)(void*)address);

	return 0;
}

