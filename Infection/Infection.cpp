//
//  Infection.cpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#include "Infection.hpp"

Infection::Infection() {
    //TODO: Read the user table from ORM
    userGraph = UserGraph(vector<User>());
}

Infection const & Infection::instance() {
    static Infection _instance;
    return _instance;
}

vector<user_id> Infection::total_infection(user_id identifier) {
    auto cluster = userGraph.findClusterByUser(identifier);
    return vector<user_id>(cluster.begin(), cluster.end());
}

vector<user_id> Infection::limited_infection(size_t amount) {
    auto cluster = userGraph.findClusterByAmount(amount);
    return vector<user_id>(cluster.begin(), cluster.end());
}