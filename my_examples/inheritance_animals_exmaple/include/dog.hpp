#pragma once
#include "animal.hpp"

class Dog: public Animal{
public:
    void voice() override;
};