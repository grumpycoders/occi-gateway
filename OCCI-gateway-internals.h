#ifndef __OCCI_GATEWAY_INTERNALS_H__
#define __OCCI_GATEWAY_INTERANSL_H__

#include <occi.h>

using namespace oracle::occi;

#ifdef COMPILING_DLL
#define OGWEXPORT __declspec(dllexport)
#else
#define OGWEXPORT __declspec(dllimport)
#endif

extern "C" {
    /* SQLException */
    OGWEXPORT void OCCIgateway_SQLException_dtor(void * e);
    OGWEXPORT const char * OCCIgateway_SQLException_what(void * e);
    OGWEXPORT const char * OCCIgateway_SQLException_getMessage(void * e);
    OGWEXPORT int OCCIgateway_SQLException_getErrorCode(void * e);

    /* Blob */
    OGWEXPORT void OCCIgateway_Blob_dtor(void * blob);
    OGWEXPORT void * OCCIgateway_Blob_getStream(void ** exception, void * blob, unsigned int v1, unsigned int v2);
    OGWEXPORT void OCCIgateway_Blob_closeStream(void ** exception, void * blob, void * strm);
    OGWEXPORT void OCCIgateway_Blob_open(void ** exception, void * blob, unsigned int mode);
    OGWEXPORT void OCCIgateway_Blob_setEmpty(void ** exception, void * blob);
    OGWEXPORT unsigned int OCCIgateway_Blob_writeChunk(void ** exception, void * blob, unsigned int amt, unsigned char * buffer, unsigned int bufsize, unsigned int offset);
    OGWEXPORT void OCCIgateway_Blob_close(void ** exception, void * blob);

    /* Bytes */
    OGWEXPORT void * OCCIgateway_Bytes_ctor(void ** exception, unsigned char * value, unsigned int count, unsigned int offset, void * envr);
    OGWEXPORT void OCCIgateway_Bytes_dtor(void * bytes);
    OGWEXPORT unsigned int OCCIgateway_Bytes_length(void ** exception, void * bytes);
    OGWEXPORT void OCCIgateway_Bytes_getBytes(void ** exception, void * bytes, unsigned char * v1, unsigned int v2, unsigned int v3, unsigned int v4);

    /* Clob */
    OGWEXPORT void OCCIgateway_Clob_dtor(void * clob);
    OGWEXPORT void * OCCIgateway_Clob_getStream(void ** exception, void * clob, unsigned int v1, unsigned int v2);
    OGWEXPORT void OCCIgateway_Clob_closeStream(void ** exception, void * clob, void * strm);

    /* Number */
    OGWEXPORT void OCCIgateway_Number_dtor(void * number);
    OGWEXPORT const char * OCCIgateway_Number_toText(void ** exception, void * number, void * envr, const char * v1, const char * v2);
    OGWEXPORT void OCCIgateway_Number_fromText(void ** exception, void * number, void * envr, const char * v1, const char * v2, const char * v3);

    /* Environment */
    OGWEXPORT void OCCIgateway_Environment_dtor(void ** exception, void * envr);
    OGWEXPORT void * OCCIgateway_createEnvironment(void ** exception, Environment::Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size), void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize), void (*mfreefp)(void *ctxp, void *memptr));
    OGWEXPORT void * OCCIgateway_createEnvironment_charset(void ** exception, const char * charset, const char * ncharset, Environment::Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size), void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize), void (*mfreefp)(void *ctxp, void *memptr));
    OGWEXPORT void OCCIgateway_terminateEnvironment(void ** exception, void * _envr);
    OGWEXPORT void * OCCIgateway_Environment_createConnection(void ** exception, void * envr, const char * username, const char * password, const char * url);    
    OGWEXPORT int OCCIgateway_Environment_getCacheMaxSize(void ** exception, void * envr);
    OGWEXPORT int OCCIgateway_Environment_getCacheOptSize(void ** exception, void * envr);
    OGWEXPORT void OCCIgateway_Environment_setCacheMaxSize(void ** exception, void * envr, int v);
    OGWEXPORT void OCCIgateway_Environment_setCacheOptSize(void ** exception, void * envr, int v);
    OGWEXPORT unsigned int OCCIgateway_Environment_getCurrentHeapSize(void ** exception, void * envr);
    OGWEXPORT void OCCIgateway_Environment_terminateConnection(void ** exception, void * envr, void * conn);

    /* Connection */
    OGWEXPORT void OCCIgateway_Connection_dtor(void ** exception, void * conn);
    OGWEXPORT void OCCIgateway_Connection_changePassword(void ** exception, void * conn, const char * username, const char * oldpassword, const char * newpassword);
    OGWEXPORT void OCCIgateway_Connection_commit(void ** exception, void * conn);
    OGWEXPORT void * OCCIgateway_Connection_createStatement(void ** exception, void * conn, const char * sql);
    OGWEXPORT void OCCIgateway_Connection_flushCache(void ** exception, void * conn);
    OGWEXPORT const char * OCCIgateway_Connection_getClientCharSet(void ** exception, void * conn);
    OGWEXPORT const char * OCCIgateway_Connection_getClientNCHARCharSet(void ** exception, void * conn);
    OGWEXPORT void OCCIgateway_Connection_rollback(void ** exception, void * conn);

    /* Statement */
    OGWEXPORT void OCCIgateway_Statement_dtor(void ** exception, void * stmt);
    OGWEXPORT void OCCIgateway_Statement_addIteration(void ** exception, void * stmt);
    OGWEXPORT void OCCIgateway_Statement_closeResultSet(void ** exception, void * stmt, void * rset);
    OGWEXPORT void OCCIgateway_Statement_closeStream(void ** exception, void * stmt, void * strm);
    OGWEXPORT int OCCIgateway_Statement_execute(void ** exception, void * stmt, const char * sql);
    OGWEXPORT int OCCIgateway_Statement_executeArrayUpdate(void ** exception, void * stmt, unsigned int v);
    OGWEXPORT void * OCCIgateway_Statement_executeQuery(void ** exception, void * stmt, const char * sql);
    OGWEXPORT unsigned int OCCIgateway_Statement_executeUpdate(void ** exception, void * stmt, const char * sql);
    OGWEXPORT int OCCIgateway_Statement_getAutoCommit(void ** exception, void * stmt);
    OGWEXPORT void * OCCIgateway_Statement_getBlob(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT void * OCCIgateway_Statement_getBytes(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT const char * OCCIgateway_Statement_getCharSet(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT void * OCCIgateway_Statement_getClob(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_Statement_getCurrentIteration(void ** exception, void * stmt);
    OGWEXPORT unsigned int OCCIgateway_Statement_getCurrentStreamIteration(void ** exception, void * stmt);
    OGWEXPORT unsigned int OCCIgateway_Statement_getCurrentStreamParam(void ** exception, void * stmt);
    OGWEXPORT void * OCCIgateway_Statement_getCursor(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT int OCCIgateway_Statement_getDatabaseNCHARParam(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT double OCCIgateway_Statement_getDouble(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT float OCCIgateway_Statement_getFloat(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT int OCCIgateway_Statement_getInt(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_Statement_getMaxIterations(void ** exception, void * stmt);
    OGWEXPORT unsigned int OCCIgateway_Statement_getMaxParamSize(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT void * OCCIgateway_Statement_getNumber(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT void * OCCIgateway_Statement_getResultSet(void ** exception, void * stmt);
    OGWEXPORT void * OCCIgateway_Statement_getRowid(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT const char * OCCIgateway_Statement_getSQL(void ** exception, void * stmt);
    OGWEXPORT void * OCCIgateway_Statement_getStream(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT const char * OCCIgateway_Statement_getString(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_Statement_getUInt(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_Statement_getUpdateCount(void ** exception, void * stmt);
    OGWEXPORT int OCCIgateway_Statement_isNull(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT int OCCIgateway_Statement_isTruncated(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT int OCCIgateway_Statement_preTruncationLength(void ** exception, void * stmt, unsigned int idx);
    OGWEXPORT void OCCIgateway_Statement_registerOutParam(void ** exception, void * stmt, unsigned int idx, unsigned int v1, unsigned int v2, const char * v3);
    OGWEXPORT void OCCIgateway_Statement_setAutoCommit(void ** exception, void * stmt, int autoCommit);
    OGWEXPORT void OCCIgateway_Statement_setBinaryStreamMode(void ** exception, void * stmt, unsigned int idx, unsigned int size);
    OGWEXPORT void OCCIgateway_Statement_setBytes(void ** exception, void * stmt, unsigned int idx, void * bytes);
    OGWEXPORT void OCCIgateway_Statement_setCharacterStreamMode(void ** exception, void * stmt, unsigned int idx, unsigned int size);
    OGWEXPORT void OCCIgateway_Statement_setCharSet(void ** exception, void * stmt, unsigned int idx, const char * charset);
    OGWEXPORT void OCCIgateway_Statement_setDatabaseNCHARParam(void ** exception, void * stmt, unsigned int idx, int isNCHAR);
    OGWEXPORT void OCCIgateway_Statement_setDouble(void ** exception, void * stmt, unsigned int idx, double value);
    OGWEXPORT void OCCIgateway_Statement_setErrorOnNull(void ** exception, void * stmt, unsigned int idx, int causeException);
    OGWEXPORT void OCCIgateway_Statement_setErrorOnTruncate(void ** exception, void * stmt, unsigned int idx, int causeException);
    OGWEXPORT void OCCIgateway_Statement_setFloat(void ** exception, void * stmt, unsigned int idx, float value);
    OGWEXPORT void OCCIgateway_Statement_setInt(void ** exception, void * stmt, unsigned int idx, int value);
    OGWEXPORT void OCCIgateway_Statement_setMaxIterations(void ** exception, void * stmt, unsigned int maxIterations);
    OGWEXPORT void OCCIgateway_Statement_setMaxParamSize(void ** exception, void * stmt, unsigned int idx, unsigned int maxSize);
    OGWEXPORT void OCCIgateway_Statement_setNull(void ** exception, void * stmt, unsigned int idx, unsigned int type);
    OGWEXPORT void OCCIgateway_Statement_setNumber(void ** exception, void * stmt, unsigned int idx, void * number);
    OGWEXPORT void OCCIgateway_Statement_setPrefetchMemorySize(void ** exception, void * stmt, unsigned int bytes);
    OGWEXPORT void OCCIgateway_Statement_setPrefetchRowCount(void ** exception, void * stmt, unsigned int bytes);
    OGWEXPORT void OCCIgateway_Statement_setRowid(void ** exception, void * stmt, unsigned int idx, void * bytes);
    OGWEXPORT void OCCIgateway_Statement_setSQL(void ** exception, void * stmt, const char * sql);
    OGWEXPORT void OCCIgateway_Statement_setString(void ** exception, void * stmt, unsigned int idx, const char * str);
    OGWEXPORT void OCCIgateway_Statement_setUInt(void ** exception, void * stmt, unsigned int idx, unsigned int value);
    OGWEXPORT unsigned int OCCIgateway_Statement_status(void ** exception, void * stmt);

    /* ResultSet */
    OGWEXPORT void OCCIgateway_ResultSet_dtor(void ** exception, void * rset);
    OGWEXPORT void OCCIgateway_ResultSet_cancel(void ** exception, void * rset);
    OGWEXPORT const char * OCCIgateway_ResultSet_getCharSet(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT void * OCCIgateway_ResultSet_getBlob(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT void * OCCIgateway_ResultSet_getBytes(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT void * OCCIgateway_ResultSet_getClob(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_ResultSet_getCurrentStreamColumn(void ** exception, void * rset);
    OGWEXPORT unsigned int OCCIgateway_ResultSet_getCurrentStreamRow(void ** exception, void * rset);
    OGWEXPORT void * OCCIgateway_ResultSet_getCursor(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT double OCCIgateway_ResultSet_getDouble(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT float OCCIgateway_ResultSet_getFloat(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT int OCCIgateway_ResultSet_getInt(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_ResultSet_getMaxColumnSize(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_ResultSet_getNumArrayRows(void ** exception, void * rset);
    OGWEXPORT void * OCCIgateway_ResultSet_getNumber(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT void * OCCIgateway_ResultSet_getRowid(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT void * OCCIgateway_ResultSet_getStream(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT const char * OCCIgateway_ResultSet_getString(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_ResultSet_getUInt(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT int OCCIgateway_ResultSet_isNull(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT int OCCIgateway_ResultSet_isTruncated(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT unsigned int OCCIgateway_ResultSet_next(void ** exception, void * rset, unsigned int numRows);
    OGWEXPORT int OCCIgateway_ResultSet_preTruncationLength(void ** exception, void * rset, unsigned int idx);
    OGWEXPORT void OCCIgateway_ResultSet_setBinaryStreamMode(void ** exception, void * rset, unsigned int idx, unsigned int size);
    OGWEXPORT void OCCIgateway_ResultSet_setCharacterStreamMode(void ** exception, void * rset, unsigned int idx, unsigned int size);
    OGWEXPORT void OCCIgateway_ResultSet_setCharSet(void ** exception, void * rset, unsigned int idx, const char * charset);
    OGWEXPORT void OCCIgateway_ResultSet_setErrorOnNull(void ** exception, void * rset, unsigned int idx, int causeException);
    OGWEXPORT void OCCIgateway_ResultSet_setErrorOnTruncate(void ** exception, void * rset, unsigned int idx, int causeException);
    
    /* Stream */
    OGWEXPORT void OCCIgateway_Stream_dtor(void ** exception, void * strm);
}

#endif
