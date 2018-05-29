# libs

This repo contains libraries that are necessary for :
* [`fillit`](https://github.com/cquillet/fillit)
* [`fdf`](https://github.com/cquillet/fdf)
* [`fractol`](https://github.com/cquillet/fractol)

#### Abstract :
* includes
* my code
  * libft : generates `libft.a`, it contains :

    | directories | description |
    | :---------: | :---------- |
    | calc        | some structures needed for calculation |
    | conv        | equivalent of some C functions in `stdlib.h` : `atoi`, `itoa`,... |
    | gnl         | get_next_line function : the equivalent of `readline` function (C) |
    | graph       | tools for graphs (in progress) |
    | is          | equivalent of C functions in `ctype.h` to test chars : `isdigit`, `isalpha`,... |
    | lifo        | tools for LIFOs (in progress) |
    | lst         | tools for lists |
    | math        | math tools (complex numbers, vectors, polynomials, quaternions) |
    | mem         | equivalent of some C functions in `string.h` concerning memory : `memcpy`, `memmove`,... |
    | put         | equivalent of some C functions in `stdio.h` to display strings : `putchar`, `putstr`,... |
    | str         | equivalent of some C functions in `string.h` to manipulate strings : `strcmp`, `strstr`, `strcat`, `strlen`,... |

  * ft_printf : generates `libftprintf.a` (a `printf` of my own)
* grahics libs **for macOS** until Sierra (10.12)
  * minilibx_macos
  * minilibx_macos_sierra
  * x11_minilibx
