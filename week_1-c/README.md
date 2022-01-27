# Lecture 1 notes - C
#### **Full & original version 👉** [cs50.harvard.edu/x/2022/notes/1](https://cs50.harvard.edu/x/2022/notes/1/)
## Table of contents
- [Types, format codes, operators](#types-format-codes-operators)
- [Conditionals, Boolean expressions](#conditionals-boolean-expressions)
- [Loops, functions](#loops-functions)

---

### **Types, format codes, operators**

- There are many data types we can use for our variables, which indicate to our program what type of data they represent:
  - `bool`, a Boolean expression of either `true` or `false`
  - `char`, a single character like `a` or `2`
  - `double`, a floating-point value with more digits than a float
  - `float`, a floating-point value, or real number with a decimal value
  - `int`, integers up to a certain size, or number of bits
  - `long`, integers with more bits, so they can count higher than an `int`
  - `string`, a string of characters
  - …
- CS50 Library has corresponding functions to get input of various types:
  - `get_char`
  - `get_double`
  - `get_float`
  - `get_int`
  - `get_long`
  - `get_string`
  - …
- For printf, too, there are different placeholders for each type, called format **codes**:
  - `%c` for chars
  - `%f` for floats or doubles
  - `%i` for ints
  - `%l`i for long integers
  - `%s` for strings
- There are several mathematical **operators** we can use, too:
  - `+` for addition
  - `-` for subtraction
  - `*` for multiplication
  - `/` for division
  - `%` for remainder

---

### **Conditionals, Boolean expressions**
- `if` conditon
    ```c
    if (x < y)
    {
        printf("x is less than y");
    }
    ```

- `if` and `else`
    ```c
    if (x < y)
    {
        printf("x is less than y");
    }
    else
    {
        printf("x is not less than y");
    }
    ```

- `else if`
    ```c
    if (x < y)
    {
        printf("x is less than y");
    }
    else if (x > y)
    {
        printf("x is greater than y");
    }
    else if (x == y)
    {
        printf("x is equal to y");
    }
    ```

- The `const` keyword specifies that a variable's value is constant and tells the compiler to prevent us from modifying it, and by convention the name of the variable should be in all uppercase:
  - ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        const int MINE = 2;
        int points = get_int("How many points did you lose? ");

        if (points < MINE)
        {
            printf("You lost fewer points than me.\n");
        }
        else if (points > MINE)
        {
            printf("You lost more points than me.\n");
        }
        else
        {
            printf("You lost the same number of points as me.\n");
        }
    }
    ```

---

### **Loops, functions**
- `while` loop
    ```c
    counter = 0;
    while (counter < 3)
    {
        printf("meow\n");
        counter += 1;
    }
    ```

- `for` loop
    ```python
    for (int i = 0; i<3; i++)
    {
        printf("meow\n");
    }
    ```

- Now we can start creating our own functions. We define our function with `void meow(void)`. The first `void` means that there isn't a return value for our function. The `void` within the parentheses also indicates that the function doesn't take any arguments, or inputs:
    ```c
    #include <stdio.h>

    void meow(void)
    {
        printf("meow\n");
    }

    int main(void)
    {
        for (int i = 0; i < 3; i++)
        {
            meow();
        }
    }
    ```
- The compiler reads our code from top to bottom, so it doesn't know what the meow function is. We can **declare** our function with a **prototype**, which just tells the compiler that we'll define our function later with the return type and argument type specified. And we can add an argument to our `meow` function:
    ```c
    #include <stdio.h>

    void meow(int n);

    int main(void)
    {
        meow(3);
    }

    void meow(int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("meow\n");
        }
    }
    ```
- Header files, ending in .h, include prototypes like `void meow(int n);`. Then, library files will include the actual implementation of each of those functions.

