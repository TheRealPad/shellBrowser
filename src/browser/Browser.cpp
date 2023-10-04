#include <iostream>
#include "browser/Browser.hpp"
#include "utils.hpp"

ShellBrowser::Browser::Browser()
{
}

ShellBrowser::Browser::~Browser()
{
}

void ShellBrowser::Browser::research(std::string subject)
{
    getRequest(subject);
}

std::string ShellBrowser::Browser::getFullResult()
{
    return this->_result;
}

std::vector<std::string> ShellBrowser::Browser::getUrls()
{
    return this->_urls;
}