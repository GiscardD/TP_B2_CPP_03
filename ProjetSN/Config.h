//
// Created by MARAFA on 16/01/2023.
//

#ifndef UNTITLED5_CONFIG_H
#define UNTITLED5_CONFIG_H

#include <string>
#include <vector>

using namespace std;

class Config
{
public:
    Config();
    vector <string> readFiles();
    virtual ~Config();

protected:

private:
};
#endif //UNTITLED5_CONFIG_H
