#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

const int MAX_BUFFER_LEN = 256;
const int LOGO_len = 20;

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

        author = new char[strlen(_author) + 1];
        i = 0;
        while (_author[i] != '\0') {
            author[i] = _author[i];
            ++i;
        }

        year = _year;
    }
};

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

//   DONE
void loader()
{

    const char logo_name[9][51] = {
    {"$$$$$$\\                                           "},
    {"$$  __$$\\                                         "},
    {"$$ /  $$ |$$\\   $$\\ $$\\   $$\\  $$$$$$\\  $$$$$$$\\  "},
    {"$$ |  $$ |$$ |  $$ |\\$$\\ $$  |$$  __$$\\ $$  __$$\\ "},
    {"$$ |  $$ |$$ |  $$ | \\$$$$  / $$$$$$$$ |$$ |  $$ |"},
    {"$$ $$\\$$ |$$ |  $$ | $$  $$<  $$   ____|$$ |  $$ |"},
    {"\\$$$$$$ / \\$$$$$$  |$$  /\\$$\\ \\$$$$$$$\\ $$ |  $$ |"},
    {" \\___$$$\\  \\______/ \\__/  \\__| \\_______|\\__|  \\__|"},
    {"     \\___|                                        "} };


    //const int len = 30;
    char loader[LOGO_len];
    for (int i = 0; i < LOGO_len; i++) { loader[i] = '-'; };

    for (int i = 0; i < LOGO_len; i++) {
        std::system("cls");

        //std::cout

        for (int k = 0; k < 9; k++) {
            for (int j = 0; j < 50; j++) {
                if (logo_name[k][j] == '$') {
                    std::cout << "\033[32m" << logo_name[k][j];
                }
                else /* if (logo_name[k][j] == '\\') */ {
                    std::cout << "\033[35m" << logo_name[k][j];
                }
                /*else {
                    std::cout << "\033[37m" << logo_name[k][j];
                }*/

                std::cout << "\033[37m";
            }
            std::cout << std::endl;
        }
        std::cout << "\n\n\n         [";
        for (int j = 0; j < LOGO_len; j++) { std::cout << loader[j]; };
        std::cout << "]";
        loader[i] = '#';
        Sleep(100);
    }
}

// Work
void saveBooks(Book books[], int count) {
    std::ofstream file("books.txt", std::ios::out);
    file << "ID,Title,Author,Year\n";
    for (int i = 0; i < count; ++i) {
        file << books[i].id << ',' << books[i].title << ',' << books[i].author << ',' << books[i].year << '\n';
    }
    file.close();
}

// try work
void loadBooks(Book*& books, int& count) {
    std::ifstream file("books.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error opening books.txt for reading." << std::endl;
        return;
    }

    char header[100];
    file.getline(header, sizeof(header));

    count = 0;
    while (file >> books[count].id) {
        file.ignore(); // Ignore the comma

        // Read title
        char bufferTitle[MAX_BUFFER_LEN];
        file.getline(bufferTitle, sizeof(bufferTitle), ',');
        books[count].title = new char[strlen(bufferTitle) + 1];
        int i = 0;
        for (i = 0; bufferTitle[i] != '\0'; ++i) {
            books[count].title[i] = bufferTitle[i];
        }
        books[count].title[i] = '\0'; // Ensure null-terminated

        /*
        while (bufferTitle[i] != '\0') {
            books[count].title[i] = bufferTitle[i];
            ++i;
        }
        */

        // Read author
        char bufferAuthor[MAX_BUFFER_LEN];
        file.getline(bufferAuthor, sizeof(bufferAuthor), ',');
        books[count].author = new char[strlen(bufferAuthor) + 1];
        /*
        i = 0;
        while (bufferAuthor[i] != '\0') {
            books[count].author[i] = bufferAuthor[i];
            ++i;
        }*/
        for (i = 0; bufferAuthor[i] != '\0'; ++i) {
            books[count].author[i] = bufferAuthor[i];
        }
        books[count].author[i] = '\0'; // Ensure null-terminated

        // Read year
        file >> books[count].year;

        ++count;
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
    while (file >> users[count].id) {
        int i = 0;

        // Read name
        char bufferName[MAX_BUFFER_LEN];
        file.getline(bufferName, sizeof(bufferName), ',');
        users[count].name = new char[strlen(bufferName) + 1];
        for (i = 0; bufferName[i] != '\0'; ++i) {
            users[count].name[i] = bufferName[i];
        }
        users[count].name[i] = '\0'; // Ensure null-terminated

        // Read surname
        char bufferSurname[MAX_BUFFER_LEN];
        file.getline(bufferSurname, sizeof(bufferSurname), ',');
        users[count].surname = new char[strlen(bufferSurname) + 1];
        for (i = 0; bufferSurname[i] != '\0'; ++i) {
            users[count].surname[i] = bufferSurname[i];
        }
        users[count].surname[i] = '\0'; // Ensure null-terminated

        // Read age
        file >> users[count].age;

        // Read book id
        file >> users[count].book_id;

        // Read time

        char bufferTime_user[MAX_BUFFER_LEN];
        file.getline(bufferTime_user, sizeof(bufferTime_user), ',');
        users[count].time_user = new char[strlen(bufferTime_user) + 1];

        for (i = 0; bufferTime_user[i] != '\0'; ++i) {
            users[count].time_user[i] = bufferTime_user[i];
        }
        users[count].time_user[i] = '\0'; // Ensure null-terminated

        ++count;
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

void addBook(Book books[], int& count) {
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
    char bufferTitle[MAX_BUFFER_LEN];
    std::cin.getline(bufferTitle, sizeof(bufferTitle));

    std::cout << "Enter author: ";
    char bufferAuthor[MAX_BUFFER_LEN];
    std::cin.getline(bufferAuthor, sizeof(bufferAuthor));

    std::cout << "Enter year: ";
    std::cin >> newBook.year;

    newBook.initialize(newBook.id, bufferTitle, bufferAuthor, newBook.year);


    books[count++] = newBook;
    saveBooks(books, count);
    std::cout << "Book added successfully." << std::endl;
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
        saveBooks(books, count);
    }
    else {
        std::cout << "Book not found." << std::endl;
    }
}


void addUser(User users[], int& count) {
    User newUser;

    // Incrementing userCount to get a unique ID
    newUser.initialize(count + 1, "", "", 0, 0, "");

    std::cout << "Enter name: ";
    char bufferName[MAX_BUFFER_LEN];
    std::cin.ignore(); // Clear the buffer
    std::cin.getline(bufferName, sizeof(bufferName));

    // Allocate memory for name and copy the content
    newUser.name = new char[strlen(bufferName) + 1];
    int i = 0;
    while (bufferName[i] != '\0') {
        newUser.name[i] = bufferName[i];
        ++i;
    }
    newUser.name[i] = '\0'; // Ensure null-terminated

    std::cout << "Enter surname: ";
    char bufferSurname[MAX_BUFFER_LEN];
    std::cin.getline(bufferSurname, sizeof(bufferSurname));

    // Allocate memory for surname and copy the content
    newUser.surname = new char[strlen(bufferSurname) + 1];
    i = 0;
    while (bufferSurname[i] != '\0') {
        newUser.surname[i] = bufferSurname[i];
        ++i;
    }
    newUser.surname[i] = '\0'; // Ensure null-terminated

    std::cout << "Enter age: ";
    std::cin >> newUser.age;

    std::cout << "Enter book ID: ";
    std::cin >> newUser.book_id;

    std::cout << "Enter time user: ";
    char bufferTimeUser[MAX_BUFFER_LEN];
    std::cin.ignore(); // Clear the buffer
    std::cin.getline(bufferTimeUser, sizeof(bufferTimeUser));

    // Allocate memory for time_user and copy the content
    newUser.time_user = new char[strlen(bufferTimeUser) + 1];
    i = 0;
    while (bufferTimeUser[i] != '\0') {
        newUser.time_user[i] = bufferTimeUser[i];
        ++i;
    }
    newUser.time_user[i] = '\0'; // Ensure null-terminated

    users[count++] = newUser;
    std::cout << "User added successfully." << std::endl;
}

void displayBooks(Book books[], int count) {
    std::cout << std::left << std::setw(5) << "ID" << std::setw(20) << "Title" << std::setw(20) << "Author" << std::setw(10) << "Year" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << std::left << std::setw(5) << books[i].id << std::setw(20) << books[i].title << std::setw(20) << books[i].author << std::setw(10) << books[i].year << std::endl;
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

    //srand(time(0));
    loader(); // load logo

    Book* books = nullptr;
    User* users = nullptr;

    int bookCount = 0;
    int userCount = 0;

    loadBooks(books, bookCount);
    loadUsers(users, userCount);

    // Dynamically allocate memory based on the actual number of books and users
    Book* newBooks = new Book[bookCount];
    std::copy(books, books + bookCount, newBooks);
    delete[] books;
    books = newBooks;

    User* newUsers = new User[userCount];
    std::copy(users, users + userCount, newUsers);
    delete[] users;
    users = newUsers;

    //displayBooks(books, bookCount);
    /*
    std::cout << std::endl << sizeof(books) << std::endl;
    std::cout << sizeof(Book) << std::endl;
    std::cout << sizeof(users) << std::endl;
    std::cout << sizeof(User) << std::endl;
    Sleep(1000);
    */

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

}
