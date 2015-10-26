//
//  testKVector.cpp
//  Infection
//
//  Created by Zhihao Li on 10/24/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#include "catch.hpp"
#include "KVector.hpp"
#include <unordered_set>
#include <utility>
using namespace std;
using namespace KA;

SCENARIO("Common use of KVectors", "[utils]") {
    GIVEN("the value is of primitive type") {
        KVector<int> kv;
        REQUIRE(kv.size() == 0);
        
        WHEN("a new element is added") {
            AND_WHEN("the vector is initially empty") {
                size_t index = kv.add(1);
                
                THEN("the size of the vector should be 1 and the index of the added element should be 0") {
                    REQUIRE(kv.size() == 1);
                    REQUIRE(index == 0);
                }
            }
            
            AND_WHEN("the vector has 5 initial values") {
                for (int i = 0; i < 5; i++) {
                    kv.add(i);
                }
                size_t index = kv.add(1);
                
                THEN("the size of the vector should be 6 and the index of the added element should be 5") {
                    REQUIRE(kv.size() == 6);
                    REQUIRE(index == 5);
                }
            }
        }
        
        WHEN("there are 5 initial values") {
            for (int i = 1; i <= 5; i++) {
                kv.add(i);
            }
            REQUIRE(kv.size() == 5);
            
            AND_WHEN("an element is removed") {
                kv.remove(0);
                
                THEN("the size should be 4") {
                    REQUIRE(kv.size() == 4);
                }
                
                AND_WHEN("an element is added afterwards") {
                    size_t index = kv.add(1);
                    
                    THEN("the position inserted to should be the same as the one just removed") {
                        REQUIRE(index == 0);
                    }
                }
            }
            
            WHEN("randomly pick a value") {
                int value = kv.randomPick();
                
                THEN("the value picked should be in the vector") {
                    REQUIRE((1 <= value && value <= 5));
                }
            }
            
            WHEN("randomly pick values with non-duplicate predicate") {
                // here we assume 0 is not a valid number
                std::unordered_set<int> visited;
                size_t counter = 0;
                for (int i = 0; i < 10; i++) {
                    int val = kv.randomPick([&visited](int t){
                        return visited.count(t) == 0;
                    });
                    if (val != 0) {
                        counter ++;
                        visited.insert(val);
                    }
                }
                
                THEN("we should get no duplicates") {
                    REQUIRE(counter <= 5);
                }
            }
        }
    }
    
    GIVEN("the value is of non-primitive type") {
        // We assume (0,0) pair is not a valid pair here
        KVector<std::pair<int, int>> kv;
        REQUIRE(kv.size() == 0);
        
        WHEN("there are 5 initial values") {
            for (int i = 1; i <= 5; i++) {
                kv.add(std::make_pair(i, 2*i));
            }
            REQUIRE(kv.size() == 5);
            
            WHEN("randomly pick a value") {
                auto value = kv.randomPick();
                
                THEN("the value picked should be in the vector") {
                    REQUIRE((1 <= value.first && value.first <= 5));
                }
            }
            
            WHEN("randomly pick values with non-duplicate predicate") {
                std::unordered_set<int> visited;
                size_t counter = 0;
                for (int i = 0; i < 10; i++) {
                    auto val = kv.randomPick([&visited](std::pair<int, int> const& t){
                        return visited.count(t.first) == 0;
                    });
                    if (val.first != 0) {
                        counter ++;
                        visited.insert(val.first);   
                    }
                }
                
                THEN("we should get no duplicates") {
                    REQUIRE(counter <= 5);
                }
            }
        }
    }
}