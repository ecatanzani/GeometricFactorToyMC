#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>

#include "anyoption.h"

#pragma once

struct in_args {
    std::string workdir;
    std::string output_path;
    bool verbose{false};
    
    unsigned int simu_events{0};
    unsigned int simu_seed{0};
};

#endif
