#include "OCCI-gateway-internals.h"
#include "OCCI-proxy.h"

static void checkException(void * e) throw (occi_proxy::SQLException) {
    if (e)
        throw occi_proxy::SQLException(e);
}

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
occi_proxy::Environment::~Environment() {
    void * e = NULL;
    if (envr)
        OCCIgateway_Environment_dtor(&e, envr);
    checkException(e);
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) {
    occi_proxy::Environment * envr;
    void * e = NULL;
    envr = new occi_proxy::Environment(OCCIgateway_createEnvironment(&e, static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp));
    if (e)
        delete envr;
    checkException(e);
    return envr;
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(const std::string &charset, const std::string &ncharset, occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) {
    occi_proxy::Environment * envr;
    void * e = NULL;
    envr = new occi_proxy::Environment(OCCIgateway_createEnvironment_charset(&e, charset.c_str(), ncharset.c_str(), static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp));
    if (e)
        delete envr;
    checkException(e);
    return envr;
}

void occi_proxy::Environment::terminateEnvironment(occi_proxy::Environment * envr) {
    void * e = NULL;
    OCCIgateway_terminateEnvironment(&e, envr->envr);
    checkException(e);
    envr->envr = NULL;
    delete envr;
}

occi_proxy::Connection * occi_proxy::Environment::createConnection(const std::string &username, const std::string &password, const std::string &url) {
    occi_proxy::Connection * conn;
    void * e = NULL;
    conn = new occi_proxy::Connection(OCCIgateway_Environment_createConnection(&e, envr, username.c_str(), password.c_str(), url.c_str()));
    if (e)
        delete conn;
    checkException(e);
    return conn;
}

int occi_proxy::Environment::getCacheMaxSize() const {
    int r;
    void * e = NULL;
    r = OCCIgateway_Environment_getCacheMaxSize(&e, envr);
    checkException(e);
    return r;
}

int occi_proxy::Environment::getCacheOptSize() const {
    int r;
    void * e = NULL;
    r = OCCIgateway_Environment_getCacheOptSize(&e, envr);
    checkException(e);
    return r;
}

void occi_proxy::Environment::setCacheMaxSize(int v) {
    void * e = NULL;
    OCCIgateway_Environment_setCacheMaxSize(&e, envr, v);
    checkException(e);
}

void occi_proxy::Environment::setCacheOptSize(int v) {
    void * e = NULL;
    OCCIgateway_Environment_setCacheOptSize(&e, envr, v);
    checkException(e);
}

unsigned int occi_proxy::Environment::getCurrentHeapSize() const {
    unsigned int r;
    void * e = NULL;
    r = OCCIgateway_Environment_getCurrentHeapSize(&e, envr);
    checkException(e);
    return r;
}

void occi_proxy::Environment::terminateConnection(occi_proxy::Connection * conn) {
    void * e = NULL;
    OCCIgateway_Environment_terminateConnection(&e, envr, conn->conn);
    checkException(e);
    conn->conn = NULL;
    delete conn;
}

/* Connection */
occi_proxy::Connection::Connection(void * _conn) : conn(_conn) { }
occi_proxy::Connection::~Connection() {
    void * e = NULL;
    if (conn)
        OCCIgateway_Connection_dtor(&e, conn);
    checkException(e);
}

void occi_proxy::Connection::changePassword(const std::string &username, const std::string &oldPassword, const std::string &newPassword) {
    void * e = NULL;
    OCCIgateway_Connection_changePassword(&e, conn, username.c_str(), oldPassword.c_str(), newPassword.c_str());
    checkException(e);
}

void occi_proxy::Connection::commit() {
    void * e = NULL;
    OCCIgateway_Connection_commit(&e, conn);
    checkException(e);
}

occi_proxy::Statement * occi_proxy::Connection::createStatement(const std::string &sql) {
    occi_proxy::Statement * stmt = NULL;
    void * e = NULL;
    stmt = new occi_proxy::Statement(OCCIgateway_Connection_createStatement(&e, conn, sql.c_str()));
    if (e)
        delete stmt;
    checkException(e);
    return stmt;
}

void occi_proxy::Connection::flushCache() {
    void * e = NULL;
    OCCIgateway_Connection_flushCache(&e, conn);
    checkException(e);
}

std::string occi_proxy::Connection::getClientCharSet() const {
    void * e = NULL;
    const char * r = NULL;
    r = OCCIgateway_Connection_getClientCharSet(&e, conn);
    checkException(e);
    return r;
}

std::string occi_proxy::Connection::getClientNCHARCharSet() const {
    void * e = NULL;
    const char * r = NULL;
    r = OCCIgateway_Connection_getClientNCHARCharSet(&e, conn);
    checkException(e);
    return r;
}

void occi_proxy::Connection::rollback() {
    void * e = NULL;
    OCCIgateway_Connection_rollback(&e, conn);
    checkException(e);
}

/* Statement */
occi_proxy::Statement::Statement(void * _stmt) : stmt(_stmt) { }
occi_proxy::Statement::~Statement() {
    void * e = NULL;
    if (stmt)
        OCCIgateway_Statement_dtor(&e, stmt);
    checkException(e);
}

void occi_proxy::Statement::addIteration() {
    void * e = NULL;
    OCCIgateway_Statement_addIteration(&e, stmt);
    checkException(e);
}

void occi_proxy::Statement::closeResultSet(occi_proxy::ResultSet * rset) {
    void * e = NULL;
    OCCIgateway_Statement_closeResultSet(&e, stmt, rset->rset);
    checkException(e);
}

void occi_proxy::Statement::closeStream(occi_proxy::Stream * strm) {
    void * e = NULL;
    OCCIgateway_Statement_closeStream(&e, stmt, strm->strm);
    checkException(e);
}

occi_proxy::Statement::Status occi_proxy::Statement::execute(const std::string &sql) {
    void * e = NULL;
    occi_proxy::Statement::Status r;
    r = static_cast<occi_proxy::Statement::Status>(OCCIgateway_Statement_execute(&e, stmt, sql.c_str()));
    checkException(e);
    return r;
}

/* ResultSet */
occi_proxy::ResultSet::ResultSet(void * _rset) : rset(_rset) { }
occi_proxy::ResultSet::~ResultSet() {
    void * e = NULL;
    if (rset)
        OCCIgateway_ResultSet_dtor(&e, rset);
    checkException(e);
}

/* Stream */
occi_proxy::Stream::Stream(void * _strm) : strm(_strm) { }
occi_proxy::Stream::~Stream() {
    void * e = NULL;
    if (strm)
        OCCIgateway_ResultSet_dtor(&e, strm);
    checkException(e);
}
