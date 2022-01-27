# Lecture 1 notes - C
> 📝 **Full & original version** 👉 [cs50.harvard.edu/x/2022/notes/1](https://cs50.harvard.edu/x/2022/notes/1/)
## Table of contents
- [Types, format codes, operators](#types-format-codes-operators)
- [Conditionals, Boolean expressions](#conditionals-boolean-expressions)
- [Loops, functions](#loops-functions)
- [Imprecision, overflow](#imprecision-overflow)

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
  - `%li` for long integers
  - `%s` for strings
- There are several mathematical **operators** we can use:
  - `+` addition
  - `-` subtraction
  - `*` multiplication
  - `/` division
  - `%` modulo

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
- **`while`** loop
    ```c
    counter = 0;
    while (counter < 3)
    {
        printf("meow\n");
        counter += 1;
    }
    ```

- **`for`** loop
    ```python
    for (int i = 0; i<3; i++)
    {
        printf("meow\n");
    }
    ```

- A **`do while`** loop does something first, and *then* checks whether the condition is true. If the condition is still true, then it repeats itself. Here, we're declaring an integer n without specifying a value. Then, we ask the user, with `get_int`, what the value of n should be. Finally, we repeat and ask the user for another input only if `n < 1`, since we want to print at least one hash:

    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        int n;
        do
        {
            n = get_int("Width: ");
        }
        while (n < 1);

        for (int i = 0; i < n; i++)
        {
            printf("#");
        }
        printf("\n");
    }
    ```

- With **`break`**, we can break out of the while loop, which would otherwise repeat forever:
    ```c
    while (true)
    {
        int n = get_int("Number: ");
        if (n > 1)
        {
            break;
        }
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

- Defining a Function
    ```c
    return_type function_name(argument list) {
        body of the function
    }
    ```
    - For example:
    ```c
    #include <stdio.h>
    
    // function declaration
    int max(int num1, int num2);

    int main () {

    // local variable definition
    int a = 100; //CHANGE THESE
    int b = 200;
    int result;
    
    // calling a function to get max value
    result = max(a, b);
    
    printf("Max value is : %i\n", result);
    
    return 0;
    }
    
    // function returns the max between two numbers
    int max(int num1, int num2) {

    // local variable declaration
    int max_number;
    
    if (num1 > num2)
        max_number = num1;
    else {
        max_number = num2;
    }
    
    return max_number; 
    }
    ```

---

### **Imprecision, overflow**
- **`%.2f`** tells the printf method to print a floating point value with 2 decimal places
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        float x = get_float("x: ");
        float y = get_float("y: ");
        float z = x / y;

        printf("%.2f\n", z);
    }
    ```

- converting `int` to `float`
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        float x = 7.68;
        printf("float x: %.2f\n", x);

        // Explicit conversion from float to int
        int y = (int) x;

        printf("int y: %i\n", y);
    }
    ```
- Another example:
    ```c
    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {
        float amount = get_float("Dollar Amount: ");
        int pennies = amount * 100;
        printf("Pennies: %i\n", pennies);
    }
    ```
    - We'll compile and run our program:
        ```
        $ ./pennies
        Dollar Amount: .99
        Pennies: 99
        $ ./pennies
        Dollar Amount: 1.23
        Pennies: 123
        $ ./pennies
        Dollar Amount: 4.20
        Pennies: 419
        ```
- It turns out that there's imprecision in storing the `float` we get from the user (`4.20` might be stored as `4.199999...`), and so when we multiply it and display it as an integer, we see `419`. We can try to solve this by rounding:

    ```c
    #include <cs50.h>
    #include <math.h>
    #include <stdio.h>

    int main(void)
    {
        float amount = get_float("Dollar Amount: ");
        int pennies = round(amount * 100);
        printf("Pennies: %i\n", pennies);
    }
    ```

    - **`math.h`** is another library that allows us to `round` numbers.

