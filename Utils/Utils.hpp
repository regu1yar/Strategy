//
//  Utils.hpp
//  
//
//  Created by Роман Климовицкий on 17.03.2018.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <ctime>
#include <random>


class Utils {
private:
    static std::mt19937 generator;
    static bool random_;

public:
    static void initRandom();
    static int getRandom(int form, int to);
};



#endif /* Utils_hpp */
