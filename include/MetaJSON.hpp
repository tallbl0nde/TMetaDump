#ifndef METAJSON_HPP
#define METAJSON_HPP

#include "nlohmann/json.hpp"
#include "TitleMetadata.hpp"

// Object representing the exported JSON object.
class MetaJSON {
    private:
        // Actual JSON object
        nlohmann::json json;

    public:
        // Constructs a new MetaJSON.
        MetaJSON();

        // Appends the given metadata to the JSON.
        void addMetadata(const TitleMetadata *);

        // Writes the in-memory JSON to the specified file.
        bool writeToFile(const std::string &);
};

#endif
