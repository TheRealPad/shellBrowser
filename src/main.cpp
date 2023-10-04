#include <iostream>
#include "shellBrowser.hpp"

int main(int argc, char **argv) {
    return !shellBrowser() ? 1 : 0;
};