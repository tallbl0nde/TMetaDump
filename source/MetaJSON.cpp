#include <fstream>
#include "MetaJSON.hpp"
#include "Utils.hpp"

MetaJSON::MetaJSON() {
    // Create base array
    this->json = nlohmann::json();
    this->json["titles"] = nlohmann::json::array();
}

void MetaJSON::addMetadata(const TitleMetadata * title) {
    nlohmann::json tJson = nlohmann::json();
    tJson["name"] = title->name;
    tJson["author"] = title->author;
    tJson["titleID"] = Utils::u64ToString(title->titleID);
    tJson["version"] = title->version;
    tJson["iconPath"] = title->iconPath();
    this->json["titles"].push_back(tJson);
}

bool MetaJSON::writeToFile(const std::string & path) {
    // Create stream
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open() || !file.good() || file.fail()) {
        return false;
    }

    // Write bytes
    file << json.dump(4) << std::endl;
    file.flush();
    return (!file.fail());
}
