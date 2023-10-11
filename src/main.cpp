#include <iostream>
#include "shellBrowser.hpp"

int main(int argc, char **argv)
{
    return !shellBrowser(argc == 2 ? argv[1] : "") ? 1 : 0;
};