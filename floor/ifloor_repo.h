#pragma once
#include "floor.h"
#include <vector>
#include <string>

class IFloorRepo {      
    public: 
        virtual void Create(Floor& floor) = 0;
        virtual Floor ReadByNumber(std::string number) = 0;
        virtual ~IFloorRepo() { }
};
