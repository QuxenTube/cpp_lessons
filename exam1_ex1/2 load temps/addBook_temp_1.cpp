void addBook(Book*& books, int& count) {
    Book* newBooks = new Book[++count];

    // Manually copy the contents
    for (int i = 0; i < count - 1; i++) {
        newBooks[i] = books[i];
    }

    /*newBooks[count] = Book();
    Book& newBook = newBooks[count];*/
    Book newBook;

    int idInput = 0;
    do {
        std::cout << "Enter ID (0 for a random ID): ";
        std::cin >> idInput;

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
            newBook.id = rand() % 1000;
            std::cout << "Random ID generated: " << newBook.id << std::endl;
        }
    } while (book_isIdExists(books, count, newBook.id));

    // Gather other book information
    std::cout << "Enter title: ";
    char bufferTitle[256];
    std::cin.ignore(); // Clear the buffer
    std::cin.getline(bufferTitle, sizeof(bufferTitle));

    newBook.title = new char[strlen(bufferTitle) + 1];
    int i = 0;
    while (bufferTitle[i] != '\0') {
        newBook.title[i] = bufferTitle[i];
        ++i;
    }

    std::cout << "Enter author: ";
    char bufferAuthor[256];
    std::cin.getline(bufferAuthor, sizeof(bufferAuthor));

    newBook.author = new char[strlen(bufferAuthor) + 1];
    i = 0;
    while (bufferAuthor[i] != '\0') {
        newBook.author[i] = bufferAuthor[i];
        ++i;
    }

    std::cout << "Enter year: ";
    std::cin >> newBook.year;

    newBooks[count] = newBook;

    delete[] books;
    books = newBooks;

    //++count;
    saveBooks(books, count);
    std::cout << "Book added successfully." << std::endl;
}