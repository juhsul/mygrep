#include "wide_exception.h"

WruntimeError::WruntimeError(const std::wstring &msg) : message(msg) {}

const wchar_t *WruntimeError::wwhat() const noexcept
{
    return message.c_str();
}

const char *WruntimeError::what() const noexcept
{
    return "Unicode error - call wwhat() for details";
}