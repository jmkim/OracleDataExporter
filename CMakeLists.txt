cmake_minimum_required(VERSION 3.8)
project(OracleDataExporter)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        examples/InterpretData.cpp
        src/oracle_datatype/Date.cpp
        src/oracle_datatype/Date.hpp
        src/oracle_datatype/Datetime.hpp
        src/oracle_datatype/Number.cpp
        src/oracle_datatype/Number.hpp
        src/oracle_datatype/Time.cpp
        src/oracle_datatype/Time.hpp
        src/oracle_datatype/Timestamp.cpp
        src/oracle_datatype/Timestamp.hpp
        src/oracle_datatype/TimestampWithTimezone.cpp
        src/oracle_datatype/TimestampWithTimezone.hpp
        src/oracle_datatype/TimeWithTimezone.cpp
        src/oracle_datatype/TimeWithTimezone.hpp
        src/util/ColumnInterpreter.cpp
        src/util/ColumnInterpreter.hpp
        src/IStringable.hpp
        src/oracle_datatype/OracleData.cpp
        src/oracle_datatype/OracleData.hpp
        src/oracle_datatype/Datetime.cpp
        src/oracle_datatype/Char.cpp
        src/oracle_datatype/Char.hpp)

add_executable(OracleDataExporter ${SOURCE_FILES})
