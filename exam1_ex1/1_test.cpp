#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_BOOKS = 100;
const int MAX_USERS = 50;
const int MAX_TITLE_LENGTH = 50;
const int MAX_AUTHOR_LENGTH = 50;
const int MAX_NAME_LENGTH = 50;

struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;

    void initialize(int _id, const char* _title, const char* _author, int _year) {
        id = _id;
        int i;
        for (i = 0; i < MAX_TITLE_LENGTH - 1 && _title[i] != '\0'; ++i) {
            title[i] = _title[i];
        }
        title[i] = '\0';

        for (i = 0; i < MAX_AUTHOR_LENGTH - 1 && _author[i] != '\0'; ++i) {
            author[i] = _author[i];
        }
        author[i] = '\0';

        year = _year;
    }
};

struct User {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;

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
        file.getline(books[count].title, sizeof(books[count].title), ',');
        file.getline(books[count].author, sizeof(books[count].author), ',');
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
    std::cout << std::setw(5) << "ID" << std::setw(20) << "Title" << std::setw(20) << "Author" << std::setw(10) << "Year" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << std::setw(5) << books[i].id << std::setw(20) << books[i].title << std::setw(20) << books[i].author << std::setw(10) << books[i].year << std::endl;
    }
}

void addBook(Book books[], int& count) {
    if (count < MAX_BOOKS) {
        Book newBook;
        newBook.initialize(count + 1, "", "", 0);

        std::cout << "Enter title: ";
        std::cin.ignore(); // Clear the buffer
        std::cin.getline(newBook.title, sizeof(newBook.title));

        std::cout << "Enter author: ";
        std::cin.getline(newBook.author, sizeof(newBook.author));

        std::cout << "Enter year: ";
        std::cin >> newBook.year;

        books[count++] = newBook;
        saveBooksCSV(books, count);
        std::cout << "Book added successfully." << std::endl;
    }
    else {
        std::cout << "Maximum number of books reached." << std::endl;
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
    std::cout << "1. Add Book\n";
    std::cout << "2. Add User\n";
    std::cout << "3. Exit\n";
    std::cout << "Select option: ";
}

int main() {
    Book books[MAX_BOOKS];
    User users[MAX_USERS];
    int bookCount = 0;
    int userCount = 0;

    loadBooksCSV(books, bookCount);
    loadUsersCSV(users, userCount);

    //displayBooks(books, bookCount);

    int choice;
    do {
        std::system("cls");
        displayBooks(books, bookCount);
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            addBook(books, bookCount);
            displayBooks(books, bookCount);
            break;
        case 2:
            addUser(users, userCount);
            break;
        case 3:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 3);

    return 0;
}
