#include "foo.hpp"

extern "C" {
    int testFunc() {
        std::cout << "how are you?" << std::endl;
        return 5;
    }
}