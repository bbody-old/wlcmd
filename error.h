#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

typedef enum
{
    eSuccess,
    eFlag,
    eAttributes,
    eCommandFile,
    eCommand,
    eUnknown
} ErrorCode;

// Exposed Function
int error(ErrorCode errorCode);

#endif // ERROR_H_INCLUDED
