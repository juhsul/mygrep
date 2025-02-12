#include "search.h"

int find_substr(const wstring &haystack, const wstring &needle)
{
    size_t pos = haystack.find(needle);
    return (pos == wstring::npos) ? -1 : static_cast<int>(pos);
}