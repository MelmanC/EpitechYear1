/*
** EPITECH PROJECT, 2023
** Epitech
** File description:
** printf.h
*/

#include <stdarg.h>

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

int my_printf(const char *format, ...);
void charac(va_list list);
void string(va_list list);
void purcent(void);
void ptr(va_list list);
void tfloat(va_list list, int numbers);
void scient(va_list list, int numbers);
//**Modified lib**
long long my_put_hexa(unsigned long long nb);
long my_put_hexas(unsigned short nb);
long long my_put_hexa_maj(unsigned long long nb);
long my_put_hexa_majs(unsigned short nb);
unsigned char my_put_hexamajus(unsigned char nb);
long long my_put_octa(unsigned long long nb);
long my_put_octas(unsigned short nb);
unsigned char my_put_octauc(unsigned char nb);
int my_put_ptr(unsigned long nb);
void my_put_float(double nb, int numbers);
void my_put_scient(double nb, int numbers);
//end
//**function_length**
void length_l(va_list list, char c);
void length_ll(va_list list, char c);
void length_h(va_list list, char c);
void length_hh(va_list list, char c);
//end
//**functions d**
void dint(va_list list);
void long_dint(va_list list);
void long_long_dint(va_list list);
void short_dint(va_list list);
void char_dint(va_list list);
//end
//**functions o**
void octa(va_list list);
void long_octa(va_list list);
void long_long_octa(va_list list);
void short_octa(va_list list);
void char_octa(va_list list);
//end
//**functions u**
void udint(va_list list);
void long_udint(va_list list);
void long_long_udint(va_list list);
void short_udint(va_list list);
void char_udint(va_list list);
//end
//**functions x**
void hexa(va_list list);
void long_hexa(va_list list);
void long_long_hexa(va_list list);
void short_hexa(va_list list);
void char_hexa(va_list list);
//end
//**functions X**
void hexa_maj(va_list list);
void long_hexa_maj(va_list list);
void long_long_hexa_maj(va_list list);
void short_hexa_maj(va_list list);
void char_hexa_maj(va_list list);
//end

#endif /* MY_PRINTF_H */
