void displayTable(Book books[], User users[], int bookCount, int userCount) {
    std::cout.width(5); std::cout << std::left << "ID";
    std::cout.width(20); std::cout << std::left << "Reader";
    std::cout.width(40); std::cout << std::left << "Book now [ID | Title]";
    std::cout.width(30); std::cout << std::left << "Book time from" << std::endl;
    for (int i = 0; i < userCount; i++) {
        std::cout.width(5); std::cout << std::left << users[i].id;
        std::cout.width(strlen(users[i].name)); std::cout << std::left << users[i].name;
        std::cout.width(1); std::cout << " ";
        std::cout.width(strlen(users[i].surname)); std::cout << std::left << users[i].surname;
        std::cout.width(2); std::cout << ", ";
        std::cout.width(20 - 3 - strlen(users[i].name) - strlen(users[i].surname)); std::cout << std::left << users[i].age;
        for (int j = 0; j < bookCount; j++) {
            if (users[i].id == books[j].id) {
                std::cout.width(40); std::cout << std::left << books[j].author << std::left << "|" << std::left << books[j].author;

            }
        }
    }
}