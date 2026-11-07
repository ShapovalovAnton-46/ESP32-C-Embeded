#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура одного елемента зв'язаного списку
typedef struct Book {
    char title[100];       // Назва книги
    double price;          // Ціна
    int pages;             // Кількість сторінок
    char language[30];     // Мова
    double weight;         // Вага (г)
    int year;              // Рік видання

    struct Book* next;     // Вказівник на наступний елемент
} Book;

// Функція створення нової книги
Book* createBook(const char* title, double price, int pages,
                 const char* language, double weight, int year) {

    Book* newBook = (Book*)malloc(sizeof(Book));

    if (newBook == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    strcpy(newBook->title, title);
    newBook->price = price;
    newBook->pages = pages;
    strcpy(newBook->language, language);
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;

    return newBook;
}

// Додавання книги в кінець списку
void appendBook(Book** head, Book* newBook) {
    if (*head == NULL) {
        *head = newBook;
        return;
    }

    Book* current = *head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newBook;
}

// Виведення інформації про всі книги
void printBooks(const Book* head) {
    const Book* current = head;
    int number = 1;

    printf("\n========== HARRY POTTER BOOKS ==========\n");

    while (current != NULL) {
        printf("\nBook #%d\n", number++);
        printf("Title: %s\n", current->title);
        printf("Price: %.2f UAH\n", current->price);
        printf("Pages: %d\n", current->pages);
        printf("Language: %s\n", current->language);
        printf("Weight: %.0f g\n", current->weight);
        printf("Publication year: %d\n", current->year);

        current = current->next;
    }

    printf("\n========================================\n");
}

// Звільнення пам'яті списку
void freeList(Book* head) {
    Book* current = head;

    while (current != NULL) {
        Book* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Book* head = NULL;

    // Додавання книг до зв'язаного списку
    appendBook(&head, createBook(
        "Harry Potter and the Philosopher's Stone",
        450.00, 223, "English", 350, 1997));

    appendBook(&head, createBook(
        "Harry Potter and the Chamber of Secrets",
        470.00, 251, "English", 380, 1998));

    appendBook(&head, createBook(
        "Harry Potter and the Prisoner of Azkaban",
        490.00, 317, "English", 420, 1999));

    appendBook(&head, createBook(
        "Harry Potter and the Goblet of Fire",
        520.00, 636, "English", 750, 2000));

    appendBook(&head, createBook(
        "Harry Potter and the Order of the Phoenix",
        550.00, 766, "English", 850, 2003));

    appendBook(&head, createBook(
        "Harry Potter and the Half-Blood Prince",
        530.00, 607, "English", 700, 2005));

    appendBook(&head, createBook(
        "Harry Potter and the Deathly Hallows",
        560.00, 607, "English", 720, 2007));

    // Виведення інформації
    printBooks(head);

    // Звільнення виділеної пам'яті
    freeList(head);

    return 0;
}