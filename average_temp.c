#include <stdio.h>
#include <time.h>

int scan_int(int *value);
int scan_float(float *value);
void menu();
void average_calc();

int main(void) {
    menu();
    return 0;
}

// Ensuring that the input is an integer number
int scan_int(int *value) {
    char control;
    return scanf("%d%c", value, &control) == 2 && control == '\n';
}

// Ensuring that the input is an float number
int scan_float(float *value) {
    char control;
    return scanf("%f%c", value, &control) == 2 && control == '\n';
}

// Show the options and call other functions
void menu() {
    int option;

    printf("\n*****Welcome!*****\n");
    printf("Type 1 to calculate the average temperatures of the year\n");
    printf("Type 2 to exit\n");
    printf("option: ");
    while (1) {

        if (!scan_int(&option)) {
            printf("Invalid input! please enter 1 or 2: ");
            while (getchar()!= '\n');
            continue;
        }

        if (option == 1) {
            average_calc();
            break;
        } else if (option == 2) {
            printf("Logging out...\n");
            break;
        } else {
            printf("Invalid input! please enter 1 or 2: ");
        }
    }
}

// Calculate the average
void average_calc() {
    const char *months[12] ={
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    float temperature[12];
    float sum = 0.0, average = 0.0;

    printf("\n-----Average temp calculator-----\n");

    // Open the file in append mode('a') to add new entries without overwriting existing data
    // use mode "w" instead if you want to overwrite the file every time
    FILE *file = fopen("temperatures.txt", "a");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // getting the current date and time
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    fprintf(file, "\n----- New Entry -----\n");
    fprintf(file, "Date: %02d/%02d/%02d - Time: %02d:%02d:%02d\n\n",
            local->tm_mday,
            local->tm_mon + 1,
            local->tm_year + 1900,
            local->tm_hour,
            local->tm_min,
            local->tm_sec);

    for (int i = 0; i < 12; i++) {
        while (1) {
            printf("Enter the temperature for %s: ", months[i]);
            if (scan_float(&temperature[i])) {
                break;
            } else {
                printf("Invalid input! please enter a valid number.\n");
                while (getchar()!= '\n');
            }
        }
        sum += temperature[i];
        fprintf(file, "%s: %.2f°C\n", months[i], temperature[i]);
    }
    printf("\n");

    average = sum / 12.0;
    printf("The yearly average temperature is: %.2f°C\n\n", average);
    fprintf(file, "\nYearly average: %.2f°C\n", average);

    printf("Months above the average temperature:\n");
    fprintf(file, "Months above the average temperature:\n");

    for (int i = 0; i < 12; i++) {
        if (temperature[i] > average) {
            printf("- %s\n", months[i]);
            fprintf(file, "- %s\n", months[i]);
        }
    }
    fclose(file);
    printf("\nResults saved in 'temperatures.txt'\n");
}

