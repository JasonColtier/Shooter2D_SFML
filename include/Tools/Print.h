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

    //un print basic sans argument, appelé si on ne passe qu'un seul argument à notre fontion PrintString
    static void SimplePrint()
    {
        std::cout << "";
    }

    //un print simple utilisé pour unpacker le Args...
    template <typename Arg>
    static void SimplePrint(Arg arg)
    {
        std::cout << arg;
    } 

    //Pour print tous les arguments un à un
    template <typename First,typename... Args>
    static void PrintArgs(First first,Args ... args) // recursive variadic function
    {
        SimplePrint(first);
        SimplePrint(args...);
    }

public:
    template <typename... Args>
    static void PrintString(LogType logType, Args ... args)
    {
        std::cout << EnumToString(logType) << " - ";
        PrintArgs(args...);
        std::cout << std::endl;
    }

    template <typename... Args>
    static void PrintString(Args ... args)
    {
        std::cout << EnumToString(LOG) << " - ";
        PrintArgs(args...);
        std::cout << std::endl;
    }
};
