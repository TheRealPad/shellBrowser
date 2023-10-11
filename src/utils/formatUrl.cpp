#include <string>
#include <algorithm>

std::string formatUrl(const std::string url)
{
    std::string newUrl = url;
    std::replace(newUrl.begin(), newUrl.end(), ' ', '+');
    return newUrl;
}