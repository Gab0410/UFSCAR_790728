#ifndef LIGER_H
#define LIGER_H

#include "Lion.h"
#include "Tiger.h"
using namespace std;
#include <iostream>
class Liger : public Lion, public Tiger {
public:
    Liger(float weight);
    virtual ~Liger();
    float getWeight() const;
};

#endif /* LIGER_H */

