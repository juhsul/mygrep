#include "search.h"

int find_substr(const wstring& haystack, const wstring& needle) {
    return haystack.find(needle);
}