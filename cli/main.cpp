#include <iostream>
#include <string>
#include "../lib/app_version.h"

int main() {
    std::cout << "build " << patchVersion() << std::endl;
    std::cout << "Hello, World!" << std::endl;

    return 0;
}