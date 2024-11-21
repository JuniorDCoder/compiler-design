#include <stdio.h>
#include <string.h>

// DFA States: S (Start state), T (Intermediate state), U (Final/accepting state)
typedef enum
{
    S, // DA (Start state)
    T, // DF
    U  // DX (Final/accepting state)
} State;

// Function to check if a string is valid based on the DFA: Returns 1 if valid, 0 otherwise
int isValid(const char *input)
{
    State currentState = S; // Start state
    int i = 0;

    // Process each character in the input: Transition based on the current state and the input character
    while (input[i] != '\0')
    {
        char c = input[i];

        // Transition table: Based on the current state and the input character, transition to the next state
        switch (currentState)
        {
        case S:
            if (c == '0')
            {
                currentState = T; // Transition to T
            }
            else if (c == '1')
            {
                currentState = U; // Transition to U
            }
            else
            {
                return 0; // Invalid character
            }
            break;

        case T:
            if (c == '0')
            {
                currentState = T; // Stay in T
            }
            else if (c == '1')
            {
                currentState = U; // Transition to U
            }
            else
            {
                return 0; // Invalid character
            }
            break;

        case U:
            if (c == '0')
            {
                currentState = T; // Transition to T
            }
            else if (c == '1')
            {
                currentState = U; // Stay in U
            }
            else
            {
                return 0; // Invalid character
            }
            break;

        default:
            return 0; // Invalid state
        }

        i++;
    }

    // Final state validation: Here, i only accept the string if the final state is U
    return currentState == U;
}

// Main function
int main()
{
    char input[100];
    char choice;

    do
    {
        printf("Enter a string to validate: ");
        scanf("%s", input);

        if (isValid(input))
        {
            printf("The string '%s' is valid.\n", input);
        }
        else
        {
            printf("The string '%s' is invalid.\n", input);
        }

        printf("\nDo you want to validate another string? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Program terminated.\n");
    return 0;
}
