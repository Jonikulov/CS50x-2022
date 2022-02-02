# Lecture 2 notes - Arrays
> 📝 **Full & original version** 👉 [cs50.harvard.edu/x/2022/notes/2](https://cs50.harvard.edu/x/2022/notes/2/)

## Table of contents
- [Compiling](#compiling)
- [Memory](#memory)
- [Strings](#strings)
- [Command-line arguments](#command-line-arguments)

---

## **Compiling**

- Compiling source code into machine code is actually made up of four smaller steps:
    - preprocessing
    - compiling
    - assembling
    - linking

---

## **Memory**

- In C, we have different types of variables we can use for storing data. Each variable is stored with a fixed number of bytes, and for most computer systems each type has the following size:
    - `bool`, 1 byte
        - A Boolean value can technically be represented with just a single bit, but for simplicity our computers use an entire byte.
    - `char`, 1 byte
        - Recall that with ASCII, we have a maximum of 256 different possible characters, since there are 8 bits in a byte.
    - `double`, 8 bytes
        - Twice as many bytes as a `float`.
    - `float`, 4 bytes
    - `int`, 4 bytes
        - Recall that a 32-bit integer can represent about 4 billion different values.
    - `long`, 8 bytes
        - Twice as many bytes as an int.
    - `string`, ? bytes
        - A string takes up a variable amount of space, since it could be short or long.

---

## **Strings**

- **Strings** are actually just arrays of characters, and defined not in C but by the CS50 library.

    ```c
    #include <cs50.h>
    #include <stdio.h>
    
    int main(void)
    {
        string s = "HI!";
        printf("%s\n", s);
    }
    ```

- In memory, our three `char` variables might have been stored like this: \
    <img src="https://cs50.harvard.edu/x/2022/notes/2/chars.png" alt="grid with H labeled c1, I labeled c2, ! labeled c3" width="200">

- Each character in our string is stored in a byte of memory as well: \
    <img src="https://cs50.harvard.edu/x/2022/notes/2/string.png" alt="grid with H labeled s[0], I labeled s[1], ! labeled s[2], \0 labeled s[3]" width="200">

- In C, strings end with a special character, '\0', or a byte with all eight bits set to 0, so our programs have a way of knowing where the string ends. This character is called the null character, or NUL. So, we actually need four bytes to store our string with three characters.

- We can use a function that comes with C's `string` library, `strlen`, to get the length of the string:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>
    
    int main(void)
    {
        string name = get_string("Name: ");
        int length = strlen(name);
        printf("%i\n", length);
    }
    ```

- Now that we can use `strlen`, we can try to print each character of our string with a loop:

    ```c
    #include <cs50.h>
    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        string s = get_string("Input:  ");
        printf("Output: ");
        for (int i = 0; i < strlen(s); i++)
        {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    ```

- We can use   for "lowercase", and it looks like there's another library, `ctype.h`, that we can use:

- Based on the CS50's **[manual pages](https://manual.cs50.io/)**, `islower` will return a non-zero value if `c`, the character passed in, is lowercase. And a non-zero value is treated as `true` in Boolean expressions.

    ```C
    #include <cs50.h>
    #include <ctype.h>
    #include <stdio.h>
    #include <string.h>

    int main(void)
    {
        string s = get_string("Before: ");
        printf("After:  ");
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (islower(s[i]))
            {
                printf("%c", s[i] - 32);
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
    ```

## **Command-line arguments**

- Programs of our own can also take in command-line arguments, or inputs given to our program in the command we use to run it. We can change what our main function to no longer take in void, or no arguments, and instead:

    ```C
    #include <stdio.h>

    int main(int argc, string argv[])
    {
        ...
    }
    ```

- `argc` and `argv` are two variables that our `main` function will now get automatically when our program is run from the command line. **`argc`** is the *argument count*, or number of arguments (words) typed in. **`argv[]`**, *argument vector* (or argument list), is an array of the arguments (words) themselves, and there's no size specified since we don't know how big that will be ahead of time.

- Let's try to print arguments:

    ```C
    #include <cs50.h>
    #include <stdio.h>
    
    int main(int argc, string argv[])
    {
        printf("hello, %s\n", argv[1]);
    }
    ```

    ```
    $ ./argv
    hello, (null)
    $ ./argv John
    hello, John
    ```

    - When we run our program without a second argument, we see `(null)` printed.

- We should make sure that we have the right number of arguments before we try to print something that isn't there:

    ```C
    #include <cs50.h>
    #include <stdio.h>
    
    int main(int argc, string argv[])
    {
        if (argc == 2)
        {
            printf("hello, %s\n", argv[1]);
        }
        else
        {
            printf("hello, world\n");
        }
    }
    ```

    ```
    $ ./argv
    hello, world
    $ ./argv John
    hello, John
    $ ./argv John Doe
    hello, world
    ```

- It turns out that our `main` function also returns an integer value called an **exit status**. By default, our `main` function returns `0` to indicate nothing went wrong, but we can write a program to return a different value:

    ```C
    #include <cs50.h>
    #include <stdio.h>

    int main(int argc, string argv[])
    {
        if (argc != 2)
        {
            printf("missing command-line argument\n");
            return 1;
        }
        printf("hello, %s\n", argv[1]);
        return 0;
    }
    ```

    - A non-zero exit status indicates some error to the system that runs our program. Once we run `return 1;` our program will exit early with an exit status of `1`. We might have seen error codes in the past when programs we used encountered errors as well.

    - We'll write `return 0` explicitly at the end of our program here, even though we don't technically need to since C will automatically return `0` for us.
