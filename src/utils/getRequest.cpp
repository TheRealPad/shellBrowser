#include <iostream>
#include <string>
#include <curl/curl.h>

std::string getRequest(const std::string url)
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        const char *url = "https://www.google.com/search?q=pad";
        curl_easy_setopt(curl, CURLOPT_URL, url);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK)
        {
            std::cout << "Requête GET réussie !" << std::endl;
        }
        else
        {
            std::cerr << "Erreur lors de la requête GET : " << curl_easy_strerror(res) << std::endl;
        }
        curl_easy_cleanup(curl);
    }
    else
    {
        std::cerr << "Impossible d'initialiser cURL." << std::endl;
    }

    return "0";
}