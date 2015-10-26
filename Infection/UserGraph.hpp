//
//  UserGraph.hpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#ifndef UserGraph_hpp
#define UserGraph_hpp

#include <vector>
#include <unordered_set>
#include "KVector.hpp"
using namespace std;

typedef size_t user_id;

struct User {
    User(user_id _identifier, vector<user_id> const & _connections)
    : identifier(_identifier), connections(_connections), cluster(0) {}
    
    user_id identifier;
    vector<user_id> connections;
    size_t cluster;
};

struct ClusterMapping {
    ClusterMapping(size_t _clusterID = 0, size_t _amount = 0, size_t _aisle = 0, size_t _position = 0)
    : clusterID(_clusterID), amount(_amount), aisle(_aisle), position(_position) {};
    
    size_t clusterID;
    size_t amount;
    size_t aisle;
    size_t position;
};

/**
 * Model the users and their relationships as a graph
 * @warning The class cannot be used before initialization. Use the constructor with parameters.
 */
class UserGraph {
    static const size_t total_aisles = 10;
    
    vector<User> users;
    KVector<unordered_set<user_id>> clusters;
    KVector<ClusterMapping> aisles[total_aisles];
    
    bool initialized = false;
    
    void importFromORM(vector<User> const & graph);
    void clustering();
    size_t findAisle(size_t amount);
    
public:
    UserGraph() {}
    /**
     * Create an instance of UserGraph and initialize.
     * @param graph The graph from ORM
     */
    UserGraph(vector<User> const & graph);
    
    /**
     * Given a user id, find all users infected by this user
     * @param userID the id of the first infected user
     * @return A set of all users infected
     */
    unordered_set<user_id> findClusterByUser(user_id userID);
    /**
     * Try to infect a limited number of users
     * @param amount The limit
     * @return A set of all users infected
     * @discussion This method uses a randomized algorithm and the returned number of users will usually larger than the specified limit. For detailed discussion, see README.
     */
    unordered_set<user_id> findClusterByAmount(size_t amount);
};

#endif /* UserGraph_hpp */
