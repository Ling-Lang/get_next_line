# Get Next Line (GNL)

Get Next Line (GNL) is a C function that reads a file descriptor line by line, returning each line without the newline character (`\n`). The function is useful for reading files, parsing user input, or processing network data.

## Usage

To use the Get Next Line function, include the `get_next_line.h` header file and compile the source files along with your project.

```
#include "get_next_line.h"
```

The primary function to call is `get_next_line(int fd)`:

```
char *line;
int fd = open("file.txt", O_RDONLY);

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s\n", line);
    free(line);
}

close(fd);
```

`get_next_line` returns a dynamically allocated string for each line read from the file descriptor. The user is responsible for freeing the memory allocated for each line after it's no longer needed.

## Functions

### `char *get_next_line(int fd)`

- **Parameters**: `fd` - file descriptor to read from.
- **Return value**: A pointer to a dynamically allocated string containing the next line (excluding the newline character) or `NULL` if an error occurs or the end of the file is reached.

### Auxiliary functions

- `int find_newline(char *buffer, int size)` - Finds the newline character's position in the buffer or returns -1 if not found.
- `void copy_data(char **output, char *buffer, int len)` - Copies data from the buffer to the output string and handles dynamic memory allocation.
- `void *ft_memcpy(void *dest, void *src, unsigned int n)` - Copies memory area.
- `size_t ft_strlen(const char *s)` - Computes the length of the string.
- `void *ft_memmove(void *dest, void *src, size_t len)` - Copies memory area, handling overlapping memory blocks.

## Configuration

You can set the `BUFFER_SIZE` macro in the `get_next_line.h` file to control the buffer size for reading the file descriptor. A smaller `BUFFER_SIZE` may result in more reads, while a larger one may result in fewer reads. The optimal buffer size depends on the specific use case and system resources.

```
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif
```

## Limitations

- The current implementation supports reading from a single file descriptor at a time. To read from multiple file descriptors simultaneously, you would need to modify the function or manage separate buffers for each file descriptor.
- This implementation assumes that the input file uses the newline character (`\n`) as the line delimiter. If the input file uses a different delimiter, you will need to modify the `find_newline` function accordingly.
