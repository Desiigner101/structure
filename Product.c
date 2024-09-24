#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ProductDescription {
    char pName[100];
    char description[500];
} pDescription;

typedef struct ProductExpiry {
    int month;
    int day;
    int year;
} pExpiry;

typedef struct ProductRecords {
    int productId;
    pDescription description;
    pExpiry expiry;
    char catergory[50]; 
    int quantity;
} pRecords;

void addNewProduct(pRecords product[], int *count, pRecords newProduct[]); 
int removeProduct(pRecords product[], int *count);
void displayAll(pRecords product[], int count);
void displayCategory(pRecords product[], int count, char *category);
int isValidExpiryDate(pExpiry expiry);

int main() {
    pRecords product[2];   
    pRecords newProduct[1]; 
    int count = 0;
    char category[500];
    int choice = 0;
    int id = 0;
    int duplicate = 0;
    int i;

    do {
        printf("\t\tWelcome to products by ginodibo\t\t\n\n");
        printf("1. Add new product\n");
        printf("2. Remove expired product\n");
        printf("3. Display all products\n");
        printf("4. Display products by department\n");
        printf("5. To exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (count == 2) {
                    printf("The array count is full....\n");
                    break;
                }
                
                printf("Enter Product ID: ");
                scanf(" %d", &newProduct[0].productId); 
                getchar();
   
                duplicate = 0;
                for (i = 0; i < count; i++) {
                    if (newProduct[0].productId == product[i].productId) {
                        printf("ID number already exists in the product array...\n\n");
                        duplicate = 1;
                        break;
                    }
                }

                if (duplicate) break;

                printf("Enter Product Name: ");
                fgets(newProduct[0].description.pName, sizeof(newProduct[0].description.pName), stdin);
                newProduct[0].description.pName[strcspn(newProduct[0].description.pName, "\n")] = 0;

                printf("Enter Product Description: ");
                fgets(newProduct[0].description.description, sizeof(newProduct[0].description.description), stdin);
                newProduct[0].description.description[strcspn(newProduct[0].description.description, "\n")] = 0;

                printf("Enter Product Category: ");
                fgets(newProduct[0].catergory, sizeof(newProduct[0].catergory), stdin);
                newProduct[0].catergory[strcspn(newProduct[0].catergory, "\n")] = 0;

                int validExpiry = 0;
                while (!validExpiry) {
                    printf("Enter Expiry Date (MM DD YYYY): ");
                    scanf("%d %d %d", &newProduct[0].expiry.month, &newProduct[0].expiry.day, &newProduct[0].expiry.year);
                    
                    validExpiry = isValidExpiryDate(newProduct[0].expiry);
                    if (!validExpiry) {
                        printf("Invalid expiry date. Please enter again.\n");
                    }
                }

                printf("Enter Product Quantity: ");
                scanf("%d", &newProduct[0].quantity);

                addNewProduct(product, &count, newProduct); 
                break;
                
            case 2:
                removeProduct(product, &count);
                break;

            case 3:
                displayAll(product, count);
                break;

            case 4:
                printf("Enter category to display: ");
                getchar(); 
                fgets(category, sizeof(category), stdin);
                category[strcspn(category, "\n")] = 0; 

                displayCategory(product, count, category);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    return 0;
}


void addNewProduct(pRecords product[], int *count, pRecords newProduct[]) {
    product[*count] = newProduct[0];
    (*count)++;  

    printf("Successfully added....\n");
}

int removeProduct(pRecords product[], int *count){
    printf("This function has no implementation yet...\n");
}

void displayAll(pRecords product[], int count) {
    printf("\n\t\tAll Products:\n");
    for (int i = 0; i < count; i++) {
        printf("Product ID: %d\n", product[i].productId);
        printf("Product Name: %s\n", product[i].description.pName);
        printf("Product Description: %s\n", product[i].description.description);
        printf("Category: %s\n", product[i].catergory);
        printf("Expiry Date: %02d/%02d/%04d\n", product[i].expiry.month, product[i].expiry.day, product[i].expiry.year);
        printf("Quantity: %d\n", product[i].quantity);
        printf("-----------------------------\n");
    }
}

// Function to display products by category
void displayCategory(pRecords product[], int count, char *category) {
    printf("\n\t\tProducts in Category: %s\n", category);

    int found = 0;
    int i;

    for (i = 0; i < count; i++) {
        if (strcmp(product[i].catergory, category) == 0) {
            printf("Product ID: %d\n", product[i].productId);
            printf("Product Name: %s\n", product[i].description.pName);
            printf("Product Description: %s\n", product[i].description.description);
            printf("Expiry Date: %02d/%02d/%04d\n", product[i].expiry.month, product[i].expiry.day, product[i].expiry.year);
            printf("Quantity: %d\n", product[i].quantity);
            printf("-----------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No products found in this category.\n");
    }
}


int isValidExpiryDate(pExpiry expiry) {
    // Validate the year
    if (expiry.year < 1900 || expiry.year > 2100) {
        return 0; // Invalid year
    }

    // Validate the month
    if (expiry.month < 1 || expiry.month > 12) {
        return 0; // Invalid month
    }

    // Validate the day
    if (expiry.month == 2) { // February
        if (expiry.year % 4 == 0) { // Leap year
            if (expiry.day < 1 || expiry.day > 29) {
                return 0; // Invalid day for leap year February
            }
        } else {
            if (expiry.day < 1 || expiry.day > 28) {
                return 0; // Invalid day for non-leap year February
            }
        }
    } else if (expiry.month == 4 || expiry.month == 6 || expiry.month == 9 || expiry.month == 11) { // April, June, September, November
        if (expiry.day < 1 || expiry.day > 30) {
            return 0; // Invalid day for these months
        }
    } else { // January, March, May, July, August, October
        if (expiry.day < 1 || expiry.day > 31) {
            return 0; // Invalid day for these months
        }
    }

    return 1; // Valid expiry date
}