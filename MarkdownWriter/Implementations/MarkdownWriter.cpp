#include "../MarkdownWriter.h"
#include "../Includes/File.h"

using std::string;
using std::stringstream;

Header::Header(const string& text, const std::string& id, HeaderSize size)
{
	Text = text;
	Id = id;
	Size = size;
}
string Header::ToString() const
{
	stringstream ss;
	for (int i = 0; i < static_cast<uint32_t>(Size); i++)
	{
		ss << '#';
	}
	ss << ' ' << Text;

	return ss.str();
}
Markdown::Markdown(const string& filePath)
{
	filePath_ = filePath;
}
void Markdown::AddHeader(const Header& header)
{
	text_ << header.ToString() << "\n";
}
void Markdown::AddHeader(const std::string& text, const std::string& id, HeaderSize size)
{
	stringstream ss;
	for (int i = 0; i < static_cast<uint32_t>(size); i++)
	{
		ss << '#';
	}
	ss << ' ' << text;
}
void Markdown::RemoveHeader()
{

}
std::string Markdown::ToString()
{
	return text_.str();
}
void Markdown::SyncFile()
{
	File::WriteText(filePath_, text_.str());
}