#include "../MarkdownWriter.h"
#include <fstream>

using std::string;
using std::stringstream;
using std::unique_ptr;

Header::Header(const string& text, HeaderSize size)
{
	Text = text;
	Size = size;
}
string Header::ToString() const
{
	stringstream ss;
	for (uint32_t i = 0; i < static_cast<uint32_t>(Size); i++)
	{
		ss << '#';
	}
	ss << ' ' << Text << "\n";

	return ss.str();
}
Markdown::Markdown(std::vector<std::unique_ptr<IElement>> elements)
{
	elements_.assign(elements.begin(), elements.end());
}
void Markdown::AddHeader(const Header& header)
{
	elements_.push_back(std::make_unique<Header>(header));
}
void Markdown::AddHeader(const string& text, HeaderSize size)
{
	elements_.push_back(std::make_unique<Header>(text, size));
}
std::string Markdown::ToString()
{
	text_.clear();
	for (const auto& element : elements_)
	{
		text_ << element->ToString();
	}
	return text_.str();
}
void Markdown::Save(const string& path)
{
	text_.clear();
	for (const auto& element : elements_)
	{
		text_ << element->ToString();
	}
	auto out = std::ofstream(path, std::ios_base::trunc);
	out << text_.str();
}