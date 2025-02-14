#pragma once

#include <string>

using namespace std;

/**
 * @brief Leveillä merkeillä toteutettu poikkeus.
 *
 */
class WruntimeError : public exception
{
private:
    wstring message;

public:
    explicit WruntimeError(const wstring &msg);

    const wchar_t *wwhat() const noexcept;
    const char *what() const noexcept override;
};