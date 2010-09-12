#ifndef __OCCI_PROXY_H__
#define __OCCI_PROXY_H__

#include <occi.h>

namespace occi_proxy {
    class SQLException {
      public:
          SQLException(void *);
          ~SQLException();
        const char * what() const;
      private:
        void * e; 
    };
    class Environment {
      public:
        enum Mode {
            DEFAULT = oracle::occi::Environment::Mode::DEFAULT,
            OBJECT = oracle::occi::Environment::Mode::OBJECT,
            SHARED = oracle::occi::Environment::Mode::SHARED,
            NO_USERCALLBACKS = oracle::occi::Environment::Mode::NO_USERCALLBACKS,
            THREADED_MUTEXED = oracle::occi::Environment::Mode::THREADED_MUTEXED,
            THREADED_UNMUTEXED = oracle::occi::Environment::Mode::THREADED_UNMUTEXED,
            EVENTS = oracle::occi::Environment::Mode::EVENTS,
            USE_LDAP = oracle::occi::Environment::Mode::USE_LDAP,
        };
        ~Environment() throw (SQLException);
        static Environment * createEnvironment(Mode mode, void *ctxp = 0, void *(*malocfp)(void *ctxp, size_t size) = 0, void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0, void (*mfreefp)(void *ctxp, void *memptr) = 0) throw (SQLException);
        static Environment * createEnvironment(const std::string &charset, const std::string &ncharset, Mode mode, void *ctxp = 0, void *(*malocfp)(void *ctxp, size_t size) = 0, void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0, void (*mfreefp)(void *ctxp, void *memptr) = 0) throw (SQLException);
      private:
        void * envr;
    };
};

#endif
