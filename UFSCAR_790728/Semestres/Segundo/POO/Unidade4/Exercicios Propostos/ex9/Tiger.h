#ifndef TIGER_H
#define TIGER_H

#include "Animal.h"
using namespace std;
#include <iostream>
class Tiger : public Animal {
public:
    Tiger(float weight);
    virtual ~Tiger();
    float getWeight() const;
};

#endif /* TIGER_H */

