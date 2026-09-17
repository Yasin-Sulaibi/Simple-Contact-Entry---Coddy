 #include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[40];
    int age;
};

struct Contact* createContact(void) {
    struct Contact *contactPtr = malloc(sizeof(struct Contact));
    if (contactPtr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    } 


    contactPtr->name[0] = '\0';
    contactPtr->phone[0] = '\0';
    contactPtr->email[0] = '\0';
    contactPtr->age = 0;

    return contactPtr;
}

void populateContact(struct Contact *contactPtr) {

    printf("Enter name: ");
    if (fgets(contactPtr->name, sizeof(contactPtr->name), stdin) != NULL) {
        contactPtr->name[strcspn(contactPtr->name, "\n")] = '\0';
    }

    printf("Enter phone: ");
    if (fgets(contactPtr->phone, sizeof(contactPtr->phone), stdin) != NULL) {
        contactPtr->phone[strcspn(contactPtr->phone, "\n")] = '\0';
    }

    printf("Enter email: ");
    if (fgets(contactPtr->email, sizeof(contactPtr->email), stdin) != NULL) {
        contactPtr->email[strcspn(contactPtr->email, "\n")] = '\0';
    }

    printf("Enter age: ");
    scanf("%d", &contactPtr->age);
}

void displayContact(const struct Contact *contactPtr) {

    printf("=== CONTACT DETAILS ===\n");
    printf("Name: %s\nPhone: %s\nEmail: %s\nAge: %d years old\n", contactPtr->name, contactPtr->phone, contactPtr->email, contactPtr->age);
    printf("========================\n");

    int length = strlen(contactPtr->name);
    printf("Name length: %d characters\n", length);

    if (contactPtr->age >= 0 && contactPtr->age <= 12) {
        printf("Generation: Child\n");
    }
    else if (contactPtr->age >= 13 && contactPtr->age <= 19) {
        printf("Generation: Teenager\n");
    }
    else if (contactPtr->age >= 20 && contactPtr->age <= 39) {
        printf("Generation: Young Adult\n");
    }
    else if (contactPtr->age >= 40 && contactPtr->age <= 59) {
        printf("Generation: Middle-aged Adult\n");
    }
    else {
        printf("Generation: Senior\n");
    }

    char *emailPtr = strchr(contactPtr->email, '@');
    if (emailPtr != NULL) {
        printf("Email format: Valid\n");
    }
    else {
        printf("Email format: Invalid\n");
    }
}

int main(void) {

    struct Contact *newContact = createContact();

    populateContact(newContact);
    displayContact(newContact);
    
    free(newContact);
    printf("Program completed successfully\n");

    return 0;
}