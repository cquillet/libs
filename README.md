# libs

This repo contains librairies that are necessary for :
* [`fillit`](https://github.com/cquillet/fillit)
* [`fdf`](https://github.com/cquillet/fdf)
* [`fractol`](https://github.com/cquillet/fractol)

#### Abstract :
* includes
* my code
  * libft : generates `libft.a`
    * calc *for some structures needed for calculation*
    * conv *equivalent of some C functions (`stdlib.h`) to convert atoi, itoa)*
    * gnl *get_next_line function : the equivalent of `readline` function (C)*
    * graph *tools for graphs (in progress)*
    * is *equivalent of C functions (`ctype.h`) to test chars : `isdigit`, `isalpha`,...*
    * lifo *tools for LIFOs*
    * lst *tools for lists*
    * math *math tools (complex numbers, vectors, polynomials, quaternions)*
    * mem *equivalent of C functions (`string.h`) to manipulates bytes : `memcpy`, `memmove`,...*
    * put *equivalent of C functions (`string.h`) to display strings : `putchar`, `putstr`,...*
    * str *equivalent of C functions (`string.h`) to manipulate strings : `strcmp`, `strstr`, `strcat`, `strlen`,...*
    * | directories | description |
      | :---------: | ----------: |
      | calc        | for some structures needed for calculation |
      | conv        | conversion function (atoi, itoa) |
      | gnl         | get_next_line function : the equivalent of `readline` function (C) |
      | graph       | tools for graphs (in progress) |
      | is          | equivalent of C functions to test chars : `isdigit`, `isalpha`,... |
      | lifo        | tools for LIFOs |
      | lst         | tools for lists |
      | math        | math tools (complex numbers, vectors, polynomials, quaternions) |
      | mem         | equivalent of C functions about memory : `memcpy`, `memmove`,... |
      | put         | equivalent of C functions to display strings : `putchar`, `putstr`,... |
      | str         | equivalent of C functions to manipulate strings : `strcmp`, `strstr`, `strcat`, `strlen`,... |

  * ft_printf : generates `libftprintf.a` (a `printf` of my own)
* grahics libs **for macOS** until Sierra (10.12)
  * minilibx_macos
  * minilibx_macos_sierra
  * x11_minilibx