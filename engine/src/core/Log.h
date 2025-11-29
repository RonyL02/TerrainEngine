#include <spdlog/spdlog.h>

#define TE_INFO(...) spdlog::info(__VA_ARGS__)
#define TE_WARN(...) spdlog::warn(__VA_ARGS__)
#define TE_ERROR(...) spdlog::error(__VA_ARGS__)
#define TE_DEBUG(...) spdlog::debug(__VA_ARGS__)