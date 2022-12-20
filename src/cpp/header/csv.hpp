#ifndef CSV
#define CSV

#include <string>
#include <vector>
#include <unordered_map>

namespace ds {

// a map-like data type generates lines 
// for CSV files by given 
// column names, delimiter and line terminator
//
// cells of row are accessed by column name or index 
//
class csv {
public: // type
  typedef std::string                             str_type;
  typedef std::vector<str_type>                   key_param_type;
  typedef std::unordered_map<str_type, str_type>  map_type;
  typedef std::vector<map_type::value_type>       item_param_type;

public: // property
  std::string header_line() const {
    std::string result;
    for (auto &column_name: __column_names) {
      result += column_name + __delimiter;
    }
    result.pop_back();
    result.push_back(__lineterminator);
    return result;
  }

  std::string row_line() const {
    std::string result;
    for (auto &column_name: __column_names) {
      result += __row.at(column_name) + __delimiter;
    }
    result.pop_back();
    result.push_back(__lineterminator);
    return result;
  }

  str_type &operator[](str_type const &column_name) {
    return __row.at(column_name);
  }

  str_type const &operator[](str_type const &column_name) const {
    return __row.at(column_name);
  }

  str_type &operator[](std::size_t column_index) {
    return __row.at(__column_names[column_index]);
  }

  str_type const &operator[](std::size_t column_index) const {
    return __row.at(__column_names[column_index]);
  }

public: // build
  csv(key_param_type const &column_names, 
      char delimiter = ',',
      char lineterminator = '\n'):
      
      __delimiter(delimiter),
      __lineterminator(lineterminator),
      __column_names(column_names) {

    for (auto &column_name: column_names) {
      __row[column_name] = {};
    }
  }

  csv(item_param_type const &column_names_and_first_cells, 
      char delimiter = ',',
      char lineterminator = '\n'):
      
      __delimiter(delimiter),
      __lineterminator(lineterminator) {

    for (auto &column_name_and_first_cell: 
         column_names_and_first_cells) {

      auto &column_name = column_name_and_first_cell.first;
      auto &first_cell = column_name_and_first_cell.second;
      __column_names.push_back(column_name);
      __row[column_name] = first_cell;
    }
  }

private: // data
  char __delimiter;
  char __lineterminator;
  key_param_type __column_names;
  map_type __row;
};

} // namespace ds

#endif // CSV
