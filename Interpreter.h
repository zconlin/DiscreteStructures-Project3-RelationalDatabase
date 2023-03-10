//
// Created by zconlin on 3/10/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_INTERPRETER_H
#define CS236PROJECT3_RELATIONALDATABASE_INTERPRETER_H

#include "database.h"
#include "parser.h"

class Interpreter {
    public:
        interpreter(){}
        ~interpreter(){}

        vector<scheme> schemesList;
        vector<scheme> factsList;
        vector<string> domain;
        vector<rule> rulesList;
        vector<predicate> queryList;
};

#endif //CS236PROJECT3_RELATIONALDATABASE_INTERPRETER_H
