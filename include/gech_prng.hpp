// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
// gechprng - small & fast prng algorithm
//
// github.com/ferhatgec/gechprng
//

#ifndef GECH_PRNG_HPP
#define GECH_PRNG_HPP

#include <string>

class gechprng {
public:
    int seed = 1;
    int bits = 1;
public:
    gechprng() = default;
    ~gechprng()= default;

    void feed(int seed) noexcept {
        this->seed = seed;
    }

    int generate() {
        this->bits ^= (this->seed >> 1) | (this->seed >> 2) | (this->seed >> 3) | (this->seed >> 4);
        this->bits  = (this->bits >> 1) | (this->bits >> 2) | (this->bits >> 3) | (this->bits >> 4);
        this->bits *= (this->bits >> 1) | (this->seed >> 2) | (this->bits >> 3) | (this->seed >> 4);

        this->bits |= (this->seed << 1) ^ (this->seed << 2) ^ (this->seed << 3) ^ (this->seed << 4);

        return this->bits << 32;
    }
};

#endif // GECH_PRNG_HPP
