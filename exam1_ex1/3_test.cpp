#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

const int MAX_BOOKS = 100;
const int MAX_USERS = 50;
const int MAX_TITLE_LENGTH = 50;
const int MAX_AUTHOR_LENGTH = 50;
const int MAX_NAME_LENGTH = 50;

const int MAX_BUFFER_LEN = 256;

struct Book {
    int id;
    char* title;
    char* author;
    int year;

public:
    void initialize(int _id, const char* _title, const char* _author, int _year) {
        id = _id;

        title = new char[strlen(_title) + 1];
        int i = 0;
        while (_title[i] != '\0') {
            title[i] = _title[i];
            ++i;
        }
        title[i] = '\0'; // Ensure null-terminated

        author = new char[strlen(_author) + 1];
        i = 0;
        while (_author[i] != '\0') {
            author[i] = _author[i];
            ++i;
        }
        author[i] = '\0'; // Ensure null-terminated

        year = _year;
    }
};

struct User {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;

public:
    void initialize(int _id, const char* _name, int _age) {
        id = _id;
        int i;
        for (i = 0; i < MAX_NAME_LENGTH - 1 && _name[i] != '\0'; ++i) {
            name[i] = _name[i];
        }
        name[i] = '\0';

        age = _age;
    }
};

//   DONE
void loader()
{
    const int len = 10;
    char loader[len];
    for (int i = 0; i < len; i++) { loader[i] = '-'; };

    for (int i = 0; i < len; i++) {
        std::system("cls");
        std::cout << "\n\n\n     [";
        for (int j = 0; j < len; j++) { std::cout << loader[j]; };
        std::cout << "]";
        loader[i] = '#';
        Sleep(100);
    }
}



void saveBooksCSV(Book books[], int count) {
    std::ofstream file("books.txt", std::ios::out);
    file << "ID,Title,Author,Year\n";
    for (int i = 0; i < count; ++i) {
        file << books[i].id << ',' << books[i].title << ',' << books[i].author << ',' << books[i].year << '\n';
    }
    file.close();
}

void loadBooksCSV(Book books[], int& count) {
    std::ifstream file("books.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening books.csv for reading." << std::endl;
        return;
    }

    char header[100];
    file.getline(header, sizeof(header));

    count = 0;
    while (file >> books[count].id) {
        file.ignore(); // Ignore the comma

        // Read title
        char bufferTitle[256];
        file.getline(bufferTitle, sizeof(bufferTitle), ',');
        books[count].title = new char[strlen(bufferTitle) + 1];
        int i = 0;
        while (bufferTitle[i] != '\0') {
            books[count].title[i] = bufferTitle[i];
            ++i;
        }
        books[count].title[i] = '\0'; // Ensure null-terminated

        // Read author
        char bufferAuthor[256];
        file.getline(bufferAuthor, sizeof(bufferAuthor), ',');
        books[count].author = new char[strlen(bufferAuthor) + 1];
        i = 0;
        while (bufferAuthor[i] != '\0') {
            books[count].author[i] = bufferAuthor[i];
            ++i;
        }
        books[count].author[i] = '\0'; // Ensure null-terminated

        // Read year
        file >> books[count].year;

        ++count;
    }

    file.close();
}


void saveUsersCSV(User users[], int count) {
    std::ofstream file("users.txt", std::ios::out);
    file << "ID,Name,Age\n";
    for (int i = 0; i < count; ++i) {
        file << users[i].id << ',' << users[i].name << ',' << users[i].age << '\n';
    }
    file.close();
}

void loadUsersCSV(User users[], int& count) {
    std::ifstream file("users.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening users.csv for reading." << std::endl;
        return;
    }

    char header[100];
    file.getline(header, sizeof(header));

    count = 0;
    while (file >> users[count].id) {
        file.ignore(); // Ignore the comma
        file.getline(users[count].name, sizeof(users[count].name), ',');
        file >> users[count].age;

        ++count;
    }

    file.close();
}

void displayBooks(Book books[], int count) {
    std::cout << std::left << std::setw(5) << "ID" << std::setw(20) << "Title" << std::setw(20) << "Author" << std::setw(10) << "Year" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << std::left << std::setw(5) << books[i].id << std::setw(20) << books[i].title << std::setw(20) << books[i].author << std::setw(10) << books[i].year << std::endl;
    }
}

bool book_isIdExists(const Book books[], int count, int idToCheck) {
    for (int i = 0; i < count; ++i) {
        if (books[i].id == idToCheck) {
            return true; // ID already exists
        }
    }
    return false; // ID does not exist
}

void addBook(Book books[], int& count) {
    if (count < MAX_BOOKS) {
        Book newBook;

        int idInput = 0;
        do {

            std::cout << "Enter ID (0 for a random ID): ";
            std::cin >> idInput;

            if (idInput != 0) {
                // Use the provided ID as an integer
                if (book_isIdExists(books, count, idInput)) {
                    std::cout << "Error: ID already exists. Exiting." << std::endl;
                }
                newBook.id = idInput;
            }
            else {
                // If ID is not provided, generate a random ID
                newBook.id = rand() % 1000;

                std::cout << "Random ID generated: " << newBook.id << std::endl;
            }
        } while (book_isIdExists(books, count, newBook.id));

        // Gather other book information
        std::cout << "Enter title: ";
        char bufferTitle[256];
        std::cin.getline(bufferTitle, sizeof(bufferTitle));

        std::cout << "Enter author: ";
        char bufferAuthor[256];
        std::cin.getline(bufferAuthor, sizeof(bufferAuthor));

        std::cout << "Enter year: ";
        std::cin >> newBook.year;

        newBook.initialize(newBook.id, bufferTitle, bufferAuthor, newBook.year);


        books[count++] = newBook;
        saveBooksCSV(books, count);
        std::cout << "Book added successfully." << std::endl;
    }
    else {
        std::cout << "Maximum number of books reached." << std::endl;
    }
}



void deleteBook(Book books[], int& count, int bookId) {
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (books[i].id == bookId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Free memory for title and author
        delete[] books[index].title;
        delete[] books[index].author;

        // Shift remaining books to fill the gap
        for (int i = index; i < count - 1; ++i) {
            books[i] = books[i + 1];
        }

        --count;
        std::cout << "Book deleted successfully." << std::endl;
        saveBooksCSV(books, count);
    }
    else {
        std::cout << "Book not found." << std::endl;
    }
}


void addUser(User users[], int& count) {
    if (count < MAX_USERS) {
        User newUser;
        newUser.initialize(count + 1, "", 0);

        std::cout << "Enter name: ";
        std::cin.ignore(); // Clear the buffer
        std::cin.getline(newUser.name, sizeof(newUser.name));

        std::cout << "Enter age: ";
        std::cin >> newUser.age;

        users[count++] = newUser;
        saveUsersCSV(users, count);
        std::cout << "User added successfully." << std::endl;
    }
    else {
        std::cout << "Maximum number of users reached." << std::endl;
    }
}

void displayMenu() {
    std::cout << "\n0. Exit\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Add User\n";
    std::cout << "6. Delete book\n\n";
    std::cout << "Select option: ";
}

int main() {

    srand(time(0));
    loader();




    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int bookCount = 0;
    int userCount = 0;

    loadBooksCSV(books, bookCount);
    loadUsersCSV(users, userCount);

    //displayBooks(books, bookCount);
    std::cout << std::endl << sizeof(books) << std::endl;
    std::cout << sizeof(Book) << std::endl;
    std::cout << sizeof(users) << std::endl;
    std::cout << sizeof(User) << std::endl;
    Sleep(1000);

    int choice;
    do {
        std::system("cls");
        displayBooks(books, bookCount);
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        case 1:
            addBook(books, bookCount);
            displayBooks(books, bookCount);
            break;
        case 2:
            addUser(users, userCount);
            break;
        case 5:
            loader();
            break;
        case 6:
            int bookId;
            std::cout << "Enter the ID of the book to delete: ";
            std::cin >> bookId;
            deleteBook(books, bookCount, bookId);
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}
