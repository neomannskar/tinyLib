# tinyLib

tinyLib is a small C library that provides utilities to make C programming a bit more convenient, inspired by some C++ features like strings and vectors. The library includes functions for error handling, dynamic strings, and dynamic arrays (vectors).

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Error Handling](#error-handling)
- [String Utilities](#string-utilities)
- [Vector Utilities](#vector-utilities)
- [License](#license)

## Usage

Include the main header in your project to access all the functionalities of the library:

```c
#include "tinyLib.h"
```

## Error Handling

tinyLib provides simple error handling utilities with ANSI color-coded messages for warnings, errors, and assertions.

### Functions

- **`tl_warning`**: Prints a warning message.
- **`tl_error`**: Prints an error message.
- **`tl_assert`**: Checks an expression and prints an assertion message if the expression is false.

Example usage:

```c
tl_warning("This is a warning message.", "Warning details");
tl_error("This is an error message.", "Error details");
tl_assert(0, "Expression was false.", "Assertion details");
```

## String Utilities

The library offers a `String` type that provides dynamic string functionality similar to C++ strings.

### Functions

- **`tl_strinit`**: Initializes a `String` with initial content.
- **`tl_strcreate`**: Creates a new `String` and initializes it with content.
- **`tl_strcap`**: Ensures the `String` has enough capacity.
- **`tl_strlen`**: Returns the length of the `String`.
- **`tl_strapp`**: Appends content to the `String`.
- **`tl_strdrop`**: Clears the `String` content.
- **`tl_strfree`**: Frees the memory allocated for the `String`.

Example usage:

```c
String myString;
tl_strinit(&myString, "Hello, ");
tl_strapp(&myString, "World!");
printf("String length: %zu\n", tl_strlen(&myString));
tl_strfree(&myString);
```

## Vector Utilities

The library offers a `Vector` type for dynamic arrays of pointers, similar to C++ vectors.

### Functions

- **`tl_vinit`**: Initializes a `Vector`.
- **`tl_vcreate`**: Creates a new `Vector`.
- **`tl_vpush`**: Pushes an element to the `Vector`.
- **`tl_vpop`**: Pops the last element from the `Vector`.
- **`tl_vget`**: Gets an element at a specific index.
- **`tl_vdrop`**: Clears the `Vector`.
- **`tl_vfree`**: Frees the memory allocated for the `Vector`.

Example usage:

```c
Vector myVector;
tl_vinit(&myVector);
int value1 = 42, value2 = 84;
tl_vpush(&myVector, &value1);
tl_vpush(&myVector, &value2);
int *retrievedValue = (int *)tl_vget(&myVector, 0);
printf("First element: %d\n", *retrievedValue);
tl_vdrop(&myVector);
```

## License

This project is licensed under the MIT License.
