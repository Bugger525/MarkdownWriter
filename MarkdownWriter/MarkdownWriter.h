#pragma once

#include <string>

class IElement
{
private:
	IElement();
};

enum class HeaderSize : uint32_t
{
	One = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6
};

class Header : public IElement
{
public:
	Header(const std::string& text, HeaderSize size = HeaderSize::One);
};

class Markdown
{
public:
	Markdown(const std::string& filePath);
	void AddElement(IElement element);
	std::string ToString();
	bool SyncFile();
private:
	std::string filePath_ = "";
};