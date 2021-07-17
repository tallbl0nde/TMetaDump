#ifndef NX_HPP
#define NX_HPP

#include "TitleMetadata.hpp"

namespace NX {
    namespace Console {
        // Initializes the console.
        void initialize();

        // Prints the given line to the console.
        void printLine(const std::string &);

        // Cleans up the console.
        void exit();
    };

    // Returns a vector of all installed titles' metadata.
    std::vector<TitleMetadata *> getInstalledTitleMetadata();

    // Blocks until plus (+) is pressed.
    void waitUntilPlusPressed();
};

#endif
