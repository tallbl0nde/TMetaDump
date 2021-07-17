#ifndef PATHS_HPP
#define PATHS_HPP

#include <string>

namespace Paths {
    static std::string BasePath = "/switch/TMetaDump/";

    static std::string IconFolder = "icons/";
    static std::string IconPath = BasePath + IconFolder;

    static std::string JSONFile = "InstalledTitles.json";
    static std::string JSONPath = BasePath + JSONFile;
};

#endif
