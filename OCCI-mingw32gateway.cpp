#include "OCCI-gateway-internals.h"
#include "OCCI-proxy.h"

static void checkException(void * e) {
	occi_proxy::SQLException::checkException(e);
}

template<class T>
class occi_proxy::refCounter {
  public:
      refCounter(void * _obj) : obj(_obj), count(1) { }
      ~refCounter() { T::dtor(obj); }
    refCounter * addRef() { count++; return this; }
    void release() { if (--count == 0) delete this; }
    void * obj;
  private:
    unsigned int count;
};

/* SQLException */
occi_proxy::SQLException::SQLException(void * e, float) : ref(new occi_proxy::refCounter<SQLException>(e)) { }
occi_proxy::SQLException::SQLException(const SQLException &e) : ref(e.ref->addRef()) { }
occi_proxy::SQLException::~SQLException() { ref->release(); }
void occi_proxy::SQLException::dtor(void * obj) { OCCIgateway_SQLException_dtor(obj); }

void occi_proxy::SQLException::checkException(void * e) throw (occi_proxy::SQLException) {
	if (e)
		throw occi_proxy::SQLException(e, .0f);
}

const char * occi_proxy::SQLException::what() const {
    return OCCIgateway_SQLException_what(ref->obj);
}

std::string occi_proxy::SQLException::getMessage() const {
	const char * p = OCCIgateway_SQLException_getMessage(ref->obj);
	std::string r = p;
	free((void *)p);
	return r;
}

int occi_proxy::SQLException::getErrorCode() const {
    return OCCIgateway_SQLException_getErrorCode(ref->obj);
}

/* Blob */
occi_proxy::Blob::Blob(void * blob, float) : ref(new occi_proxy::refCounter<Blob>(blob)) { }
occi_proxy::Blob::Blob(const Blob &blob) : ref(blob.ref->addRef()) { }
occi_proxy::Blob::~Blob() { ref->release(); }
void occi_proxy::Blob::dtor(void * obj) { OCCIgateway_Blob_dtor(obj); }

occi_proxy::Stream * occi_proxy::Blob::getStream(unsigned int v1, unsigned int v2) {
    void * strm;
    void * e = NULL;
    strm = OCCIgateway_Blob_getStream(&e, ref->obj, v1, v2);
    checkException(e);
    return new occi_proxy::Stream(strm, .0f);
}

void occi_proxy::Blob::closeStream(occi_proxy::Stream * strm) {
    void * e = NULL;
    OCCIgateway_Blob_closeStream(&e, ref->obj, strm->strm);
    checkException(e);
    strm->strm = NULL;
    delete strm;
}

void occi_proxy::Blob::open(LobOpenMode mode) {
	void * e = NULL;
	OCCIgateway_Blob_open(&e, ref->obj, static_cast<unsigned int>(mode));
	checkException(e);
}

void occi_proxy::Blob::setEmpty() {
	void * e = NULL;
	OCCIgateway_Blob_setEmpty(&e, ref->obj);
	checkException(e);
}

unsigned int occi_proxy::Blob::writeChunk(unsigned int amt, unsigned char * buffer, unsigned int bufsize, unsigned int offset) {
	void * e = NULL;
	unsigned int r;
	r = OCCIgateway_Blob_writeChunk(&e, ref->obj, amt, buffer, bufsize, offset);
	checkException(e);
	return r;
}

void occi_proxy::Blob::close() {
	void * e = NULL;
	OCCIgateway_Blob_close(&e, ref->obj);
	checkException(e);
}

/* Bytes */
occi_proxy::Bytes::Bytes(void * bytes, float) : ref(new occi_proxy::refCounter<Bytes>(bytes)) { }
occi_proxy::Bytes::Bytes(const Bytes &bytes) : ref(bytes.ref->addRef()) { }
occi_proxy::Bytes::~Bytes() { ref->release(); }
void occi_proxy::Bytes::dtor(void * obj) { OCCIgateway_Bytes_dtor(obj); }

occi_proxy::Bytes::Bytes(unsigned char * value, unsigned int count, unsigned int offset, const occi_proxy::Environment * envr) {
	void * e = NULL;
	void * b = NULL;
	b = OCCIgateway_Bytes_ctor(&e, value, count, offset, envr ? envr->envr : NULL);
	checkException(e);
	ref = new occi_proxy::refCounter<Bytes>(b);
}

unsigned int occi_proxy::Bytes::length() const {
    void * e = NULL;
    unsigned int r;
    r = OCCIgateway_Bytes_length(&e, ref->obj);
    checkException(e);
    return r;
}

void occi_proxy::Bytes::getBytes(unsigned char * v1, unsigned int v2, unsigned int v3, unsigned int v4) const {
    void * e = NULL;
    OCCIgateway_Bytes_getBytes(&e, ref->obj, v1, v2, v3, v4);
    checkException(e);
}

/* Clob */
occi_proxy::Clob::Clob(void * clob, float) : ref(new occi_proxy::refCounter<Clob>(clob)) { }
occi_proxy::Clob::Clob(const Clob &clob) : ref(clob.ref->addRef()) { }
occi_proxy::Clob::~Clob() { ref->release(); }
void occi_proxy::Clob::dtor(void * obj) { OCCIgateway_Clob_dtor(obj); }

occi_proxy::Stream * occi_proxy::Clob::getStream(unsigned int v1, unsigned int v2) {
    void * strm;
    void * e = NULL;
    strm = OCCIgateway_Clob_getStream(&e, ref->obj, v1, v2);
    checkException(e);
    return new occi_proxy::Stream(strm, .0f);
}

void occi_proxy::Clob::closeStream(occi_proxy::Stream * strm) {
    void * e = NULL;
    OCCIgateway_Clob_closeStream(&e, ref->obj, strm->strm);
    checkException(e);
    strm->strm = NULL;
    delete strm;
}

/* Number */
occi_proxy::Number::Number(void * number, float) : ref(new occi_proxy::refCounter<Number>(number)) { }
occi_proxy::Number::Number(const Number &number) : ref(number.ref->addRef()) { }
occi_proxy::Number::~Number() { ref->release(); }
void occi_proxy::Number::dtor(void * obj) { OCCIgateway_Number_dtor(obj); }

std::string occi_proxy::Number::toText(const occi_proxy::Environment * env, std::string v1, std::string v2) const {
	const char * p = NULL;
	void * e = NULL;
	p = OCCIgateway_Number_toText(&e, ref->obj, env ? env->envr : NULL, v1.c_str(), v2.c_str());
	checkException(e);
	std::string r = p;
	free((void *)p);
	return r;
}

/* Environment */
occi_proxy::Environment::Environment(void * _envr, float) : envr(_envr) { }
occi_proxy::Environment::~Environment() {
    void * e = NULL;
    if (envr)
        OCCIgateway_Environment_dtor(&e, envr);
    checkException(e);
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) {
    void * e = NULL;
    void * envr;
    envr = OCCIgateway_createEnvironment(&e, static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp);
    checkException(e);
    return new occi_proxy::Environment(envr, .0f);
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(const std::string &charset, const std::string &ncharset, occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) {
    void * e = NULL;
    void * envr;
    envr = OCCIgateway_createEnvironment_charset(&e, charset.c_str(), ncharset.c_str(), static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp);
    checkException(e);
    return new occi_proxy::Environment(envr, .0f);
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
    conn = new occi_proxy::Connection(OCCIgateway_Environment_createConnection(&e, envr, username.c_str(), password.c_str(), url.c_str()), .0f);
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
occi_proxy::Connection::Connection(void * _conn, float) : conn(_conn) { }
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
    stmt = new occi_proxy::Statement(OCCIgateway_Connection_createStatement(&e, conn, sql.c_str()), .0f);
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
    const char * p = NULL;
    p = OCCIgateway_Connection_getClientCharSet(&e, conn);
    checkException(e);
	std::string r = p;
	free((void *)p);
    return r;
}

std::string occi_proxy::Connection::getClientNCHARCharSet() const {
    void * e = NULL;
    const char * p = NULL;
    p = OCCIgateway_Connection_getClientNCHARCharSet(&e, conn);
    checkException(e);
	std::string r = p;
	free((void *)p);
    return r;
}

void occi_proxy::Connection::rollback() {
    void * e = NULL;
    OCCIgateway_Connection_rollback(&e, conn);
    checkException(e);
}

/* Statement */
occi_proxy::Statement::Statement(void * _stmt, float) : stmt(_stmt) { }
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
    rset->rset = NULL;
    delete rset;
}

void occi_proxy::Statement::closeStream(occi_proxy::Stream * strm) {
    void * e = NULL;
    OCCIgateway_Statement_closeStream(&e, stmt, strm->strm);
    checkException(e);
    strm->strm = NULL;
    delete strm;
}

occi_proxy::Statement::Status occi_proxy::Statement::execute(const std::string &sql) {
    void * e = NULL;
    occi_proxy::Statement::Status r;
    r = static_cast<occi_proxy::Statement::Status>(OCCIgateway_Statement_execute(&e, stmt, sql.c_str()));
    checkException(e);
    return r;
}

occi_proxy::Statement::Status occi_proxy::Statement::executeArrayUpdate(unsigned int v) {
    void * e = NULL;
    occi_proxy::Statement::Status r;
    r = static_cast<occi_proxy::Statement::Status>(OCCIgateway_Statement_executeArrayUpdate(&e, stmt, v));
    checkException(e);
    return r;
}

occi_proxy::ResultSet * occi_proxy::Statement::executeQuery(const std::string &sql) {
    void * e = NULL;
    void * r;
    r = OCCIgateway_Statement_executeQuery(&e, stmt, sql.c_str());
    checkException(e);
    return new occi_proxy::ResultSet(r, .0f);
}

unsigned int occi_proxy::Statement::executeUpdate(const std::string &sql) {
    void * e = NULL;
    unsigned int r;
    r = OCCIgateway_Statement_executeUpdate(&e, stmt, sql.c_str());
    checkException(e);
    return r;
}

bool occi_proxy::Statement::getAutoCommit() const {
    void * e = NULL;
    int r;
    r = OCCIgateway_Statement_getAutoCommit(&e, stmt);
    checkException(e);
    return !!r;
}

occi_proxy::Blob occi_proxy::Statement::getBlob(unsigned int idx) {
    void * e = NULL;
    void * blob = NULL;
    blob = OCCIgateway_Statement_getBlob(&e, stmt, idx);
    checkException(e);
    return Blob(blob, .0f);
}

occi_proxy::Bytes occi_proxy::Statement::getBytes(unsigned int idx) {
    void * e = NULL;
    void * bytes = NULL;
    bytes = OCCIgateway_Statement_getBytes(&e, stmt, idx);
    checkException(e);
    return Bytes(bytes, .0f);
}

std::string occi_proxy::Statement::getCharSet(unsigned int idx) {
    void * e = NULL;
    const char * p = NULL;
    p = OCCIgateway_Statement_getCharSet(&e, stmt, idx);
    checkException(e);
	std::string r = p;
	free((void *)p);
    return r;
}

occi_proxy::Clob occi_proxy::Statement::getClob(unsigned int idx) {
    void * e = NULL;
    void * clob = NULL;
    clob = OCCIgateway_Statement_getClob(&e, stmt, idx);
    checkException(e);
    return Clob(clob, .0f);
}

unsigned int occi_proxy::Statement::getCurrentIteration() const {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getCurrentIteration(&e, stmt);
	checkException(e);
	return r;
}

unsigned int occi_proxy::Statement::getCurrentStreamIteration() const {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getCurrentStreamIteration(&e, stmt);
	checkException(e);
	return r;
}

unsigned int occi_proxy::Statement::getCurrentStreamParam() const {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getCurrentStreamParam(&e, stmt);
	checkException(e);
	return r;
}

occi_proxy::ResultSet * occi_proxy::Statement::getCursor(unsigned int idx) {
	void * e = NULL;
	void * rset = NULL;
	rset = OCCIgateway_Statement_getCursor(&e, stmt, idx);
	checkException(e);
	return new occi_proxy::ResultSet(rset, .0f);
}

bool occi_proxy::Statement::getDatabaseNCHARParam(unsigned int idx) {
	void * e = NULL;
	int r = 0;
	r = OCCIgateway_Statement_getDatabaseNCHARParam(&e, stmt, idx);
	checkException(e);
	return !!r;
}

double occi_proxy::Statement::getDouble(unsigned int idx) {
	void * e = NULL;
	double r = 0;
	r = OCCIgateway_Statement_getDouble(&e, stmt, idx);
	checkException(e);
	return r;
}

float occi_proxy::Statement::getFloat(unsigned int idx) {
	void * e = NULL;
	float r = 0;
	r = OCCIgateway_Statement_getFloat(&e, stmt, idx);
	checkException(e);
	return r;
}

int occi_proxy::Statement::getInt(unsigned int idx) {
	void * e = NULL;
	int r = 0;
	r = OCCIgateway_Statement_getInt(&e, stmt, idx);
	checkException(e);
	return r;
}

unsigned int occi_proxy::Statement::getMaxIterations() const {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getMaxIterations(&e, stmt);
	checkException(e);
	return r;
}

unsigned int occi_proxy::Statement::getMaxParamSize(unsigned int idx) const {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getMaxParamSize(&e, stmt, idx);
	checkException(e);
	return r;
}

occi_proxy::Number occi_proxy::Statement::getNumber(unsigned int idx) {
	void * e = NULL;
	void * r = NULL;
	r = OCCIgateway_Statement_getNumber(&e, stmt, idx);
	checkException(e);
	return Number(r, .0f);
}

occi_proxy::ResultSet * occi_proxy::Statement::getResultSet() {
	void * e = NULL;
	void * rset = NULL;
	rset = OCCIgateway_Statement_getResultSet(&e, stmt);
	checkException(e);
	return new occi_proxy::ResultSet(rset, .0f);
}

occi_proxy::Bytes occi_proxy::Statement::getRowid(unsigned int idx) {
	void * e = NULL;
	void * bytes = NULL;
	bytes = OCCIgateway_Statement_getRowid(&e, stmt, idx);
	checkException(e);
	return Bytes(bytes, .0f);
}

std::string occi_proxy::Statement::getSQL() const {
	void * e = NULL;
	const char * p = NULL;
	p = OCCIgateway_Statement_getSQL(&e, stmt);
	checkException(e);
	std::string r = p;
	free((void *)p);
	return r;
}

occi_proxy::Stream * occi_proxy::Statement::getStream(unsigned int idx) {
	void * e = NULL;
	void * strm = NULL;
	strm = OCCIgateway_Statement_getStream(&e, stmt, idx);
	checkException(e);
	return new Stream(strm, .0f);
}

std::string occi_proxy::Statement::getString(unsigned int idx) {
	void * e = NULL;
	const char * p = NULL;
	p = OCCIgateway_Statement_getString(&e, stmt, idx);
	checkException(e);
	std::string r = p;
	free((void *)p);
	return r;
}

unsigned int occi_proxy::Statement::getUInt(unsigned int idx) {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getUInt(&e, stmt, idx);
	checkException(e);
	return r;
}

unsigned int occi_proxy::Statement::getUpdateCount() const {
	void * e = NULL;
	unsigned int r = 0;
	r = OCCIgateway_Statement_getUpdateCount(&e, stmt);
	checkException(e);
	return r;
}

bool occi_proxy::Statement::isNull(unsigned int idx) const {
	void * e = NULL;
	int r = 0;
	r = OCCIgateway_Statement_isNull(&e, stmt, idx);
	checkException(e);
	return !!r;
}

bool occi_proxy::Statement::isTruncated(unsigned int idx) const {
	void * e = NULL;
	int r = 0;
	r = OCCIgateway_Statement_isTruncated(&e, stmt, idx);
	checkException(e);
	return !!r;
}

int occi_proxy::Statement::preTruncationLength(unsigned int idx) const {
	void * e = NULL;
	int r = 0;
	r = OCCIgateway_Statement_preTruncationLength(&e, stmt, idx);
	checkException(e);
	return r;
}

void occi_proxy::Statement::registerOutParam(unsigned int idx, occi_proxy::Type type, unsigned int maxSize, const std::string &sqltype) {
	void * e = NULL;
	OCCIgateway_Statement_registerOutParam(&e, stmt, idx, static_cast<unsigned int>(type), maxSize, sqltype.c_str());
	checkException(e);
}

void occi_proxy::Statement::setAutoCommit(bool autoCommit) {
	void * e = NULL;
	OCCIgateway_Statement_setAutoCommit(&e, stmt, !!autoCommit);
	checkException(e);
}

void occi_proxy::Statement::setBinaryStreamMode(unsigned int idx, unsigned int size) {
	void * e = NULL;
	OCCIgateway_Statement_setBinaryStreamMode(&e, stmt, idx, size);
	checkException(e);
}

void occi_proxy::Statement::setBytes(unsigned int idx, const Bytes &bytes) {
	void * e = NULL;
	OCCIgateway_Statement_setBytes(&e, stmt, idx, bytes.ref->obj);
	checkException(e);
}

void occi_proxy::Statement::setCharacterStreamMode(unsigned int idx, unsigned int size) {
	void * e = NULL;
	OCCIgateway_Statement_setCharacterStreamMode(&e, stmt, idx, size);
	checkException(e);
}

/* ResultSet */
occi_proxy::ResultSet::ResultSet(void * _rset, float) : rset(_rset) { }
occi_proxy::ResultSet::~ResultSet() {
    void * e = NULL;
    if (rset)
        OCCIgateway_ResultSet_dtor(&e, rset);
    checkException(e);
}

/* Stream */
occi_proxy::Stream::Stream(void * _strm, float) : strm(_strm) { }
occi_proxy::Stream::~Stream() {
    void * e = NULL;
    if (strm)
        OCCIgateway_ResultSet_dtor(&e, strm);
    checkException(e);
}
