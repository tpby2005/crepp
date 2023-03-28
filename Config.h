//
// Created by toby on 3/27/23.
//

#ifndef CREPP_CONFIG_H
#define CREPP_CONFIG_H

#include <string>

class Config {
private:
    std::string m_query;
    std::string m_file_path;
    bool m_ignore_case = false;

public:
    Config(int argc, char **argv);

    void run();
};


#endif//CREPP_CONFIG_H
