﻿#include <iostream>
#include <fstream>
#include <Windows.h>
#include <time.h>

//   DONE
void loader(int LOGO_len)
{

    char* loader = new char[LOGO_len];
    for (int i = 0; i < LOGO_len; i++) { loader[i] = '-'; };

    for (int i = 0; i < LOGO_len; i++) {
        std::system("cls");

        std::cout << "\033[32m$$$$$$\033[35m\\                                           " << std::endl;
        std::cout << "\033[32m$$\033[35m  __\033[32m$$\033[35m\\                                         " << std::endl;
        std::cout << "\033[32m$$\033[35m /  \033[32m$$\033[35m |\033[32m$$\033[35m\\   \033[32m$$\033[35m\\ \033[32m$$\033[35m\\   \033[32m$$\033[35m\\  \033[32m$$$$$$\033[35m\\  \033[32m$$$$$$$\033[35m\\  " << std::endl;
        std::cout << "\033[32m$$\033[35m |  \033[32m$$\033[35m |\033[32m$$\033[35m |  \033[32m$$\033[35m |\\\033[32m$$\033[35m\\ \033[32m$$\033[35m  |\033[32m$$\033[35m  __\033[32m$$\033[35m\\ \033[32m$$\033[35m  __\033[32m$$\033[35m\\ " << std::endl;
        std::cout << "\033[32m$$\033[35m |  \033[32m$$\033[35m |\033[32m$$\033[35m |  \033[32m$$\033[35m | \\\033[32m$$$$\033[35m  / \033[32m$$$$$$$$\033[35m |\033[32m$$\033[35m |  \033[32m$$\033[35m |" << std::endl;
        std::cout << "\033[32m$$\033[35m \033[32m$$\033[35m\\\033[32m$$\033[35m |\033[32m$$\033[35m |  \033[32m$$\033[35m | \033[32m$$\033[35m  \033[32m$$\033[35m<  \033[32m$$\033[35m   ____|\033[32m$$\033[35m |  \033[32m$$\033[35m |" << std::endl;
        std::cout << "\\\033[32m$$$$$$\033[35m / \\\033[32m$$$$$$\033[35m  |\033[32m$$\033[35m  /\\\033[32m$$\033[35m\\ \\\033[32m$$$$$$$\033[35m\\ \033[32m$$\033[35m |  \033[32m$$\033[35m |" << std::endl;
        std::cout << " \\___\033[32m$$$\033[35m\\  \\______/ \\__/  \\__| \\_______|\\__|  \\__|" << std::endl;
        std::cout << "     \\___|                                        " << std::endl;
        std::cout << "\033[37m";

        std::cout << "\n\n\n         [";
        for (int j = 0; j < LOGO_len; j++) { std::cout << loader[j]; };
        std::cout << "]";
        loader[i] = '#';
        Sleep(100);
    }

    delete[] loader;
}

void changeColor(char theme[]) {

    char color_n;
    std::cin >> color_n;
    switch (color_n) {
    case 'p': {

    };
    default: {

    }
    }
}

// Work
int getInput(int _default) {
    char userInput[256];
    std::cin.getline(userInput, 256);
    // Check if the user pressed Enter without entering anything
    int intValue = _default;
    if (std::strlen(userInput) != 0) {
        intValue = 0;
        for (int i = 0; userInput[i] != '\0'; i++) {
            intValue = intValue * 10 + (int(userInput[i])-48);
        }
    }
    return intValue; // Convert char array to integer
    
}

// BOOK Section
struct Book {
    int id;
    char* title;
    char* author;
    int year;

public:
    void initialize(int _id, char* _title, const char* _author, int _year) {
        id = _id;

        title = new char[strlen(_title) + 1];
        for (int i = 0; i < strlen(_title); i++) {
            title[i] = _title[i];
        }

        author = new char[strlen(_author) + 1];
        for (int i = 0; i < strlen(_author); i++) {
            author[i] = _author[i];
        }

        year = _year;
    }
};

void loadBooks(Book*& books, int& count, char theme[]) {
    std::ifstream file("books.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening books.txt for reading." << std::endl;
    } else {

        char header[100];
        file.getline(header, sizeof(header));

        count = 0;
        while (file) {

            Book newBook; //temp book
            char buffer[256];

            // Read ID
            file >> newBook.id;
            if (!file) { break; } // Check for EOF

            file.ignore(256, char(29)); // Ignore the char(29)

            // Read title
            file.getline(buffer, sizeof(buffer), char(29));
            newBook.title = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) { 
                newBook.title[i] = buffer[i]; 
                newBook.title[i+1] = '\0'; // Ensure null-terminated
            }
            
            /*for (int j = 0; j < sizeof(buffer); j++) {
                buffer[j] = '\0';
            }*/

            // Read author
            file.getline(buffer, sizeof(buffer), char(29));
            newBook.author = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) { 
                newBook.author[i] = buffer[i];
                newBook.author[i+1] = '\0'; // Ensure null-terminated
            }

            // Read year
            file >> newBook.year;

            Book* newBooks = new Book[++count];

            // Manually copy the contents
            for (int i = 0; i < count - 1; i++) { newBooks[i] = books[i]; }

            newBooks[count - 1] = newBook;

            if (count != 1) { delete[] books; };

            books = newBooks;
        }
        file.close();
    }
}

void saveBooks(Book*& books, int& count) {
    std::ofstream file("books.txt", std::ios::out);
    file << "ID,Title,Author,Year\n";
    for (int i = 0; i < count; i++) {
        file << books[i].id << char(29) << books[i].title << char(29) << books[i].author << char(29) << books[i].year << '\n';
    }
    file.close();
}

void addBook(Book*& books, int& count, char theme[]) {
    
    Book newBook;
    char buffer[256];
    
    std::cin.ignore();
    while (true) {
        int idInput = -1;
        std::cout << "Enter book ID (press Enter for a random ID): ";
        idInput = getInput(-1);

        if (idInput != -1) {
            // Use the provided ID as an integer
            if (idInput >= 0) {
                for (int i = 0; i < count; i++) {
                    if (books[i].id == idInput && count != 0) {
                        std::cout << "Error: ID already exists. Exiting." << std::endl;
                        idInput = -1;
                        break;
                    }                     
                }
                if (idInput != -1) {
                    newBook.id = idInput;
                    break;
                }
            } else { std::cout << "ID < 0"; }
        } else {
            while (true) {
                idInput = (rand() % 999)+1;
                for (int j = 0; j < count; j++) {
                    if (books[j].id == idInput && count != 0) {
                        idInput = -1;
                        break; // ID already exists
                    }
                }
                if (idInput != -1) {
                    newBook.id = idInput;
                    break;
                }
            }
            newBook.id = idInput;
            std::cout << "Random ID generated: " << newBook.id << std::endl;
            break;
        }
    }

    std::cout << "Enter title: ";
    //std::cin.ignore(); // Clear the buffer
    std::cin.getline(buffer, sizeof(buffer));

    newBook.title = new char[strlen(buffer) + 1];
    for (int i = 0; i < strlen(buffer) + 1; i++) {
        newBook.title[i] = buffer[i];
        newBook.title[i + 1] = '\0'; // Ensure null-terminated
    }

    std::cout << "Enter author: ";
    std::cin.getline(buffer, sizeof(buffer));

    newBook.author = new char[strlen(buffer) + 1];
    for (int i = 0; i < strlen(buffer) + 1; i++) {
        newBook.author[i] = buffer[i];
        newBook.author[i + 1] = '\0'; // Ensure null-terminated
    }

    std::cout << "Enter year: ";
    newBook.year = getInput(0);

    Book* newBooks;
    newBooks = new Book[++count];

    // Manually copy the contents
    for (int i = 0; i < count - 1; i++) {
        newBooks[i] = books[i];
    }

    newBooks[count - 1] = newBook;

    if (count != 1) { delete[] books; };

    books = newBooks;

    saveBooks(books, count);
    std::cout << "Book added successfully." << std::endl;
    Sleep(500);
}

void changeBook(Book*& books, int& count, char theme[]) {

    int bookId;
    std::cout << "Enter the ID of the book to change: ";
    std::cin >> bookId;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].id == bookId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        char buffer[256];

        std::cout << "Enter title: ";
        std::cin.ignore(); // Clear the buffer
        std::cin.getline(buffer, sizeof(buffer));

        if (strlen(buffer) != 0) {
            books[index].title = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) {
                books[index].title[i] = buffer[i];
                books[index].title[i + 1] = '\0'; // Ensure null-terminated
            }
        }

        std::cout << "Enter author: ";
        std::cin.getline(buffer, sizeof(buffer));

        if (strlen(buffer) != 0) {
            books[index].author = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) {
                books[index].author[i] = buffer[i];
                books[index].author[i + 1] = '\0'; // Ensure null-terminated
            }

        }

        std::cout << "Enter year: ";
        int bookYear = getInput(-1);
        if (bookYear != -1) {
            books[index].year = bookYear;
        }

        saveBooks(books, count);
        std::cout << "Book changed successfully." << std::endl;
        Sleep(500);
    }
    else {
        std::cout << "Book not found." << std::endl;
        Sleep(500);
    }
}

void sortBooks(Book*& books, int& count, char theme[]) {

    for (int i =0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (books[j].id > books[j + 1].id) {
                std::swap(books[j], books[j + 1]);
            }
        }
    }


    std::cout << "::Save sorted table of books to file? [y/N]\n" << " >";
    char ans[2] = { '\0' };
    std::cin.ignore();
    std::cin.getline(ans, sizeof(ans));
    if (ans[0] == 'y' || ans[0] == 'Y') {
        saveBooks(books, count);
        std::cout << "\nBooks saved successfully." << std::endl;
        Sleep(500);
    }
}

void deleteBook(Book*& books, int& count, char theme[]) {
    int bookId;
    std::cout << "Enter the ID of the book to delete: ";
    std::cin >> bookId;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (books[i].id == bookId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Free memory for title and author
        books[index].title = nullptr;
        delete[] books[index].title;
        books[index].author = nullptr;
        delete[] books[index].author;

        // Shift remaining books to fill the gap
        for (int i = index; i < count - 1; i++) {
            books[i] = books[i + 1];
        }

            Book* newBooks = new Book[--count];

            // Manually copy the contents
            for (int i = 0; i < count; i++) {
                newBooks[i] = books[i];
            }

            delete[] books;
            books = newBooks;

        saveBooks(books, count);
        std::cout << "Book deleted successfully." << std::endl;
        Sleep(500);
    }
    else {
        std::cout << "Book not found." << std::endl;
        Sleep(500);
    }
}


struct User {
    int id;
    char* name;
    char* surname;
    int age;
    int book_id;
    char* time_user;

public:
    void initialize(int _id, const char* _name, const char* _surname, int _age, int _book_id, const char* _time_user) {
        id = _id;

        name = new char[strlen(_name) + 1];
        for (int i = 0; _name[i] != '\0'; i++) {
            name[i] = _name[i];
        }

        surname = new char[strlen(_surname) + 1];
        for (int i = 0; _surname[i] != '\0'; i++) {
            surname[i] = _surname[i];
        }

        age = _age;

        book_id = _book_id;

        time_user = new char[strlen(_time_user) + 1];
        for (int i = 0; _time_user[i] != '\0'; i++) {
            time_user[i] = _time_user[i];
        }
    }
};

void loadUsers(User*& users, int& count, char theme[]) {
    std::ifstream file("users.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening users.txt for reading." << std::endl;
        return;
    }

    char header[100];
    file.getline(header, sizeof(header));

    count = 0;
    while (file) {

        User newUser;
        char buffer[256];

        // Read ID
        file >> newUser.id;
        if (!file) break;  // Check for EOF

        file.ignore(256, char(29)); // Ignore the comma

        // Read name
        file.getline(buffer, sizeof(buffer), char(29));
        newUser.name = new char[strlen(buffer) + 1];
        for (int i = 0; i < strlen(buffer) + 1; i++) {
            newUser.name[i] = buffer[i];
            newUser.name[i+1] = '\0'; // Ensure null-terminated
        }

        // Read surname
        file.getline(buffer, sizeof(buffer), char(29));
        newUser.surname = new char[strlen(buffer) + 1];
        for (int i = 0; i < strlen(buffer) + 1; i++) {
            newUser.surname[i] = buffer[i];
            newUser.surname[i+1] = '\0'; // Ensure null-terminated
        }
        // Read age
        file >> newUser.age;

        // Skip the comma after age
        file.ignore(256, char(29));
        // Read book id
        file >> newUser.book_id;
        file.ignore(256, char(29));

        // Read time
        file.getline(buffer, sizeof(buffer));
        newUser.time_user = new char[strlen(buffer) + 1];
        for (int i = 0; i < strlen(buffer) + 1; i++) {
            newUser.time_user[i] = buffer[i];
            newUser.time_user[i+1] = '\0'; // Ensure null-terminated
        }

        User* newUsers;
        newUsers = new User[++count];

        // Manually copy the contents
        for (int j = 0; j < count - 1; j++) {
            newUsers[j] = users[j];
        }

        newUsers[count - 1] = newUser;


        if (count != 1) { delete[] users; };

        users = newUsers;

    }
    file.close();
}

void saveUsers(User users[], int count) {
    std::ofstream file("users.txt", std::ios::out);
    file << "ID,Name,Surname,Age,Book_id,Time_user\n";
    for (int i = 0; i < count; i++) {
        file << users[i].id << char(29) << users[i].name << char(29) << users[i].surname << char(29) << users[i].age << char(29) << users[i].book_id << char(29) << users[i].time_user << '\n';
    }
    file.close();
}

void addUser(User*& users, int& count, char theme[]) {

    User newUser;
    char buffer[256];

    std::cin.ignore();
    while (true) {
        int idInput = -1;
        std::cout << "Enter user ID (press Enter for a random ID): ";
        idInput = getInput(-1);

        if (idInput != -1) {
            // Use the provided ID as an integer
            if (idInput >= 0) {
                for (int i = 0; i < count; i++) {
                    if (users[i].id == idInput && count != 0) {
                        std::cout << "Error: ID already exists. Exiting." << std::endl;
                        idInput = -1;
                        break;
                    }
                }
                if (idInput != -1) {
                    newUser.id = idInput;
                    break;
                }
            }
            else { std::cout << "ID < 0"; }
        }
        else {
            while (true) {
                idInput = (rand() % 999) + 1;
                for (int j = 0; j < count; j++) {
                    if (users[j].id == idInput && count != 0) {
                        idInput = -1;
                        break; // ID already exists
                    }
                }
                if (idInput != -1) {
                    newUser.id = idInput;
                    break;
                }
            }
            newUser.id = idInput;
            std::cout << "Random ID generated: " << newUser.id << std::endl;
            break;
        }

    }

    std::cout << "Enter name: ";
    //std::cin.ignore(); // Clear the buffer
    std::cin.getline(buffer, sizeof(buffer));

    // User name
    newUser.name = new char[strlen(buffer) + 1];
    for (int i = 0; i < strlen(buffer) + 1; i++) {
        newUser.name[i] = buffer[i];
        newUser.name[i + 1] = '\0'; // Ensure null-terminated
    }

    std::cout << "Enter surname: ";
    std::cin.getline(buffer, sizeof(buffer));

    // User surname
    newUser.surname = new char[strlen(buffer) + 1];
    for (int i = 0; i < strlen(buffer)+1; i++) {
        newUser.surname[i] = buffer[i];
        newUser.surname[i + 1] = '\0'; // Ensure null-terminated
    }

    std::cout << "Enter age: ";
    newUser.age = getInput(0);

    std::cout << "Enter book ID (press Enter for skip): ";
    std::cin.ignore();
    newUser.book_id = getInput(-1);

    std::cout << "Enter time user: ";
    //std::cin.ignore(); // Clear the buffer
    std::cin.getline(buffer, sizeof(buffer));

    // User time_user
    newUser.time_user = new char[strlen(buffer) + 1];
    for (int i = 0; i < strlen(buffer) + 1; i++) {
        newUser.time_user[i] = buffer[i];
        newUser.time_user[i + 1] = '\0'; // Ensure null-terminated
    }

    User* newUsers;
    newUsers = new User[++count];

    // Manually copy the contents
    for (int i = 0; i < count - 1; i++) {
        newUsers[i] = users[i];
    }

    newUsers[count - 1] = newUser;


    if (count != 1) { delete[] users; };

    users = newUsers;
    saveUsers(users, count);
    std::cout << "User added successfully." << std::endl;
    Sleep(500);
}

void changeUser(User*& users, int& count, char theme[]) {
    int userId;
    std::cout << "Enter the ID of the user to delete: ";
    std::cin >> userId;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (users[i].id == userId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        char buffer[256];

        std::cout << "Enter name: ";
        std::cin.ignore(); // Clear the buffer
        std::cin.getline(buffer, sizeof(buffer));

        // User name
        if (strlen(buffer) != 0) {
            users[index].name = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) {
                users[index].name[i] = buffer[i];
                users[index].name[i + 1] = '\0'; // Ensure null-terminated
            }
        }

        std::cout << "Enter surname: ";
        std::cin.getline(buffer, sizeof(buffer));

        // User surname
        if (strlen(buffer) != 0) {
            users[index].surname = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) {
                users[index].surname[i] = buffer[i];
                users[index].surname[i + 1] = '\0'; // Ensure null-terminated
            }
        }

        std::cout << "Enter age: ";
        int userAge = getInput(-1);
        if (userAge != -1) {
            users[index].age = userAge;
        }

        std::cout << "Enter book ID (press Enter for skip): ";
        int bookId = getInput(-1);
        if (bookId != -1) {
            users[index].book_id = bookId;
        }

        std::cout << "Enter time user: ";
        std::cin.ignore(); // Clear the buffer
        std::cin.getline(buffer, sizeof(buffer));

        // User time_user
        if (strlen(buffer) != 0) {
            users[index].time_user = new char[strlen(buffer) + 1];
            for (int i = 0; i < strlen(buffer) + 1; i++) {
                users[index].time_user[i] = buffer[i];
                users[index].time_user[i + 1] = '\0'; // Ensure null-terminated
            }
        }

        saveUsers(users, count);
        std::cout << "User deleted successfully." << std::endl;
        Sleep(500);
    }
    else {
        std::cout << "User not found." << std::endl;
        Sleep(500);
    }
}

void sortUsers(User*& users, int& count, char theme[]) {

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (users[j].id > users[j + 1].id) {
                std::swap(users[j], users[j + 1]);
            }
        }
    }

    std::cout << "::Save sorted table of users to file? [y/N]\n" << " >";
    char ans[2] = { '\0' };
    std::cin.ignore();
    std::cin.getline(ans, sizeof(ans));
    if (ans[0] == 'y' || ans[0] == 'Y') {
        saveUsers(users, count);
        std::cout << "\nUsers saved successfully." << std::endl;
        Sleep(500);
    }

}

void deleteUser(User*& users, int& count, char theme[]) {
    int userId;
    std::cout << "Enter the ID of the user to delete: ";
    std::cin >> userId;
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (users[i].id == userId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Free memory for char*
        users[index].name = nullptr;
        delete[] users[index].name;
        users[index].surname = nullptr;
        delete[] users[index].surname;
        users[index].time_user = nullptr;
        delete[] users[index].time_user;

        // Shift remaining users to fill the gap
        for (int i = index; i < count - 1; i++) {
            users[i] = users[i + 1];
        }

        User* newUsers = new User[--count];

        // Manually copy the contents
        for (int i = 0; i < count; i++) {
            newUsers[i] = users[i];
        }

        delete[] users;
        users = newUsers;

        saveUsers(users, count);
        std::cout << "User deleted successfully." << std::endl;
        Sleep(500);
    }
    else {
        std::cout << "User not found." << std::endl;
        Sleep(500);
    }
}

// DISPLAY Section

void displayMenu(int bookCount, int userCount, char theme[]) {
    std::cout << theme[0] << "\n\n\n\n0. Exit\n";
    std::cout << "1. Add Book\n";
    if (bookCount > 0) { std::cout << "2. Change book\n"; }
    if (bookCount > 0) { std::cout << "3. Delete book\n"; }
    if (bookCount > 1) { std::cout << "4. Sort books\n"; }

    std::cout << "6. Add User\n";
    if (userCount > 0) { std::cout << "7. Change user\n"; }
    if (userCount > 0) { std::cout << "8. Delete user\n"; }
    if (userCount > 1) { std::cout << "9. Sort users\n"; }

    std::cout << "\n\n";
    std::cout << "Select option:\n" << " > ";
}

void displayUserTable(Book books[], User users[], int bookCount, int userCount, char theme[]) {
    std::cout.width(15);  std::cout << "\033[1m" << std::left << "Readers\033[0m" << "\n";
    std::cout.fill(char(205));
    std::cout.width(5+1);  std::cout << std::left << char(201); std::cout.width(30+1); std::cout << std::left << char(203); std::cout.width(40+1); std::cout << std::left << char(203); std::cout.width(20+1); std::cout << std::left << char(203) << char(187) << "\n";
    std::cout.fill(' ');
    std::cout << char(186); std::cout.width(5);  std::cout << std::left << "ID";
    std::cout << char(186); std::cout.width(30); std::cout << std::left << "Reader";
    std::cout << char(186); std::cout.width(40); std::cout << std::left << "[ID   | Title] Book in hands now";
    std::cout << char(186); std::cout.width(20); std::cout << std::left << "Book time from" << char(186) << std::endl;
    for (int i = 0; i < userCount; i++) {
        std::cout << char(186);
        std::cout.width(5); std::cout << std::left << users[i].id;
        std::cout << char(186);
        std::cout.width(strlen(users[i].name)); std::cout << std::left << users[i].name;
        std::cout.width(1); std::cout << " ";
        std::cout.width(strlen(users[i].surname)); std::cout << std::left << users[i].surname;
        std::cout.width(2); std::cout << ", ";
        std::cout.width(30 - 3 - strlen(users[i].name) - strlen(users[i].surname)); std::cout << std::left << users[i].age;
        std::cout << char(186); 
        std::cout.width(5); std::cout << std::left << users[i].book_id;
        std::cout.width(3); std::cout << " | ";
        bool book_check = true;
        for (int j = 0; j < bookCount; j++) {
            if (users[i].book_id == books[j].id) {
                if (int(books[j].title) != 0) {
                    std::cout.width(40 - 3 - 5); std::cout << std::left << books[j].title << char(186);
                    book_check = false;
                }
            }
        }
        if (book_check) {
            std::cout.width(40 + 1 - 3 - 5); std::cout << std::right << char(186);
        }

        std::cout.width(20); std::cout << std::left << users[i].time_user;
        std::cout << char(186) << std::endl;
    }
    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(200); std::cout.width(30 + 1); std::cout << std::left << char(202); std::cout.width(40 + 1); std::cout << std::left << char(202); std::cout.width(20 + 1); std::cout << std::left << char(202) << char(188) << "\n";
    std::cout.fill(' ');
}

void displayBookTable(Book books[], User users[], int bookCount, int userCount, char theme[]) {
    std::cout.width(15);  std::cout << "\033[1m" << std::left << "Books\033[0m\n";
    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(201); std::cout.width(30 + 1); std::cout << std::left << char(203); std::cout.width(30 + 1); std::cout << std::left << char(203); std::cout.width(30 + 1); std::cout << std::left << char(203) << char(187) << "\n";
    std::cout.fill(' ');
    std::cout << char(186); std::cout.width(5);  std::cout << std::left << "ID";
    std::cout << char(186); std::cout.width(30); std::cout << std::left << "Title";
    std::cout << char(186); std::cout.width(30); std::cout << std::left << "Author";
    std::cout << char(186); std::cout.width(30); std::cout << std::left << "Year" << char(186) << std::endl;
    for (int i = 0; i < bookCount; i++) {
        std::cout << char(186);
        std::cout.width(5); std::cout << std::left << books[i].id;
        std::cout << char(186); std::cout.width(30); std::cout << std::left << books[i].title;
        std::cout << char(186); std::cout.width(30); std::cout << std::left << books[i].author;
        std::cout << char(186); std::cout.width(30); std::cout << std::left << books[i].year << char(186) << std::endl;

    }

    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(200); std::cout.width(30 + 1); std::cout << std::left << char(202); std::cout.width(30 + 1); std::cout << std::left << char(202); std::cout.width(30 + 1); std::cout << std::left << char(202) << char(188) << "\n";
    std::cout.fill(' ');
}

int main() {

    Book* books = new Book[1];
    User* users = new User[1];

    int bookCount = 0;
    int userCount = 0;
    int choice;
    // char color_theme[] { "reset", "main text", "2nd text", "background", "table_border", "Success color", "Error Color" };
    // char color_theme[7] { '\033[0m', '\033[38;5;15m',   '\033[0m',  '\033[0m',    '\033[0m',      '\033[0m',        '\033[0m'    };
    char color_theme[7]{ '\033[0m', 'ESC[38;5;15m',   '\033[0m',  '\033[0m',    '\033[0m',      '\033[0m',        '\033[0m' };

    srand(time(0));
    loader(10); // load logo

    loadBooks(books, bookCount, color_theme);
    loadUsers(users, userCount, color_theme);

    do {
        std::system("cls");
        displayUserTable(books, users, bookCount, userCount, color_theme);
        displayBookTable(books, users, bookCount, userCount, color_theme);
        displayMenu(bookCount, userCount, color_theme);
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Exiting program." << std::endl;
            Sleep(500);
            break;
        case 1:
            addBook(books, bookCount, color_theme);
            break;
        case 2:
            changeBook(books, bookCount, color_theme);
            break;
        case 3:
            std::system("cls");
            displayBookTable(books, users, bookCount, userCount, color_theme);
            deleteBook(books, bookCount, color_theme);
            break;
        case 4:
            sortBooks(books, bookCount, color_theme);
            break;
        case 6:
            addUser(users, userCount, color_theme);
            break;
        case 7:
            changeUser(users, userCount, color_theme);
            break;
        case 8:
            std::system("cls");
            displayUserTable(books, users, bookCount, userCount, color_theme);
            deleteUser(users, userCount, color_theme);
            break;
        case 9:
            sortUsers(users, userCount, color_theme);
            break;
        case 69:
            changeColor(color_theme);
            break;
        case 99:
            loader(15);
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            Sleep(500);
        }
    } while (choice != 0);

    // Cleanup
    for (int i = 0; i < bookCount; i++) {
        books[i].title = nullptr;
        delete[] books[i].title;
        books[i].author = nullptr;
        delete[] books[i].author;
    }
    delete[] books;

    for (int i = 0; i < userCount; i++) {
        users[i].name = nullptr;
        delete[] users[i].name;
        users[i].surname = nullptr;
        delete[] users[i].surname;
        users[i].time_user = nullptr;
        delete[] users[i].time_user;
    }
    delete[] users;
}
