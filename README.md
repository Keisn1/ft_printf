![](cover-ft_printf-bonus.png)

<p align="center">
<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Keisn1/ft_printf?color=blueviolet" />
<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Keisn1/ft_printf?color=blue" />
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Keisn1/ft_printf?color=brightgreen" />
<img alt="GitHub Lines of Code" src="https://tokei.rs/b1/github/Keisn1/ft_printf?category=code" />
</p>

# Table of contents <span class="tag" data-tag-name="TOC_2"><span class="smallcaps">TOC\_2</span></span>

  - [What is ft\_printf](#what-is-ft_printf)
  - [Incorporating libft into
    libftprint](#incorporating-libft-into-libftprint)
      - [Building libft from Makefile in Root
        directory](#building-libft-from-makefile-in-root-directory)
      - [Incorporating newly compiled object files into
        libft.a](#incorporating-newly-compiled-object-files-into-libfta)
  - [variable argument lists](#variable-argument-lists)
      - [va\_start](#va_start)
      - [va\_arg](#va_arg)
      - [va\_end](#va_end)
  - [Format string and conversions](#format-string-and-conversions)
      - [precision](#precision)
      - [minimum field width](#minimum-field-width)
      - [conversion specifiers](#conversion-specifiers)
  - [Testing](#testing)
      - [Capturing output](#capturing-output)
      - [variadic arguments](#variadic-arguments)
  - [bonus](#bonus)
      - [flags](#flags)
      - [length modifier](#length-modifier)
      - [conversions](#conversions)

# What is ft\_printf

The **ft\_printf** project is a component of the *Core Curriculum at
42school* where students are tasked with creating their own version of
the standard library function `printf`. This project serves multiple
educational purposes:

  - It introduces students to variadic functions in C, emphasizing the
    use of [variable argument lists](#variable-argument-lists) and
    memory management.
  - Students learn how to parse strings effectively.
  - They gain insight into the inner workings of `printf`, achieving a
    deeper understanding of the function, including various flags.
  - Depending on the extent of the bonus exercises completed, students
    also learn about the conversion of different numerical types and
    their binary representation.

To succeed in this project:

  - Students must thoroughly study the `printf` man page.
  - They need to grasp the format specifier and the various applicable
    syntaxes.
  - Additionally, students receive more exposure to handling libraries
    in C. By incorporating their `libft` library, they enhance it with
    their `printf` implementation, resulting in the `libftprintf`
    library.

# Incorporating libft into libftprint

## Building libft from Makefile in Root directory

``` makefile
$(LIBFT_DIR)/libft.a:
    $(MAKE) -C libft
```

## Incorporating newly compiled object files into libft.a

``` makefile
$(NAME): $(OBJ_FILES) $(LIBFT_DIR)/libft.a
    cp $(LIBFT_DIR)/libft.a $(NAME)
    ar rc $(NAME) $(OBJ_FILES)
```

The command `ar` is used to modify the `libft.a` archive file, basically
expanding their binaries

  - `r`: This flag stands for "replace" or "insert." It adds the
    specified files (`$(OBJ_FILES)` in this case) to the archive
    (`$(NAME)`). If the files already exist within the archive, they
    will be replaced with the new versions.
  - `c`: This flag tells `ar` to "create" the archive if it doesn't
    already exist.

# variable argument lists

The `va_arg`, `va_start`, and `va_end` macros are part of the C standard
library and are used to handle functions with a variable number of
arguments. They are defined in the `<stdarg.h>` header.

``` c
void va_start(va_list ap, last);
void va_end(va_list ap);
```

## va\_start

``` c
void va_start(va_list ap, last);
```

  - Initializes a `va_list` variable for subsequent use by `va_arg` and
    `va_end`.
  - Should be called once before accessing the variable arguments.
  - `ap` is the `va_list` variable, and `last` is the last fixed
    argument before the variable arguments.

## va\_arg

``` c
type va_arg(va_list ap, type);
```

  - Retrieves the next argument in the list.
  - Should be called after `va_start` and before `va_end`.
  - `ap` is the `va_list` variable, and `type` is the type of the next
    argument.

### allowed types

1.  a type so that by adding a \* to the type, it becomes a pointer to
    that type
    
    Man page:
    
    ``` example
    The argument type is a type name specified so that the type of a pointer to an object that has the specified type can be obtained simply by adding a * to type.
    ```
    
      - need to specify the type in a way that allows `va_arg` to
        correctly calculate the memory offset for the next argument
      - this requirement needs special care when working with array and
        function types
    
    <!-- end list -->
    
    1.  arrays
        
        Wrong:
        
        ``` c
        int array[10] = va_arg(args, int[10]);
        ```
        
        correct:
        
        ``` c
        int *array = va_arg(args, int *);
        ```
    
    2.  functions
        
        wrong:
        
        ``` c
        void (func)() = va_arg(args, void());
        ```
        
        correct (not tested yet):
        
        ``` c
        void (*func)() = va_arg(args, void (*));
        ```

2.  default argument promotion and fully promoted type
    
    From the man page
    
    ``` c
    /* need a cast here since va_arg only
       takes fully promoted types */
    c = (char) va_arg(ap, int);
    ```
    
    <https://stackoverflow.com/a/1256122>
    <https://stackoverflow.com/a/1255818>
    
    In C, function arguments undergo a process known as "default
    argument promotions" when passed to a variadic function like
    `printf`.
    
    The default argument promotions ensure that arguments are compatible
    with the function's parameter types and include the following rules:
    
      - Integer promotions:
          - Types smaller than `int` (like `char` and `short`) are
            promoted to `int` or `unsigned int` if `int` can represent
            all the values of the original type.
      - Float arguments are promoted to `double` if the function
        parameter's type is `float`.
    
    If the type specified in the function call does not match the actual
    promoted type of the argument, you may need to use appropriate casts
    to correctly interpret the value retrieved using `va_arg`.
    
    ``` c
    /* need a cast here since va_arg only
       takes fully promoted types */
    c = (char) va_arg(ap, int);
    ```

## va\_end

``` c
void va_end(va_list ap);
```

  - Cleans up the `va_list` variable when done.
  - Should be called after accessing all the variable arguments.

# Format string and conversions

  - Each conversion specification is introduced by the character `%`,
    and ends with a `conversion specifier`.
  - In between there may be (in this order) zero or more flags, an
    `optional minimum field width`, an `optional precision` and an
    `optional length modifier`.

`%[$][flags][width][.precision][length modifier]conversion`

  - arguments are used in the order given
  - `*` and `conversion specifiers` ask for the next argument
  - what is probably not asked for: Explicitly specifying which argument
    to use
      - `m` denotes position in arg-list, indexed with 1…
    
      - `%m$` instead of `%`
    
      - `*m$` instead of `*`
    
      - example:
        
        ``` c
        printf("%2$*1$d", width, num);
        printf("[%2$][*m1$][conversion]", width, num);
        ```

## precision

  - `.` followed by optional decimal string
  - or by '\*'
      - means that the precision is given in the next argument
      - must by of type `int`
  - if precision given as '.', it equals to 0
  - negative precision is as if precision is omitted

## minimum field width

`%[$][flags][width][.precision][length modifier]conversion`

  - minimum number of characters to be printed for a given value
  - independent of format string -\> only effects the conversion
  - padding on left if converted value has fewer chararcters than field
    width
      - Value: | text|
  - if a conversion is wider than the field width, the field is expanded
    to contain the conversion (non-existant or too small therefore don't
    lead to truncation)
  - value can be given with `*`

### `-`: `dash`

  - negative field-width
  - A negative field width is taken as a '-' flag followed by a positive
    field width.
      - value is to be left adjusted on the field boundary

### `0`: zero-flag

  - value shall be zero padded
  - **for integer**: left with zeros rather than blanks
  - `0` and `-` than `0` is ignored
  - if precision is given than `0` flag is ignored
  - behavior undefined for other conversions

## conversion specifiers

### string conversion specifiers

  - printing with `ft_putstr_fd`
  - getting the length with `ft_strlen`

### character conversion specifiers

  - printing with `ft_putchar_fd`
  - expect that always returns 1

### integer conversions specifiers

  - default **precision** = 1
  - zero with explicit precision 0, output is empty
  - **precision**: minimum number of digits to appear

<!-- end list -->

1.  d / i
    
      - printing with `ft_putnbr_fd`
      - getting nbr of digits with `ft_num_of_digits`

2.  x / X
    
      - using `ft_unsigned_to_hex`, which sets a string to the
        hexadecimal representation of the argument
      - using `print_hex_str` to print this string
          - has an extra parameter to set if lower or upper\_case

3.  u
    
      - printing with `ft_put_unsigned_int_fd`
      - getting nbr of digits with `ft_num_of_digits_unsigned`

### pointer conversion specifiers

  - use `ft_putstr_fd` if the pointer is `NULL`
  - using `ft_ptr_to_hex`, which sets a string to the hexadecimal
    representation of the argument (a pointer in this case)
  - using `print_hex_str` to print this string

# Testing

We are dealing with two problems when testing a function like
ft\_prinft.

## Capturing output

Since we need to verify that we're printing the right thing to stdout,
we need to capture what is actually printed to stdout.

Gtest has a feature that allows us to do that. The syntax is as follows.

``` cpp
testing::internal::CaptureStdout();
ft_printf(fmt_string, args...);
std::string ftPrintfResult = testing::internal::GetCapturedStdout();
```

## variadic arguments

Variadic arguments, also known as variadic functions, are functions in C
(and other languages) that can accept a variable number of arguments.

In C, variadic functions are defined using the ellipsis (…) syntax in
the function parameter list.

Actually there is no big problem, it is just so that we are not able to
do parametrized tests easily. But the layout that I found I think is
compelling and easy enough.

``` c

template<typename... Args>
void compare_printf(const char* fmt_string, Args... args) {
    ...
}

TEST(ft_printf_test, without_arguments) {
    compare_printf("Hello", "");
    ...
}


TEST(ft_printf_test, string_conversions) {
    compare_printf("Hello %s", "World");
}
```

# bonus

## <span class="done DONE">DONE</span> flags

### <span class="done DONE">DONE</span> \#

  - "alternate form" conversion
  - 'x': to "0x" or "0X" for nonzero result
  - double: result always contains a decimal-point
  - "g": trailing zeros are not removed
  - for "m", errno contains valid error code
  - for other conversions undefined

### <span class="done DONE">DONE</span> ' ' - SPACE

  - only signed conversion (or empty string)
  - (a space) A blank should be left before a positive number (or empty
    string) produced by a signed conversion
  - This is useful for formatting purposes, to ensure that positive
    numbers align correctly with negative numbers when using a
    fixed-width format.
  - If the value is negative, the negative sign is placed before the
    number as usual

### <span class="done DONE">DONE</span> +

  - always place a sign before a number
  - placed before a number produced by a signed conversion.
  - By default, a sign is used only for negative numbers.
  - A '+' overrides a space if both are used

## length modifier

### ll

### l

### h

### <span class="done DONE">DONE</span> hh

  - integer conversion to a signed char or unsigned char

  - A following integer conversion corresponds to a signed char or
    unsigned char argument

<!-- end list -->

1.  hh what are practical implications?
    
    When using the "hh" flag in printf, the practical implications are:
    
    1.  It tells the printf function that the corresponding argument
        should be interpreted as a signed char or unsigned char. This
        can affect how the argument is formatted and displayed.
    2.  It can be useful when you want to print the value of a char
        variable as an integer value, or when you want to ensure that a
        char argument is treated correctly by printf.
    3.  It allows you to control how the argument is converted and
        displayed in the output, especially when dealing with characters
        or small integer values.

2.  give me examples that illustrate the difference in behavior and
    output
    
    ``` c
    #include <stdio.h>
    
    int main() {
        char c = 'A';
        unsigned char uc = 65;
    
        // Using %c specifier without hh flag
        printf("Character c: %c\n", c);
        printf("Character uc: %c\n", uc);
    
        // Using %c specifier with hh flag
        printf("Character c (with hh): %hhd\n", c);
        printf("Character uc (with hh): %hhu\n", uc);
    
        return 0;
    }
    ```
    
    In the code above, the first two printf statements without the "hh"
    flag will interpret both `c` and `uc` as integers and print the
    corresponding ASCII characters for their values. The second set of
    printf statements with the "hh" flag will interpret `c` as a char
    and `uc` as an unsigned char, printing their numerical values
    instead of the corresponding characters.

## conversions

### n

  - a conversion specifier
  - The number of characters written so far is stored into the integer
    pointed to by the corresponding argument
  - argument shall be an int\\\*, or variant whose size matches the
    <span class="underline">(optionally)</span> supplied integer length
    modifier
  - no argument is converted
  - behavior is undefined if conversion specification includes any
    flags, a field width or a precision

### f - float / double

`[-]ddd.ddd` : default `6`

  - rounded
  - converted to decimal notation
  - nbr of digits after decimal-point character is equal to the
    precision spec
  - precision = 0 =\> no deciaml point
  - at least one digit appears before a decimal-point
  - 
### e - exponential

`[-]d.ddde+/-dd` : default `6`

  - rounded
  - one digit before the decimal point
  - nbr of digits after decimal-point is the precision
  - no decimal-point character if precision is missing
  - exponent always contains at least 2 digits
  - if value is zero, exponent is 00

### g

  - if precision is 0, it is treated as 1
  - Style [7.3.3](#*e%20-%20exponential) is used if exponent is
      - less than `-4`
      - greater than or equal to the precision
  - trailing zeros are removed from the fractional part of the result
  - a decimal point appears only if it is followed by at least one digit
