# Printf

A simplified reimplementation of the C standard library's `printf`, focused on understanding variadic functions and format-string parsing. This version doesn't replicate the internal buffering the original `printf` uses.

## About

`ft_printf` recreates the core behavior of `printf`: reading a format string, identifying conversion specifiers, and printing the corresponding arguments — all passed through C's variadic argument mechanism (`stdarg.h`).

## Supported conversions

| Specifier | Description |
|:---:|---|
| `%d` | Signed integer |
| `%i` | Signed integer |
| `%u` | Unsigned integer |
| `%x` | Unsigned integer in lowercase hexadecimal |
| `%X` | Unsigned integer in uppercase hexadecimal |
| `%p` | Pointer address |
| `%c` | Character |
| `%s` | String |
| `%%` | A literal percent sign |

## How it works

The function scans the format string character by character. When it encounters a `%`, it looks at the next character to determine which conversion to apply. Once identified, it:

1. Retrieves the next argument from the variadic list (`va_arg`)
2. Converts that value into its string representation
3. Prints the result
4. Advances to the next argument in the list

This repeats until the end of the format string is reached. Any characters outside of a `%` conversion are printed as-is.

## Compilation

```bash
make        # compiles libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # recompiles everything from scratch
```

## Usage

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You have %d new messages.\n", "world", 5);
    return (0);
}
```

Link the library when compiling:

```bash
gcc your_program.c -I./ft_printf -L./ft_printf -lftprintf -o your_program
```
