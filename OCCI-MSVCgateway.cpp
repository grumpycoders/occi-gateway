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

void OCCIgateway_terminateEnvironment(void ** exception, void * _envr) {
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        Environment::terminateEnvironment(envr);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
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

int OCCIgateway_Environment_getCacheMaxSize(void ** exception, void * _envr) {
    int r = 0;
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        r = envr->getCacheMaxSize();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Environment_getCacheOptSize(void ** exception, void * _envr) {
    int r = 0;
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        r = envr->getCacheOptSize();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Environment_setCacheMaxSize(void ** exception, void * _envr, int v) {
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        envr->setCacheMaxSize(v);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Environment_setCacheOptSize(void ** exception, void * _envr, int v) {
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        envr->setCacheOptSize(v);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_Environment_getCurrentHeapSize(void ** exception, void * _envr) {
    unsigned int r = 0;
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        r = envr->getCurrentHeapSize();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Environment_terminateConnection(void ** exception, void * _envr, void * _conn) {
    Environment * envr = static_cast<Environment *>(_envr);
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
        envr->terminateConnection(conn);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
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

void OCCIgateway_Connection_changePassword(void ** exception, void * _conn, const char * username, const char * oldpassword, const char * newpassword) {
    Connection * conn = static_cast<Connection *>(_conn);
    try {
        conn->changePassword(username, oldpassword, newpassword);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Connection_commit(void ** exception, void * _conn) {
    Connection * conn = static_cast<Connection *>(_conn);
    try {
        conn->commit();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void * OCCIgateway_Connection_createStatement(void ** exception, void * _conn, const char * sql) {
    Statement * stmt = NULL;
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
        stmt = conn->createStatement(sql);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return stmt;
}

void OCCIgateway_Connection_terminateStatement(void ** exception, void * _conn, void * _stmt) {
    Connection * conn = static_cast<Connection *>(_conn);
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        conn->terminateStatement(stmt);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Connection_flushCache(void ** exception, void * _conn) {
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
        conn->flushCache();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

const char * OCCIgateway_Connection_getClientCharSet(void ** exception, void * _conn) {
    const char * r = NULL;
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
        r = conn->getClientCharSet().c_str();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

const char * OCCIgateway_Connection_getClientNCHARCharSet(void ** exception, void * _conn) {
    const char * r = NULL;
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
        r = conn->getClientNCHARCharSet().c_str();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Connection_rollback(void ** exception, void * _conn) {
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
        conn->rollback();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

/* Statement */
void OCCIgateway_Statement_dtor(void ** exception, void * _stmt) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    try {
        delete stmt;
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_addIteration(void ** exception, void * _stmt) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    try {
        stmt->addIteration();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_closeResultSet(void ** exception, void * _stmt, void * _rset) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        stmt->closeResultSet(rset);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_closeStream(void ** exception, void * _stmt, void * _strm) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Stream * strm = static_cast<Stream *>(_strm);
    try {
        stmt->closeStream(strm);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

/* ResultSet */
void OCCIgateway_ResultSet_dtor(void ** exception, void * _rset) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        delete rset;
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

/* Stream */
void OCCIgateway_Stream_dtor(void ** exception, void * _strm) {
    Stream * strm = static_cast<Stream *>(_strm);
    try {
        delete strm;
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}