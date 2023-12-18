#include <iostream>
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

void changeColor() {

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
int getInput() {
    char userInput[256];
    std::cin.getline(userInput, 256);
    // Check if the user pressed Enter without entering anything
    int intValue = -1;
    if (std::strlen(userInput) != 0) {
        intValue = 0;
        for (int i = 0; userInput[i] != '\0'; i++) {
            intValue = intValue * 10 + (int(userInput[i]) - 48);
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

        for (int i = 0; _title[i] != '\0'; i++) {
            title[i] = _title[i];
        }

        author = new char[strlen(_author) + 1];
        for (int i = 0; _author[i] != '\0'; i++) {
            author[i] = _author[i];
        }

        year = _year;
    }
};


// Work
void loadBooks(Book*& books, int& count) {
    std::ifstream file("books.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening books.txt for reading." << std::endl;
    }
    else {

        char header[100];
        file.getline(header, sizeof(header));

        count = 0;
        while (file) {

            Book newBook; //temp book

            char bufferTitle[256];
            char bufferAuthor[256];

            // Read ID
            file >> newBook.id;
            if (!file) { break; } // Check for EOF

            file.ignore(256, char(29)); // Ignore the char(29)

            // Read title
            file.getline(bufferTitle, sizeof(bufferTitle), char(29));
            newBook.title = new char[strlen(bufferTitle) + 1];
            for (int i = 0; bufferTitle[i] != '\0'; i++) {
                newBook.title[i] = bufferTitle[i];
                newBook.title[i + 1] = '\0'; // Ensure null-terminated
            }

            // Read author
            file.getline(bufferAuthor, sizeof(bufferAuthor), char(29));
            newBook.author = new char[strlen(bufferAuthor) + 1];
            for (int i = 0; bufferAuthor[i] != '\0'; i++) {
                newBook.author[i] = bufferAuthor[i];
                newBook.author[i + 1] = '\0'; // Ensure null-terminated
            }

            // Read year
            file >> newBook.year;

            Book* newBooks;
            newBooks = new Book[++count];

            // Manually copy the contents
            for (int i = 0; i < count - 1; i++) { newBooks[i] = books[i]; }

            newBooks[count - 1] = newBook;

            if (count != 1) { delete[] books; };

            books = newBooks;
        }
        file.close();
    }
}

// Work
void saveBooks(Book*& books, int& count) {
    std::ofstream file("books.txt", std::ios::out);
    file << "ID,Title,Author,Year\n";
    for (int i = 0; i < count; ++i) {
        file << books[i].id << char(29) << books[i].title << char(29) << books[i].author << char(29) << books[i].year << '\n';
    }
    file.close();
}

// Work
void addBook(Book*& books, int& count) {

    Book newBook;

    char bufferTitle[256];
    char bufferAuthor[256];

    std::cin.ignore();
    while (true) {
        int idInput = -1;
        std::cout << "Enter book ID (press Enter for a random ID): ";
        idInput = getInput();

        if (idInput != -1) {
            // Use the provided ID as an integer
            if (idInput >= 0) {
                for (int i = 0; i < count; ++i) {
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
            }
            else { std::cout << "ID < 0"; }
        }
        else {
            while (true) {
                idInput = (rand() % 999) + 1;
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
    std::cin.getline(bufferTitle, sizeof(bufferTitle));

    newBook.title = new char[strlen(bufferTitle) + 1];
    for (int i = 0; bufferTitle[i] != '\0'; i++) {
        newBook.title[i] = bufferTitle[i];
        newBook.title[i + 1] = '\0'; // Ensure null-terminated
    }

    std::cout << "Enter author: ";
    std::cin.getline(bufferAuthor, sizeof(bufferAuthor));

    newBook.author = new char[strlen(bufferAuthor) + 1];
    for (int i = 0; bufferAuthor[i] != '\0'; i++) {
        newBook.author[i] = bufferAuthor[i];
        newBook.author[i + 1] = '\0'; // Ensure null-terminated
    }

    std::cout << "Enter year: ";
    std::cin >> newBook.year;

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
}

//
void changeBook(Book*& books, int& count) {



}

void sortBooks(Book*& books, int& count) {

    for (int i = 0; i < count; i++) {
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
    }
}

// Work
void deleteBook(Book*& books, int& count) {
    int bookId;
    std::cout << "Enter the ID of the book to delete: ";
    std::cin >> bookId;
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

        Book* newBooks = new Book[--count];

        // Manually copy the contents
        for (int i = 0; i < count; ++i) {
            newBooks[i] = books[i];
        }

        delete[] books;
        books = newBooks;

        saveBooks(books, count);
        std::cout << "Book deleted successfully." << std::endl;
    }
    else {
        std::cout << "Book not found." << std::endl;
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

//try work
void loadUsers(User*& users, int& count) {
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

        // Read ID
        file >> newUser.id;
        if (!file) break;  // Check for EOF

        file.ignore(256, char(29)); // Ignore the comma

        // Read name
        char bufferName[256];
        file.getline(bufferName, sizeof(bufferName), char(29));
        newUser.name = new char[strlen(bufferName) + 1];
        int i = 0;
        for (i = 0; bufferName[i] != '\0'; ++i) {
            newUser.name[i] = bufferName[i];
        }
        newUser.name[i] = '\0'; // Ensure null-terminated

        // Read surname
        char bufferSurname[256];
        file.getline(bufferSurname, sizeof(bufferSurname), char(29));
        newUser.surname = new char[strlen(bufferSurname) + 1];
        for (i = 0; bufferSurname[i] != '\0'; ++i) {
            newUser.surname[i] = bufferSurname[i];
        }
        newUser.surname[i] = '\0'; // Ensure null-terminated
        // Read age
        file >> newUser.age;

        // Skip the comma after age
        file.ignore(256, char(29));
        // Read book id
        file >> newUser.book_id;
        file.ignore(256, char(29));

        // Read time

        char bufferTime_user[256];
        file.getline(bufferTime_user, sizeof(bufferTime_user));
        newUser.time_user = new char[strlen(bufferTime_user) + 1];

        for (i = 0; bufferTime_user[i] != '\0'; ++i) {
            newUser.time_user[i] = bufferTime_user[i];
        }
        newUser.time_user[i] = '\0'; // Ensure null-terminated

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

//try work
void saveUsers(User users[], int count) {
    std::ofstream file("users.txt", std::ios::out);
    file << "ID,Name,Surname,Age,Book_id,Time_user\n";
    for (int i = 0; i < count; ++i) {
        file << users[i].id << char(29) << users[i].name << char(29) << users[i].surname << char(29) << users[i].age << char(29) << users[i].book_id << char(29) << users[i].time_user << '\n';
    }
    file.close();
}

void addUser(User*& users, int& count) {

    User newUser;

    std::cin.ignore();
    while (true) {
        int idInput = -1;
        std::cout << "Enter user ID (press Enter for a random ID): ";
        idInput = getInput();

        if (idInput != -1) {
            // Use the provided ID as an integer
            if (idInput >= 0) {
                for (int i = 0; i < count; ++i) {
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
    char bufferName[256];
    //std::cin.ignore(); // Clear the buffer
    std::cin.getline(bufferName, sizeof(bufferName));

    // User name
    newUser.name = new char[strlen(bufferName) + 1];
    int i = 0;
    while (bufferName[i] != '\0') {
        newUser.name[i] = bufferName[i];
        ++i;
    }
    newUser.name[i] = '\0'; // Ensure null-terminated

    std::cout << "Enter surname: ";
    char bufferSurname[256];
    std::cin.getline(bufferSurname, sizeof(bufferSurname));

    // User surname
    newUser.surname = new char[strlen(bufferSurname) + 1];
    i = 0;
    while (bufferSurname[i] != '\0') {
        newUser.surname[i] = bufferSurname[i];
        ++i;
    }
    newUser.surname[i] = '\0'; // Ensure null-terminated

    std::cout << "Enter age: ";
    std::cin >> newUser.age;

    std::cout << "Enter book ID (press Enter for skip): ";
    std::cin.ignore();
    newUser.book_id = getInput();
    //std::cin >> newUser.book_id;

    std::cout << "Enter time user: ";
    char bufferTimeUser[256];
    std::cin.ignore(); // Clear the buffer
    std::cin.getline(bufferTimeUser, sizeof(bufferTimeUser));

    // User time_user
    newUser.time_user = new char[strlen(bufferTimeUser) + 1];
    i = 0;
    while (bufferTimeUser[i] != '\0') {
        newUser.time_user[i] = bufferTimeUser[i];
        ++i;
    }
    newUser.time_user[i] = '\0'; // Ensure null-terminated

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
}

void sortUsers(User*& users, int& count) {

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
    }

}

void deleteUser(User*& users, int& count) {
    int userId;
    std::cout << "Enter the ID of the book to delete: ";
    std::cin >> userId;
    int index = -1;
    for (int i = 0; i < count; ++i) {
        if (users[i].id == userId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Free memory for char*
        delete[] users[index].name;
        delete[] users[index].surname;
        delete[] users[index].time_user;

        // Shift remaining users to fill the gap
        for (int i = index; i < count - 1; ++i) {
            users[i] = users[i + 1];
        }

        User* newUsers = new User[--count];

        // Manually copy the contents
        for (int i = 0; i < count; ++i) {
            newUsers[i] = users[i];
        }

        delete[] users;
        users = newUsers;

        saveUsers(users, count);
        std::cout << "User deleted successfully." << std::endl;
    }
    else {
        std::cout << "User not found." << std::endl;
    }
}



// DISPLAY Section

void displayMenu(int bookCount, int userCount) {
    std::cout << "\033[0m" << "\n\n\n\n0. Exit\n";
    std::cout << "1. Add Book\n";
    if (bookCount > 0) { std::cout << "2. Change book\n"; }
    if (bookCount > 0) { std::cout << "3. Delete book\n"; }
    if (bookCount > 1) { std::cout << "4. Sort books\n"; }

    std::cout << "6. Add User\n";
    if (userCount > 0) { std::cout << "7. Change user\n"; }
    if (userCount > 0) { std::cout << "8. Delete user\n"; }
    if (userCount > 1) { std::cout << "9. Sort users\n"; }

    std::cout << "\n\n";
    std::cout << "Select option: ";
}

void displayUserTable(Book books[], User users[], int bookCount, int userCount) {
    std::cout.width(15);  std::cout << "\033[1m" << std::left << "Readers\033[0m" << "\n";
    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(201); std::cout.width(30 + 1); std::cout << std::left << char(203); std::cout.width(40 + 1); std::cout << std::left << char(203); std::cout.width(20 + 1); std::cout << std::left << char(203) << char(187) << "\n";
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

void displayBookTable(Book books[], User users[], int bookCount, int userCount) {
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
    // char color_theme[] {"number of ", "reset", "main text", "2nd text", "background", "table_border"};
    char color_theme[10];

    srand(time(0));
    loader(10); // load logo

    loadBooks(books, bookCount);
    loadUsers(users, userCount);

    do {
        std::system("cls");
        displayUserTable(books, users, bookCount, userCount);
        displayBookTable(books, users, bookCount, userCount);
        displayMenu(bookCount, userCount);
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        case 1:
            addBook(books, bookCount);
            break;
            /*case 2:
                changeBook(books, bookCount);
                break;*/
        case 3:
            std::system("cls");
            displayBookTable(books, users, bookCount, userCount);
            deleteBook(books, bookCount);
            break;
        case 4:
            sortBooks(books, bookCount);
            break;
        case 6:
            addUser(users, userCount);
            break;
            /*case 7:
                changeUser(users, userCount);
                break;*/
        case 8:
            std::system("cls");
            displayUserTable(books, users, bookCount, userCount);
            deleteUser(users, userCount);
            break;
        case 9:
            sortUsers(users, userCount);
            break;
        case 99:
            loader(15);
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    } while (choice != 0);

    // Cleanup
    for (int i = 0; i < bookCount; ++i) {
        delete[] books[i].title;
        delete[] books[i].author;
    }
    delete[] books;

    for (int i = 0; i < userCount; ++i) {
        delete[] users[i].name;
        delete[] users[i].surname;
        delete[] users[i].time_user;
    }
    delete[] users;
}
