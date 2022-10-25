#pragma once

#include <string>
#include <sstream>
#include <fstream>


/**
 * @brief Gets the contents of the .json file
 *
 * @param path The path to the .json file
 *
 * @return Returns a string with all the components on an entity
 */
std::string GetFileContents(const std::string path)
{
    std::stringstream jsonStream;

    std::ifstream fJson;

    /**
     * @brief Open the file specified in the path param
     */
    fJson.open(path, std::ios::in);

    if (!fJson.is_open())
        throw std::runtime_error("File \"" + path + "\" could not be opened");

    /**
     * @brief While there is still information on the file, extract it. When there is no more information, close the file
     */
    std::string jsonLine;
    while (std::getline(fJson, jsonLine))
        jsonStream << jsonLine << '\n';

    fJson.close();

    /**
     * @brief Return the stringstream with the information on the file
     */
    return jsonStream.str();
}