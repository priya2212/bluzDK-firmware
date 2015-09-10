#ifndef _SOCKET_H
#define	_SOCKET_H

#ifdef __cplusplus

#include <stdint.h>
#include "data_service.h"

typedef struct
{
    uint16_t   sa_family;
    uint8_t    sa_data[14];
} sockaddr_b;

class Socket
{
public:
    Socket();
    
    int32_t connect(uint32_t sockid, const sockaddr_b *addr, long addrlen);
    int32_t send(const void* buffer, uint32_t len);
    int32_t receive(void* buffer, uint32_t len, unsigned long _timeout);
    int32_t close();
    
    static const int32_t SOCKET_BUFFER_SIZE = 1024;
    bool inUse;
    
private:
    uint32_t id;
    uint8_t buffer[SOCKET_BUFFER_SIZE];
};

#endif
#endif	/* _SOCKET_H */