#include <iostream>
#include <string>
#include <curl/curl.h>

struct ResponseData {
    std::string data;
};

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    ((ResponseData*)userp)->data.append((char*)contents, totalSize);
    return totalSize;
}

std::string getRequest(const std::string myUrl)
{
    CURL *curl;
    CURLcode res;
    ResponseData responseData;

    curl = curl_easy_init();
    if (curl) {
        const char *url = myUrl.c_str();
        curl_easy_setopt(curl, CURLOPT_URL, url);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseData);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "Error with GET request : " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Error with curl" << std::endl;
    }
    return responseData.data;
}