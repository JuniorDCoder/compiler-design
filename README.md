# DFA String Validator

## This is a C program that validates binary strings (`0`s and `1`s) using a Deterministic Finite Automaton (DFA). It continuously allows the user to test strings until they decide to exit.

## Program Overview

This program implements a DFA with the following states:

- **`S` (Start State)**: The initial state of the DFA.
- **`T` (Intermediate State)**: Transitioned to when specific conditions are met.
- **`U` (Accepting/Final State)**: The state that determines if the input string is valid.

### DFA Transitions:

1. From `S`:
   - `0` → Go to `T`.
   - `1` → Go to `U`.
2. From `T`:
   - `0` → Stay in `T`.
   - `1` → Go to `U`.
3. From `U`:
   - `0` → Go to `T`.
   - `1` → Stay in `U`.

### Valid Strings:

A string is **valid** if it ends in **state `U`** after processing all characters.

---

## How to Run the Program

### Compilation

Make sure you have `gcc` installed on your system. To compile the program, run:

```bash
gcc lexer.c -o lexer
```

### Execution

Run the compiled program:

```bash
./lexer
```

### Testing

The program will prompt you to enter binary strings for validation. It will continuously ask for inputs unless you choose to exit.

---

## Program Workflow

### Main Features:

1. **Input**: Accepts a binary string (`0`s and `1`s).
2. **Validation**: Checks the string against DFA transitions.
3. **Output**: Displays whether the string is valid or invalid.
4. **Repeat or Exit**: Prompts the user to continue or exit.

---

## Code Explanation

### Headers

```c
#include <stdio.h>
#include <string.h>
```

- **`#include <stdio.h>`**: Includes functions for input/output (`printf`, `scanf`).
- **`#include <string.h>`**: Includes string manipulation functions, though not used directly here.

---

### Enumerated States

```c
typedef enum {
    S,  // Start state
    T,  // Intermediate state
    U   // Final/Accepting state
} State;
```

- Defines the DFA states as an enumerated type.

---

### `isValid` Function

```c
int isValid(const char *input);
```

This function processes the input string and validates it based on the DFA rules:

1. **Start at State `S`**.
2. For each character:
   - Transition to the next state based on the current state and input.
   - Return `0` if an invalid character is encountered.
3. **Accept if the final state is `U`**; otherwise, reject.

---

### Main Function

```c
int main() {
    char input[100];
    char choice;
    ...
}
```

1. **Input**: Prompts the user to enter a binary string.
2. **Validation**: Calls `isValid` to check the string.
3. **Output**: Displays whether the string is valid or invalid.
4. **Repeat or Exit**: Allows the user to test another string or terminate the program.

---

### DFA Transition Logic

The DFA transitions are implemented using a `switch`-`case` block inside `isValid`:

#### Example:

```c
case S:
    if (c == '0') {
        currentState = T;  // Transition to T
    } else if (c == '1') {
        currentState = U;  // Transition to U
    } else {
        return 0;  // Invalid character
    }
    break;
```

- Transitions are determined based on the current state and input character.
- Invalid characters (`not '0' or '1'`) immediately terminate validation.

---

### Loop for Multiple Inputs

The program allows multiple inputs using a `do-while` loop:

```c
do {
    // Input, validation, and output
    printf("Do you want to validate another string? (y/n): ");
    scanf(" %c", &choice);
} while (choice == 'y' || choice == 'Y');
```

- Continues until the user enters `n` or any non-`y` character.

---

### Example Usage

**Input 1**:

```
Enter a string to validate: 101
The string '101' is valid.

Do you want to validate another string? (y/n): y
```

**Input 2**:

```
Enter a string to validate: 1002
The string '1002' is invalid.

Do you want to validate another string? (y/n): n
```

---

## Contribution

Feel free to fork, modify, and submit pull requests. This is a simple implementation to learn DFA programming concepts in C.

---

## License

This project is licensed under the MIT License.
