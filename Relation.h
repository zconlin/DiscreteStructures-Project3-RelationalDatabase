//
// Created by zacco on 3/3/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_RELATION_H
#define CS236PROJECT3_RELATIONALDATABASE_RELATION_H

#include <set>
#include <string>
#include "Scheme.h"
#include "Tuple.h"

// A Relation object represents a table in a database. A Relation has a name, a Scheme, and a set of Tuples.
// The name is used to uniquely identify the Relation. The Scheme gives the names of the columns of the Relation.
// The set of Tuples gives the values of the rows of the Relation.

// The Scheme and Tuples of a Relation need to be the same size.
// For example, consider the following Scheme and Tuple:
//      Scheme: ID, Name, Major
//      Tuple: '42', 'Ann', 'CS'
// The Scheme determines the number of columns in the Relation. (In this case the Relation has three columns.)
// Each Tuple in this Relation needs to have three values, one for each of the columns.
//
// Schemes and Tuples are related to each other by position. The name at a given position in the Scheme corresponds to the value at that same position in the Tuple. In the example above, 'Major' is at index 2 in the Scheme. The value for 'Major' in the Tuple is 'CS' because it is at index 2 in the Tuple.

class Relation {
private:
    string name;
    Scheme scheme;
    set<Tuple> tuples;

public:
    Relation(const string &name, const Scheme &scheme)
            : name(name), scheme(scheme) {}

    void addTuple(const Tuple &tuple) {
        tuples.insert(tuple);
    }

    string toString() const {
        stringstream out;
        for (auto &tuple: tuples)
            out << tuple.toString(scheme) << endl;
        return out.str();
    }

    Relation select(int index, const string &value) const {
        Relation result(name, scheme);
        // add tuples to the result if they meet the condition
        for (auto &tuple: tuples) {
            if (tuple.at(index) == value) {
                result.addTuple(tuple);
            }
        }
        return result;
    };
};
#endif //CS236PROJECT3_RELATIONALDATABASE_RELATION_H
