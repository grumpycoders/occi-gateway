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

void occi_proxy::Environment::terminateConnection(occi_proxy::Connection * conn) throw (SQLException) {
    void * e = NULL;
    OCCIgateway_Environment_terminateConnection(&e, envr, conn->conn);
    if (e)
        throw occi_proxy::SQLException(e);
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

void occi_proxy::Connection::changePassword(const std::string &username, const std::string &oldPassword, const std::string &newPassword) throw (occi_proxy::SQLException) {
    void * e = NULL;
    OCCIgateway_Connection_changePassword(&e, conn, username.c_str(), oldPassword.c_str(), newPassword.c_str());
    if (e)
        throw occi_proxy::SQLException(e);
}

void occi_proxy::Connection::commit() throw (occi_proxy::SQLException) {
    void * e = NULL;
    OCCIgateway_Connection_commit(&e, conn);
    if (e)
        throw occi_proxy::SQLException(e);
}

occi_proxy::Statement * occi_proxy::Connection::createStatement(const std::string &sql) throw (occi_proxy::SQLException) {
    occi_proxy::Statement * stmt = NULL;
    void * e = NULL;
    stmt = new occi_proxy::Statement(OCCIgateway_Connection_createStatement(&e, conn, sql.c_str()));
    if (e) {
        delete stmt;
        throw occi_proxy::SQLException(e);
    }
    return stmt;
}

void occi_proxy::Connection::flushCache() throw (occi_proxy::SQLException) {
    void * e = NULL;
    OCCIgateway_Connection_flushCache(&e, conn);
    if (e)
        throw occi_proxy::SQLException(e);
}

std::string occi_proxy::Connection::getClientCharSet() const throw (occi_proxy::SQLException) {
    void * e = NULL;
    const char * r = NULL;
    r = OCCIgateway_Connection_getClientCharSet(&e, conn);
    if (e)
        throw occi_proxy::SQLException(e);
    return r;
}

std::string occi_proxy::Connection::getClientNCHARCharSet() const throw (occi_proxy::SQLException) {
    void * e = NULL;
    const char * r = NULL;
    r = OCCIgateway_Connection_getClientNCHARCharSet(&e, conn);
    if (e)
        throw occi_proxy::SQLException(e);
    return r;
}

void occi_proxy::Connection::rollback() throw (occi_proxy::SQLException) {
    void * e = NULL;
    OCCIgateway_Connection_rollback(&e, conn);
    if (e)
        throw occi_proxy::SQLException(e);
}

/* Statement */
occi_proxy::Statement::Statement(void * _stmt) : stmt(_stmt) { }
occi_proxy::Statement::~Statement() throw (occi_proxy::SQLException) {
    void * e = NULL;
    if (stmt)
        OCCIgateway_Statement_dtor(&e, stmt);
    if (e)
        throw occi_proxy::SQLException(e);
}

void occi_proxy::Statement::addIteration() throw (occi_proxy::SQLException) {
    void * e = NULL;
    OCCIgateway_Statement_addIteration(&e, stmt);
    if (e)
        throw occi_proxy::SQLException(e);
}
