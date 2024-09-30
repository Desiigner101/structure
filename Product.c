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
    char category[50]; 
    int quantity;
} pRecords;

void addNewProduct(pRecords product[], int *count, pRecords newProduct[]); 
int removeProduct(pRecords product[], int *count);
void displayAll(pRecords product[], int count);
void displayCategory(pRecords product[], int count, char *category);
int isValidExpiryDate(pExpiry expiry);
void scanString(char *field);

int main() {
    pRecords product[2];   
    pRecords newProduct[1]; 
    char category[500];
    int count = 0;
    int choice = 0;
    int duplicate = 0;
    int i;

    do {
        printf("\t\tWelcome to products by ginodibo\t\t\n\n");
        printf("1. Add new product\n");
        printf("2. Remove product by ID\n");
        printf("3. Display all products\n");
        printf("4. Display products by department\n");
        printf("5. To exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                if (count == 2) {
                    printf("The array is full....\n");
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
                scanString(newProduct[0].description.pName);

                printf("Enter Product Description: ");
                scanString(newProduct[0].description.description);

                printf("Enter Product Category: ");
                scanString(newProduct[0].category);

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
                scanString(category);

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

void scanString(char *field) {
    fgets(field, 1000, stdin); 
    field[strcspn(field, "\n")] = 0; 
}

void addNewProduct(pRecords product[], int *count, pRecords newProduct[]) {
    product[*count] = newProduct[0];
    (*count)++;  

    printf("Product successfully added.\n");
}

int removeProduct(pRecords product[], int *count) {
    int productId, found = 0;

    printf("Enter Product ID to remove: ");
    scanf("%d", &productId);

    // Search for the product by ID
    for (int i = 0; i < *count; i++) {
        if (product[i].productId == productId) {
            found = 1; // Product found
            // Shift products to the left to remove the product
            for (int j = i; j < *count - 1; j++) {
                product[j] = product[j + 1];
            }
            (*count)--; // Decrease the count
            printf("Product with ID %d removed successfully.\n", productId);
            break; // Exit the loop after removing the product
        }
    }

    if (!found) {
        printf("Product with ID %d not found.\n", productId);
    }

    return found ? 1 : 0; // Return 1 if product was found and removed, otherwise return 0
}

void displayAll(pRecords product[], int count) {
    int i;

    printf("\n\t\tAll Products:\n");
    for (i = 0; i < count; i++) {
        printf("Product ID: %d\n", product[i].productId);
        printf("Product Name: %s\n", product[i].description.pName);
        printf("Product Description: %s\n", product[i].description.description);
        printf("Category: %s\n", product[i].category); 
        printf("Expiry Date: %02d/%02d/%04d\n", product[i].expiry.month, product[i].expiry.day, product[i].expiry.year);
        printf("Quantity: %d\n", product[i].quantity);
        printf("-----------------------------\n");
    }
}

void displayCategory(pRecords product[], int count, char *category) {
    int found = 0;
    int i;
    
    printf("\n\t\tProducts in Category: %s\n", category);
    for (i = 0; i < count; i++) {
        if (strcmp(product[i].category, category) == 0) { 
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
    if (expiry.month < 1 || expiry.month > 12) {
        return 0; // Invalid month
    }

    if (expiry.month == 2) { // February
        if (expiry.day < 1 || expiry.day > 28) {
            return 0; 
        }
    } else if (expiry.month == 4 || expiry.month == 6 || expiry.month == 9 || expiry.month == 11) { // April, June, September, November
        if (expiry.day < 1 || expiry.day > 30) {
            return 0; 
        }
    } else { // January, March, May, July, August, October, December
        if (expiry.day < 1 || expiry.day > 31) {
            return 0;
        }
    }

    return 1; 
}
