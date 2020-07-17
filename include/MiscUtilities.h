#pragma once
#include <vector>
#include <string>

/**
 * Utilities to manipulate strings.
 */
namespace StringUtils
{
	/**
	 * Split a string at a given separator.
	 */
	std::vector<std::string> split(const std::string& s, char delimiter);
	/**
	 * Remove leading and trailing spaces from a string.
	 */
	std::string trim(std::string const& str);
}

/**
 * Utilities to perform file I/O.
 */
namespace IoUtils
{
	typedef enum {
		APPEND, ///< When opening a file for writing, append to the existing content of the file.
		TRUNCATE, ///<When opening a file for writing, truncate the existing content of the file.
	} Mode;
	/**
	 * Write a string to a file.
	 */
	int writeTextFile(const std::string& path, const std::string& content, Mode mode = TRUNCATE);
	/**
	 * Utilities to read and write config files with one `KEY=VALUE` pair per lin.
	 */
	namespace ConfigFile {
		/**
		 * Read the value corresponding to \p key from \p path.
		 *
		 * @param path path to the file to read from.
		 * @param key the key to find.
		 * @return The read value, or an empty string if the \p key was not found.
		 */
		std::string readValue(const std::string& path, const std::string& key);
		/**
		 * Write the key-value pair to \p path.
		 *
		 * @param path path to the file to write.
		 * @param key the key
		 * @param value the value
		 * @param mode whether to truncate or append to the path.
		 * @return 0 on success, or an error code otherwise.
		 */
		int writeValue(const std::string& file, const std::string& key, const std::string& value, Mode mode = TRUNCATE);
	}
}