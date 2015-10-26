//
//  UseBeforeInitialization.hpp
//  Infection
//
//  Created by Zhihao Li on 10/25/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#ifndef UseBeforeInitialization_hpp
#define UseBeforeInitialization_hpp

#include <exception>

namespace KA {
    class UseBeforeInitializationException : std::exception {
    public:
        const char * what() {
            return "The class is used before initialization";
        }
    };
}

#endif /* UseBeforeInitialization_hpp */
