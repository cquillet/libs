# libs

#### Abstract
This repo contains libraries that are necessary for :
* [`fillit`](https://github.com/cquillet/fillit)
* [`fdf`](https://github.com/cquillet/fdf)
* [`fractol`](https://github.com/cquillet/fractol)

#### Content
* includes : header files
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

    | directories           | links |
    | :-------------------: | :---------- |
    | minilibx_macos        | [man](https://github.com/cquillet/libs/blob/master/minilibx_macos/man/man3/mlx.1) |
    | minilibx_macos_sierra | [man](https://github.com/cquillet/libs/blob/master/minilibx_macos_sierra/man/man3/mlx.1) |
    | x11_minilibx          | [man](https://github.com/cquillet/libs/blob/master/x11_minilibx/man/man3/mlx.1), [wiki](https://en.wikipedia.org/wiki/Xlib) |

    Here is a [markdown-formated manpage](https://github.com/qst0/ft_libgfx/blob/master/man_mlx.md) thanks to [qst0](https://github.com/qst0) 🙏

#### Usage
Suppose you want to clone the projects in a directory named `dir` :

* `dir/`
  * `fdf` -> do `make` in this directory to compile `fdf`
  * `fillit` -> do `make` in this directory to compile `fillit`
  * `fractol` -> do `make` in this directory to compile `fractol`
  * `libs` -> do `make re` in this directory to recompile `libs` if you have compilation issues with the other projects
  
Do not put `libs` in other projects' directories 
