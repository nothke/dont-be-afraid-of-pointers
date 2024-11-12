---
@import-theme 'nothke'
marp: true
theme: nothke
---


# Don't be afraid of pointers

## Intro
- I got many questions from people about pointers. Seems like
- What is a pointer? A pointer is an adress

***

## What is memory
- a strip of zeroes and ones
```
000000000111110101010101111111111011...
```
***

- memory is split by 8 bits into bytes

```
00000000|01111101|01010101|11111111|10110111|...
```
***

But, for simplicity we usually write it in hexadecimal (hex)

```
00|7D|55|FF|B7|..
```

- How many values can 1 byte have?

```
1B = 8b  = 256
2B = 16b = 65,536
4B = 32b = 4,294,967,296
8B = 64b = 18,446,744,073,709,551,616
```

- ADD PIC OF HEX EDITOR

Every byte in the memory, has an address

```
00 7D 55 FF B7 ..
0  1  2  3  4
```

- a3 - vrednost - value
- 3 - adresa - pointer
- referenciranje - na kojoj adresi je FF?
- dereferenciranje - koja je vrednost na adresi 3?

Svaka vrednost zivi na nekoj adresi u memoriji

## Copying
- C kod
```c
int a = 1;
int c = a + b;
```

```c
int a = 1;
int b = a;
b = 3;
printf("a: %i, b: %i\n", a, b);
```

Gde zive ove vrednosti?

Programski stack

stack se uvecava, i smanjuje kako definisemo vrednosti


scope
```c
int a = 3;
int b = 4;

{
    int c = 4;
}
```

kakve ovo ima veze sa pointerima?

U C: int* pointer na int

C stringovi

What if we need more memory?

dynamic allocation - heap

malloc - syscall, OS gives us permission to allocate memory

C++

Uvodi reference type int&
- can't be null
- can't be reassigned to
- reference with int& aRef = a;
- dereference with . instead of ->
- adds a few complications - unclear
- is not actually a pointer, but an alias

Uvodi RAII

constructors and destructors

rust

Garbage collected languages Java/C#

value type i reference type
- value type se kopira, reference type se referencuje pointer (kopiramo samo pointer)

weakly typed languages - python, javascript

funkcionalni jezici - we don't talk about them