# 42 Cursus - GET_NEXT_LINE

![get_next_line_score](/get_next_line_score.png)

## Información del proyecto

### Resumen
El proyecto consiste en crear una función que sea capaz de leer líneas de texto de un `fd` (_file descriptor_).

### Parte obligatoria
Crear la función `get_next_line` según el siguiente prototipo:
```
char *get_next_line(int fd);
```
La función devuelve la línea que se acaba de leer, y devuelve `NULL` si no se ha podido realizar la lectura.
Los archivos que se entregan son:
```
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

### Restricciones
* No se permite la utilización de `libft`.
* Se prohibe la utilización de `lseek`.
* Se prohibe la utilización de variables globales.

### Parte bonus
* Consiste en desarrollar `get_next_line` con una sola variable estática y gestionar múltiples _file descriptor_ a la vez y sin perder el hilo de lectura de cada uno.
* Se entregan los siguientes ficheros:
```
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c
```

## Compilación
```
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.
```
La lectura se hace en bloques cuyo tamaño viene dado por el flag `BUFFER_SIZE`.
