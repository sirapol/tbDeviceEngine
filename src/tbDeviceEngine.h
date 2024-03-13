#ifndef TBDEVICEENGINE_H
#define TBDEVICEENGINE_H

#include <Arduino.h>

class tbDeviceEngine {
public:
    static void setHost(const char* host);
    static void setPort(int port);
    static void setToken(const char* token);

    static const char* getHost();
    static int getPort();
    static const char* getToken();

private:
    static const char* m_host;
    static int m_port;
    static const char* m_token;
};

#endif
