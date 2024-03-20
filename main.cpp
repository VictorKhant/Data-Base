#include <iostream>
#include <iomanip>
#include "includes/sql/sql.h"

using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;
    SQL sql;
    // sql.batch("select.txt");
    sql.run();
    cout << "\n\n\n=====================" << endl;
    return 0;
}
