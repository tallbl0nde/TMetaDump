#include <iomanip>
#include <sstream>
#include "Utils.hpp"

namespace Utils {
    std::string u64ToString(const uint64_t value) {
        std::stringstream ss;
        ss << std::uppercase << std::setfill('0') << std::setw(16) << std::hex << value;
        return ss.str();
    }
};
