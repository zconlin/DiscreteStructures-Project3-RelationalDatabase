//
// Created by zacco on 3/3/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_SCHEME_H
#define CS236PROJECT3_RELATIONALDATABASE_SCHEME_H

#include <vector>

class Scheme : public vector<string> {

public:
    Scheme(vector<string> names) : vector<string>(names) { }
};

#endif //CS236PROJECT3_RELATIONALDATABASE_SCHEME_H
