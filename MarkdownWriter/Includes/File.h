#pragma once

#include <string>
#include <vector>

class File
{
public:
	static void AppendText(const std::string& path, const std::string& text);
	static void WriteText(const std::string& path, const std::string& text);
	static std::vector<std::string> ReadLines(const std::string& path);
	static std::string ReadText(const std::string& path);
};