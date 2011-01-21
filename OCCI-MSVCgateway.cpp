#include <string.h>
#include "OCCI-gateway-internals.h"

#pragma warning(disable: 4996)

/* utility to ensure that the same heap that allocated memory (e.g. strdup) frees it */
void OCCIgateway_free(void * p) {
    free(p);
}

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

    return strdup(e->getMessage().c_str());
}

int OCCIgateway_SQLException_getErrorCode(void * _e) {
    SQLException * e = static_cast<SQLException *>(_e);

    return e->getErrorCode();
}

/* Blob */
void OCCIgateway_Blob_dtor(void * _blob) {
    Blob * blob = static_cast<Blob *>(_blob);

    delete blob;
}

void * OCCIgateway_Blob_getStream(void ** exception, void * _blob, unsigned int v1, unsigned int v2) {
    Stream * strm = NULL;
    Blob * blob = static_cast<Blob *>(_blob);
    *exception = NULL;
    try {
        strm = blob->getStream(v1, v2);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return strm;
}

void OCCIgateway_Blob_closeStream(void ** exception, void * _blob, void * _strm) {
    Blob * blob = static_cast<Blob *>(_blob);
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        blob->closeStream(strm);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Blob_open(void ** exception, void * _blob, unsigned int mode) {
    Blob * blob = static_cast<Blob *>(_blob);
    *exception = NULL;
    try {
        blob->open(static_cast<LobOpenMode>(mode));
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Blob_setEmpty(void ** exception, void * _blob) {
    Blob * blob = static_cast<Blob *>(_blob);
    *exception = NULL;
    try {
        blob->setEmpty();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_Blob_writeChunk(void ** exception, void * _blob, unsigned int amt, unsigned char * buffer, unsigned int bufsize, unsigned int offset) {
    unsigned int r = 0;
    Blob * blob = static_cast<Blob *>(_blob);
    *exception = NULL;
    try {
        r = blob->writeChunk(amt, buffer, bufsize, offset);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Blob_close(void ** exception, void * _blob) {
    Blob * blob = static_cast<Blob *>(_blob);
    *exception = NULL;
    try {
        blob->close();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_Blob_length(void ** exception, void * _blob) {
    unsigned int r = 0;
    Blob * blob = static_cast<Blob *>(_blob);
    *exception = NULL;
    try {
        r = blob->length();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

/* Bytes */
void * OCCIgateway_Bytes_ctor(void ** exception, unsigned char * value, unsigned int count, unsigned int offset, void * _envr) {
    Bytes * bytes = NULL;
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        bytes = new Bytes(value, count, offset, envr);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return bytes;
}

void OCCIgateway_Bytes_dtor(void * _bytes) {
    Bytes * bytes = static_cast<Bytes *>(_bytes);

    delete bytes;
}

unsigned int OCCIgateway_Bytes_length(void ** exception, void * _bytes) {
    Bytes * bytes = static_cast<Bytes *>(_bytes);
    unsigned int r = 0;
    *exception = NULL;
    try {
        r = bytes->length();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Bytes_getBytes(void ** exception, void * _bytes, unsigned char * v1, unsigned int v2, unsigned int v3, unsigned int v4) {
    Bytes * bytes = static_cast<Bytes *>(_bytes);
    *exception = NULL;
    try {
        bytes->getBytes(v1, v2, v3, v4);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

/* Clob */
void OCCIgateway_Clob_dtor(void * _clob) {
    Clob * clob = static_cast<Clob *>(_clob);

    delete clob;
}

void * OCCIgateway_Clob_getStream(void ** exception, void * _clob, unsigned int v1, unsigned int v2) {
    Stream * strm = NULL;
    Clob * clob = static_cast<Clob *>(_clob);
    *exception = NULL;
    try {
        strm = clob->getStream(v1, v2);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return strm;
}

void OCCIgateway_Clob_closeStream(void ** exception, void * _clob, void * _strm) {
    Clob * clob = static_cast<Clob *>(_clob);
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        clob->closeStream(strm);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_Clob_length(void ** exception, void * _clob) {
    unsigned int r = 0;
    Clob * clob = static_cast<Clob *>(_clob);
    *exception = NULL;
    try {
        r = clob->length();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

/* Number */
void * OCCIgateway_Number_ctor_int(void ** exception, int v) {
    void * r = NULL;
    *exception = NULL;
    try {
        r = new Number(v);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Number_dtor(void * _number) {
    Number * number = static_cast<Number *>(_number);

    delete number;
}

const char * OCCIgateway_Number_toText(void ** exception, void * _number, void * _envr, const char * v1, const char * v2) {
    const char * r = NULL;
    Number * number = static_cast<Number *>(_number);
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        r = strdup(number->toText(envr, v1, v2).c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Number_fromText(void ** exception, void * _number, void * _envr, const char * v1, const char * v2, const char * v3) {
    Number * number = static_cast<Number *>(_number);
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
        number->fromText(envr, v1, v2, v3);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

/* MetaData */
void OCCIgateway_MetaData_dtor(void * _meta) {
    MetaData * meta = static_cast<MetaData *>(_meta);

    delete meta;
}

const char * OCCIgateway_MetaData_getString(void ** exception, void * _meta, unsigned int attrid) {
    const char * r = NULL;
    MetaData * meta = static_cast<MetaData *>(_meta);
    *exception = NULL;
    try {
        r = strdup(meta->getString(static_cast<MetaData::AttrId>(attrid)).c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void ** OCCIgateway_MetaData_getVector(size_t * size, void ** exception, void * _meta, unsigned int attrid) {
    MetaData * meta = static_cast<MetaData *>(_meta);
    void ** r = NULL;
    *size = 0;
    *exception = NULL;
    try {
    	std::vector<MetaData> v = meta->getVector(static_cast<MetaData::AttrId>(attrid));
    	r = (void **) malloc(sizeof(void *) * (*size = v.size()));
    	int c = 0;
    	for (std::vector<MetaData>::iterator i = v.begin(); i != v.end(); c++, i++)
    		r[c] = new MetaData(*i);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
}
int OCCIgateway_MetaData_getInt(void ** exception, void * _meta, unsigned int attrid) {
    int r = 0;
    MetaData * meta = static_cast<MetaData *>(_meta);
    *exception = NULL;
    try {
    	r = meta->getInt(static_cast<MetaData::AttrId>(attrid));
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
}
bool OCCIgateway_MetaData_getBoolean(void ** exception, void * _meta, unsigned int attrid) {
    bool r = false;
    MetaData * meta = static_cast<MetaData *>(_meta);
    *exception = NULL;
    try {
    	r = meta->getBoolean(static_cast<MetaData::AttrId>(attrid));
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
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

void * OCCIgateway_Environment_createStatelessConnectionPool(void ** exception, void * _envr, const char * poolUserName, const char * poolPassword, const char * connectString, unsigned int maxConn, unsigned int minConn, unsigned int incrConn, StatelessConnectionPool::PoolType pType ) {
    StatelessConnectionPool * poolp = NULL;
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
    	poolp = envr->createStatelessConnectionPool(poolUserName, poolPassword, connectString, maxConn, minConn, incrConn, pType);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return poolp;
}

void OCCIgateway_Environment_terminateStatelessConnectionPool(void ** exception, void * _envr, void * _poolp, StatelessConnectionPool::DestroyMode mode) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    Environment * envr = static_cast<Environment *>(_envr);
    *exception = NULL;
    try {
    	envr->terminateStatelessConnectionPool(poolp, mode);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

OCIEnv * OCCIgateway_Environment_getOCIEnvironment(void ** exception, void * _envr) {
    Environment * envr = static_cast<Environment *>(_envr);
    OCIEnv * r = NULL;
    *exception = NULL;
    try {
    	r = envr->getOCIEnvironment();
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
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
        r = strdup(conn->getClientCharSet().c_str());
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
        r = strdup(conn->getClientNCHARCharSet().c_str());
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

OCISvcCtx * OCCIgateway_Connection_getOCIServiceContext(void ** exception, void * _conn) {
    OCISvcCtx * r = NULL;
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
    	r = conn->getOCIServiceContext();
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_Connection_getMetaData(void ** exception, void * _conn, const char * object, MetaData::ParamType prmtyp) {
    MetaData * meta = NULL;
    Connection * conn = static_cast<Connection *>(_conn);
    *exception = NULL;
    try {
    	meta = new MetaData(conn->getMetaData(object, prmtyp));
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return meta;
}


/* Statement */
void OCCIgateway_Statement_dtor(void ** exception, void * _stmt) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        delete stmt;
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_addIteration(void ** exception, void * _stmt) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->addIteration();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_closeResultSet(void ** exception, void * _stmt, void * _rset) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        stmt->closeResultSet(rset);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_closeStream(void ** exception, void * _stmt, void * _strm) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        stmt->closeStream(strm);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

int OCCIgateway_Statement_execute(void ** exception, void * _stmt, const char * sql) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Statement::Status r = Statement::UNPREPARED;
    *exception = NULL;
    try {
        r = stmt->execute(sql);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return static_cast<int>(r);
}

int OCCIgateway_Statement_executeArrayUpdate(void ** exception, void * _stmt, unsigned int v) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Statement::Status r = Statement::UNPREPARED;
    *exception = NULL;
    try {
        r = stmt->executeArrayUpdate(v);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return static_cast<int>(r);
}

void * OCCIgateway_Statement_executeQuery(void ** exception, void * _stmt, const char * sql) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    ResultSet * r = NULL;
    *exception = NULL;
    try {
        r = stmt->executeQuery(sql);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_executeUpdate(void ** exception, void * _stmt, const char * sql) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    unsigned int r = 0;
    *exception = NULL;
    try {
        r = stmt->executeUpdate(sql);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Statement_getAutoCommit(void ** exception, void * _stmt) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    bool r = false;
    *exception = NULL;
    try {
        r = stmt->getAutoCommit();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return static_cast<int>(r);
}

void * OCCIgateway_Statement_getBlob(void ** exception, void * _stmt, unsigned int idx) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Blob blob;
    *exception = NULL;
    try {
        blob = stmt->getBlob(idx);
        return new Blob(blob);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_Statement_getBytes(void ** exception, void * _stmt, unsigned int idx) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Bytes bytes;
    *exception = NULL;
    try {
        bytes = stmt->getBytes(idx);
        return new Bytes(bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

const char * OCCIgateway_Statement_getCharSet(void ** exception, void * _stmt, unsigned int idx) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    const char * r = NULL;
    *exception = NULL;
    try {
        r = strdup(stmt->getCharSet(idx).c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_Statement_getClob(void ** exception, void * _stmt, unsigned int idx) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Clob clob;
    *exception = NULL;
    try {
        clob = stmt->getClob(idx);
        return new Clob(clob);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

unsigned int OCCIgateway_Statement_getCurrentIteration(void ** exception, void * _stmt) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getCurrentIteration();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_getCurrentStreamIteration(void ** exception, void * _stmt) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getCurrentStreamIteration();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_getCurrentStreamParam(void ** exception, void * _stmt) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getCurrentStreamParam();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_Statement_getCursor(void ** exception, void * _stmt, unsigned int idx) {
    ResultSet * rset = NULL;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        rset = stmt->getCursor(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return rset;
}

int OCCIgateway_Statement_getDatabaseNCHARParam(void ** exception, void * _stmt, unsigned int idx) {
    bool r = false;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getDatabaseNCHARParam(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

double OCCIgateway_Statement_getDouble(void ** exception, void * _stmt, unsigned int idx) {
    double r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getDouble(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

float OCCIgateway_Statement_getFloat(void ** exception, void * _stmt, unsigned int idx) {
    float r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getFloat(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Statement_getInt(void ** exception, void * _stmt, unsigned int idx) {
    int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getInt(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_getMaxIterations(void ** exception, void * _stmt) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getMaxIterations();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_getMaxParamSize(void ** exception, void * _stmt, unsigned int idx) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getMaxParamSize(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_Statement_getNumber(void ** exception, void * _stmt, unsigned int idx) {
    Number n;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        n = stmt->getNumber(idx);
        return new Number(n);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_Statement_getResultSet(void ** exception, void * _stmt) {
    ResultSet * r = NULL;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getResultSet();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_Statement_getRowid(void ** exception, void * _stmt, unsigned int idx) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Bytes bytes;
    *exception = NULL;
    try {
        bytes = stmt->getRowid(idx);
        return new Bytes(bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

const char * OCCIgateway_Statement_getSQL(void ** exception, void * _stmt) {
    const char * r = NULL;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = strdup(stmt->getSQL().c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_Statement_getStream(void ** exception, void * _stmt, unsigned int idx) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Stream * strm = NULL;
    *exception = NULL;
    try {
        strm = stmt->getStream(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return strm;
}

const char * OCCIgateway_Statement_getString(void ** exception, void * _stmt, unsigned int idx) {
    const char * r = NULL;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = strdup(stmt->getString(idx).c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_getUInt(void ** exception, void * _stmt, unsigned int idx) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getUInt(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_Statement_getUpdateCount(void ** exception, void * _stmt) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->getUpdateCount();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Statement_isNull(void ** exception, void * _stmt, unsigned int idx) {
    bool r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->isNull(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Statement_isTruncated(void ** exception, void * _stmt, unsigned int idx) {
    bool r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->isTruncated(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Statement_preTruncationLength(void ** exception, void * _stmt, unsigned int idx) {
    int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = stmt->preTruncationLength(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Statement_registerOutParam(void ** exception, void * _stmt, unsigned int idx, unsigned int v1, unsigned int v2, const char * v3) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->registerOutParam(idx, static_cast<Type>(v1), v2, v3);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setAutoCommit(void ** exception, void * _stmt, int autoCommit) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setAutoCommit(!!autoCommit);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setBinaryStreamMode(void ** exception, void * _stmt, unsigned int idx, unsigned int size) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setBinaryStreamMode(idx, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setBytes(void ** exception, void * _stmt, unsigned int idx, void * _bytes) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Bytes * bytes = static_cast<Bytes *>(_bytes);
    *exception = NULL;
    try {
        stmt->setBytes(idx, *bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setCharacterStreamMode(void ** exception, void * _stmt, unsigned int idx, unsigned int size) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setCharacterStreamMode(idx, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setCharSet(void ** exception, void * _stmt, unsigned int idx, const char * charset) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setCharSet(idx, charset);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setDatabaseNCHARParam(void ** exception, void * _stmt, unsigned int idx, int isNCHAR) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setDatabaseNCHARParam(idx, !!isNCHAR);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setDouble(void ** exception, void * _stmt, unsigned int idx, double value) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setDouble(idx, value);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setErrorOnNull(void ** exception, void * _stmt, unsigned int idx, int causeException) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setErrorOnNull(idx, !!causeException);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setErrorOnTruncate(void ** exception, void * _stmt, unsigned int idx, int causeException) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setErrorOnTruncate(idx, !!causeException);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setFloat(void ** exception, void * _stmt, unsigned int idx, float value) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setFloat(idx, value);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setInt(void ** exception, void * _stmt, unsigned int idx, int value) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setInt(idx, value);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setMaxIterations(void ** exception, void * _stmt, unsigned int maxIterations) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setMaxIterations(maxIterations);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setMaxParamSize(void ** exception, void * _stmt, unsigned int idx, unsigned int maxSize) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setMaxParamSize(idx, maxSize);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setNull(void ** exception, void * _stmt, unsigned int idx, unsigned int type) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setNull(idx, static_cast<Type>(type));
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setNumber(void ** exception, void * _stmt, unsigned int idx, void * _n) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Number * n = static_cast<Number *>(_n);
    *exception = NULL;
    try {
        stmt->setNumber(idx, *n);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setPrefetchMemorySize(void ** exception, void * _stmt, unsigned int bytes) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setPrefetchMemorySize(bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setPrefetchRowCount(void ** exception, void * _stmt, unsigned int rowCount) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setPrefetchRowCount(rowCount);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setRowid(void ** exception, void * _stmt, unsigned int idx, void * _bytes) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    Bytes * bytes = static_cast<Bytes *>(_bytes);
    *exception = NULL;
    try {
        stmt->setRowid(idx, *bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setSQL(void ** exception, void * _stmt, const char * sql) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setSQL(sql);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setString(void ** exception, void * _stmt, unsigned int idx, const char * str) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setString(idx, str);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setUInt(void ** exception, void * _stmt, unsigned int idx, unsigned int value) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        stmt->setInt(idx, value);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_Statement_status(void ** exception, void * _stmt) {
    unsigned int r = 0;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
        r = static_cast<unsigned int>(stmt->status());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

OCIStmt * OCCIgateway_Statement_getOCIStatement(void ** exception, void * _stmt) {
    OCIStmt * r = NULL;
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
    	r = stmt->getOCIStatement();
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Statement_disableCaching(void ** exception, void * _stmt) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
    	stmt->disableCaching();
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setDataBuffer(void ** exception, void * _stmt, unsigned int paramIndex, void *buffer, Type type, sb4 size, ub2 *length, sb2 *ind, ub2 *rc) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
    	stmt->setDataBuffer(paramIndex, buffer, type, size, length, ind, rc);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setBinaryStreamModeEx(void ** exception, void * _stmt, unsigned int colIndex, unsigned int size, bool INArg) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
    	stmt->setBinaryStreamMode(colIndex,size,INArg);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_Statement_setCharacterStreamModeEx(void ** exception, void * _stmt, unsigned int colIndex, unsigned int size, bool INArg) {
    Statement * stmt = static_cast<Statement *>(_stmt);
    *exception = NULL;
    try {
    	stmt->setCharacterStreamMode(colIndex,size,INArg);
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

void OCCIgateway_ResultSet_cancel(void ** exception, void * _rset) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        rset->cancel();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

const char * OCCIgateway_ResultSet_getCharSet(void ** exception, void * _rset, unsigned int idx) {
    const char * r = NULL;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        r = strdup(rset->getCharSet(idx).c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_ResultSet_getBlob(void ** exception, void * _rset, unsigned int idx) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    Blob blob;
    *exception = NULL;
    try {
        blob = rset->getBlob(idx);
        return new Blob(blob);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_ResultSet_getBytes(void ** exception, void * _rset, unsigned int idx) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    Bytes bytes;
    *exception = NULL;
    try {
        bytes = rset->getBytes(idx);
        return new Bytes(bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_ResultSet_getClob(void ** exception, void * _rset, unsigned int idx) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    Clob clob;
    *exception = NULL;
    try {
        clob = rset->getClob(idx);
        return new Clob(clob);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

unsigned int OCCIgateway_ResultSet_getCurrentStreamColumn(void ** exception, void * _rset) {
    unsigned int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        r = rset->getCurrentStreamColumn();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_ResultSet_getCurrentStreamRow(void ** exception, void * _rset) {
    unsigned int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        r = rset->getCurrentStreamRow();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_ResultSet_getCursor(void ** exception, void * _rset, unsigned int idx) {
    void * r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        r = rset->getCursor(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

double OCCIgateway_ResultSet_getDouble(void ** exception, void * _rset, unsigned int idx) {
    double r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->getDouble(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

float OCCIgateway_ResultSet_getFloat(void ** exception, void * _rset, unsigned int idx) {
    float r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->getFloat(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_ResultSet_getInt(void ** exception, void * _rset, unsigned int idx) {
    int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->getInt(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_ResultSet_getMaxColumnSize(void ** exception, void * _rset, unsigned int idx) {
    unsigned int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->getMaxColumnSize(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_ResultSet_getNumArrayRows(void ** exception, void * _rset) {
    unsigned int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    try {
        r = rset->getNumArrayRows();
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_ResultSet_getNumber(void ** exception, void * _rset, unsigned int idx) {
    Number n;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        n = rset->getNumber(idx);
        return new Number(n);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_ResultSet_getRowid(void ** exception, void * _rset, unsigned int idx) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    Bytes bytes;
    *exception = NULL;
    try {
        bytes = rset->getRowid(idx);
        return new Bytes(bytes);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return NULL;
}

void * OCCIgateway_ResultSet_getStream(void ** exception, void * _rset, unsigned int idx) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    Stream * strm = NULL;
    *exception = NULL;
    try {
        strm = rset->getStream(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return strm;
}

const char * OCCIgateway_ResultSet_getString(void ** exception, void * _rset, unsigned int idx) {
    const char * r = NULL;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = strdup(rset->getString(idx).c_str());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_ResultSet_getUInt(void ** exception, void * _rset, unsigned int idx) {
    unsigned int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->getUInt(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_ResultSet_isNull(void ** exception, void * _rset, unsigned int idx) {
    bool r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->isNull(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_ResultSet_isTruncated(void ** exception, void * _rset, unsigned int idx) {
    bool r = false;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->isTruncated(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_ResultSet_next(void ** exception, void * _rset, unsigned int numRows) {
    unsigned int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = static_cast<unsigned int>(rset->next(numRows));
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_ResultSet_preTruncationLength(void ** exception, void * _rset, unsigned int idx) {
    int r = 0;
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        r = rset->preTruncationLength(idx);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_ResultSet_setBinaryStreamMode(void ** exception, void * _rset, unsigned int idx, unsigned int size) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setBinaryStreamMode(idx, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_ResultSet_setCharacterStreamMode(void ** exception, void * _rset, unsigned int idx, unsigned int size) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setCharacterStreamMode(idx, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_ResultSet_setCharSet(void ** exception, void * _rset, unsigned int idx, const char * charset) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setCharSet(idx, charset);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_ResultSet_setDatabaseNCHARParam(void ** exception, void * _rset, unsigned int idx, int isNCHAR) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setDatabaseNCHARParam(idx, !!isNCHAR);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_ResultSet_setErrorOnNull(void ** exception, void * _rset, unsigned int idx, int causeException) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setErrorOnNull(idx, !!causeException);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_ResultSet_setErrorOnTruncate(void ** exception, void * _rset, unsigned int idx, int causeException) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setErrorOnTruncate(idx, !!causeException);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_ResultSet_setMaxColumnSize(void ** exception, void * _rset, unsigned int idx, int max) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
        rset->setMaxColumnSize(idx, max);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_ResultSet_status(void ** exception, void * _rset) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    unsigned int r = 0;
    *exception = NULL;
    try {
        r = static_cast<unsigned int>(rset->status());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void ** OCCIgateway_ResultSet_getColumnListMetaData(size_t * size, void ** exception, void * _rset) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    void ** r = NULL;
    *size = 0;
    *exception = NULL;
    try {
        std::vector<MetaData> v = rset->getColumnListMetaData();
        r = (void **) malloc(sizeof(void *) * (*size = v.size()));
        int c = 0;
        for (std::vector<MetaData>::iterator i = v.begin(); i != v.end(); c++, i++)
            r[c] = new MetaData(*i);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_ResultSet_setDataBuffer(void ** exception, void * _rset, unsigned int colIndex, void *buffer, Type type, sb4 size, ub2 *length, sb2 *ind, ub2 *rc) {
    ResultSet * rset = static_cast<ResultSet *>(_rset);
    *exception = NULL;
    try {
    	rset->setDataBuffer(colIndex,buffer,type,size,length,ind,rc);
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

int OCCIgateway_Stream_readBuffer(void ** exception, void * _strm, char * buffer, unsigned int size) {
    int r = 0;
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        r = strm->readBuffer(buffer, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

int OCCIgateway_Stream_readLastBuffer(void ** exception, void * _strm, char * buffer, unsigned int size) {
    int r = 0;
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        r = strm->readLastBuffer(buffer, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

void OCCIgateway_Stream_writeBuffer(void ** exception, void * _strm, char * buffer, unsigned int size) {
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        strm->writeBuffer(buffer, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

void OCCIgateway_Stream_writeLastBuffer(void ** exception, void * _strm, char * buffer, unsigned int size) {
    Stream * strm = static_cast<Stream *>(_strm);
    *exception = NULL;
    try {
        strm->writeLastBuffer(buffer, size);
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_Stream_status(void ** exception, void * _strm) {
    ResultSet * strm = static_cast<ResultSet *>(_strm);
    unsigned int r = 0;
    *exception = NULL;
    try {
        r = static_cast<unsigned int>(strm->status());
    } catch (SQLException e) {
        *exception = new SQLException(e);
    }
    return r;
}

/* StatelessConnectionPool */
void OCCIgateway_StatelessConnectionPool_dtor(void ** exception, void * _poolp) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	delete poolp;
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_StatelessConnectionPool_setBusyOption(void ** exception, void * _poolp, StatelessConnectionPool::BusyOption busyOption ) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	poolp->setBusyOption(busyOption);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_StatelessConnectionPool_setStmtCacheSize(void ** exception, void * _poolp, unsigned int cacheSize) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	poolp->setStmtCacheSize(cacheSize);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_StatelessConnectionPool_setTimeOut(void ** exception, void * _poolp, unsigned int connTimeOut) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	poolp->setTimeOut(connTimeOut);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

unsigned int OCCIgateway_StatelessConnectionPool_getOpenConnections(void ** exception, void * _poolp) {
    unsigned int r = 0;
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	r = poolp->getOpenConnections();
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
}

unsigned int OCCIgateway_StatelessConnectionPool_getBusyConnections(void ** exception, void * _poolp) {
    unsigned int r = 0;
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	r = poolp->getBusyConnections();
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return r;
}

void * OCCIgateway_StatelessConnectionPool_getConnection(void ** exception, void * _poolp, const char * tag) {
    Connection * conn = NULL;
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    try {
    	conn = poolp->getConnection(tag);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
    return conn;
}

void OCCIgateway_StatelessConnectionPool_releaseConnection (void ** exception, void * _poolp, void * _connection, const char * tag) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    Connection * conn = static_cast<Connection *>(_connection);
    try {
    	poolp->releaseConnection(conn, tag);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

void OCCIgateway_StatelessConnectionPool_terminateConnection (void ** exception, void * _poolp, void * _connection) {
    StatelessConnectionPool * poolp = static_cast<StatelessConnectionPool *>(_poolp);
    Connection * conn = static_cast<Connection *>(_connection);
    try {
    	poolp->terminateConnection(conn);
    } catch (SQLException e) {
    	*exception = new SQLException(e);
    }
}

