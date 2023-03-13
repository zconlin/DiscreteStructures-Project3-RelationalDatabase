//
// Created by zconlin on 3/10/2023.
//

#ifndef CS236PROJECT3_RELATIONALDATABASE_INTERPRETER_H
#define CS236PROJECT3_RELATIONALDATABASE_INTERPRETER_H

#include "Database.h"
#include "parser.h"
#include "Predicate.h"

class Interpreter {
    // Takes a DatalogProgram (the vectors of schemes, facts, rules, and queries)
    // Stores the DatalogProgram as a data member
    // Makes a Database using the schemes and the facts, and stores it as a data member
    // Will evaluate the queries in Part B and the rules in project 4

    // Interpreter pseudocode:
        // Input: DatalogProgram
        //      Store the DatalogProgram as a data member
        //      Make a Relation for each scheme-Predicate, and put that Relation in the Database data member
        //      Make a Tuple for each fact-Predicate, and put that Tuple in the appropriate Relation in the Database

    Relation Interpreter::evaluateQuery(Predicate query) {
        Relation relation = db.relations[query.getName()];
        for (auto &parameter : query.getParameterList()) {
            if (parameter.isID) {
                relation = relation.select(parameter.value);
            }
            else {
                relation = relation.select(parameter.value, parameter.value);
            }
        }
        return relation;
    }

    // Input comes from turning a scheme predicate into a scheme object, and
    // turning a fact predicate into a tuple object
    // Predicates come from the DatalogProgram
    // Interpreter will take in those predicates and make a scheme or tuple from that predicate
    // Store that in the database


    string checkForConstant() {
        // test if the first character is a ', if it is then that makes it a constant,
        // if not it is a variable
        // OR test if isID is true?
    }

public:
        Interpreter(){}
        ~Interpreter(){}

    Interpreter::Interpreter(DatalogProgram dl) {
        this->dl = dl;
        db = Database(dl.Schemes, dl.Facts);
    }
};

#endif //CS236PROJECT3_RELATIONALDATABASE_INTERPRETER_H
