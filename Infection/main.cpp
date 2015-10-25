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

int main(int argc, const char * argv[]) {
    if (argc != 2) return 1;
    Infection::instance().initialize(argv[1]);
    std::string buf;
    cout << "Incremental Service Console" << endl;
    cout << "DB file: " << argv[1] << endl;
    cout << "** We assume ALL OPERATIONS ARE LEGAL **" << endl;
    while (true) {
        cout << "> ";
        cin >> buf;
        if (buf[0] == 'l') {
            size_t amount = atol(buf.c_str()+1);
            auto limit = Infection::instance().limited_infection(amount);
            for (auto l : limit) {
                cout << l << " ";
            }
        } else if (buf[0] == 't') {
            size_t user_id = atol(buf.c_str()+1);
            auto total = Infection::instance().total_infection(user_id);
            for (auto t : total) {
                cout << t << " ";
            }
        } else {
            break;
        }
        cout << endl;
    }
    return 0;
}
