#include "OCCI-gateway-internals.h"
#include "OCCI-proxy.h"

occi_proxy::SQLException::SQLException(void * _e) : e(_e) { }

occi_proxy::SQLException::~SQLException() {
    OCCIgateway_SQLException_dtor(e);
}

const char * occi_proxy::SQLException::what() const {
    return OCCIgateway_SQLException_what(e);
}

occi_proxy::Environment::~Environment() throw (occi_proxy::SQLException) {
    void * e = NULL;
    OCCIgateway_Environment_dtor(&e, envr);
    if (e)
        throw occi_proxy::SQLException(e);
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) throw (SQLException) {
    occi_proxy::Environment * envr;
    void * e;
    envr = static_cast<occi_proxy::Environment *>(OCCIgateway_createEnvironment(&e, static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp));
    if (e)
        throw occi_proxy::SQLException(e);
    return envr;
}

occi_proxy::Environment * occi_proxy::Environment::createEnvironment(const std::string &charset, const std::string &ncharset, occi_proxy::Environment::Mode mode, void *ctxp, void *(*malocfp)(void *, size_t), void *(*ralocfp)(void *, void *, size_t), void (*mfreefp)(void *, void *)) throw (SQLException) {
    occi_proxy::Environment * envr;
    void * e;
    envr = static_cast<occi_proxy::Environment *>(OCCIgateway_createEnvironment_charset(&e, charset.c_str(), ncharset.c_str(), static_cast<oracle::occi::Environment::Mode>(mode), ctxp, malocfp, ralocfp, mfreefp));
    if (e)
        throw occi_proxy::SQLException(e);
    return envr;
}
