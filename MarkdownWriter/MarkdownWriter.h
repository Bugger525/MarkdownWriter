#pragma once

#include <string>
#include <sstream>
#include <map>

enum class HeaderSize : uint32_t
{
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6
};
enum class TextStyle
{
	Regular,
	Italic,
	Bold
};
class Header
{
public:
	Header(const std::string& text, const std::string& id, HeaderSize size = HeaderSize::One);

	std::string Text = "";
	std::string Id = "";
	HeaderSize Size{};

	std::string ToString() const;
};
class Text
{

};

class Markdown
{
public:
	Markdown(const std::string& filePath);

	void AddHeader(const Header& header);
	void AddHeader(const std::string& text, const std::string& id, HeaderSize size = HeaderSize::One);
	void RemoveHeader();

	void AddText(const Text& text);
	void AddText(const std::string& text, const std::string& id, TextStyle style = TextStyle::Regular);


	std::string ToString();
	void SyncFile();
private:
	std::string filePath_ = "";
	std::stringstream text_{};
};