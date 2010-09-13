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

    /* Connection */
    OGWEXPORT void OCCIgateway_Connection_dtor(void ** exception, void * conn);
}

#endif
