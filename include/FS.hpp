#ifndef FS_HPP
#define FS_HPP

#include <string>

namespace FS {
    // Creates the specified folder
    void createFolder(const std::string &);

    // Deletes the requested file
    void deleteFile(const std::string &);

    // Deletes the requested folder
    void deleteFolder(const std::string &);
};

#endif
