#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <memory>

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
class IElement
{
public:
	std::string Text = "";
	virtual std::string ToString() const = 0;
};
class Header : public IElement
{
public:
	Header(const std::string& text, HeaderSize size);

	HeaderSize Size{};

	std::string ToString() const override;
};
class Text : public IElement
{

};

std::unique_ptr<Header> MdHeader(const std::string& text, HeaderSize size = HeaderSize::One);

class Markdown
{
public:
	Markdown(std::vector<std::unique_ptr<IElement>> elements);

	void AddHeader(const Header& header);
	void AddHeader(const std::string& text, HeaderSize size = HeaderSize::One);

	void AddText(const Text& text);
	void AddText(const std::string& text, TextStyle style = TextStyle::Regular);

	std::string ToString();
	void Save(const std::string& path);
private:
	std::vector<std::unique_ptr<IElement>> elements_{};
	std::stringstream text_{};
};