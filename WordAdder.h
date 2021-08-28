#pragma once

#define FIRST_TIME_HERE ([] { \
    static bool is_first_time = true; \
    auto was_first_time = is_first_time; \
    is_first_time = false; \
    return was_first_time; } ())

std::string out = "combined.txt";
std::string success = "Successfulldy done merging 2 files!";