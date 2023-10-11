#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "test/doctest.h"
#include "browser/Browser.hpp"
#include "utils.hpp"

int hasUrls() {
    ShellBrowser::Browser browser;

    browser.research("google");
    return browser.getUrls().size();
}

std::string formatString(std::string const &str)
{
    return formatUrl(str);
}

TEST_CASE("Number of urls test") {
    CHECK(hasUrls() > 0);
}

TEST_CASE("Format url test") {
    CHECK(formatString("google") == "google");
    CHECK(formatString("google") != "googlehgvejfbkshldmkhvgbkhlj");
    CHECK(formatString("toi et moi") == "toi+et+moi");
}

TEST_CASE("Get http response test") {
    CHECK(getRequest("https://example.com/").find("<!doctype html>") == 0);
}
