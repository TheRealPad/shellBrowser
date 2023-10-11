#include <iostream>
#include <regex>
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
    // (?<=href="\/url\?q=)(.*?)(?=[%&])
    std::regex pattern("href=\"/url\\?q=([^%&]+)");
    this->_result = getRequest("https://www.google.com/search?q=" + formatUrl(subject));
    std::sregex_iterator it(this->_result.begin(), this->_result.end(), pattern);
    std::sregex_iterator end;

    this->_urls.clear();
    while (it != end) {
        this->_urls.push_back(it->str().erase(0, 13));
        ++it;
    }
}

std::string ShellBrowser::Browser::getFullResult()
{
    return this->_result;
}

std::vector<std::string> ShellBrowser::Browser::getUrls()
{
    return this->_urls;
}