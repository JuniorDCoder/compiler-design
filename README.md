# DFA String Validator and Lexer Implementation

## Overview

This repository contains two main implementations for binary string validation and lexical analysis:

1. **Manual Lexer (in the `Lexer` folder)**: A manually implemented deterministic finite automaton (DFA) to validate binary strings.
2. **Flex-based Lexer (in the `Flex` folder)**: A scanner generated using the `Flex` tool to handle lexical analysis.

---

## Manual Lexer (in `Lexer` folder)

### Program Overview

The manual lexer validates binary strings (`0`s and `1`s) using a Deterministic Finite Automaton (DFA). It continuously allows the user to test strings until they decide to exit.

### DFA States and Transitions:

- **States**:

  - `S` (Start State)
  - `T` (Intermediate State)
  - `U` (Accepting/Final State)

- **Transitions**:

  1. From `S`:
     - `0` → `T`
     - `1` → `U`
  2. From `T`:
     - `0` → `T`
     - `1` → `U`
  3. From `U`:
     - `0` → `T`
     - `1` → `U`

- A string is **valid** if it ends in state `U`.

---

### How to Run the Manual Lexer

1. Navigate to the `Lexer` folder:

   ```bash
   cd Lexer
   ```

2. Compile the program:

   ```bash
   gcc lexer.c -o lexer
   ```

3. Run the compiled program:

   ```bash
   ./lexer
   ```

4. Enter binary strings for validation. The program will determine if the input is valid or invalid.

---

## Flex-based Lexer (in `Flex` folder)

### Program Overview

The Flex-based lexer is a general-purpose lexical analyzer generated using the `Flex` tool. It identifies tokens from an input file using predefined patterns.

### Token Definitions:

- **Whitespace**: Ignored.
- **Keywords**: `while`
- **Operators**: `+`
- **Identifiers**: Any sequence of letters.
- **Numbers**: Any sequence of digits.
- **Error**: Any unrecognized character.

---

### How to Run the Flex Lexer

1. Navigate to the `Flex` folder:

   ```bash
   cd Flex
   ```

2. Generate the C scanner code from the `scanner.flex` file:

   ```bash
   flex scanner.flex
   ```

   This will generate the `lex.yy.c` file.

3. Compile the generated scanner code with the main program:

   ```bash
   gcc lex.yy.c main.c -o scanner
   ```

4. Create or use a test file (e.g., `program.c`) with sample input code.

5. Run the lexer, specifying the input file:

   ```bash
   ./scanner
   ```

6. The lexer will output tokens and their corresponding text.

---

### Example Input (`program.c`):

```c
while (x + 5)
{
    x = x + 1;
}
```

### Example Output:

```
token: 1 text: while
token: 2 text: (
token: 3 text: x
token: 4 text: +
token: 5 text: 5
token: 6 text: )
...
```

---

## Folder Structure

- **`Lexer`**: Contains the manually implemented lexer with DFA logic.
- **`Flex`**: Contains the Flex scanner implementation, including:
  - `scanner.flex`: The Flex specification file.
  - `main.c`: The main driver program for the lexer.
  - `token.h`: Defines the token types.

---

## Contribution

Feel free to fork, modify, and submit pull requests. Contributions to improve either the manual or Flex-based lexer implementations are welcome.

---

## License

This project is licensed under the MIT License.
