//
// Created by zconlin on 3/10/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_DATABASE_H
#define CS236PROJECT3_RELATIONALDATABASE_DATABASE_H

#include <map>
#include "relation.h"

class Database {
    database(){}
    ~database(){}
    map<string, Relation> relations;

    string toString()
    {
        string output;
        for(map<string,relation>::iterator i = relations.begin(); i != relations.end(); i++)
        {
            output += i->second.toString() + "\n";
        }
        return output;
    }

};

#endif //CS236PROJECT3_RELATIONALDATABASE_DATABASE_H
