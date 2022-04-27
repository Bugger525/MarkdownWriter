#include "MarkdownWriter.h"
#include <iostream>

int main()
{
	auto md = Markdown({
		MdHeader("Hello World!"),
		MdHeader("Hello C++!", HeaderSize::Two),
		MdHeader("Hello namespace std!", HeaderSize::Three)
		});
	//std::cout << md.ToString();
	md.Save("Test.md");
}