#include "tbDeviceEngine.h"

const char* tbDeviceEngine::m_host = nullptr;
int tbDeviceEngine::m_port = 1883; // Default ThingsBoard MQTT port
const char* tbDeviceEngine::m_token = nullptr;

void tbDeviceEngine::setHost(const char* host) {
    m_host = host;
}

void tbDeviceEngine::setPort(int port) {
    m_port = port;
}

void tbDeviceEngine::setToken(const char* token) {
    m_token = token;
}

const char* tbDeviceEngine::getHost() {
    return m_host;
}

int tbDeviceEngine::getPort() {
    return m_port;
}

const char* tbDeviceEngine::getToken() {
    return m_token;
}
