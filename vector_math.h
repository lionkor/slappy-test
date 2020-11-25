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

#endif // VECTOR_MATH_H
