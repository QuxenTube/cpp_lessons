#include <iostream>

int main() {
    std::string color_theme[] = { "\033[0m", "\033[1;37m", "\033[1;34m", "\033[48;5;235m", "\033[38;5;242m", "\033[1;32m", "\033[1;31m" };

    std::cout << color_theme[0] << "Reset" << std::endl;
    std::cout << color_theme[1] << "Main Text" << std::endl;
    std::cout << color_theme[2] << "2nd Text" << std::endl;
    std::cout << color_theme[3] << "Background" << std::endl;
    std::cout << color_theme[4] << "Table Border" << std::endl;
    std::cout << color_theme[5] << "Success Color" << std::endl;
    std::cout << color_theme[6] << "Error Color" << std::endl;

    return 0;
}
