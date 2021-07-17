#include <filesystem>
#include "FS.hpp"

namespace FS {
    void createFolder(const std::string & path) {
        std::filesystem::create_directories(path);
    }

    void deleteFile(const std::string & path) {
        std::filesystem::remove(path);
    }

    void deleteFolder(const std::string & path) {
        std::filesystem::remove_all(path);
    }
};
