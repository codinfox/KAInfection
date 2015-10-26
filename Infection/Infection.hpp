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

namespace KA {
    /**
     * An interface class to do total and limited infection
     * @warning The class cannot be used before initialization. Call initialize() first.
     * @discussion This class is implemented as a singleton since I believe there should not be multiple instances exsist of such class.
     */
    class Infection {
        UserGraph userGraph;
        bool initialized = false;
        
        Infection() {};
        Infection(Infection const &) = delete;
        void operator=(Infection const &) = delete;
    public:
        /**
         * Getter of the singleton instance
         * @return the Infection instance
         */
        static Infection & instance();
        /**
         * Initialize the Infection instance by loading data from the "database"
         * @param path The path to "database" file, which is essentially a plain text file with certain format
         */
        void initialize(std::string const& path);
        
        /**
         * Get the total users infected starting from a specified user.
         * @param identifier The user id where the infection started from.
         * @return An array of user ids.
         */
        std::vector<user_id> total_infection(user_id identifier);
        /**
         * Given a limit to infection, get user ids that are infected.
         * @param amount The limit
         * @return An array of user ids.
         * @discussion The number of users returned may not be exactly the number specified. Usually it will be more than the number specified.
         */
        std::vector<user_id> limited_infection(size_t amount);
    };
}

#endif /* Infection_hpp */
