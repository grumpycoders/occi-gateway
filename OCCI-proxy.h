#ifndef __OCCI_PROXY_H__
#define __OCCI_PROXY_H__

#include <occi.h>

namespace occi_proxy {
    class SQLException {
      public:
          SQLException(void *);
          ~SQLException();
        const char * what() const;
        std::string getMessage() const;
        int getErrorCode() const;
      private:
        void * e; 
    };
    enum Type {
        OCCI_SQLT_CHR = oracle::occi::OCCI_SQLT_CHR,
        OCCI_SQLT_NUM = oracle::occi::OCCI_SQLT_NUM,
        OCCIINT = oracle::occi::OCCIINT,
        OCCIFLOAT = oracle::occi::OCCIFLOAT,
        OCCIBFLOAT = oracle::occi::OCCIBFLOAT,
        OCCIBDOUBLE = oracle::occi::OCCIBDOUBLE,
        OCCIIBFLOAT = oracle::occi::OCCIIBFLOAT,
        OCCIIBDOUBLE = oracle::occi::OCCIIBDOUBLE,
        OCCI_SQLT_STR = oracle::occi::OCCI_SQLT_STR,
        OCCI_SQLT_VNU = oracle::occi::OCCI_SQLT_VNU,
        OCCI_SQLT_PDN = oracle::occi::OCCI_SQLT_PDN,
        OCCI_SQLT_LNG = oracle::occi::OCCI_SQLT_LNG,
        OCCI_SQLT_VCS = oracle::occi::OCCI_SQLT_VCS,
        OCCI_SQLT_NON = oracle::occi::OCCI_SQLT_NON,
        OCCI_SQLT_RID = oracle::occi::OCCI_SQLT_RID,
        OCCI_SQLT_DAT = oracle::occi::OCCI_SQLT_DAT,
        OCCI_SQLT_VBI = oracle::occi::OCCI_SQLT_VBI,
        OCCI_SQLT_BIN = oracle::occi::OCCI_SQLT_BIN,
        OCCI_SQLT_LBI = oracle::occi::OCCI_SQLT_LBI,
        OCCIUNSIGNED_INT = oracle::occi::OCCIUNSIGNED_INT,
        OCCI_SQLT_SLS = oracle::occi::OCCI_SQLT_SLS,
        OCCI_SQLT_LVC = oracle::occi::OCCI_SQLT_LVC,
        OCCI_SQLT_LVB = oracle::occi::OCCI_SQLT_LVB,
        OCCI_SQLT_AFC = oracle::occi::OCCI_SQLT_AFC,
        OCCI_SQLT_AVC = oracle::occi::OCCI_SQLT_AVC,
        OCCI_SQLT_CUR = oracle::occi::OCCI_SQLT_CUR,
        OCCI_SQLT_RDD = oracle::occi::OCCI_SQLT_RDD,
        OCCI_SQLT_LAB = oracle::occi::OCCI_SQLT_LAB,
        OCCI_SQLT_OSL = oracle::occi::OCCI_SQLT_OSL,
        OCCI_SQLT_NTY = oracle::occi::OCCI_SQLT_NTY,
        OCCI_SQLT_REF = oracle::occi::OCCI_SQLT_REF,
        OCCI_SQLT_CLOB = oracle::occi::OCCI_SQLT_CLOB,
        OCCI_SQLT_BLOB = oracle::occi::OCCI_SQLT_BLOB,
        OCCI_SQLT_BFILEE = oracle::occi::OCCI_SQLT_BFILEE,
        OCCI_SQLT_CFILEE = oracle::occi::OCCI_SQLT_CFILEE,
        OCCI_SQLT_RSET = oracle::occi::OCCI_SQLT_RSET,
        OCCI_SQLT_NCO = oracle::occi::OCCI_SQLT_NCO,
        OCCI_SQLT_VST = oracle::occi::OCCI_SQLT_VST,
        OCCI_SQLT_ODT = oracle::occi::OCCI_SQLT_ODT,
        OCCI_SQLT_DATE = oracle::occi::OCCI_SQLT_DATE,
        OCCI_SQLT_TIME = oracle::occi::OCCI_SQLT_TIME,
        OCCI_SQLT_TIME_TZ = oracle::occi::OCCI_SQLT_TIME_TZ,
        OCCI_SQLT_TIMESTAMP = oracle::occi::OCCI_SQLT_TIMESTAMP,
        OCCI_SQLT_TIMESTAMP_TZ = oracle::occi::OCCI_SQLT_TIMESTAMP_TZ,
        OCCI_SQLT_INTERVAL_YM = oracle::occi::OCCI_SQLT_INTERVAL_YM,
        OCCI_SQLT_INTERVAL_DS = oracle::occi::OCCI_SQLT_INTERVAL_DS,
        OCCI_SQLT_TIMESTAMP_LTZ = oracle::occi::OCCI_SQLT_TIMESTAMP_LTZ,
        OCCI_SQLT_FILE = oracle::occi::OCCI_SQLT_FILE,
        OCCI_SQLT_CFILE = oracle::occi::OCCI_SQLT_CFILE,
        OCCI_SQLT_BFILE = oracle::occi::OCCI_SQLT_BFILE,
        OCCICHAR = oracle::occi::OCCICHAR,
        OCCIDOUBLE = oracle::occi::OCCIDOUBLE,
        OCCIBOOL = oracle::occi::OCCIBOOL,
        OCCIANYDATA = oracle::occi::OCCIANYDATA,
        OCCINUMBER = oracle::occi::OCCINUMBER,
        OCCIBLOB = oracle::occi::OCCIBLOB,
        OCCIBFILE = oracle::occi::OCCIBFILE,
        OCCIBYTES = oracle::occi::OCCIBYTES,
        OCCICLOB = oracle::occi::OCCICLOB,
        OCCIVECTOR = oracle::occi::OCCIVECTOR,
        OCCIMETADATA = oracle::occi::OCCIMETADATA,
        OCCIPOBJECT = oracle::occi::OCCIPOBJECT,
        OCCIREF = oracle::occi::OCCIREF,
        OCCIREFANY = oracle::occi::OCCIREFANY,
        OCCISTRING = oracle::occi::OCCISTRING,
        OCCISTREAM = oracle::occi::OCCISTREAM,
        OCCIDATE = oracle::occi::OCCIDATE,
        OCCIINTERVALDS = oracle::occi::OCCIINTERVALDS,
        OCCIINTERVALYM = oracle::occi::OCCIINTERVALYM,
        OCCITIMESTAMP = oracle::occi::OCCITIMESTAMP,
        OCCIROWID = oracle::occi::OCCIROWID,
        OCCICURSOR = oracle::occi::OCCICURSOR,
    };
    class Connection {
      public:
          Connection(void *);
          ~Connection() throw (SQLException);
      private:
        void * conn;
    };
    class Environment {
      public:
        enum Mode {
            DEFAULT = oracle::occi::Environment::DEFAULT,
            OBJECT = oracle::occi::Environment::OBJECT,
            SHARED = oracle::occi::Environment::SHARED,
            NO_USERCALLBACKS = oracle::occi::Environment::NO_USERCALLBACKS,
            THREADED_MUTEXED = oracle::occi::Environment::THREADED_MUTEXED,
            THREADED_UNMUTEXED = oracle::occi::Environment::THREADED_UNMUTEXED,
            EVENTS = oracle::occi::Environment::EVENTS,
            USE_LDAP = oracle::occi::Environment::USE_LDAP,
        };
        Environment(void *);
        ~Environment() throw (SQLException);
        static Environment * createEnvironment(Mode mode, void *ctxp = 0, void *(*malocfp)(void *ctxp, size_t size) = 0, void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0, void (*mfreefp)(void *ctxp, void *memptr) = 0) throw (SQLException);
        static Environment * createEnvironment(const std::string &charset, const std::string &ncharset, Mode mode, void *ctxp = 0, void *(*malocfp)(void *ctxp, size_t size) = 0, void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0, void (*mfreefp)(void *ctxp, void *memptr) = 0) throw (SQLException);
        Connection * createConnection(const std::string &username, const std::string &password, const std::string &url = "");
      private:
        void * envr;
    };
};

#endif
