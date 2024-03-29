//
//  KVector.hpp
//  Infection
//
//  Created by Zhihao Li on 10/24/15.
//  Copyright © 2015 TAC. All rights reserved.
//

#ifndef KVector_hpp
#define KVector_hpp

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

namespace KA {
    
    /**
     * A vector with better remove performance (like linkedlist) and easier to serilize (like array).
     */
    template <typename T>
    class KVector {
        std::vector<T> container;
        size_t sz = 0;
        std::vector<size_t> freeSlots;
    public:
        size_t add(const T & value);
        T& operator[](size_t pos);
        const T& operator[](size_t pos) const;
        size_t size() const;
        void remove(size_t pos);
        bool empty() const;
        void clear();
        /**
         * Randomly pick one element from the vector.
         * @return An element picked from the vector. If no one is picked, the default T() will be returned. This requires T() be the invalid case.
         */
        T randomPick();
        /**
         * Randomly pick one element from the vector with predicates.
         * @param A predicate, which accepts one element (with type of T) and returns true (if should pick) or false (if should not pick)
         * @return An element picked from the vector. If no one is picked, the default T() will be returned. This requires T() be the invalid case.
         */
        template<typename Pred>
        T randomPick(Pred const& pred);
    };
    
    template <typename T>
    size_t KVector<T>::add(const T &value) {
        size_t index;
        sz++;
        if (freeSlots.empty()) {
            index = container.size();
            container.push_back(value);
        } else {
            index = freeSlots.back();
            freeSlots.pop_back();
            container[index] = value;
        }
        return index;
    }
    
    template <typename T>
    T& KVector<T>::operator[](size_t pos) {
        return container[pos];
    }
    
    template <typename T>
    const T& KVector<T>::operator[](size_t pos) const {
        return container[pos];
    }
    
    template <typename T>
    size_t KVector<T>::size() const {
        return sz;
    }
    
    template <typename T>
    void KVector<T>::remove(size_t pos) {
        if (pos >= container.size()) return;
        if (std::find(freeSlots.begin(), freeSlots.end(), pos) != freeSlots.end()) return;
        sz--;
        freeSlots.push_back(pos);
    }
    
    template <typename T>
    bool KVector<T>::empty() const {
        return sz == 0;
    }
    
    template <typename T>
    void KVector<T>::clear() {
        sz = 0;
        container.clear();
        freeSlots.clear();
    }
    
    template <typename T>
    T KVector<T>::randomPick() {
        return randomPick([](T const&){return true;});
    }
    
    template <typename T>
    template <typename Pred>
    T KVector<T>::randomPick(Pred const& pred) {
        if (sz == 0) return T();
        std::srand((unsigned int)std::time(0));
        size_t index;
        ssize_t counter = 20; // maximum number of trails
        do {
            index = std::rand() % sz;
        } while (--counter > 0 &&
                 ((std::find(freeSlots.begin(), freeSlots.end(), index) != freeSlots.end()) ||
                  !pred(container[index])));
        if (counter > 0) return container[index];
        return T();
    }
}

#endif /* KVector_hpp */