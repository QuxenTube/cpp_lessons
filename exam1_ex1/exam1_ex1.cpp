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

int getInput() {
    char userInput[256];

    //std::cout << "Enter something (press Enter for default): ";
    std::cin.ignore();
    std::cin.getline(userInput, 256);

    // Check if the user pressed Enter without entering anything
    if (std::strlen(userInput) == 0) {
        return 0;
    }

    int intValue = 0;
    for (int i = 0; userInput[i] != '\0'; i++) {
        intValue = intValue * 10 + (int(userInput[i]));
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
        int i = 0;
        while (_title[i] != '\0') {
            title[i] = _title[i];
            ++i;
        }

        author = new char[strlen(_author) + 1];
        i = 0;
        while (_author[i] != '\0') {
            author[i] = _author[i];
            ++i;
        }

        year = _year;
    }
};


// Work
void loadBooks(Book*& books, int& count) {
    std::ifstream file("books.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening books.txt for reading." << std::endl;
        return;
    }

    char header[100];
    file.getline(header, sizeof(header));

    count = 0;
    while (file) {

        Book newBook;

        // Read ID
        file >> newBook.id;
        if (!file) break;  // Check for EOF

        file.ignore(); // Ignore the comma

        // Read title
        char bufferTitle[256];
        file.getline(bufferTitle, sizeof(bufferTitle), ',');
        newBook.title = new char[strlen(bufferTitle) + 1];
        int i = 0;
        for (i = 0; bufferTitle[i] != '\0'; ++i) {
            newBook.title[i] = bufferTitle[i];
        }
        newBook.title[i] = '\0'; // Ensure null-terminated

        // Read author
        char bufferAuthor[256];
        file.getline(bufferAuthor, sizeof(bufferAuthor), ',');
        newBook.author = new char[strlen(bufferAuthor) + 1];
        for (i = 0; bufferAuthor[i] != '\0'; ++i) {
            newBook.author[i] = bufferAuthor[i];
        }
        newBook.author[i] = '\0'; // Ensure null-terminated

        // Read year
        file >> newBook.year;

        Book* newBooks;
        newBooks = new Book[++count];

        // Manually copy the contents
        for (int i = 0; i < count - 1; i++) {
            newBooks[i] = books[i];
        }

        newBooks[count - 1] = newBook;


        if (count != 1) { delete[] books; };

        books = newBooks;
    }

    file.close();
}

// Work
void saveBooks(Book*& books, int& count) {
    std::ofstream file("books.txt", std::ios::out);
    file << "ID,Title,Author,Year\n";
    for (int i = 0; i < count; ++i) {
        file << books[i].id << ',' << books[i].title << ',' << books[i].author << ',' << books[i].year << '\n';
    }
    file.close();
}

// custom ID checker
bool book_isIdExists(const Book books[], int count, int idToCheck) {
    for (int i = 0; i < count; ++i) {
        if (books[i].id == idToCheck) {
            return true; // ID already exists
        }
    }
    return false; // ID does not exist
}

// Work
void addBook(Book*& books, int& count) {
    
    Book newBook;
    

    int idInput = 0;
    std::cout << "Enter book ID (press Enter for a random ID): ";
    idInput = getInput();
    //std::cin >> idInput;
    do {

        if (idInput != 0) {
            // Use the provided ID as an integer
            if (book_isIdExists(books, count, idInput)) {
                std::cout << "Error: ID already exists. Exiting." << std::endl;
                return;
            }
            newBook.id = idInput;
        }
        else {
            // If ID is not provided, generate a random ID
            bool checker = true;
            int id_try;
            while (checker) {
                id_try = rand() % 1000;
                checker = book_isIdExists(books, count, id_try);
            }
            newBook.id = id_try;
            std::cout << "Random ID generated: " << newBook.id << std::endl;
        }
    } while (book_isIdExists(books, count, newBook.id));

    // Gather other book information
    std::cout << "Enter title: ";
    char bufferTitle[256];
    //std::cin.ignore(); // Clear the buffer
    std::cin.getline(bufferTitle, sizeof(bufferTitle));

    newBook.title = new char[strlen(bufferTitle) + 1];
    int i = 0;
    while (bufferTitle[i] != '\0') {
        newBook.title[i] = bufferTitle[i];
        ++i;
    }
    newBook.title[i] = '\0';

    std::cout << "Enter author: ";
    char bufferAuthor[256];
    std::cin.getline(bufferAuthor, sizeof(bufferAuthor));

    newBook.author = new char[strlen(bufferAuthor) + 1];
    i = 0;
    while (bufferAuthor[i] != '\0') {
        newBook.author[i] = bufferAuthor[i];
        ++i;
    }
    newBook.author[i] = '\0';

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

    for (int i =0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (books[j].id > books[j + 1].id) {
                std::swap(books[j], books[j + 1]);
            }
        }
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

        int i = 0;
        name = new char[strlen(_name) + 1];
        while (_name[i] != '\0') {
            name[i] = _name[i];
            ++i;
        }

        i = 0;
        surname = new char[strlen(_surname) + 1];
        while (_surname[i] != '\0') {
            surname[i] = _surname[i];
            ++i;
        }

        age = _age;

        book_id = _book_id;

        i = 0;
        time_user = new char[strlen(_time_user) + 1];
        while (_time_user[i] != '\0') {
            time_user[i] = _time_user[i];
            ++i;
        }
        time_user[i] = '\0'; // Ensure null-terminated
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

        file.ignore(); // Ignore the comma

        // Read name
        char bufferName[256];
        file.getline(bufferName, sizeof(bufferName), ',');
        newUser.name = new char[strlen(bufferName) + 1];
        int i = 0;
        for (i = 0; bufferName[i] != '\0'; ++i) {
            newUser.name[i] = bufferName[i];
        }
        newUser.name[i] = '\0'; // Ensure null-terminated

        // Read surname
        char bufferSurname[256];
        file.getline(bufferSurname, sizeof(bufferSurname), ',');
        newUser.surname = new char[strlen(bufferSurname) + 1];
        for (i = 0; bufferSurname[i] != '\0'; ++i) {
            newUser.surname[i] = bufferSurname[i];
        }
        newUser.surname[i] = '\0'; // Ensure null-terminated
        // Read age
        file >> newUser.age;

        // Skip the comma after age
        file.ignore();
        // Read book id
        file >> newUser.book_id;
        file.ignore();

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
        file << users[i].id << ',' << users[i].name << ',' << users[i].surname << ',' << users[i].age << ',' << users[i].book_id << ',' << users[i].time_user << '\n';
    }
    file.close();
}

bool user_isIdExists(const User users[], int count, int idToCheck) {
    for (int i = 0; i < count; ++i) {
        if (users[i].id == idToCheck) {
            return true; // ID already exists
        }
    }
    return false; // ID does not exist
}

void addUser(User*& users, int& count) {

    User newUser;

    int idInput = 0;
    std::cout << "Enter user ID (press Enter for a random ID): ";
    idInput = getInput();
    //std::cin >> idInput;
    do {

        if (idInput != 0) {
            // Use the provided ID as an integer
            if (user_isIdExists(users, count, idInput)) {
                std::cout << "Error: ID already exists. Exiting." << std::endl;
                return;
            }
            newUser.id = idInput;
        }
        else {
            // If ID is not provided, generate a random ID
            bool checker = true;
            int id_try;
            while (checker) {
                id_try = rand() % 1000;
                checker = user_isIdExists(users, count, id_try);
            }
            newUser.id = id_try;
            std::cout << "Random ID generated: " << newUser.id << std::endl;
        }
    } while (user_isIdExists(users, count, newUser.id));

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
    std::cout << "\n\n\n\n0. Exit\n";
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
    std::cout.width(5+1);  std::cout << std::left << char(201); std::cout.width(20+1); std::cout << std::left << char(203); std::cout.width(40+1); std::cout << std::left << char(203); std::cout.width(30+1); std::cout << std::left << char(203) << char(187) << "\n";
    std::cout.fill(' ');
    std::cout << char(186); std::cout.width(5);  std::cout << std::left << "ID";
    std::cout << char(186); std::cout.width(20); std::cout << std::left << "Reader";
    std::cout << char(186); std::cout.width(40); std::cout << std::left << "[ID   | Title] Book in hands now";
    std::cout << char(186); std::cout.width(30); std::cout << std::left << "Book time from" << char(186) << std::endl;
    for (int i = 0; i < userCount; i++) {
        std::cout << char(186);
        std::cout.width(5); std::cout << std::left << users[i].id;
        std::cout << char(186);
        std::cout.width(strlen(users[i].name)); std::cout << std::left << users[i].name;
        std::cout.width(1); std::cout << " ";
        std::cout.width(strlen(users[i].surname)); std::cout << std::left << users[i].surname;
        std::cout.width(2); std::cout << ", ";
        std::cout.width(20 - 3 - strlen(users[i].name) - strlen(users[i].surname)); std::cout << std::left << users[i].age;
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

        std::cout.width(30); std::cout << std::left << users[i].time_user;
        std::cout << char(186) << std::endl;
    }
    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(200); std::cout.width(20 + 1); std::cout << std::left << char(202); std::cout.width(40 + 1); std::cout << std::left << char(202); std::cout.width(30 + 1); std::cout << std::left << char(202) << char(188) << "\n";
    std::cout.fill(' ');
}

void displayBookTable(Book books[], User users[], int bookCount, int userCount) {
    std::cout.width(15);  std::cout << "\033[1m" << std::left << "Books\033[0m\n";
    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(201); std::cout.width(20 + 1); std::cout << std::left << char(203); std::cout.width(40 + 1); std::cout << std::left << char(203); std::cout.width(30 + 1); std::cout << std::left << char(203) << char(187) << "\n";
    std::cout.fill(' ');
    std::cout << char(186); std::cout.width(5);  std::cout << std::left << "ID";
    std::cout << char(186); std::cout.width(20); std::cout << std::left << "Title";
    std::cout << char(186); std::cout.width(40); std::cout << std::left << "Author";
    std::cout << char(186); std::cout.width(30); std::cout << std::left << "Year" << char(186) << std::endl;
    for (int i = 0; i < bookCount; i++) {
        std::cout << char(186);
        std::cout.width(5); std::cout << std::left << books[i].id;
        std::cout << char(186); std::cout.width(20); std::cout << std::left << books[i].title;
        std::cout << char(186); std::cout.width(40); std::cout << std::left << books[i].author;
        std::cout << char(186); std::cout.width(30); std::cout << std::left << books[i].year << char(186) << std::endl;

    }

    std::cout.fill(char(205));
    std::cout.width(5 + 1);  std::cout << std::left << char(200); std::cout.width(20 + 1); std::cout << std::left << char(202); std::cout.width(40 + 1); std::cout << std::left << char(202); std::cout.width(30 + 1); std::cout << std::left << char(202) << char(188) << "\n";
    std::cout.fill(' ');
}

int main() {

    Book* books = new Book[1];
    User* users = new User[1];

    int bookCount = 0;
    int userCount = 0;

    srand(time(0));
    loader(10); // load logo

    loadBooks(books, bookCount);
    loadUsers(users, userCount);

    int choice;
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
