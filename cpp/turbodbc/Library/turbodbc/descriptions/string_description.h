#pragma once

#include <turbodbc/description.h>

namespace turbodbc {

/**
 * @brief Represents a description to bind a buffer holding string values
 */
class string_description : public description {
public:
	const static int max_code_units_per_unicode_code_point = 4;
	string_description(std::size_t maximum_length);
	string_description(std::string name, bool supports_null, std::size_t maximum_length);
	~string_description();
private:
	std::size_t do_element_size() const final;
	SQLSMALLINT do_column_c_type() const final;
	SQLSMALLINT do_column_sql_type() const final;
	SQLSMALLINT do_digits() const final;
	type_code do_get_type_code() const final;

	std::size_t maximum_length_;
};

}
