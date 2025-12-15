#include <stdio.h>
#include "ft_printf.h"

#define FUNC int (*f)(const char *str, ...)
void printtest(int *counter, char *str, FUNC)
{
	(*counter)++;
	f("___________________________________________________________________\n");
	f("Test %d - %s\n", *counter, str == NULL ? "" : str);
	f("-------------------------------------------------------------------\n");
}

void base(FUNC, int *counter)
{
	printtest(counter, NULL, f);
	f("\t===============\n");
	f("\t=   default   =\n");
	f("\t===============\n");
}


void mine(FUNC, int *counter)
{
	printtest(counter, NULL, f);
	f("\t===============\n");
	f("\t=     mine    =\n");
	f("\t===============\n");
}

int main()
{
	int counter1 = 0;
	int counter2 = 0;

	//printf("Pointer adress int\n");
	//printf("%ls\n", &a);
	int d = 96;
	long ln = 9223372036854775807;
	int chr = 300;
	char *nul = NULL;
	
	
	
	//undefined behaviour
#pragma region 	
	char *str1 ="\nString size %i\n\n";
	char *str2 ="char %c\nchar overflow val %c\nDecimal %d\nDecimal Ptr %d\nInt %i\nInt Ptr %d\nUnsigned + %u\nUnsigned - %u\nPointer at memory %p\nPointer at value %p\nhex positive %x\nhex negative %x\nhexadecimal on long %x\n";
	base(printf, &counter1);
	printf(str1,printf(str2, 
		d,		//char
		chr,	//overflow char
		d,		//Decimal
		&d,		//Decimal ptr
		d, 		//int
		&d,		//int ptr
		d,		//+ u int
		-d,		//- u int
		&d,		//ptr at memory
		d,		//ptr at value
		d,		//hex posivite
		-d,		//hex negative
		ln));	//hex on long
	mine(ft_printf,&counter2);

	ft_printf(str1,ft_printf(str2, d,chr,d, &d, d, &d, d, -d, &d, d, d, -d,ln));
#pragma endregion

#pragma region 	
	char *str3 = "\nString size of just %% %i\n\n";
	char *str4 ="%";
	base(printf, &counter1);
	printf(str3, printf(str4));
	mine(ft_printf,&counter2);

	ft_printf(str3, ft_printf(str4));
#pragma endregion

#pragma region 
	char *str5 ="\nString size of %% and more %i\n\n";
	char *str6 ="%   have more\n";
	base(printf, &counter1);
	printf(str5, printf(str6));
	mine(ft_printf,&counter2);
	ft_printf(str5, ft_printf(str6));
#pragma endregion

#pragma region 
	char *str7 ="\nString size of %% with param %i\n\n";
	char *str8 ="%    gwa have more and a valid int %d\n";
	base(printf, &counter1);
	printf(str7, printf(str8,d));
	mine(ft_printf,&counter2);
	ft_printf(str7, ft_printf(str8,d));

#pragma endregion

#pragma region 
	char *str9 ="\nString size of %% with spaces between %i\n\n";
	char *str10 ="%    i hello am i working\n";
	base(printf, &counter1);
	printf(str9, printf(str10,d));
	mine(ft_printf,&counter2);
	ft_printf(str9, ft_printf(str10,d));
#pragma endregion

#pragma region 
	char *str11 ="\nString size of %% with whitespaces between %i\n\n";
	char *str12 ="%\n   \n";
	base(printf, &counter1);
	printf(str11, printf(str12,d));
	mine(ft_printf,&counter2);
	ft_printf(str11, ft_printf(str12,d));
#pragma endregion

#pragma region 
	char *str13 ="\nString size of %% with whitespaces between  and more %i\n\n";
	char *str14 ="% \ni hello am i working\n";
	base(printf, &counter1);
	printf(str13, printf(str14,d));
	mine(ft_printf,&counter2);
	ft_printf(str13, ft_printf(str14,d));
#pragma endregion

#pragma region 
	char *str15 ="\nString size of null string %i\n\n";
	char *str16 ="%s\n";
	base(printf, &counter1);
	printf(str15, printf(str16,nul));
	mine(ft_printf,&counter2);
	ft_printf(str15, ft_printf(str16,nul));
#pragma endregion


#pragma region 
	char *str17 ="\nString size of null ptr %i\n\n";
	char *str18 ="%p\n";
	base(printf, &counter1);
	printf(str17, printf(str18,nul));
	mine(ft_printf,&counter2);
	ft_printf(str17, ft_printf(str18,nul));
#pragma endregion

#pragma region 
	char *str19 ="\nString size of null not inicialiazed ptr %i\n\n";
	char *str20 ="%p\n";
	base(printf, &counter1);
	printf(str19, printf(str20,nul));
	mine(ft_printf,&counter2);
	ft_printf(str19, ft_printf(str20,nul));
#pragma endregion

#pragma region 
	char *str21 ="\nString size of null input string %i\n\n";
	char *str22 = NULL;
	base(printf, &counter1);
	printf(str21, printf(str22,nul));
	mine(ft_printf,&counter2);
	ft_printf(str21, ft_printf(str22,nul));
#pragma endregion

#pragma region 
	char *str23 ="\nString size of %% and then null terminator %i\n\n";
	char *str24 ="\nHello %";
	base(printf, &counter1);
	printf(str23, printf(str24));
	mine(ft_printf,&counter2);
	ft_printf(str23, ft_printf(str24));

#pragma endregion
	printf("___________________________________________________________________\n");
}