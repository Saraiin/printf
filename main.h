#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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


/****************** check ******************/
int ckprintable(char c); //check if character is printable
int ckdigit(char c); // check if character is digit
long int convert_nsize(long int n, int size);  //Casts a number to the specified size
long int convert_unsize(unsigned long int num, int size);

/****************** gprecision ******************/
int gprecision(const char *format, int *ag, va_list list);


/****************** gsize ******************/
int gsize(const char *format, int *ag);

/****************** argprint ******************/
int argprint(const char *ft, int *id, va_list list, char buffer[],
                int flags, int width, int precision, int size);






int _printf(const char *format, ...);
#endif 
