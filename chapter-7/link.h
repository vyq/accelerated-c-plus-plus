#ifndef LINK
#define LINK 

#include <string>
#include <vector>

std::vector<std::string> FindLinks(const std::string&);
std::string::const_iterator FindProtocol(
  std::string::const_iterator,
  std::string::const_iterator
);
std::string::const_iterator FindResource(
  std::string::const_iterator,
  std::string::const_iterator
);
bool IsNotLinkCharacter(char c);

#endif
