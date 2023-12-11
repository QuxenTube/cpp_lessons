void displayTable(Book books[], User users[], int bookCount, int userCount) {
    std::cout << std::left << std::setw(5) << "ID" << std::setw(30) << "Reader" << std::setw(40) << "Book now [ID | Title]" << std::setw(10) << "Book time from" << std::endl;
    for (int i = 0; i < userCount; i++) {
        std::cout << std::left << std::setw(5) << users[i].id;
        std::cout.width(40);
        std::cout /*<< std::setw(30)*/ << users[i].name << " " << users[i].surname << ", " << users[i].age;
        for (int j = 0; j < bookCount; j++) {
            if (users[i].id == books[j].id) {
                std::cout << std::setw(20) << books[j].author << "|" << books[j].author;

            }
        }
        //<< std::setw(20) << books[i].author << std::setw(10) << books[i].year << std::endl;
    }
}