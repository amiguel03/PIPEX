/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:07:18 by sergio            #+#    #+#             */
/*   Updated: 2024/03/04 20:42:03 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Libft es una biblioteca de funciones de C que contiene implementaciones de
// funciones de la libreria estandar de C, asi como otras funciones adicionales
// que pueden ser de utilidad. Esta biblioteca se utiliza en la mayoria de los
// proyectos de la escuela 42.

#ifndef LIBFT_H
# define LIBFT_H

// Librerias necesarias para el correcto funcionamiento de las funciones.
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define BUFFER_SIZE 32

// Estructura de lista enlazada simple para las funciones de listas.
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ft_isalpha - Comprueba si el caracter es alfabético.
int		ft_isalpha(int c);
// ft_isdigit - Comprueba si el caracter es un digito.
int		ft_isdigit(int c);
// ft_isalnum - Comprueba si el caracter es alfanumerico.
int		ft_isalnum(int c);
// ft_isascii - Comprueba si el caracter es un caracter ASCII.
int		ft_isascii(int c);
// ft_isprint - Comprueba si el caracter es imprimible.
int		ft_isprint(int c);
// ft_strlen - Calcula la longitud de una cadena.
size_t	ft_strlen(const char *str);
// ft_intlen - Calcula la longitud de un entero.
int		ft_intlen(int n);
// ft_memset - Rellena un bloque de memoria con un valor constante.
void	*ft_memset(void *str, int value, size_t len);
// ft_bzero - Rellena un bloque de memoria con ceros.
void	*ft_bzero(void *str, size_t len);
// ft_memmove - Copia len bytes de un area de memoria a otra. (overlap control)
void	*ft_memmove(void *dst, const void *src, size_t len);
// ft_memcpy - Copia len bytes de un area de memoria a otra. (!overlap control)
void	*ft_memcpy(void *dest, const void *src, size_t len);
// ft_strlcpy - Copia hasta dstsize - 1 caracteres de la cadena src a dst.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
// ft_strlcat - Concatena la cadena src a la cadena dst hasta dstsize - 1.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
// ft_toupper - Convierte un caracter a mayuscula.
int		ft_toupper(int c);
// ft_tolower - Convierte un caracter a minuscula.
int		ft_tolower(int c);
// ft_strchr - Localiza la primera aparicion de value en la cadena str.
char	*ft_strchr(const char *str, int value);
// ft_strrchr - Localiza la ultima aparicion de value en la cadena str.
char	*ft_strrchr(const char *str, int value);
// ft_strncmp - Compara los primeros len caracteres de las cadenas str1 y str2.
int		ft_strncmp(const char *str1, const char *str2, size_t len);
// ft_memchr - Localiza la primera aparicion de value en la len de str.
void	*ft_memchr(const void *str, int value, size_t len);
// ft_memcmp - Compara los primeros len caracteres de las cadenas str1 y str2.
int		ft_memcmp(const void *str1, const void *str2, size_t len);
// ft_strnstr - Localiza la primera aparicion de needle en haystack.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
// ft_atoi - Convierte una cadena a un entero.
long	ft_atoi(const char *str);
// ft_isspace - Comprueba si el caracter es un espacio.
int		ft_isspace(int c);
// ft_calloc - Reserva memoria y la rellena con ceros.
void	*ft_calloc(size_t count, size_t size);
// ft_strdup - Duplica una cadena.
char	*ft_strdup(const char *str);
// ft_substr - Crea una subcadena a partir de otra.
char	*ft_substr(char const *str, unsigned int start, size_t len);
// ft_strjoin - Concatena dos cadenas alocando memoria para la nueva cadena.
char	*ft_strjoin(char *str1, char *str2);
// ft_strtrim - Elimina los caracteres indicados en set de los extremos de str.
char	*ft_strtrim(char const *str, char const *set);
// ft_split - Divide un string en multiples strings y los guarda en un array.
char	**ft_split(const char *str, char value);
// ft_itoa - Convierte un entero a un string de caracteres.
char	*ft_itoa(int n);
// ft_strmapi - Aplica la funcion f a cada caracter de la cadena str.
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
// ft_striteri - Aplica la funcion f a cada caracter de la cadena str.
void	ft_striteri(char *str, void (*f)(unsigned int, char*));
// ft_putchar_fd - Escribe un caracter en el descriptor de archivo fd.
void	ft_putchar_fd(char c, int fd);
// ft_putstr_fd - Escribe una cadena en el descriptor de archivo fd.
void	ft_putstr_fd(char *str, int fd);
// ft_putenendl_fd - Escribe una cadena seguida de un salto de linea en fd.
void	ft_putendl_fd(char *str, int fd);
// ft_putnbr_fd - Escribe un entero en el descriptor de archivo fd.
void	ft_putnbr_fd(long long n, int fd);
// ft_lstnew - Crea un nuevo nodo de lista.
t_list	*ft_lstnew(void *content);
// ft_lstadd_front - Añade un nuevo nodo al principio de la lista.
void	ft_lstadd_front(t_list **lst, t_list *new);
// ft_lstadd_back - Añade un nuevo nodo al final de la lista.
void	ft_lstadd_back(t_list **lst, t_list *new);
// ft_lstsize - Cuenta el numero de nodos de la lista.
int		ft_lstsize(t_list *lst);
// ft_lstlast - Devuelve el ultimo nodo de la lista.
t_list	*ft_lstlast(t_list *lst);
// ft_lstclear - Borra y libera la memoria de un nodo.
void	ft_lstdelone(t_list *lst, void (*del)(void*));
// ft_lstclear - Borra y libera la memoria de todos los nodos de la lista.
void	ft_lstclear(t_list **lst, void (*del)(void*));
// ft_lstiter - Itera sobre los nodos de la lista y aplica la funcion f.
void	ft_lstiter(t_list *lst, void (*f)(void *));
// ft_lstmap - Itera sobre los nodos aplicando una funcion. Crea una nueva lista
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// ft_printf - Imprime en la salida estandar segun el formato especificado.
int		ft_printf(char const *str, ...);
// ft_gnl - Lee una linea de un archivo hasta encontrar un salto de linea o EOF.
char	*ft_gnl(int fd);

#endif