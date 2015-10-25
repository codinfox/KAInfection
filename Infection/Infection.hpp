//
//  Infection.hpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#ifndef Infection_hpp
#define Infection_hpp

#include <string>
#include <vector>
#include "UserGraph.hpp"

class Infection {
    UserGraph userGraph;
    bool initialized = false;
    
    Infection() {};
    Infection(Infection const &) = delete;
    void operator=(Infection const &) = delete;
public:
    static Infection & instance();
    void initialize(string const& path);
    
    std::vector<user_id> total_infection(user_id identifier);
    std::vector<user_id> limited_infection(size_t amount);
};

#endif /* Infection_hpp */
