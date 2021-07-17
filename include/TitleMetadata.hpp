#ifndef TITLEMETADATA_HPP
#define TITLEMETADATA_HPP

#include <fstream>
#include "Paths.hpp"
#include "Utils.hpp"
#include <vector>

// Collection of metadata associated with an installed title.
struct TitleMetadata {
    std::string name;             // Name of title
    std::string author;           // Author/publisher of title
    uint64_t titleID;             // Unique ID of title
    std::string version;          // Version of installed title
    std::vector<uint8_t> icon;    // Title's icon, stored as JPEG

    // Returns the path to save the title's icon to.
    std::string iconPath() const {
        return Paths::IconFolder + Utils::u64ToString(this->titleID) + ".jpg";
    }

    bool writeIconToFile(const std::string & path) const {
        // Create stream
        std::ofstream file(path, std::ios::binary);
        if (!file.is_open() || !file.good() || file.fail()) {
            return false;
        }

        // Write bytes
        file.write(reinterpret_cast<const char *>(this->icon.data()), this->icon.size());
        return (!file.fail());
    }
};

#endif
