#include <string.h>
#include "OCCI-gateway-internals.h"

#pragma warning(disable: 4996)

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
    unsigned int r;
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

/* Number */
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
    Statement::Status r;
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
    Statement::Status r;
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
    unsigned int r;
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
    bool r;
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
	ResultSet * r;
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