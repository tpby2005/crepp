//
// Created by toby on 3/27/23.
//

#include "Config.h"
#include "Lib.h"

#include <fstream>
#include <iostream>
#include <string>

Config::Config(int argc, char **argv) {
    if (argc == 4) {
        m_query = argv[1];
        m_file_path = argv[2];
        std::string argument = argv[3];

        if (argument == "-i") {
            m_ignore_case = true;
        } else {
            std::cerr << "Argument not recognized.\n";
        }
    }

    else if (argc == 3) {
        m_query = argv[1];
        m_file_path = argv[2];
    }

    else if (argc == 2) {
        std::cerr << "Not enough arguments.\n";
        exit(EXIT_FAILURE);
    }

    else if (argc == 1) {
        Lib::usage();
        exit(EXIT_FAILURE);
    }

    else {
        std::cerr << "Too little arguments.\n";
    }
}
void Config::run() {
    int count = 1;
    std::string line;
    std::ifstream contents;

    contents.open(m_file_path);

    if (!contents.is_open()) {
        std::cerr << "File cannot be opened.";
        exit(EXIT_FAILURE);
    }

    while(getline(contents, line)) {
        if (!m_ignore_case) {
            std::size_t found = line.find(m_query);

            if (found != std::string::npos) {
                std::cout << count << "\t" << line << std::endl;
            }
        } else {
            std::string line_lower = line;

            for (int i = 0; i < line_lower.length(); i++) {
                line_lower[i] = tolower(line_lower[i]);
            }

            for (int i = 0; i < m_query.length(); i++) {
                m_query[i] = tolower(m_query[i]);
            }

            std::size_t found = line_lower.find(m_query);

            if (found != std::string::npos) {
                std::cout << count << "\t" << line << std::endl;
            }
        }

        count++;
    }
}
