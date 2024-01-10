#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

// Function to parse user input into command and arguments
void parseInput(char *input, char **command, char **arguments) {
    *command = strtok(input, " \t\n");

    int argIndex = 0;
    char *token;

    while ((token = strtok(NULL, " \t\n")) != NULL) {
        arguments[argIndex++] = token;
    }

    arguments[argIndex] = NULL; // Set the last argument to NULL
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command, *arguments[MAX_ARGUMENTS];

    while (1) {
        // Display a prompt
        printf("SimpleShell> ");
        fflush(stdout);

        // Read user input
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Exit on EOF (Ctrl+D)
        }

        // Remove the newline character from the input
        input[strcspn(input, "\n")] = '\0';

        // Parse the input
        parseInput(input, &command, arguments);

        // Exit the shell if the user enters "exit" or "quit"
        if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0) {
            break;
        }

        // Fork a new process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            if (execvp(command, arguments) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Child process exited with status %d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("Child process terminated by signal %d\n", WTERMSIG(status));
            }
        }
    }

    printf("Goodbye!\n");

    return 0;
}