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

    /* Environment */
    OGWEXPORT void OCCIgateway_Environment_dtor(void ** exception, void * envr);
    OGWEXPORT void * OCCIgateway_createEnvironment(void ** exception, Environment::Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size), void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize), void (*mfreefp)(void *ctxp, void *memptr));
    OGWEXPORT void * OCCIgateway_createEnvironment_charset(void ** exception, const char * charset, const char * ncharset, Environment::Mode mode, void *ctxp, void *(*malocfp)(void *ctxp, size_t size), void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize), void (*mfreefp)(void *ctxp, void *memptr));
    OGWEXPORT void OCCIgateway_terminateEnvironment(void ** exception, void * _envr);
    OGWEXPORT void * OCCIgateway_Environment_createConnection(void ** exception, void * _envr, const char * username, const char * password, const char * url);    
    OGWEXPORT int OCCIgateway_Environment_getCacheMaxSize(void ** exception, void * _envr);
    OGWEXPORT int OCCIgateway_Environment_getCacheOptSize(void ** exception, void * _envr);
    OGWEXPORT void OCCIgateway_Environment_setCacheMaxSize(void ** exception, void * _envr, int v);
    OGWEXPORT void OCCIgateway_Environment_setCacheOptSize(void ** exception, void * _envr, int v);
    OGWEXPORT unsigned int OCCIgateway_Environment_getCurrentHeapSize(void ** exception, void * _envr);
    OGWEXPORT void OCCIgateway_Environment_terminateConnection(void ** exception, void * _envr, void * _conn);

    /* Connection */
    OGWEXPORT void OCCIgateway_Connection_dtor(void ** exception, void * conn);
    OGWEXPORT void OCCIgateway_Connection_changePassword(void ** exception, void * _conn, const char * username, const char * oldpassword, const char * newpassword);
    OGWEXPORT void OCCIgateway_Connection_commit(void ** exception, void * _conn);
    OGWEXPORT void * OCCIgateway_Connection_createStatement(void ** exception, void * _conn, const char * sql);
    OGWEXPORT void OCCIgateway_Connection_flushCache(void ** exception, void * _conn);
    OGWEXPORT const char * OCCIgateway_Connection_getClientCharSet(void ** exception, void * _conn);
    OGWEXPORT const char * OCCIgateway_Connection_getClientNCHARCharSet(void ** exception, void * _conn);
    OGWEXPORT void OCCIgateway_Connection_rollback(void ** exception, void * _conn);

    /* Statement */
    OGWEXPORT void OCCIgateway_Statement_dtor(void ** exception, void * stmt);
    OGWEXPORT void OCCIgateway_Statement_addIteration(void ** exception, void * stmt);
    OGWEXPORT void OCCIgateway_Statement_closeResultSet(void ** exception, void * stmt, void * rset);
    OGWEXPORT void OCCIgateway_Statement_closeStream(void ** exception, void * stmt, void * strm);
    OGWEXPORT int OCCIgateway_Statement_execute(void ** exception, void * stmt, const char * sql);
    OGWEXPORT int OCCIgateway_Statement_executeArrayUpdate(void ** exception, void * _stmt, unsigned int v);

    /* ResultSet */
    OGWEXPORT void OCCIgateway_ResultSet_dtor(void ** exception, void * rset);
    
    /* Stream */
    OGWEXPORT void OCCIgateway_Stream_dtor(void ** exception, void * _strm);
}

#endif
