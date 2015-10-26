//
//  main.cpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Infection.hpp"
using namespace KA;

int main(int argc, const char * argv[]) {
    if (argc != 2) return 1;
    Infection::instance().initialize(argv[1]);
    std::string buf;
    std::cout << "Incremental Service Console" << std::endl;
    std::cout << "DB file: " << argv[1] << std::endl;
    std::cout << "** We assume ALL OPERATIONS ARE LEGAL **" << std::endl;
    while (true) {
        std::cout << "> ";
        std::cin >> buf;
        if (buf[0] == 'l') {
            size_t amount = atol(buf.c_str()+1);
            auto limit = Infection::instance().limited_infection(amount);
            for (auto l : limit) {
                std::cout << l << " ";
            }
        } else if (buf[0] == 't') {
            size_t user_id = atol(buf.c_str()+1);
            auto total = Infection::instance().total_infection(user_id);
            for (auto t : total) {
                std::cout << t << " ";
            }
        } else {
            break;
        }
        std::cout << std::endl;
    }
    return 0;
}
