#ifndef DIGIPIN_H
#define DIGIPIN_H

#include <string>
#include <array>
#include <cmath>
#include <limits>
#include <utility>

class Digipin
{
public:
    // Constants for bounding box
    static constexpr double LON_MIN = 63.5;
    static constexpr double LON_MAX = 99.5;
    static constexpr double LAT_MIN = 2.5;
    static constexpr double LAT_MAX = 38.5;

    // Encode latitude/longitude into 10-character DIGIPIN
    static std::string encode(double lat, double lon);

    // Decode 10-character DIGIPIN -> (bounding box)
    static std::pair<double, double> decode(std::string &code);
};

#endif
