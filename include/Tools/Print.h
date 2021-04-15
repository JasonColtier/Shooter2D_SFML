#include <iostream>
#include <ostream>
#include <string>

enum LogType
{
    LOG,
    WARN,
    ERROR,
    FATAL
};

class Print
{
private:
    static std::string EnumToString(LogType logType)
    {
        switch (logType)
        {
        case LOG: return "LOG";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case FATAL: return "FATAL";

        default: return "LOG";
        }
    }

    template <typename Arg, typename... Args>
    static void doPrint(std::ostream& out, Arg&& arg, Args&&... args)
    {
        out << std::forward<Arg>(arg);
        using expander = int[];
        (void)expander{0, (void(out << std::forward<Args>(args)), 0)...};
    }

public:

    template <typename... Args>
static void PrintLog(LogType logType,Args ... args)
    {
        std::cout << EnumToString(logType) << " - ";
        doPrint(std::cout,args...);
        std::cout << std::endl;
    }

    template <typename... Args>
    static void PrintLog(Args ... args)
    {
        std::cout << EnumToString(LOG) << " - ";
        doPrint(std::cout,args...);
        std::cout << std::endl;
    }
};
