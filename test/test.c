#include "../main.h"
#include "limits.h"
#include <stdio.h>

int main(void)
{
	printf("%+u %+x\n", 10 , 32);
	_printf("%9c\n", 'd');
	printf("%9c\n", 'd');
	_printf("%+d\n", INT_MIN); _printf("%+d\n", INT_MAX);
	_printf("%+ld\n", LONG_MAX);
	_printf("test %+ld\n", -2112341L);
	_printf("%+hd\n", SHRT_MAX);
	_printf("%+hd\n", SHRT_MIN);
	_printf("%+.20u\n", UINT_MAX);
	_printf("%hu\n", USHRT_MAX);
	_printf("%lu\n", ULONG_MAX);
	_printf("%lu\n", 1);
	_printf("%lx\n", ULONG_MAX);
	_printf("%lo\n", ULONG_MAX);
	printf("%o\n", UINT_MAX);
	_printf("%b\n", 0);
	printf("%d\n",printf("%"));
	printf("%d\n", _printf("%"));
	printf("%d\n",printf("%s %c %+d %#x %#X %+i %#o\n", "mic", 'c', 100, 100, 100, 100, 100));	

	_printf("%d\n",_printf("%s %c %+d %#x %#X %+i %#o\n", "mic", 'c', 100, 100, 100, 100, 100));	
	printf("%d\n", printf("%-15.5s", "ttttttttt"));
	_printf("%d\n", _printf("%-15.5s", "ttttttttt"));
	_printf("%#p\n", 0);
	printf("%p\n",NULL);
	_printf("%p\n", NULL);
	printf("%p\n",(void *) 0);
	_printf("%S\n", "mic\nmic\t");


	return 0;
}
