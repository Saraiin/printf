#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/*struct*/

/**
 * struct ft - struct
 * @ft: format
 * @f: the function associated
 */
struct ft
{
	char ft;
	int (*f)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct ft ft_t - Struct op
 *
 * @ft: The format.
 * @f_t: The function associated.
 */
typedef struct ft ft_t;
/**
 *  ft_t ft_types[] = {
                {'c', pr_char}, {'s', pr_string}, {'%', pr_percent},
                {'i', pr_int}, {'d', pr_int}, {'b', pr_binary},
                {'u', pr_unsigned}, {'o', pr_octal}, {'x', pr_hexadecimal},
                {'X', pr_hexa_upper}, {'p', pr_pointer}, {'S', pr_nonprintable},
                {'r', pr_reverse}, {'R', pr_rot13string}, {'\0', NULL}
       };
*/
/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1


/****************** check ******************/
int ckprintable(char c); /*check if character is printable*/
int ckdigit(char c); /* check if character is digit*/
long int convert_nsize(long int n, int size);  /*Cast a number to the specified size*/
long int convert_unsize(unsigned long int num, int size);

int aphexa_code(char ascicode, char buffer[], int i);
/****************** gprecision ******************/
int gprecision(const char *format, int *ag, va_list list);


/****************** gsize ******************/
int gsize(const char *format, int *ag);

/****************** argprint ******************/
int argprint(const char *ft, int *id, va_list list, char buffer[],
                int flags, int width, int precision, int size);

/****************** printfunc_0 ******************/
int pr_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_int(va_list types, char buffer[], int flags,
		int width, int precision, int size);

int pr_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/****************** gflags ******************/
int gflags(const char *format, int *ag);

/****************** gwidth ******************/
int gwidth(const char *format, int *ag, va_list list);

/****************** printfunc_1******************/
int pr_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_hexa(va_list types, char ax[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

/****************** printfunc_2 ******************/
int pr_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int pr_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/****************** data_writer ******************/
int character_writer(char c, char buffer[],
	int flags, int width, int precision, int size);

int print_string(int is_negative, int id, char buffer[],
	int flags, int width, int precision, int size);

int num_write_buf(int id, char buffer[],
	int flags, int width, int prec,
	int length, char pd, char ec);

int write_un(int is_negative, int id,
	char buffer[],
	int flags, int width, int precision, int size);

int write_mem_addr(char buffer[], int id, int length,
	int width, int flags, char pd, char ec, int pd_start);

/****************** -printf ******************/


void print_buffer(char buffer[], int *buff_id);
int _printf(const char *format, ...);
#endif 
