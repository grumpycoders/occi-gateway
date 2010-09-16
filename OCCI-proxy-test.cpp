#include <stdio.h>
#include "OCCI-proxy.h"

using namespace occi_proxy;

int main(void) {
    Environment * envr;

    try {
        envr = Environment::createEnvironment(Environment::THREADED_MUTEXED);
        printf("Got an environment: %p\n", envr);
    } catch (SQLException e) {
        printf("Got an exception: %s\n", e.what());
    }
}
