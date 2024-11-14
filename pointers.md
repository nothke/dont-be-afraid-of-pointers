---
marp: true
class: invert
paginate: true

---

# Don't Be Afraid of Pointers

---

## Intro
- realized many people don't understand pointers
- this talk is going to have A LOT of simplifications

***

## What is memory?
- a strip of zeroes and ones
```
000000000111110101010101111111111011...
```
***

## What is memory?
- memory is split by 8 bits into bytes

```
00000000|01111101|01010101|11111111|10110111|...
```
***

## What is memory?
But, for simplicity we usually write it in hexadecimal (hex)

```
00|7D|55|FF|B7|..
```

***

## What is memory?
- Q: How many values can 1 byte have?
  - 00000000 - 11111111

***

## What is memory?
- Q: How many values can 1 byte have?
```
1B = 8b  = 256
```
- Q: And more bytes?

---

- How many values can 1, 2, 4, 8 bytes have?
```
2B = 16b = 65,536
4B = 32b = 4,294,967,296
8B = 64b = 18,446,744,073,709,551,616
```

---
<style scoped>
{
  text-align: center;
}
</style>
![alt text](content/hexedit.png)

---

Every byte in the memory, has an address

```
00 7D 55 FF B7 ..
0  1  2  3  4
```

---

- a3 - value
- 3 - adress - pointer
- __referencing__ - on which address is FF?
- __dereferencing__ - what is the value of 3?

Every value lives somewhere!


---

# C
- 1972; 52 years ago
- manual memory management
- clear what is on stack and what on heap

---

## Copying
```c
#include "stdio.h"

int main() {
    int a = 1;
    int b = a;

    a = 3;

    printf("a: %i, b: %i\n", a, b);
}
```

---

## But where do these values "live"?

---

## But where do these values "live"?
- in this case, on the stack


## Scope
```c
char a = 3;
char b = 4;

{
    char c = 5;
}

printf("%d", c); // error!
```

- we cannot get values outside of scope!

---

## in memory?
 ![alt text](content/stack_bytes.png)

---

![](content/herb.png)

---

- int has 4 bytes in C
```c
int a = 3;
int b = 4;
int c = 5;

printf("%d", c);
```

.
![alt text](content/stack_ints.png)

---

What does this all have to do with pointers??

---

## Pointers
- Pointers are values (objects) that store an address
- `int*` pointer to int

---
## Referencing and dereferencing
```c
int a = 3;

int* aPtr = &a; // Take the address of a

*bPtr = 6; // Set a new value to a through a pointer
```
- [example: ref/deref](examples\c\deref.c)

---

- Q: What is the size of pointers?

---

- Q: What is the size of pointers?
  - 32bit (4 bytes) on 32 bit systems
  - 64bit (8 bytes) on 64 bit systems

---

```c
int a = 3;
int b = 4;

int* bPtr = &b;
```

![alt text](content/pointer_to_stack.png)

---

- Pointers don't need to point to stack, but anywhere in program's memory
- stack, static, heap

---
## Stack
- pros:
  - fast allocations
  - fast access, related values are close in memory
- cons:
  - total size is limited
  - must have predictable size (at compile time)
---

![alt text](content/stack_sizes.png)

---

# Heap
- dynamic memory
- pros:
  - You can have as much memory as you want* at runtime
- cons:
  - allocations are slow
  - scattered in memory

---
# Heap in C
- allocating on the heap can be done with malloc()

```C
{
  void* myBlockOfMemory = malloc(sizeof(int));

  int* intPtr = (int*)myBlockOfMemory;

  *intPtr = 34;
}
```
- Q: what did I forget here?
---
# Heap in C
- every malloc() must also be freed
```C
{
  void* myBlockOfMemory = malloc(sizeof(int));

  int* intPtr = (int*)myBlockOfMemory;

  *intPtr = 34;

  free(intPtr);
}
```

---
![alt text](content/heap_ptr.png)

---
# C
## Heap in C
- malloc() is a syscall
- Dynamically allocated mamory must be freed!
- Dangers: 
  - use after free
  - dereferencing a null pointer
  - double free

---

# C
## Strings
- C pointers don't store the size, only the start
- Strings in C are just char* - meaning they are a simple pointer
- Strings known at compile time are stored in global memory
  - [example: string literal](examples/c/string_literal.c)
- strings end with a `\0` - null terminated
- _Danger:_ we can insert a 0, or we can overwrite a 0 at the end and continue

---

# C
## Strings
![](content/pointer-to-string.png)
- [example: overriding null terminator](examples/c/string_literal.c)


---
- Example: Linked lists
![alt text](content/linked_list.png)


```C++
typedef struct Node {
    int val;
    struct Node* next;
} node_t;

```

---
# C
Pointers to pointers
- `int**` - pointer to a pointer to an int

---
![alt text](content/five_star_programmer.png)

---
# C
## Arrays
- values are contiguous in memory
- must have known size
- do not store the size

---

```C
#include <stdio.h>
#include <stdlib.h>

int main() {
    char array[4] = {1, 2, 3, 4};

    array[0] = 13;

    printf("%d", array[0]);

    return 0;
}
```
- [example](examples/c/array.c)

---

# C
## Arrays
In C, arrays behave both like values and pointers
- sizeof(array) is the total size of array
- will get disposed at the end of the scope like any value


---

# C
## Pointer arithmetic
- incrementing and decrementing depends on the size of pointer type
- `char* charPtr; charPtr += 3;` increment by 3 bytes
- `int* intPtr; intPtr += 3;` increment by 3 * 4 bytes
  - ^ which is equivalent to `intPtr[3]` !
- Quirk: `intPtr[5]` is the same as `5[intPtr]`
  - that's because `a[n]` is nothing else than a sugar syntax to `*(a + n)`
- danger: decrementing pointers below zero will overflow

---

# C
# unions
- All members at the same location in memory
- [example](examples/c/union.c)
- quirk: allows for "type punning" - but don't do it!

---

# C++
- 1985; 39 years ago
- constructors, destructors that enable RAII
- reference types

---

# C++

Introduces reference type - `int&`
- can't be null
- can't be reassigned to
- reference with `int& aRef = a;`
- dereference with `.` instead of `->`
- is not actually an object, but an alias!
- [example](examples\cpp\pass_by_ref.cpp)

---

# C++
## RAII
- means Resource Acquisition Is Initialization
- classes have constructors and destructors
- memory can be managed by a class and hidden from the user
- [example: RAII, ctors and dtors](examples\cpp\ctordtor.cpp)
- This allows for a lot more high level abstraction than C
  - [example: std::vector](examples/cpp/vector.cpp)

---



# Garbage Collected languages
- Java, C#, Python, Go, javascript..
- user doesn't need to think about memory
- memory usage is tracked at runtime and freed automatically when not used
- GC trades runtime cost with programmer flexibility

---

# C#
- (as an example of a GC language I know)
- value and reference types
- value types:
    - simple types and structs
    - on stack (or in-place)
    - always copied
    - you cannot take references out of scopes

---

# C#
- reference types
    - class
    - memory tracked at runtime
    - usually implemented as a reference counter
    - must be created with `new`

---
```C#
class Person {
  String name;
  int age;
  int jmbg;
}

Person person = new Person();
person.name = "Nothke";
```
---
- python, everything is a reference type..?
- go - values get allocated on the heap when grabbed as a reference
- javascript - Depends on the browser, but ECMAscript defines some standards

---

# Rust
- memory tracked at compile time
- much more errors can be caught at compile time than in other languages

---
<style scoped>
{
  text-align: center;
}
</style>

# C
![w:800px](content/programer_cop.png)

---
<style scoped>
{
  text-align: center;
}
</style>

# Rust
![w:800px](content/compiler_cop.png)

---
<style scoped>
{
  text-align: center;
}
</style>

# GC
![w:800px](content/exe_cop.png) 

---

## fat / wide pointers
- hold 2 values:
    - a pointer to the start
    - and a size
- C++ - `std::span<T>`, `std::string_view<T>`
- zig - []T - slice
- rust - slices

---

## what about indexing?
- Can be used instead of pointers for arrays

---

# Functional languages?

---

# ~~Functional languages?~~
- we don't talk about them
- Why? Because they have abstracted away memory from the user

---

That's it, thanks!
- @nothke everywhere
- nothke@dmz.rs