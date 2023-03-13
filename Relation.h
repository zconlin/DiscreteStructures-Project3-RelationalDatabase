 //
// Created by zconlin on 3/3/2023.
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
    Relation() = default;
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

    // 2 Types of Select (narrow down rows)
    // Select type 1 - Passing in a constant (Editor='Smith')
    Relation select(int index, const string &value) const {
        Relation result(name, scheme);
        // Add tuples to the result if they meet the condition
        for (auto &tuple: tuples) {
            if (tuple.at(index) == value) {
                result.addTuple(tuple);
            }
        }
        return result;
    };

    // Select type 2 - Passing in a variable (Author=Editor) - Only happens if you find a duplicate variable
    Relation matchSelect(int index, const string &value) const {
        Relation result(name, scheme);
        // TODO
        return result;
    };

    // Project (narrow down columns)
    // Will take in a vector of indexes and return a new relation with only those columns
    // As we go through the tuples, make a new tuple with just those columns,
    // and that new tuple is what we add to the relation
    Relation project(const vector<int> &indexes) const {
        // Create a new scheme with the new column names
        vector<string> newNames;
        for (auto &index: indexes) {
            newNames.push_back(scheme.at(index));
        }
        Scheme newScheme(newNames);

        // Create a new relation with the new scheme
        Relation result(name, newScheme);

        // Add tuples to the result
        for (auto &tuple: tuples) {
            // Create a new tuple with just the columns we want
            vector<string> newValues;
            for (auto &index: indexes) {
                newValues.push_back(tuple.at(index));
            }
            Tuple newTuple(newValues);
            result.addTuple(newTuple);
        }
        return result;
    };


    // Rename - Will take in a scheme and rename the columns of the relation
    // Create a new scheme where we've changed the names of the columns
    // Add back in the same tuples into a relation with the new scheme
    // Then return that new relation
    Relation rename(const Scheme &newScheme) const {
        Relation result(name, newScheme);
        // TODO: change the names of the columns
        for (auto &tuple: tuples) {
            result.addTuple(tuple);
        }
        return result;
    };


    // Evaluate predicate - Mark for Project and Rename
    //      Go through and do all the selects
    //      How do you keep track of the variables you've already seen and what columns you saw them in?
    //      map<string, int> is a good idea, but this alphabetizes them
    //      Also keep a vector<string> to retain the order we saw them
    // Keeping track of the first time we see each variable prepares us for Project and Rename, plus type-2 selects.
    // Project each column that we have saved (not in alphabetical order)
    // Rename columns to their corresponding variable names
    Relation evaluatePredicate(const Predicate &predicate) const {
        Relation result(name, scheme);
        // TODO
        return result;
    };
};
#endif //CS236PROJECT3_RELATIONALDATABASE_RELATION_H
