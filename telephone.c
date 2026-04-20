#include <stdio.h>
#include <stdlib.h>
struct Contact {
    char name[50];
    char phone[15];
};
void addContact() {
    FILE *fp = fopen("contacts.txt", "a");
    struct Contact c;
    printf("Enter Name: ");
    scanf("%s", c.name);
    printf("Enter Phone: ");
    scanf("%s", c.phone);
    fprintf(fp, "%s %s\n", c.name, c.phone);
    fclose(fp);
    printf("Saved Successfully!\n");
}
void displayContacts() {
    FILE *fp = fopen("contacts.txt", "r");
    struct Contact c;
    while(fscanf(fp, "%s %s", c.name, c.phone) != EOF) {
        printf("\nName: %s", c.name);
        printf("\nPhone: %s\n", c.phone);
    }
    fclose(fp);
}
int main() {
    int choice;
    while(1) {
        printf("\n1.Add 2.Display 3.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: exit(0);
            default: printf("Invalid\n");
        }
    }
}
