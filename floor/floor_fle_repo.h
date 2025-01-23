#pragma once
#include "ifloor_repo.h"
#include "floor.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class FloorFileRepo : public IFloorRepo {
private:
    std::string repo_file_name = "floor.dat";

    void CreateFile_() { 
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        output.close();
    }

    int GetLastId_() {
        CreateFile_(); //create file if not exists

        std::fstream file(repo_file_name, std::ios::binary | std::ios::in);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        // Get the size of the file
        file.seekg(0, std::ios::end);
        size_t fileSize = file.tellg();

        // Check if the file is empty
        if (fileSize == 0) {
            file.close();
            return 0; // No records exist
        }

        // Calculate the position of the last record
        size_t lastRecordPos = fileSize - sizeof(FileFloor);

        // Seek to the last record
        file.seekg(lastRecordPos, std::ios::beg);

        // Read the last record
        FileFloor fileFloor;
        file.read((char*)&fileFloor, sizeof(fileFloor));

        file.close();
        return fileFloor.id;
    }

public:
    void Create(Floor& entity) { 
        int lastId = GetLastId_();
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileFloor fileAccount = FloorConverter::ConvertFloorToFileFloor(entity);
        fileAccount.id = lastId + 1; // new Id
        output.write((char*)&fileAccount, sizeof(fileAccount));
        output.close();
    }

    Floor ReadByNumber(std::string number) {
        CreateFile_(); //create file if not exists

        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileFloor fileFloor;

        while (input.read((char*)&fileFloor, sizeof(fileFloor))) {
            if (strcmp(fileFloor.number, number.c_str()) == 0) {
                input.close();
                return FloorConverter::ConvertFileFloorToFloor(fileFloor);
            }
        }

        input.close();
        throw std::runtime_error("User with given email not found.");
    }

    // std::vector<User> ReadAll() {
    //     CreateFile_(); //create file if not exists
        
    //     std::vector<User> users;

    //     std::ifstream file(repo_file_name, std::ios::binary);
    //     if (!file) {
    //         throw std::runtime_error("Failed to open file for reading.");
    //     }

    //     FileUser fileUser;

    //     while (file.read((char*)&fileUser, sizeof(FileUser))) {
    //         auto&& user = UserConverter::ConvertFileUserToUser(fileUser);
    //         users.push_back(user);
    //     }

    //     file.close();
    //     return users;
    // }
};
