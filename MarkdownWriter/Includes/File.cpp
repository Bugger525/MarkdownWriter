#include "File.h"
#include <fstream>

using std::string;

void File::AppendText(const string& path, const string& str)
{
	auto out = std::ofstream(path, std::ios_base::app);
	out << str;
}
void File::WriteText(const string& path, const string& str)
{
	auto out = std::ofstream(path, std::ios_base::trunc);
	out << str;
}
std::vector<string> File::ReadLines(const string& path)
{
	std::vector<string> result;
	auto in = std::ifstream(path);
	if (in.is_open())
	{
		while (in)
		{
			string temp;
			std::getline(in, temp);

			result.push_back(temp);
		}
	}
	return result;
}
string File::ReadText(const string& path)
{
	string result = "";
	auto in = std::ifstream(path);
	if (in.is_open())
	{
		in >> result;
	}
	return result;
}