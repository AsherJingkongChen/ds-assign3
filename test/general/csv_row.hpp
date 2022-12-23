#ifndef CSV_ROW
#define CSV_ROW

#include <string>
#include <vector>
#include <unordered_map>

namespace ds {

// a key-value type container generates lines 
// for CSV files by the given
// column names, delimiter and line terminator
//
// cells of row are accessed by column name or index 
//
class csv_row {
public: // type
  typedef std::string                               cell_type;
  typedef std::string                               line_type;
  typedef std::vector<cell_type>                    cell_arg_type;
  typedef std::unordered_map<cell_type, cell_type>  container_type;

public: // property
  cell_type lineterm() const {
    return __lineterminator;
  }

  line_type header() const {
    line_type result;
    for (auto &column_name: __column_names) {
      result += column_name + __delimiter;
    }
    for (std::size_t t(__delimiter.size()); t--;) {
      result.pop_back();
    }
    result += __lineterminator;
    return result;
  }

  line_type line() const {
    line_type result;
    for (auto &column_name: __column_names) {
      result += __dict.at(column_name) + __delimiter;
    }
    for (std::size_t t(__delimiter.size()); t--;) {
      result.pop_back();
    }
    result += __lineterminator;
    return result;
  }

  cell_arg_type header_args() const {
    return __column_names;
  }

  cell_arg_type line_args() const {
    cell_arg_type result;
    for (auto &column_name: __column_names) {
      result.push_back(__dict.at(column_name));
    }
    return result;
  }

  cell_type &operator[](cell_type const &column_name) {
    return __dict.at(column_name);
  }

  cell_type const &operator[](cell_type const &column_name) const {
    return __dict.at(column_name);
  }

  cell_type &operator[](std::size_t column_index) {
    return __dict.at(__column_names[column_index]);
  }

  cell_type const &operator[](std::size_t column_index) const {
    return __dict.at(__column_names[column_index]);
  }

private: // internal property
  cell_arg_type split(line_type const &line) const {
    cell_arg_type result;

    std::size_t 
    spos(0),
    epos(line.find(__delimiter, spos));

    for (; epos != std::string::npos;
         epos = line.find(__delimiter, spos)) {
  
        cell_type cell(line.substr(spos, epos));
        result.push_back(cell);
        spos = epos + __delimiter.length();
    }

    return result;
  }

public: // build
  csv_row(
        cell_arg_type const &column_names, 
        cell_type const &delimiter = ",",
        cell_type const &lineterminator = "\n"):

      __delimiter(delimiter),
      __lineterminator(lineterminator),
      __column_names(column_names) {

    for (auto &column_name: __column_names) {
      __dict[column_name] = {};
    }
  }

  csv_row(
      line_type const &header, 
      cell_type const &delimiter = ",",
      cell_type const &lineterminator = "\n"):
      
      __delimiter(delimiter),
      __lineterminator(lineterminator),
      __column_names(split(header)) {

    for (auto &column_name: __column_names) {
      __dict[column_name] = {};
    }
  }

private: // data
  cell_type       __delimiter;
  cell_type       __lineterminator;
  cell_arg_type   __column_names;
  container_type  __dict;
};

} // namespace ds

#endif // CSV_ROW
