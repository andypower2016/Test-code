#include <stdio.h>
#include <stddef.h>

typedef void (*pfunc)(void);
typedef size_t /*int*/ addr_type;

void print_func(void)
{
	printf("print_func success\n");
}

int main()
{
	printf("sizeof size_t = %lu\n", sizeof(size_t));
	printf("sizeof int    = %lu\n", sizeof(int));
	printf("sizeof double = %lu\n", sizeof(double));
	printf("sizeof int*   = %lu\n", sizeof(int*));
	printf("sizeof (void *ptr)(void) = %lu\n", sizeof(pfunc));
	printf("\n");

	pfunc func_ptr;
	func_ptr = print_func;
	addr_type address = (addr_type) func_ptr;
	printf("address pointed by func_ptr=%p\n", func_ptr);
	printf("address = %p\n",address);

	/* will ocuur seg fault if addr_type is int (both 4byte in 32/64 bit compiler) */
	((pfunc)address)();

	return 0;
}

