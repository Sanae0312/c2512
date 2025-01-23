#pragma once
#include <cstring>
#include <string>
class Floor {
    private:
        int id;
        std::string number;
    public: // getters | setters 
        void SetId(int id) { this->id = id; }
        int GetId() { return this->id; }
        void SetNumber(std::string number) { this->number = number; }
        std::string GetNumber() { return this->number; }
};

class FileFloor {
    public: 
        int id;
        char number[255];
};

class FloorConverter { 
    public: 
        static FileFloor ConvertFloorToFileFloor(Floor& floor) {
            FileFloor fileFloor;
            fileFloor.id = floor.GetId();
            strcpy(fileFloor.number, floor.GetNumber().c_str());
            return fileFloor;
        }
        static Floor ConvertFileFloorToFloor(FileFloor& fileFloor) {
            Floor floor;
            floor.SetId(fileFloor.id);
            floor.SetNumber(fileFloor.number);
            return floor;
        }
};
