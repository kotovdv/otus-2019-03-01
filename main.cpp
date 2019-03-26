#include <iostream>
#include "version/app_version.h"
#include <string>

int main() {
    std::cout << "build " << patchVersion() << std::endl;
    std::cout << "Hello, World!";

    return 0;
}