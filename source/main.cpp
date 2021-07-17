#include "FS.hpp"
#include "MetaJSON.hpp"
#include "NX.hpp"

int main(void) {
    // Initialize everything
    FS::createFolder(Paths::BasePath);
    FS::createFolder(Paths::BasePath + Paths::IconFolder);
    NX::Console::initialize();
    MetaJSON json = MetaJSON();

    // Print heading
    NX::Console::printLine("TMetaDump v" VER_STRING);
    NX::Console::printLine(" ");

    // Get all metadata
    NX::Console::printLine("Reading metadata of all installed titles...");
    std::vector<TitleMetadata *> meta = NX::getInstalledTitleMetadata();
    if (meta.empty()) {
        NX::Console::printLine("Failed to read title metadata!");
        goto waitForExit;
    }

    NX::Console::printLine("Parsed " + std::to_string(meta.size()) + " titles.");

    // Convert to JSON
    NX::Console::printLine("Creating JSON containing metadata...");
    for (TitleMetadata * title : meta) {
        json.addMetadata(title);
    }
    if (!json.writeToFile(Paths::JSONPath)) {
        NX::Console::printLine("Failed to create JSON file!");
        goto waitForExit;
    }

    NX::Console::printLine("Successfully wrote metadata to '" + Paths::JSONPath + "'.");

    // Save icons
    NX::Console::printLine("Extracting icons...");
    for (TitleMetadata * title : meta) {
        if (!title->writeIconToFile(Paths::BasePath + title->iconPath())) {
            NX::Console::printLine("Failed to export icons!");
            FS::deleteFolder(Paths::IconFolder);
            FS::deleteFile(Paths::JSONPath);
            goto waitForExit;
        }
    }
    NX::Console::printLine("Extracted " + std::to_string(meta.size()) + " icons.");

    // Success message
    NX::Console::printLine("Title metadata extracted successfully! :)");
    NX::Console::printLine("Extracted data can be found in: '" + Paths::BasePath + "'.");

waitForExit:
    NX::Console::printLine("Press + to exit.");
    NX::waitUntilPlusPressed();

    // Clean up
    NX::Console::exit();
    for (TitleMetadata * title : meta) {
        delete title;
    }

    return 0;
}
