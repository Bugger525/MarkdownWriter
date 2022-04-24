#include "MarkdownWriter.h"
#include <iostream>

int main()
{
	auto h = Header("README.MD IS GREAT!", "Title1", HeaderSize::One);
	auto md = Markdown("Test.md");

	md.AddHeader(h);
	md.AddHeader(Header{ "I'm Bugger", "Intro", HeaderSize::Four });

	md.SyncFile();
}