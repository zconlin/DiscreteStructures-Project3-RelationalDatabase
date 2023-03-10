//
// Created by zconlin on 1/27/2023.
//

#include "scanner.h"
#include "token.h"
#include "parser.h"
#include "Scheme.h"
#include "Tuple.h"
#include "Relation.h"
#include <iostream>
#include <fstream>

int main() { // Part 3
    // The result of the select should only include tuples where the 'Major' is 'CS'.
    // "..\\tests\project3-passoff\20\input21.txt"

    vector<string> names = { "ID", "Name", "Major" };

    Scheme scheme(names);

    Relation relation("student", scheme);

    vector<string> values[] = {
            {"'42'", "'Ann'", "'CS'"},
            {"'32'", "'Bob'", "'CS'"},
            {"'64'", "'Ned'", "'EE'"},
            {"'16'", "'Jim'", "'EE'"},
    };

    for (auto& value : values) {
        Tuple tuple(value);
        cout << tuple.toString(scheme) << endl;
        relation.addTuple(tuple);
    }

    cout << "relation:" << endl;
    cout << relation.toString();

    Relation result = relation.select(2, "'CS'");

    cout << "select Major='CS' result:" << endl;
    cout << result.toString();

}

//int main() { // Part 2
//    vector<string> names = { "ID", "Name", "Major" };
//    Scheme scheme(names);
//    Relation relation("student", scheme);
//    vector<string> values[] = {
//            {"'42'", "'Ann'", "'CS'"},
//            {"'32'", "'Bob'", "'CS'"},
//            {"'64'", "'Ned'", "'EE'"},
//            {"'16'", "'Jim'", "'EE'"},
//    };
//
//    for (auto& value : values) {
//        Tuple tuple(value);
//        cout << tuple.toString(scheme) << endl;
//        relation.addTuple(tuple);
//    }
//
//    cout << "relation:" << endl;
//    cout << relation.toString();
//
//}


//    int main() { // Part 1
//        vector<string> names = { "ID", "Name", "Major" };
//        Scheme scheme(names);
//        vector<string> values[] = {
//                {"'42'", "'Ann'", "'CS'"},
//                {"'32'", "'Bob'", "'CS'"},
//                {"'64'", "'Ned'", "'EE'"},
//                {"'16'", "'Jim'", "'EE'"},
//        };
//
//        for (auto& value : values) {
//            Tuple tuple(value);
//            cout << tuple.toString(scheme) << endl;
//        }
//    }