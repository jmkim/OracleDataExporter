//
// Created by jmkim on 10/12/17.
//

#include "OracleData.hpp"

oracle_data_exporter::oracle_datatype::OracleData::OracleData
    (const uint8_t column_data[], const size_t &column_data_size)
    : OracleData (std::vector<uint8_t> (column_data, column_data + column_data_size))
{}

oracle_data_exporter::oracle_datatype::OracleData::OracleData
    (const std::vector<uint8_t> &column_data)
    : column_data_ (column_data)
{}

oracle_data_exporter::oracle_datatype::OracleData::OracleData
    (const OracleData &oracle_data)
    : column_data_ (oracle_data.column_data_)
{}

oracle_data_exporter::oracle_datatype::OracleData &
oracle_data_exporter::oracle_datatype::OracleData::operator=
    (const OracleData &rhs)
{ column_data_ = rhs.column_data_; }

oracle_data_exporter::oracle_datatype::OracleData &
oracle_data_exporter::oracle_datatype::OracleData::operator=
    (const std::vector<uint8_t> &rhs)
{ column_data_ = rhs; }
