#include <iostream>
#include "Lib.h"
#include "Config.h"

int main(int argc, char **argv) {
    Config *config = new Config{argc, argv};

    config->run();
    return 0;
}
