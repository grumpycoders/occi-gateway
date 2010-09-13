#include "OCCI-gateway-internals.h"
#include "OCCI-proxy.h"

/* SQLException */
occi_proxy::SQLException::SQLException(void * _e) : e(_e) { }
occi_proxy::SQLException::~SQLException() {
    OCCIgateway_SQLException_dtor(e);
}

const char * occi_proxy::SQLException::what() const {
    return OCCIgateway_SQLException_what(e);
}

std::string occi_proxy::SQLException::getMessage() const {
    return OCCIgateway_SQLException_getMessage(e);
}

int occi_proxy::SQLException::getErrorCode() const {
    return OCCIgateway_SQLException_getErrorCode(e);
}

/* Environment */
occi_proxy::Environment::Environment(void * _envr) : envr(_envr) { }
occi_proxy::Environment::~Environment() throw (occi_proxy::SQLException) {
    void * e = NULL;
    if (envr)
        OCCIgateway_Environment_dtor(&e, envr);
    if (e)
        throw occi_proxy::SQLException(e);
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) throw (SQLException) {
    occi_proxy::Environment * envr;
    void * e = NULL;
    envr = new occi_proxy::Environment(OCCIgateway_createEnvironment(&e, static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp));
    if (e) {
        delete envr;
        throw occi_proxy::SQLException(e);
    }
    return envr;
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(const std::string &charset, const std::string &ncharset, occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) throw (SQLException) {
    occi_proxy::Environment * envr;
    void * e = NULL;
    envr = new occi_proxy::Environment(OCCIgateway_createEnvironment_charset(&e, charset.c_str(), ncharset.c_str(), static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp));
    if (e) {
        delete envr;
        throw occi_proxy::SQLException(e);
    }
    return envr;
}

void occi_proxy::Environment::terminateEnvironment(occi_proxy::Environment * envr) throw (SQLException) {
    void * e = NULL;
    OCCIgateway_terminateEnvironment(&e, envr->envr);
    if (e)
        throw occi_proxy::SQLException(e);
    delete envr;
}

occi_proxy::Connection * occi_proxy::Environment::createConnection(const std::string &username, const std::string &password, const std::string &url) {
    occi_proxy::Connection * conn;
    void * e = NULL;
    conn = new occi_proxy::Connection(OCCIgateway_Environment_createConnection(&e, envr, username.c_str(), password.c_str(), url.c_str()));
    if (e) {
        delete conn;
        throw occi_proxy::SQLException(e);
    }
    return conn;
}

int occi_proxy::Environment::getCacheMaxSize() const throw (SQLException) {
    int r;
    void * e = NULL;
    r = OCCIgateway_Environment_getCacheMaxSize(&e, envr);
    if (e)
        throw occi_proxy::SQLException(e);
    return r;
}

int occi_proxy::Environment::getCacheOptSize() const throw (SQLException) {
    int r;
    void * e = NULL;
    r = OCCIgateway_Environment_getCacheOptSize(&e, envr);
    if (e)
        throw occi_proxy::SQLException(e);
    return r;
}

void occi_proxy::Environment::setCacheMaxSize(int v) throw (SQLException) {
    void * e = NULL;
    OCCIgateway_Environment_setCacheMaxSize(&e, envr, v);
    if (e)
        throw occi_proxy::SQLException(e);
}

void occi_proxy::Environment::setCacheOptSize(int v) throw (SQLException) {
    void * e = NULL;
    OCCIgateway_Environment_setCacheOptSize(&e, envr, v);
    if (e)
        throw occi_proxy::SQLException(e);
}

unsigned int occi_proxy::Environment::getCurrentHeapSize() const throw (SQLException) {
    unsigned int r;
    void * e = NULL;
    r = OCCIgateway_Environment_getCurrentHeapSize(&e, envr);
    if (e)
        throw occi_proxy::SQLException(e);
    return r;
}

/* Connection */
occi_proxy::Connection::Connection(void * _conn) : conn(_conn) { }
occi_proxy::Connection::~Connection() throw (occi_proxy::SQLException) {
    void * e = NULL;
    if (conn)
        OCCIgateway_Connection_dtor(&e, conn);
    if (e)
        throw occi_proxy::SQLException(e);
}
