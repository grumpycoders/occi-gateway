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
        friend class ResultSet;
      private:
        refCounter<Number> * ref;
    };
    class MetaData {
      public:
        enum AttrId {
            ATTR_PTYPE = oracle::occi::MetaData::ATTR_PTYPE,
            ATTR_TIMESTAMP = oracle::occi::MetaData::ATTR_TIMESTAMP,
            ATTR_OBJ_ID = oracle::occi::MetaData::ATTR_OBJ_ID,
            ATTR_OBJ_NAME = oracle::occi::MetaData::ATTR_OBJ_NAME,
            ATTR_OBJ_SCHEMA = oracle::occi::MetaData::ATTR_OBJ_SCHEMA,
            ATTR_OBJID = oracle::occi::MetaData::ATTR_OBJID,
            ATTR_NUM_COLS = oracle::occi::MetaData::ATTR_NUM_COLS,
            ATTR_LIST_COLUMNS = oracle::occi::MetaData::ATTR_LIST_COLUMNS,
            ATTR_REF_TDO = oracle::occi::MetaData::ATTR_REF_TDO,
            ATTR_IS_TEMPORARY = oracle::occi::MetaData::ATTR_IS_TEMPORARY,
            ATTR_IS_TYPED = oracle::occi::MetaData::ATTR_IS_TYPED,
            ATTR_DURATION = oracle::occi::MetaData::ATTR_DURATION,
            ATTR_COLLECTION_ELEMENT = oracle::occi::MetaData::ATTR_COLLECTION_ELEMENT,
            ATTR_RDBA = oracle::occi::MetaData::ATTR_RDBA,
            ATTR_TABLESPACE = oracle::occi::MetaData::ATTR_TABLESPACE,
            ATTR_CLUSTERED = oracle::occi::MetaData::ATTR_CLUSTERED,
            ATTR_PARTITIONED = oracle::occi::MetaData::ATTR_PARTITIONED,
            ATTR_INDEX_ONLY = oracle::occi::MetaData::ATTR_INDEX_ONLY,
            ATTR_LIST_ARGUMENTS = oracle::occi::MetaData::ATTR_LIST_ARGUMENTS,
            ATTR_IS_INVOKER_RIGHTS = oracle::occi::MetaData::ATTR_IS_INVOKER_RIGHTS,
            ATTR_LIST_SUBPROGRAMS = oracle::occi::MetaData::ATTR_LIST_SUBPROGRAMS,
            ATTR_NAME = oracle::occi::MetaData::ATTR_NAME,
            ATTR_OVERLOAD_ID = oracle::occi::MetaData::ATTR_OVERLOAD_ID,
            ATTR_TYPECODE = oracle::occi::MetaData::ATTR_TYPECODE,
            ATTR_COLLECTION_TYPECODE = oracle::occi::MetaData::ATTR_COLLECTION_TYPECODE,
            ATTR_VERSION = oracle::occi::MetaData::ATTR_VERSION,
            ATTR_IS_INCOMPLETE_TYPE = oracle::occi::MetaData::ATTR_IS_INCOMPLETE_TYPE,
            ATTR_IS_SYSTEM_TYPE = oracle::occi::MetaData::ATTR_IS_SYSTEM_TYPE,
            ATTR_IS_PREDEFINED_TYPE = oracle::occi::MetaData::ATTR_IS_PREDEFINED_TYPE,
            ATTR_IS_TRANSIENT_TYPE = oracle::occi::MetaData::ATTR_IS_TRANSIENT_TYPE,
            ATTR_IS_SYSTEM_GENERATED_TYPE = oracle::occi::MetaData::ATTR_IS_SYSTEM_GENERATED_TYPE,
            ATTR_HAS_NESTED_TABLE = oracle::occi::MetaData::ATTR_HAS_NESTED_TABLE,
            ATTR_HAS_LOB = oracle::occi::MetaData::ATTR_HAS_LOB,
            ATTR_HAS_FILE = oracle::occi::MetaData::ATTR_HAS_FILE,
            ATTR_NUM_TYPE_ATTRS = oracle::occi::MetaData::ATTR_NUM_TYPE_ATTRS,
            ATTR_LIST_TYPE_ATTRS = oracle::occi::MetaData::ATTR_LIST_TYPE_ATTRS,
            ATTR_NUM_TYPE_METHODS = oracle::occi::MetaData::ATTR_NUM_TYPE_METHODS,
            ATTR_LIST_TYPE_METHODS = oracle::occi::MetaData::ATTR_LIST_TYPE_METHODS,
            ATTR_MAP_METHOD = oracle::occi::MetaData::ATTR_MAP_METHOD,
            ATTR_ORDER_METHOD = oracle::occi::MetaData::ATTR_ORDER_METHOD,
            ATTR_DATA_SIZE = oracle::occi::MetaData::ATTR_DATA_SIZE,
            ATTR_DATA_TYPE = oracle::occi::MetaData::ATTR_DATA_TYPE,
            ATTR_PRECISION = oracle::occi::MetaData::ATTR_PRECISION,
            ATTR_SCALE = oracle::occi::MetaData::ATTR_SCALE,
            ATTR_TYPE_NAME = oracle::occi::MetaData::ATTR_TYPE_NAME,
            ATTR_SCHEMA_NAME = oracle::occi::MetaData::ATTR_SCHEMA_NAME,
            ATTR_CHARSET_ID = oracle::occi::MetaData::ATTR_CHARSET_ID,
            ATTR_CHARSET_FORM = oracle::occi::MetaData::ATTR_CHARSET_FORM,
            ATTR_ENCAPSULATION = oracle::occi::MetaData::ATTR_ENCAPSULATION,
            ATTR_IS_CONSTRUCTOR = oracle::occi::MetaData::ATTR_IS_CONSTRUCTOR,
            ATTR_IS_DESTRUCTOR = oracle::occi::MetaData::ATTR_IS_DESTRUCTOR,
            ATTR_IS_OPERATOR = oracle::occi::MetaData::ATTR_IS_OPERATOR,
            ATTR_IS_SELFISH = oracle::occi::MetaData::ATTR_IS_SELFISH,
            ATTR_IS_MAP = oracle::occi::MetaData::ATTR_IS_MAP,
            ATTR_IS_ORDER = oracle::occi::MetaData::ATTR_IS_ORDER,
            ATTR_IS_RNDS = oracle::occi::MetaData::ATTR_IS_RNDS,
            ATTR_IS_RNPS = oracle::occi::MetaData::ATTR_IS_RNPS,
            ATTR_IS_WNDS = oracle::occi::MetaData::ATTR_IS_WNDS,
            ATTR_IS_WNPS = oracle::occi::MetaData::ATTR_IS_WNPS,
            ATTR_NUM_ELEMS = oracle::occi::MetaData::ATTR_NUM_ELEMS,
            ATTR_LINK = oracle::occi::MetaData::ATTR_LINK,
            ATTR_MIN = oracle::occi::MetaData::ATTR_MIN,
            ATTR_MAX = oracle::occi::MetaData::ATTR_MAX,
            ATTR_INCR = oracle::occi::MetaData::ATTR_INCR,
            ATTR_CACHE = oracle::occi::MetaData::ATTR_CACHE,
            ATTR_ORDER = oracle::occi::MetaData::ATTR_ORDER,
            ATTR_HW_MARK = oracle::occi::MetaData::ATTR_HW_MARK,
            ATTR_IS_NULL = oracle::occi::MetaData::ATTR_IS_NULL,
            ATTR_POSITION = oracle::occi::MetaData::ATTR_POSITION,
            ATTR_HAS_DEFAULT = oracle::occi::MetaData::ATTR_HAS_DEFAULT,
            ATTR_LEVEL = oracle::occi::MetaData::ATTR_LEVEL,
            ATTR_IOMODE = oracle::occi::MetaData::ATTR_IOMODE,
            ATTR_RADIX = oracle::occi::MetaData::ATTR_RADIX,
            ATTR_SUB_NAME = oracle::occi::MetaData::ATTR_SUB_NAME,
            ATTR_LIST_OBJECTS = oracle::occi::MetaData::ATTR_LIST_OBJECTS,
            ATTR_NCHARSET_ID = oracle::occi::MetaData::ATTR_NCHARSET_ID,
            ATTR_LIST_SCHEMAS = oracle::occi::MetaData::ATTR_LIST_SCHEMAS,
            ATTR_MAX_PROC_LEN = oracle::occi::MetaData::ATTR_MAX_PROC_LEN,
            ATTR_MAX_COLUMN_LEN = oracle::occi::MetaData::ATTR_MAX_COLUMN_LEN,
            ATTR_CURSOR_COMMIT_BEHAVIOR = oracle::occi::MetaData::ATTR_CURSOR_COMMIT_BEHAVIOR,
            ATTR_MAX_CATALOG_NAMELEN = oracle::occi::MetaData::ATTR_MAX_CATALOG_NAMELEN,
            ATTR_CATALOG_LOCATION = oracle::occi::MetaData::ATTR_CATALOG_LOCATION,
            ATTR_SAVEPOINT_SUPPORT = oracle::occi::MetaData::ATTR_SAVEPOINT_SUPPORT,
            ATTR_NOWAIT_SUPPORT = oracle::occi::MetaData::ATTR_NOWAIT_SUPPORT,
            ATTR_AUTOCOMMIT_DDL = oracle::occi::MetaData::ATTR_AUTOCOMMIT_DDL,
            ATTR_LOCKING_MODE = oracle::occi::MetaData::ATTR_LOCKING_MODE,
            ATTR_IS_FINAL_TYPE = oracle::occi::MetaData::ATTR_IS_FINAL_TYPE,
            ATTR_IS_INSTANTIABLE_TYPE = oracle::occi::MetaData::ATTR_IS_INSTANTIABLE_TYPE,
            ATTR_IS_SUBTYPE = oracle::occi::MetaData::ATTR_IS_SUBTYPE,
            ATTR_SUPERTYPE_SCHEMA_NAME = oracle::occi::MetaData::ATTR_SUPERTYPE_SCHEMA_NAME,
            ATTR_SUPERTYPE_NAME = oracle::occi::MetaData::ATTR_SUPERTYPE_NAME,
            ATTR_FSPRECISION = oracle::occi::MetaData::ATTR_FSPRECISION,
            ATTR_LFPRECISION = oracle::occi::MetaData::ATTR_LFPRECISION,
            ATTR_IS_FINAL_METHOD = oracle::occi::MetaData::ATTR_IS_FINAL_METHOD,
            ATTR_IS_INSTANTIABLE_METHOD = oracle::occi::MetaData::ATTR_IS_INSTANTIABLE_METHOD,
            ATTR_IS_OVERRIDING_METHOD = oracle::occi::MetaData::ATTR_IS_OVERRIDING_METHOD,
            ATTR_CHAR_USED = oracle::occi::MetaData::ATTR_CHAR_USED,
            ATTR_CHAR_SIZE = oracle::occi::MetaData::ATTR_CHAR_SIZE,
            ATTR_COL_ENC = oracle::occi::MetaData::ATTR_COL_ENC,
            ATTR_COL_ENC_SALT = oracle::occi::MetaData::ATTR_COL_ENC_SALT,
            ATTR_TABLE_ENC = oracle::occi::MetaData::ATTR_TABLE_ENC,
            ATTR_TABLE_ENC_ALG = oracle::occi::MetaData::ATTR_TABLE_ENC_ALG,
            ATTR_TABLE_ENC_ALG_ID = oracle::occi::MetaData::ATTR_TABLE_ENC_ALG_ID,
        };
        enum ParamType {
            PTYPE_TABLE = oracle::occi::MetaData::PTYPE_TABLE,
            PTYPE_VIEW = oracle::occi::MetaData::PTYPE_VIEW,
            PTYPE_PROC = oracle::occi::MetaData::PTYPE_PROC,
            PTYPE_FUNC = oracle::occi::MetaData::PTYPE_FUNC,
            PTYPE_PKG = oracle::occi::MetaData::PTYPE_PKG,
            PTYPE_TYPE = oracle::occi::MetaData::PTYPE_TYPE,
            PTYPE_TYPE_ATTR = oracle::occi::MetaData::PTYPE_TYPE_ATTR,
            PTYPE_TYPE_COLL = oracle::occi::MetaData::PTYPE_TYPE_COLL,
            PTYPE_TYPE_METHOD = oracle::occi::MetaData::PTYPE_TYPE_METHOD,
            PTYPE_SYN = oracle::occi::MetaData::PTYPE_SYN,
            PTYPE_SEQ = oracle::occi::MetaData::PTYPE_SEQ,
            PTYPE_COL = oracle::occi::MetaData::PTYPE_COL,
            PTYPE_ARG = oracle::occi::MetaData::PTYPE_ARG,
            PTYPE_TYPE_ARG = oracle::occi::MetaData::PTYPE_TYPE_ARG,
            PTYPE_TYPE_RESULT = oracle::occi::MetaData::PTYPE_TYPE_RESULT,
            PTYPE_SCHEMA = oracle::occi::MetaData::PTYPE_SCHEMA,
            PTYPE_DATABASE = oracle::occi::MetaData::PTYPE_DATABASE,
            PTYPE_UNK = oracle::occi::MetaData::PTYPE_UNK,
        };
        enum {
            DURATION_SESSION = oracle::occi::MetaData::DURATION_SESSION,
            DURATION_TRANS = oracle::occi::MetaData::DURATION_TRANS,
            DURATION_NULL = oracle::occi::MetaData::DURATION_NULL,
            TYPEENCAP_PRIVATE = oracle::occi::MetaData::TYPEENCAP_PRIVATE,
            TYPEENCAP_PUBLIC = oracle::occi::MetaData::TYPEENCAP_PUBLIC,
            TYPEPARAM_IN = oracle::occi::MetaData::TYPEPARAM_IN,
            TYPEPARAM_OUT = oracle::occi::MetaData::TYPEPARAM_OUT,
            TYPEPARAM_INOUT = oracle::occi::MetaData::TYPEPARAM_INOUT,
            CURSOR_OPEN = oracle::occi::MetaData::CURSOR_OPEN,
            CURSOR_CLOSED = oracle::occi::MetaData::CURSOR_CLOSED,
            CL_START = oracle::occi::MetaData::CL_START,
            CL_END = oracle::occi::MetaData::CL_END,
            SP_SUPPORTED = oracle::occi::MetaData::SP_SUPPORTED,
            SP_UNSUPPORTED = oracle::occi::MetaData::SP_UNSUPPORTED,
            NW_SUPPORTED = oracle::occi::MetaData::NW_SUPPORTED,
            NW_UNSUPPORTED = oracle::occi::MetaData::NW_UNSUPPORTED,
            AC_DDL = oracle::occi::MetaData::AC_DDL,
            NO_AC_DDL = oracle::occi::MetaData::NO_AC_DDL,
            LOCK_IMMEDIATE = oracle::occi::MetaData::LOCK_IMMEDIATE,
            LOCK_DELAYED = oracle::occi::MetaData::LOCK_DELAYED,
        };
          MetaData(const MetaData &);
          ~MetaData();
        std::string getString(AttrId attrid) const;
      protected:
          MetaData(void *, float);
        static void dtor(void * obj);
        friend class refCounter<MetaData>;
        friend class ResultSet;
      private:
        refCounter<MetaData> * ref;
    };
    class ResultSet {
      public:
        enum Status {
            END_OF_FETCH = oracle::occi::ResultSet::END_OF_FETCH,
            DATA_AVAILABLE = oracle::occi::ResultSet::DATA_AVAILABLE,
            STREAM_DATA_AVAILABLE = oracle::occi::ResultSet::STREAM_DATA_AVAILABLE,
        };
          ~ResultSet();
        void cancel();
        std::string getCharSet(unsigned int idx) const;
        Blob getBlob(unsigned int idx);
        Bytes getBytes(unsigned int idx);
        Clob getClob(unsigned int idx);
        unsigned int getCurrentStreamColumn() const;
        unsigned int getCurrentStreamRow() const;
        ResultSet * getCursor(unsigned int idx);
        double getDouble(unsigned int idx);
        float getFloat(unsigned int idx);
        int getInt(unsigned int idx);
        unsigned int getMaxColumnSize(unsigned int idx) const;
        unsigned int getNumArrayRows() const;
        Number getNumber(unsigned int idx);
        Bytes getRowid(unsigned int idx);
        Stream * getStream(unsigned int idx);
        std::string getString(unsigned int idx);
        unsigned int getUInt(unsigned int idx);
        bool isNull(unsigned int idx) const;
        bool isTruncated(unsigned int idx) const;
        Status next(unsigned int numRows = 1);
        int preTruncationLength(unsigned int idx) const;
        void setBinaryStreamMode(unsigned int idx, unsigned int size);
        void setCharacterStreamMode(unsigned int idx, unsigned int size);
        void setCharSet(unsigned int idx, const std::string &charset);
        void setErrorOnNull(unsigned int idx, bool causeException);
        void setErrorOnTruncate(unsigned int idx, bool causeException);
        void setMaxColumnSize(unsigned int idx, unsigned int max);
        Status status() const;
        std::vector<MetaData> getColumnListMetaData() const;
      protected:
          ResultSet(void *, float);
        void * rset;
        friend class Statement;
    };
    class Stream {
      public:
          ~Stream();
        void writeBuffer(char * buffer, unsigned int size);
        void writeLastBuffer(char * buffer, unsigned int size);
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
