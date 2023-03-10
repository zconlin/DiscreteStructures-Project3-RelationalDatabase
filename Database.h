//
// Created by zconlin on 3/10/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_DATABASE_H
#define CS236PROJECT3_RELATIONALDATABASE_DATABASE_H

#include <map>
#include "relation.h"

class Database {
    Database(){}
    ~Database(){}
    map<string, Relation> relations;
};

#endif //CS236PROJECT3_RELATIONALDATABASE_DATABASE_H
