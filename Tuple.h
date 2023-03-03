//
// Created by zacco on 3/3/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_TUPLE_H
#define CS236PROJECT3_RELATIONALDATABASE_TUPLE_H

#include <vector>
#include "token.h"

class Tuple : public vector<string> {
public:
    Tuple(vector<string> values) : vector<string>(values) { }

    string toString(const Scheme& scheme) const {
        const Tuple& tuple = *this;
        stringstream out;
        //out << scheme.size();
        //out << tuple.size();
        out << scheme.at(0);
        out << "=";
        out << tuple.at(0);
        out << ", ";
        out << scheme.at(1);
        out << "=";
        out << tuple.at(1);
        out << ", ";
        out << scheme.at(2);
        out << "=";
        out << tuple.at(2);
        return out.str();
    }
};

#endif //CS236PROJECT3_RELATIONALDATABASE_TUPLE_H
