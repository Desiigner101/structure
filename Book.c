
#include <stdio.h>
#include <string.h>

// Structure to store Author information
struct Author {
    char firstName[50];
    char middleName[50];
    char lastName[50];
};

// Structure to store Book information
struct Book {
    char title[100];
    struct Author author;  // Embedding Author structure
    float price;
};

// Function to copy input data into a Book structure
void inputData(struct Book *book, char title[], char firstName[], char middleName[], char lastName[], float price) {
    strcpy(book->title, title);
    strcpy(book->author.firstName, firstName);
    strcpy(book->author.middleName, middleName);
    strcpy(book->author.lastName, lastName);
    book->price = price;
}

// Function to retrieve data from Book structure
void display(struct Book book) {
    printf("\nBook Title: %s\n", book.title);
    printf("Author: %s %s %s\n", book.author.firstName, book.author.middleName, book.author.lastName);
    printf("Price: $%.2f\n", book.price);
}

int main() {
    struct Book book1, book2;
    char title[100], firstName[50], middleName[50], lastName[50];
    float price;

    // Input data for the first book
    printf("Enter the first book's title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;  // Remove trailing newline

    printf("Enter the first book's author's first name: ");
    fgets(firstName, 50, stdin);
    firstName[strcspn(firstName, "\n")] = 0;

    printf("Enter the first book's author's middle name: ");
    fgets(middleName, 50, stdin);
    middleName[strcspn(middleName, "\n")] = 0;

    printf("Enter the first book's author's last name: ");
    fgets(lastName, 50, stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    printf("Enter the first book's price: ");
    scanf("%f", &price);

    inputData(&book1, title, firstName, middleName, lastName, price);

    // Display the first book's data
    display(book1);

    // Input data for the second book
    getchar();  // To consume leftover newline from previous input
    printf("\nEnter the second book's title: ");
    fgets(title, 100, stdin);
    title[strcspn(title, "\n")] = 0;

    printf("Enter the second book's author's first name: ");
    fgets(firstName, 50, stdin);
    firstName[strcspn(firstName, "\n")] = 0;

    printf("Enter the second book's author's middle name: ");
    fgets(middleName, 50, stdin);
    middleName[strcspn(middleName, "\n")] = 0;

    printf("Enter the second book's author's last name: ");
    fgets(lastName, 50, stdin);
    lastName[strcspn(lastName, "\n")] = 0;

    printf("Enter the second book's price: ");
    scanf("%f", &price);

    inputData(&book2, title, firstName, middleName, lastName, price);

    // Display the second book's data
    display(book2);

    return 0;
}