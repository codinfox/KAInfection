//
//  Infection.cpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Infection.hpp"
#include "UseBeforeInitialization.hpp"

Infection & Infection::instance() {
    static Infection _instance;
    return _instance;
}

std::vector<user_id> Infection::total_infection(user_id identifier) {
    if (!initialized) throw UseBeforeInitializationException();
    auto cluster = userGraph.findClusterByUser(identifier);
    return std::vector<user_id>(cluster.begin(), cluster.end());
}

std::vector<user_id> Infection::limited_infection(size_t amount) {
    if (!initialized) throw UseBeforeInitializationException();
    auto cluster = userGraph.findClusterByAmount(amount);
    return std::vector<user_id>(cluster.begin(), cluster.end());
}

static void tokenize(std::string str, std::vector<string> &token_v, char delim){
    size_t start = str.find_first_not_of(delim), end=start;
    
    while (start != std::string::npos){
        // Find next occurence of delimiter
        end = str.find(delim, start);
        // Push back the token found into vector
        token_v.push_back(str.substr(start, end-start));
        // Skip all occurences of the delimiter to find new start
        start = str.find_first_not_of(delim, end);
    }
}

void Infection::initialize(const string &path) {
    // Assume that the file format is always correct
    std::ifstream is(path);
    std::string buf;
    std::vector<User> graph;
    
    if (is.is_open()) {
        while (getline(is, buf)) {
            std::vector<std::string> tokens;
            tokenize(buf, tokens, ',');
            user_id userID = atol(tokens[0].c_str());
            vector<user_id> conns;
            for (auto iter = tokens.begin() + 1; iter != tokens.end(); iter++) {
                conns.push_back(atol(iter->c_str()));
            }
            graph.push_back(User(userID, conns));
        }
    }
    is.close();
    
    userGraph = UserGraph(graph);
    initialized = true;
}