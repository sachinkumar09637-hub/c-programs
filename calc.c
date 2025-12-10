#include <stdio.h>
#include <math.h>

int main() {
    // Variable declaration:
    // 'o' (operator) and 't' (operation type: 's' for sequential)
    // Initializing 'o' to space (' ') prevents the while loop from checking 
    // an uninitialized variable on the first run.
    char o = ' ', t; 
    
    // Main loop: Keeps the calculator running until the user enters 'e' (exit).
    while(o != 'e'){
        // --- Menu Display ---
        printf("Operators:-\n(+)  Addition\n(-)  Subtraction\n(*)  Multiplication\n(/)  Division\n(p)  Power\n(r)  Root\n\nSelect an operator or (e)Exit: ");
        
        // Read operator input. The leading space in scanf handles potential leftover newlines.
        scanf(" %c", &o); 
        printf("\n");
        
        // --- Exit Condition Check ---
        if(o == 'e') {
            printf("Exiting... Goodbye!\n");
            break; 
        }

        // --- Input Validation ---
        // Checks if the entered character is a valid operator.
        if(o != '+' && o !='-' && o !='*' && o !='/' && o !='p' && o !='r'){
            printf("\n-- You have Selected wrong Operator !--\nPlease select Correct Operator 👍.\n\n");      
        } else {
            // --- Operation Type Selection ---
            printf("(s)         Sequential Operation\n(Any key)   One time operation\n\nSelect operation type:");
            scanf(" %c",&t); // Reads operation type ('s' or other key)
            printf("\n");
            
            // --- SEQUENTIAL OPERATION BLOCK ---
            if(t == 's' || t == 'S'){
                printf("Sequential operation of \"%c\" is starting:\n", o);
                
                // --- Sequential Addition/Subtraction Logic ---
                if(o == '+' || o == '-'){
                    // 'a' is the accumulator (running total), 'b' is the new input number.
                    double a = 0.0; 
                    double b = 0.0; 
                    
                    // Ask for the base number to initialize the accumulator 'a'.
                    printf("Enter base number: ");
                    scanf("%lf", &a); 

                    printf("(Enter 0.0 to stop)\n\n");
                    
                    // Inner infinite loop for sequential calculation.
                    while (1) {
                        printf("Current Total: %.2lf\n", a);
                        printf("Enter a number:");
                        scanf("%lf", &b);

                        if (b == 0.0) {
                            break; // Exit loop if sentinel (0.0) is entered.
                        }
                        
                        // Perform the operation based on the selected operator 'o'.
                        if (o == '+') {
                            a += b;
                        } else { // o == '-'
                            a -= b;
                        }
                    }
                    printf("\nFinal result is: %.2lf\n", a);

                // --- Sequential Multiplication Logic ---
                } else if(o == '*'){
                    // Accumulator 'a' starts at 1.0 (identity element for multiplication).
                    double a = 1.0; 
                    double b = 0.0; 
                    
                    printf("Enter starting number: ");
                    scanf("%lf", &a); // Initialize accumulator 'a' with the first number.

                    printf("(Enter 1.0 to stop)\n\n");
                    
                    while (1) {
                        printf("Current Total: %.2lf\n", a);
                        printf("Enter number to multiply:");
                        scanf("%lf", &b); 

                        if (b == 1.0) { 
                            break; // Exit loop if sentinel (1.0) is entered.
                        }
                        a *= b;
                    }
                    printf("\nFinal result is: %.2lf\n", a);

                // --- Sequential Division Logic ---
                } else if(o == '/'){
                    double a = 0.0; 
                    double b = 0.0; 
                    
                    printf("Enter base number: ");
                    scanf("%lf", &a); // Initialize accumulator 'a' with the dividend.

                    printf("(Enter 1.0 to stop)\n\n");
                    
                    while (1) {
                        printf("Current Total: %.2lf\n", a);
                        printf("Enter divisor (or 1.0 to stop):");
                        scanf("%lf", &b); 

                        if (b == 1.0) {
                            break; // Exit loop if sentinel (1.0) is entered.
                        }
                        // Check for division by zero error.
                        if (b == 0.0) {
                            printf("Error: Cannot divide by zero. Skipping.\n");
                            continue; // Skip calculation and ask for new input.
                        }
                        a /= b;
                    }
                    printf("\nFinal result is: %.2lf\n", a);
                
                // --- Sequential Power Logic (a = a^b) ---
                } else if (o == 'p') {
                    double a = 0.0; // Accumulator (Base)
                    double b = 0.0; // Power value
                    
                    printf("Enter base number: ");
                    scanf("%lf", &a); // Initialize accumulator 'a'.

                    printf("(Enter -1.0 to stop)\n\n");
                    
                    while (1) {
                        printf("Current Total: %.2lf\n", a);
                        printf("Enter power index (or -1.0 to stop):");
                        scanf("%lf", &b);

                        if (b == -1.0) {
                            break; // Exit loop if sentinel (-1.0) is entered.
                        }
                        // Use pow() function from math.h
                        a = pow(a, b); 
                    }
                    printf("\nFinal Result: %.2lf\n\n", a);

                // --- Sequential Root Logic (a = a^(1/b)) ---
                } else if (o == 'r') {
                    double a = 0.0; // Accumulator (Base)
                    double b = 0.0; // Root index
                    
                    printf("Enter base number: ");
                    scanf("%lf", &a); // Initialize accumulator 'a'.

                    printf("(Enter -1.0 to stop)\n\n");
                    
                    while (1) {
                        printf("Current Total: %.2lf\n", a);
                        printf("Enter root index (e.g., 2, or -1.0 to stop):");
                        scanf("%lf", &b);

                        if (b == -1.0) {
                            break; // Exit loop if sentinel (-1.0) is entered.
                        }
                        // Check for root index of zero error.
                        if (b == 0.0) {
                            printf("Error: Root index cannot be zero. Skipping operation.\n");
                            continue;
                        }
                        // Use pow() to calculate the root (a raised to the power of 1/b).
                        a = pow(a, 1.0 / b); 
                    }
                    printf("\nFinal Result: %.2lf\n\n", a);
                }

            // --- ONE-TIME OPERATION BLOCK (If 't' is not 's') ---
            } else {
                double a_val, b_val; 
                
                if(o == '+'){
                    printf("You selected: %c\n",o); 
                    printf("Enter 1st Number: ");
                    scanf("%lf",&a_val);
                    printf("Enter 2nd Number: ");
                    scanf("%lf",&b_val);
                    printf("%.2lf + %.2lf = %.2lf",a_val,b_val,a_val+b_val);
                    printf("\n");
                } else if(o=='-'){
                    printf("You selected: %c\n",o);
                    printf("Enter 1st Number: ");
                    scanf("%lf",&a_val);
                    printf("Enter 2nd Number: ");
                    scanf("%lf",&b_val);
                    printf("%.2lf - %.2lf = %.2lf",a_val,b_val,a_val-b_val);
                    printf("\n");
                } else if(o=='*'){
                    printf("You selected: %c\n",o);
                    printf("Enter 1st Number: ");
                    scanf("%lf",&a_val);
                    printf("Enter 2nd Number: ");
                    scanf("%lf",&b_val);
                    printf("%.2lf * %.2lf = %.2lf",a_val,b_val,a_val*b_val);
                    printf("\n");
                } else if(o=='/'){
                    printf("You selected: %c\n",o);
                    printf("Enter 1st Number: ");
                    scanf("%lf",&a_val);
                    printf("Enter 2nd Number: ");
                    scanf("%lf",&b_val);
                    
                    if (b_val == 0.0) {
                         printf("Error: Cannot divide by zero.\n");
                    } else {
                        printf("%.2lf / %.2lf = %.2lf",a_val,b_val,a_val/b_val);
                    }
                    printf("\n");
                } else if(o=='p'){
                    printf("You selected: Power\n");
                    double base, power;
                    printf("Enter base Number: ");
                    scanf("%lf", &base);
                    printf("Enter power Number: ");
                    scanf("%lf", &power);
                    printf("%.2lf ^ %.2lf = %.2lf", base, power, pow(base, power));
                    printf("\n");
                } else if(o=='r'){
                    printf("You selected: Root\n");
                    double base, root;
                    printf("Enter base Number: ");
                    scanf("%lf", &base);
                    printf("Enter root index (e.g., 2 for square root): ");
                    scanf("%lf", &root);
                    
                    if (root == 0.0) {
                        printf("Error: Root index cannot be zero.\n");
                    } else {
                        printf("Root(%.0lf) of %.2lf = %.2lf", root, base, pow(base, 1.0/root));
                    }
                    printf("\n");
                }
            }
        }
        printf("--------------------------------------------\n\n");
    }
    return 0;
}