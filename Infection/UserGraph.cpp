//
//  UserGraph.cpp
//  Infection
//
//  Created by Zhihao Li on 10/23/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#include <queue>
#include <algorithm>
#include "UserGraph.hpp"
#include "UseBeforeInitialization.hpp"

namespace KA {
    UserGraph::UserGraph(std::vector<User> const & graph) {
        importFromORM(graph);
        clustering();
        initialized = true;
    }
    
    void UserGraph::importFromORM(const std::vector<User> &graph) {
        /* We first need to convert the user table from database to the format used in this program. Here, for convenience, we assume that the data structure used by ORM is the same with the data structure used in this program. */
        users = graph;
    }
    
    void UserGraph::clustering() {
        /* We first BFS the whole graph and find all the clusters */
        std::unordered_set<user_id> visited;
        for (User user : users) {
            if (visited.count(user.identifier)) continue;
            
            size_t clusterID = clusters.add(std::unordered_set<user_id>());
            std::unordered_set<user_id> & cluster = clusters[clusterID];
            std::queue<user_id> userQ;
            userQ.push(user.identifier);
            while (!userQ.empty()) {
                user_id current = userQ.front();
                users[current].cluster = clusterID;
                cluster.insert(current);
                visited.insert(current);
                userQ.pop();
                
                for (auto conn : users[current].connections) {
                    if (visited.count(conn)) continue;
                    userQ.push(conn);
                }
            }
            
            size_t aisle = findAisle(cluster.size());
            size_t position = aisles[aisle].add(ClusterMapping(clusterID, cluster.size(), aisle, 0));
            aisles[aisle][position].position = position;
        }
    }
    
    size_t UserGraph::findAisle(size_t amount) {
        for (int i = 1; i < total_aisles; i++) {
            if (amount < (1<<i) && amount >= (1<<(i-1))) return (i - 1);
        }
        return total_aisles - 1;
    }
    
    std::unordered_set<user_id> UserGraph::findClusterByUser(user_id userID) {
        if (!initialized) throw UseBeforeInitializationException();
        return clusters[users[userID].cluster];
    }
    
    std::unordered_set<user_id> UserGraph::findClusterByAmount(size_t amount) {
        if (!initialized) throw UseBeforeInitializationException();
        std::unordered_set<user_id> rtnValue;
        std::unordered_set<size_t> clustersChosen;
        ssize_t innerAmount = amount;
        ssize_t index = findAisle(innerAmount); // which aisle does the query belongs to
        while (index >= 0 && innerAmount > 0) {
            ClusterMapping mapping = aisles[index].randomPick([&clustersChosen](ClusterMapping const& m){
                return clustersChosen.count(m.clusterID) == 0;
            });
            if (mapping.amount == 0) {
                // We have exhausted the current aisle (there's no unvisited clusters in current aisle)
                index --; // use a smaller one
                continue;
            }
            clustersChosen.insert(mapping.clusterID);
            rtnValue.insert(clusters[mapping.clusterID].begin(), clusters[mapping.clusterID].end());
            innerAmount -= mapping.amount;
            index = std::min(index, (ssize_t)findAisle(innerAmount));
        }
        return rtnValue;
    }
}
