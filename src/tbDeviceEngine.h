#ifndef TBDEVICEENGINE_H
#define TBDEVICEENGINE_H

// #define IS_GATEWAY

#include <Espressif_Updater.h>
#include <ArduinoJson.h>
#include <ArduinoCommondLib.h>
#include <Arduino.h>


#define MQTT_TOPIC_DEVICE_PROVISIONING_REQUEST "/provision/request"
#define MQTT_TOPIC_DEVICE_PROVISIONING_RESPONSE "/provision/response"

#define KEY_CREDENTIAL_VALUE "credentialsValue"
#define KEY_CREDENTIAL_TYPE "credentialsType"
#define KEY_STATUS "status"
#define KEY_ERROR_MSG "errorMsg"

#define CREDENTIAL_TYPE_ACCES_TOKEN "ACCESS_TOKEN"
#define STATUS_SUCCESS "SUCCESS"
#define STATUS_FAILURE "FAILURE"

#define MQTT_TOPIC_GATEWAT_CONNECT "v1/gateway/connect"
#define MQTT_TOPIC_GATEWAT_DISCONNECT "v1/gateway/disconnect"
#define MQTT_TOPIC_GATEWAY_ATTRIBUTES "v1/gateway/attributes"
#define MQTT_TOPIC_GATEWAY_TELEMETRY "v1/gateway/telemetry"
#define MQTT_TOPIC_GATEWAY_RPC "v1/gateway/rpc"

#define MQTT_TOPIC_DEVICE_TELEMETRY "v1/devices/me/telemetry"
#define MQTT_TOPIC_DEVICE_ATTRIBUTES "v1/devices/me/attributes"
#define MQTT_TOPIC_DEVICE_ATTRIBUTES_RESPONSE "v1/devices/me/attributes/response/"
#define MQTT_TOPIC_DEVICE_RPC_REQUEST "v1/devices/me/rpc/request/"
#define MQTT_TOPIC_DEVICE_RPC_RESPONSE "v1/devices/me/rpc/response/"

#define RPC_METHOD_GATEWAY_PING "gateway_ping"
#define RPC_METHOD_GATEWAY_STATS "gateway_stats"
#define RPC_METHOD_GATEWAY_DEVICES "gateway_devices"
#define RPC_METHOD_GATEWAY_UPDATE "gateway_update"
#define RPC_METHOD_GATEWAY_VERSION "gateway_version"
#define RPC_METHOD_GATEWAY_RESTART "gateway_restart"
#define RPC_METHOD_GATEWAY_REBOOT "gateway_reboot"
// #define RPC_METHOD_GATEWAY_OTA_MODE "gateway_ota_mode"

#define console Serial

class tbDeviceEngine
{
public:
    // Setters
    bool setTbHost(const char *host);
    bool setTbPort(int port);
    bool setTbDeviceToken(const char *token);
    bool setTbDeviceProvisionKey(const char *deviceProvisionKey);
    bool setTbDeviceProvisionSecret(const char *deviceProvisionSecret);
    bool setClientSsid(const char *clientSsid);
    bool setClientPassword(const char *clientPassword);
    bool setApSsid(const char *apSsid);
    bool setApPassword(const char *apPassword);
    bool setIsAp(bool isAp);
    bool setIsGateway(bool isGateway);
    bool setmDns(const char *mDns);
    bool setConfigFile(const char *filePath);
    bool setTbUpdateInterval(unsigned int interval);
    bool setTbOtaMode(bool otaMode);

    void setAllCredentials(const char *host,
                           int port,
                           const char *deviceToken,
                           const char *deviceProvisionKey,
                           const char *deviceProvisionSecret,
                           const char *clientSsid,
                           const char *clientPassword,
                           const char *apSsid,
                           const char *apPassword,
                           bool isAp,
                           const char *mDns,
                           unsigned int tbUpdateInterval,
                           bool otaMode);
    bool setAllCredentialsFromJson(const char *jsonString);
    bool loadAllCredentialsFromFile(bool printSensitive);
    bool saveAllCredentialToFile();

    // Getters
    const char *getTbHost() const;
    int getTbPort() const;
    const char *getTbDeviceToken() const;
    const char *getTbDeviceProvisionKey() const;
    const char *getTbDeviceProvisionSecret() const;
    const char *getClientSsid() const;
    const char *getClientPassword() const;
    const char *getApSsid() const;
    const char *getApPassword() const;
    bool getIsAp() const;
    const char *getmDns() const;
    unsigned int getTbRpcRequestId();
    unsigned int getTbUpdateInterval() const;
    bool getTbOtaMode();

    String getAllCredentialsAsJson();
    void printCredentials(bool printSensitive);

    void increaseTbRpcRequestId();

    bool isProvisioned();
    bool isCredentials();

private:
    char *_tbHost;                  // Private member to store host address
    int _tbPort = 1883;             // Private member to store port. Default 1883.
    char *_tbDeviceToken;           // Private member to store device access token
    char *_tbDeviceProvisionKey;    // Private member to store device provision key
    char *_tbDeviceProvisionSecret; // Private member to store device provision secret
    char *_clientSsid;              // Private member to store client ssid
    char *_clientPassword;          // Private member to store client password
    char *_apSsid;                  // Private member to store access point ssid
    char *_apPassword;              // Private member to store access point password
    bool _isAp = false;             // Private member to store is access point. Default false.
    bool _isGateway = false;        // Private member to store is access point. Default false.
    char *_mDns;
    char *_tbConfigFilePath;
    unsigned int _tbRpcRequestId = 1;
    unsigned int _tbUpdateInterval = 10000; // default 10sec.
    bool _tbOtaMode = false;
};

#endif
