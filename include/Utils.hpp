#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdint>
#include <string>

namespace Utils {
    // Converts the given 8 byte value to it's hexadecimal representation.
    std::string u64ToString(const uint64_t);
};

#endif
