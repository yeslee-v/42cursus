# ft_printf 

> This project is pretty straight forward. You will recode printf. Fortunetaly
you will be able to reuse it in future projects as a legit function of your libft. You will
mainly learn how to use variadic arguments.

## Content

- The prototype of ft_printf should be `int ft_printf(const char *, ...);`

- You have to recode the libc’s **printf** function

- It must not do the buffer management like the real **printf**

- It will manage the following conversions: cspdiuxX%

  - `%c` print a single character.
    
  - `%s` print a string of characters.
    
  - `%p` The void * pointer argument is printed in hexadecimal.
    
  - `%d` print a decimal (base 10) number.
    
  - `%i` print an integer in base 10.
    
  - `%u` print an unsigned decimal (base 10) number.
    
  - `%x` print a number in hexadecimal (base 16), with lowercase.
    
  - `%X` print a number in hexadecimal (base 16), with uppercase.
    
  - `%%` print a percent sign

- It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions

- It will be compared with the real printf

- You must use the command ar to create your librairy, using the command libtool
is forbidden.

## Project Diary

https://yeslee5004.notion.site/ft_printf-d1ff619f16884531a34cd47b3b82b128
