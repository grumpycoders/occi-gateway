#include <stdio.h>
#include "OCCI-proxy.h"

using namespace occi_proxy;

int main(void) {
    Environment * envr;
    Connection * conn;
    Statement * stmt;
    ResultSet * rset;

    try {
        envr = Environment::createEnvironment(Environment::THREADED_MUTEXED);
        printf("Got an environment: %p\n", envr);
        conn = envr->createConnection("OE", "OE");
        printf("Got a connection  : %p\n", conn);
        stmt = conn->createStatement("select * from user_objects where object_type = 'TABLE'");
        printf("Got a statement   : %p\n", stmt);
        rset = stmt->executeQuery();
        printf("Got a resultset   : %p\n", rset);
        int n = rset->next();
        printf("rset->next() = %i\n", n);
        if (n) {
            std::string s = rset->getString(1);
            printf("s = %s\n", s.c_str());
        }
        stmt->closeResultSet(rset);
        conn->terminateStatement(stmt);
        envr->terminateConnection(conn);
        Environment::terminateEnvironment(envr);
    } catch (SQLException e) {
        printf("Got an exception: %s\n", e.what());
        e.getMessage();
    }
}
