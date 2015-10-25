//
//  Infection.hpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#ifndef Infection_hpp
#define Infection_hpp

#include "UserGraph.hpp"

class Infection {
    UserGraph userGraph;
    
    Infection();
    Infection(Infection const &) = delete;
    void operator=(Infection const &) = delete;
public:
    static Infection const & instance();
    vector<user_id> total_infection(user_id identifier);
    vector<user_id> limited_infection(size_t amount);
};

#endif /* Infection_hpp */
