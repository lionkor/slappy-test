#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include "SFML/System.hpp"
#include <math.h>

// Vector length
inline float length(const sf::Vector2f& vec) {
    return std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
}

// Vector normalization
inline sf::Vector2f normalized(const sf::Vector2f& vec) {
    return vec / length(vec);
}

inline void ensure_boundaries(sf::Vector2f& pos, const sf::Vector2i& screen_size) {
    // off the left side
    if (pos.x <= 0) {
        pos.x = screen_size.x - 1;
    }
    // off the top side
    if (pos.y <= 0) {
        pos.y = screen_size.y - 1;
    }
    // off the right side
    if (pos.x >= screen_size.x) {
        pos.x = 1;
    }
    // off the bottom side
    if (pos.y >= screen_size.y) {
        pos.y = 1;
    }
}

#endif // VECTOR_MATH_H
