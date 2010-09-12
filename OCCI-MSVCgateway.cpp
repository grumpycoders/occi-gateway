#include "OCCI-gateway-internals.h"

/* SQLException */
void OCCIgateway_SQLException_dtor(void * _e) {
    SQLException * e = static_cast<SQLException *>(_e);

    delete e;
}

const char * OCCIgateway_SQLException_what(void * _e) {
    SQLException * e = static_cast<SQLException *>(_e);

    return e->what();
}

const char * OCCIgateway_SQLException_getMessage(void * _e) {
    SQLException * e = static_cast<SQLException *>(_e);

    return e->getMessage().c_str();
}

int OCCIgateway_SQLException_getErrorCode(void * _e) {
    SQLException * e = static_cast<SQLException *>(_e);

    return e->getErrorCode();
}

/* Environment */
void OCCIgateway_Environment_dtor(void ** exception, void * _envr) {
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        delete envr;
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void * OCCIgateway_createEnvironment(void ** exception, Environment::Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size), void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize), void (*mfreefp)(void *ctxp, void *memptr)) {
    Environment * envr = NULL;
    *exception = NULL;
    try {
        envr = Environment::createEnvironment(mode, ctxp, malocfp, ralocfp, mfreefp);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return envr;
}

void * OCCIgateway_createEnvironment_charset(void ** exception, const char * charset, const char * ncharset, Environment::Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size), void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize), void (*mfreefp)(void *ctxp, void *memptr)) {
    Environment * envr = NULL;
    *exception = NULL;
    try {
        envr = Environment::createEnvironment(charset, ncharset, mode, ctxp, malocfp, ralocfp, mfreefp);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return envr;
}

void * OCCIgateway_Environment_createConnection(void ** exception, void * _envr, const char * username, const char * password, const char * url) {
    Connection * conn = NULL;
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        conn = envr->createConnection(username, password, url);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return conn;
}

/* Connection */
void OCCIgateway_Connection_dtor(void ** exception, void * _conn) {
    Connection * conn = static_cast<Connection *>(_conn);

    try {
        delete conn;
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}
