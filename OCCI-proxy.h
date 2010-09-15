#ifndef __OCCI_PROXY_H__
#define __OCCI_PROXY_H__

#include <occi.h>

#pragma warning (disable: 4290)

namespace occi_proxy {
    class SQLException;
    class Blob;
    class Bytes;
    class Clob;
    class Number;
    class ResultSet;
    class Stream;
    class Statement;
    class Connection;
    class Environment;
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
    enum LobOpenMode {
        OCCI_LOB_READONLY = oracle::occi::OCCI_LOB_READONLY,
        OCCI_LOB_READWRITE = oracle::occi::OCCI_LOB_READWRITE,
        OCCI_LOB_WRITEONLY = oracle::occi::OCCI_LOB_WRITEONLY,
        OCCI_LOB_APPENDONLY = oracle::occi::OCCI_LOB_APPENDONLY,
        OCCI_LOB_FULLOVERWRITE = oracle::occi::OCCI_LOB_FULLOVERWRITE,
        OCCI_LOB_FULLREAD = oracle::occi::OCCI_LOB_FULLREAD,
    };
    template<class T> class refCounter;
    class SQLException {
      public:
          SQLException(const SQLException &);
          ~SQLException();
        const char * what() const;
        std::string getMessage() const;
        int getErrorCode() const;
        static void checkException(void *) throw (SQLException);
      protected:
          SQLException(void *, float);
        static void dtor(void * obj);
        friend class refCounter<SQLException>;
      private:
        refCounter<SQLException> * ref; 
    };
    class Blob {
      public:
          Blob(const Blob &);
          ~Blob();
        Stream * getStream(unsigned int offset = 1, unsigned int amount = 0);
        void closeStream(Stream * strm);
        void open(LobOpenMode mode = OCCI_LOB_READWRITE);
        void setEmpty();
        unsigned int writeChunk(unsigned int amt, unsigned char * buffer, unsigned int bufsize, unsigned int offset = 1);
        void close();
      protected:
          Blob(void *, float);
        static void dtor(void * obj);
        friend class refCounter<Blob>;
        friend class Statement;
        friend class ResultSet;
      private:
        refCounter<Blob> * ref;
    };
    class Bytes {
      public:
          Bytes(unsigned char * value, unsigned int count, unsigned int offset = 0, const Environment * envr = NULL);
          Bytes(const Bytes &);
          ~Bytes();
        unsigned int length() const;
        void getBytes(unsigned char * dst, unsigned int count, unsigned int srcBegin = 0, unsigned int dstBegin = 0) const;
      protected:
          Bytes(void *, float);
        static void dtor(void * obj);
        friend class refCounter<Bytes>;
        friend class Statement;
        friend class ResultSet;
      private:
        refCounter<Bytes> * ref;
    };
    class Clob {
      public:
          Clob(const Clob &);
          ~Clob();
        Stream * getStream(unsigned int offset = 1, unsigned int amount = 0);
        void closeStream(Stream * strm);
      protected:
          Clob(void *, float);
        static void dtor(void * obj);
        friend class refCounter<Clob>;
        friend class Statement;
        friend class ResultSet;
      private:
        refCounter<Clob> * ref;
    };
    class Number {
      public:
          Number(const Number &);
          ~Number();
        std::string toText(const Environment * envr, const std::string &fmt, const std::string &nslparam = "") const;
        void fromText(const Environment * envr, const std::string &number, const std::string &fmt, const std::string &nslparam = "");
      protected:
          Number(void *, float);
        static void dtor(void * obj);
        friend class refCounter<Number>;
        friend class Statement;
      private:
        refCounter<Number> * ref;
    };
    class ResultSet {
      public:
          ~ResultSet();
        void cancel();
        std::string getCharSet(unsigned int idx) const;
        Blob getBlob(unsigned int idx);
        Bytes getBytes(unsigned int idx);
        Clob getClob(unsigned int idx);
        unsigned int getCurrentStreamColumn() const;
      protected:
          ResultSet(void *, float);
        void * rset;
        friend class Statement;
    };
    class Stream {
      public:
          ~Stream();
      protected:
          Stream(void *, float);
        void * strm;
        friend class Statement;
        friend class ResultSet;
        friend class Blob;
        friend class Clob;
    };
    class Statement {
      public:
        enum Status {
            UNPREPARED = oracle::occi::Statement::UNPREPARED,
            PREPARED = oracle::occi::Statement::PREPARED,
            RESULT_SET_AVAILABLE = oracle::occi::Statement::RESULT_SET_AVAILABLE,
            UPDATE_COUNT_AVAILABLE = oracle::occi::Statement::UPDATE_COUNT_AVAILABLE,
            NEEDS_STREAM_DATA = oracle::occi::Statement::NEEDS_STREAM_DATA,
            STREAM_DATA_AVAILABLE = oracle::occi::Statement::STREAM_DATA_AVAILABLE,
        };
          ~Statement();
        void addIteration();
        void closeResultSet(ResultSet * rset);
        void closeStream(Stream * strm);
        Status execute(const std::string &sql = "");
        Status executeArrayUpdate(unsigned int arrayLength);
        ResultSet * executeQuery(const std::string &sql = "");
        unsigned int executeUpdate(const std::string &sql = "");
        bool getAutoCommit() const;
        Blob getBlob(unsigned int idx);
        Bytes getBytes(unsigned int idx);
        std::string getCharSet(unsigned int idx);
        Clob getClob(unsigned int idx);
        unsigned int getCurrentIteration() const;
        unsigned int getCurrentStreamIteration() const;
        unsigned int getCurrentStreamParam() const;
        ResultSet * getCursor(unsigned int idx);
        bool getDatabaseNCHARParam(unsigned int idx);
        double getDouble(unsigned int idx);
        float getFloat(unsigned int idx);
        int getInt(unsigned int idx);
        unsigned int getMaxIterations() const;
        unsigned int getMaxParamSize(unsigned int idx) const;
        Number getNumber(unsigned int idx);
        ResultSet * getResultSet();
        Bytes getRowid(unsigned int idx);
        std::string getSQL() const;
        Stream * getStream(unsigned int idx);
        std::string getString(unsigned int idx);
        unsigned int getUInt(unsigned int idx);
        unsigned int getUpdateCount() const;
        bool isNull(unsigned int idx) const;
        bool isTruncated(unsigned int idx) const;
        int preTruncationLength(unsigned int idx) const;
        void registerOutParam(unsigned int idx, Type type, unsigned int maxSize = 0, const std::string &sqltype = "");
        void setAutoCommit(bool autoCommit);
        void setBinaryStreamMode(unsigned int idx, unsigned int size);
        void setBytes(unsigned int idx, const Bytes &bytes);
        void setCharacterStreamMode(unsigned int idx, unsigned int size);
        void setCharSet(unsigned int idx, const std::string &charset);
        void setDatabaseNCHARParam(unsigned int idx, bool isNCHAR);
        void setDouble(unsigned int idx, double value);
        void setErrorOnNull(unsigned int idx, bool causeException);
        void setErrorOnTruncate(unsigned int idx, bool causeException);
        void setFloat(unsigned int idx, float value);
        void setInt(unsigned int idx, int value);
        void setMaxIterations(unsigned int maxIterations);
        void setMaxParamSize(unsigned int idx, unsigned int maxSize);
        void setNull(unsigned int idx, Type type);
        void setNumber(unsigned int idx, const Number &n);
        void setPrefetchMemorySize(unsigned int bytes);
        void setPrefetchRowCount(unsigned int rowCount);
        void setRowid(unsigned int idx, const Bytes &x);
        void setSQL(const std::string &sql);
        void setString(unsigned int idx, const std::string &str);
        void setUInt(unsigned int idx, unsigned int value);
        Status status() const;
      protected:
          Statement(void *, float);
        void * stmt;
        friend class Connection;
    };
    class Connection {
      public:
            ~Connection();
          void changePassword(const std::string &username, const std::string &oldPassword, const std::string &newPassword);
          void commit();
          Statement * createStatement(const std::string &sql = "");
          void flushCache();
          std::string getClientCharSet() const ;
          std::string getClientNCHARCharSet() const ;
          void rollback();
      protected:
          Connection(void *, float);
        void * conn;
        friend class Environment;
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
          ~Environment();
        static Environment * createEnvironment(Mode mode, void *ctxp = 0, void *(*malocfp)(void *ctxp, size_t size) = 0, void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0, void (*mfreefp)(void *ctxp, void *memptr) = 0);
        static Environment * createEnvironment(const std::string &charset, const std::string &ncharset, Mode mode, void *ctxp = 0, void *(*malocfp)(void *ctxp, size_t size) = 0, void *(*ralocfp)(void *ctxp, void *memptr, size_t newsize) = 0, void (*mfreefp)(void *ctxp, void *memptr) = 0);
        static void terminateEnvironment(Environment * envr);
        Connection * createConnection(const std::string &username, const std::string &password, const std::string &url = "");
        int getCacheMaxSize() const ;
        int getCacheOptSize() const ;
        void setCacheMaxSize(int maxSize);
        void setCacheOptSize(int optSize);
        unsigned int getCurrentHeapSize() const ;
        void terminateConnection(Connection * conn);
      private:
          Environment(void *, float);
        void * envr;
        friend class Number;
        friend class Bytes;
    };
};

#endif
