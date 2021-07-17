#include <array>
#include <iostream>
#include "NX.hpp"
#include <switch.h>

namespace NX {
    namespace Console {
        void initialize() {
            consoleInit(nullptr);
        }

        void printLine(const std::string & line) {
            std::cout << line << std::endl;
            consoleUpdate(nullptr);
        }

        void exit() {
            consoleExit(nullptr);
        }
    };

    std::vector<TitleMetadata *> getInstalledTitleMetadata() {
        std::vector<TitleMetadata *> meta;

        // Prepare ns session
        if (R_FAILED(nsInitialize())) {
            return meta;
        }

        int32_t count = 0;
        std::array<NsApplicationRecord, 100> records;
        Result rc;

        // Iterate over 100 titles at a time
        do {
            rc = nsListApplicationRecord(records.data(), records.size(), meta.size(), &count);
            if (R_FAILED(rc)) {
                // Return no titles
                for (TitleMetadata * title : meta) {
                    delete title;
                }
                meta.clear();

            } else {
                NsApplicationControlData data;
                NacpLanguageEntry * lang = nullptr;
                uint64_t size;

                // Create a TitleMetadata object for each title
                for (NsApplicationRecord & record : records) {
                    // Get metadata for ID
                    if (R_FAILED(nsGetApplicationControlData(NsApplicationControlSource_Storage, record.application_id, &data, sizeof(data), &size))) {
                        continue;
                    }
                    if (R_FAILED(nsGetApplicationDesiredLanguage(&data.nacp, &lang))) {
                        continue;
                    }

                    TitleMetadata * title = new TitleMetadata;
                    title->name = std::string(lang->name);
                    title->author = std::string(lang->author);
                    title->titleID = record.application_id;
                    title->version = std::string(data.nacp.display_version);
                    title->icon = std::vector<uint8_t>(data.icon, data.icon + (size - sizeof(data.nacp)));
                    meta.push_back(title);
                }
            }
        } while (count != 0 && R_SUCCEEDED(rc));

        nsExit();
        return meta;
    }

    void waitUntilPlusPressed() {
        PadState pad;
        padConfigureInput(1, HidNpadStyleSet_NpadStandard);
        padInitializeDefault(&pad);

        while (appletMainLoop()) {
            padUpdate(&pad);
            if (padGetButtonsDown(&pad) & HidNpadButton_Plus) {
                return;
            }
        }
    }
};
