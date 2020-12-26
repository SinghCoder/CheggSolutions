#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 101
#define MAX_NUM_BOOKS 10
int numBooks = 0;
/**
 * id, title, author and publisher are assumed to be of maximum 100 characters length
 * Length can be increased by changing value of MAX_LENGTH at line 4
 */
typedef struct book{
    char id[MAX_LENGTH];
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    struct{
        int day;
        int month;
        int year;
    } publicationDate;
    char publisher[MAX_LENGTH];
} Book;

Book library[MAX_NUM_BOOKS];

void printBook(Book b){
    printf("Book's details are: \n");
    printf("-----------------------------------------------------------\n");
    printf("ID: %s\n", b.id);
    printf("Title: %s\n", b.title);
    printf("Author: %s\n", b.author);
    printf("Publication Date(YYYY-MM-DD): %d-%d-%d\n", b.publicationDate.year, b.publicationDate.month, b.publicationDate.day);
    printf("Publisher: %s\n", b.publisher);
    printf("-----------------------------------------------------------\n");
}

int getChoice(){
    int choice;
    printf("--------------Welcome to the Books Library-----------------\n");
    printf("1. Insert a Book\n");
    printf("2. Search for a Book\n");
    printf("3. Delete a Book\n");
    printf("4. Edit a Book\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    printf("-----------------------------------------------------------\n");
    return choice;
}

void insertBook(){
    if(numBooks == MAX_NUM_BOOKS){
        printf("Library is FULL!! Cannot insert anymore books");
        return;
    }
    
    int bookIndex = numBooks;
    size_t len = MAX_LENGTH-1;
    numBooks++;
    printf("Enter Book ID: ");
    fgets(library[bookIndex].id, MAX_LENGTH - 1,  stdin);
    printf("Enter Book Title: ");
    fgets(library[bookIndex].title, MAX_LENGTH - 1,  stdin);
    printf("Enter Book Author: ");
    fgets(library[bookIndex].author, MAX_LENGTH - 1,  stdin);
    printf("Enter Book's Publication date:\n");
    printf("\tYear: ");
    scanf("%d", &library[bookIndex].publicationDate.year);
    printf("\tMonth: ");
    scanf("%d", &library[bookIndex].publicationDate.month);
    printf("\tDay: ");
    scanf("%d", &library[bookIndex].publicationDate.day);
    getchar();
    printf("Enter Book Publisher: ");
    fgets(library[bookIndex].publisher, MAX_LENGTH - 1,  stdin);
}

bool searchBook(){
    printf("Criteria for searching: \n");
    int choice;
    size_t len = MAX_LENGTH-1;
    printf("1. BookID\n");
    printf("2. Book Title\n");
    printf("3. Author\n");
    printf("4. Date of publication\n");
    printf("5. Publisher\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    int i;
    bool found = false;
    switch(choice){
        case 1:
            {
                char bookID[MAX_LENGTH];
                printf("Enter book ID to search\n");
                fgets(bookID, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, bookID) == 0){
                        printf("Found a book in library with this ID\n");
                        printBook(library[i]);
                        found = true;
                    }
                }
            }
            break;
        case 2:
            {
                char title[MAX_LENGTH];
                printf("Enter book title to search\n");
                fgets(title, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, title) == 0){
                        printf("Found a book in library with this title\n");
                        printBook(library[i]);
                        found = true;
                    }
                }
            }
            break;
        case 3:
            {
                char author[MAX_LENGTH];
                printf("Enter book Author to search\n");
                fgets(author, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, author) == 0){
                        printf("Found a book in library with this author\n");
                        printBook(library[i]);
                        found = true;
                    }
                }
            }
            break;
        case 4:
            {
                int year, month, day;
                printf("Enter publication date to search\n");
                 printf("\tYear: ");
                scanf("%d", &year);
                printf("\tMonth: ");
                scanf("%d", &month);
                printf("\tDay: ");
                scanf("%d", &day);
                getchar();
                for(i = 0; i < numBooks; i++){
                    if(library[i].publicationDate.year == year && library[i].publicationDate.month == month 
                    && library[i].publicationDate.day == day ){
                        printf("Found a book in library with this publication date\n");
                        printBook(library[i]);
                        found = true;
                    }
                }
            }
            break;
        case 5:
            {
                char publisher[MAX_LENGTH];
                printf("Enter book publisher to search\n");
                fgets(publisher, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, publisher) == 0){
                        printf("Found a book in library with this publisher\n");
                        printBook(library[i]);
                        found = true;
                    }
                }
            }
            break;
        default:
            printf("Invalid option selected. Please try again\n");
            break;
    }
}

void deleteBookAtIndex(int idx){
    int i;
    for(i = idx; i < numBooks-1; i++){
        strcpy(library[i].author, library[i+1].author);
        strcpy(library[i].id, library[i+1].id);
        strcpy(library[i].title, library[i+1].title);
        strcpy(library[i].publisher, library[i+1].publisher);
        library[i].publicationDate.day = library[i+1].publicationDate.day;
        library[i].publicationDate.month = library[i+1].publicationDate.month;
        library[i].publicationDate.year = library[i+1].publicationDate.year;
    }
    numBooks--;
}

void deleteBook(){
    printf("Criteria for deleting: \n");
    int choice;
    size_t len = MAX_LENGTH-1;
    printf("1. BookID\n");
    printf("2. Book Title\n");
    printf("3. Author\n");
    printf("4. Date of publication\n");
    printf("5. Publisher\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    int i;
    bool found = false;
    switch(choice){
        case 1:
            {
                char bookID[MAX_LENGTH];
                printf("Enter book ID to delete\n");
                fgets(bookID, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, bookID) == 0){
                        printf("Found a book in library with this ID, deleting it\n");
                        deleteBookAtIndex(i);
                        i--;
                        found = true;
                    }
                }
            }
            break;
        case 2:
            {
                char title[MAX_LENGTH];
                printf("Enter book title to delete\n");
                fgets(title, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, title) == 0){
                        printf("Found a book in library with this title, deleting it\n");
                        deleteBookAtIndex(i);
                        i--;
                        found = true;
                    }
                }
            }
            break;
        case 3:
            {
                char author[MAX_LENGTH];
                printf("Enter book Author to delete\n");
                fgets(author, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, author) == 0){
                        printf("Found a book in library with this author, deleting it\n");
                        deleteBookAtIndex(i);
                        i--;
                        found = true;
                    }
                }
            }
            break;
        case 4:
            {
                int year, month, day;
                printf("Enter publication date to delete\n");
                printf("\tYear: ");
                scanf("%d", &year);
                printf("\tMonth: ");
                scanf("%d", &month);
                printf("\tDay: ");
                scanf("%d", &day);
                getchar();
                for(i = 0; i < numBooks; i++){
                    if(library[i].publicationDate.year == year && library[i].publicationDate.month == month 
                    && library[i].publicationDate.day == day ){
                        printf("Found a book in library with this publication date, deleting it\n");
                        deleteBookAtIndex(i);
                        i--;
                        found = true;
                    }
                }
            }
            break;
        case 5:
            {
                char publisher[MAX_LENGTH];
                printf("Enter book publisher to delete\n");
                fgets(publisher, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, publisher) == 0){
                        printf("Found a book in library with this publisher, deleting it\n");
                        deleteBookAtIndex(i);
                        i--;
                        found = true;
                    }
                }
            }
            break;
        default:
            printf("Invalid option selected. Please try again\n");
            break;
    }
    if(!found){
        printf("No book found satisfying criteria\n");
    }
}

void editBook(){
    printf("Criteria for Editing: \n");
    int choice;
    printf("1. Book Title\n");
    printf("2. Author\n");
    printf("3. Date of publication\n");
    printf("4. Publisher\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    int i;
    size_t len = MAX_LENGTH-1;
    bool found = false;
    switch(choice){        
        case 1:
            {
                char title[MAX_LENGTH], newTitle[MAX_LENGTH];
                printf("Enter original book title to edit\n");
                fgets(title, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, title) == 0){
                        printf("Enter new title\n");
                        fgets(newTitle, MAX_LENGTH - 1,  stdin);
                        strcpy(library[i].title, newTitle);
                        found = true;
                    }
                }
                if(found == false){
                    printf("No such book title found\n");
                }
            }
            break;
        case 2:
            {                
                char author[MAX_LENGTH], newAuthor[MAX_LENGTH];
                printf("Enter original book Author to edit\n");
                fgets(author, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, author) == 0){
                        printf("Found a book in library with this author, enter new author\n");
                        fgets(newAuthor, MAX_LENGTH - 1,  stdin);
                        strcpy(library[i].author, newAuthor);
                        found = true;
                    }
                }
                if(found == false){
                    printf("No such book author found\n");
                }
            }
            break;
        case 3:
            {
                int year, month, day, newYear, newMonth, newDay;
                printf("Enter original publication date to edit\n");
                 printf("\tYear: ");
                scanf("%d", &year);
                printf("\tMonth: ");
                scanf("%d", &month);
                printf("\tDay: ");
                scanf("%d", &day);
                for(i = 0; i < numBooks; i++){
                    if(library[i].publicationDate.year == year && library[i].publicationDate.month == month 
                    && library[i].publicationDate.day == day ){
                        printf("Found a book in library with this publication date, enter new date to edit\n");
                        printf("\tYear: ");
                        scanf("%d", &newYear);
                        printf("\tMonth: ");
                        scanf("%d", &newMonth);
                        printf("\tDay: ");
                        scanf("%d", &newDay);
                        library[i].publicationDate.year = newYear;
                        library[i].publicationDate.month = newMonth;
                        library[i].publicationDate.day = newDay;
                        found = true;
                    }
                }
                if(found == false){
                    printf("No such publication date found\n");
                }
            }
            break;
        case 4:
            {
                char publisher[MAX_LENGTH], newPublisher[MAX_LENGTH];
                printf("Enter original book publisher to edit\n");
                fgets(publisher, MAX_LENGTH - 1,  stdin);
                for(i = 0; i < numBooks; i++){
                    if(strcmp(library[i].id, publisher) == 0){
                        printf("Found a book in library with this publisher, enter new publisher\n");
                        fgets(newPublisher, MAX_LENGTH - 1,  stdin);
                        strcpy(library[i].publisher, newPublisher);
                        found = true;
                    }
                }
                if(found == false){
                    printf("No such publisher found\n");
                }
            }
            break;
        default:
            printf("Invalid option selected. Please try again\n");
            break;
    }
}

int main()
{
    int choice;
    do{
        choice = getChoice();
        switch(choice){
            case 1:
                insertBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                editBook();
                break;
            case 5:
                return 0;
                break;
        }
    }while(choice != 5);
    
    return 0;
}