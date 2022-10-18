#include<stdio.h>
#include<stdarg.h>
/**
*
*
*
*/
void _printf(char *,...); //the printf function

char* convert(unsigned int, int); //Convert integer number into octal, hex, etc.

int main()
{
	_printf(" Lets see how it goes:\n %d", 7);
	return 0;
}

void _printf(char* format,...)
{
	//First part:These are Initializing _printf's arguments
	char *coding;
	unsigned int i;
	char *s;

	va_list arg;

	va_start(arg, format);

	for(coding = format; *coding != '\0'; coding++)
{
	while( *coding != '%' )
{
	putchar(*coding);
	coding++;
}
	coding++;

	//Second part: Fetching and executing arguments
	switch(*coding)
{
	case 'c' : i = va_arg(arg,int); //Fetch char argument
	putchar(i);
	break;
	
	case 'd' : i = va_arg(arg,int); //Fetch Decimal/Integer argument
	
	if(i<0)
{
	i = -i;
	putchar('-');
}

	puts(convert(i,10));
	break;
	
	case 'o': i = va_arg(arg,unsigned int); //Fetch Octalrepresentation
	puts(convert(i,8));
	break;
	
	case 's': s = va_arg(arg,char *); //Fetch string
	puts(s);
	break;
	
	case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
	puts(convert(i,16));
	break;
}
}

	//Third part: Closing argument list to necessary clean-up
	va_end(arg);
}
	char *convert(unsigned int num, int base)

{
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50];
	char *ptr;
	ptr = &buffer[49];
	*ptr = '\0';
	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	}

		while(num != 0);
		return(ptr);
} 
