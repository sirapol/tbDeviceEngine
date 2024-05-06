#include "tbDeviceEngine.h"

// Function setter
bool tbDeviceEngine::setTbHost(const char *host)
{
    if (!host)
    {
        return false;
    }
    _tbHost = (char *)malloc(strlen(host) + 1); // Allocate memory
    if (_tbHost == nullptr)
    {
        // Handle memory allocation failure (e.g., print error message)
        return false;
    }
    strcpy(_tbHost, host);
    return true;
}

bool tbDeviceEngine::setTbPort(int port)
{
    _tbPort = port;
    return true;
}

bool tbDeviceEngine::setTbDeviceToken(const char *token)
{
    if (!token)
    {
        return false;
    }
    _tbDeviceToken = (char *)malloc(strlen(token) + 1); // Allocate memory

    if (_tbDeviceToken == nullptr)
    {
        // Handle memory allocation failure (e.g., print error message)
        return false;
    }
    strcpy(_tbDeviceToken, token);
    return true;
}

bool tbDeviceEngine::setTbDeviceProvisionKey(const char *deviceProvisionKey)
{
    if (!deviceProvisionKey)
    {
        return false;
    }
    // Allocate memory for the string
    _tbDeviceProvisionKey = (char *)malloc(strlen(deviceProvisionKey) + 1);
    if (_tbDeviceProvisionKey == nullptr)
    {
        // Handle memory allocation failure (e.g., print error message)
        return false;
    }
    strcpy(_tbDeviceProvisionKey, deviceProvisionKey);
    return true;
}

bool tbDeviceEngine::setTbDeviceProvisionSecret(const char *deviceProvisionSecret)
{
    if (!deviceProvisionSecret)
    {
        return false;
    }
    // Allocate memory for the string
    _tbDeviceProvisionSecret = (char *)malloc(strlen(deviceProvisionSecret) + 1);
    if (_tbDeviceProvisionSecret == nullptr)
    {
        // Handle memory allocation failure
        return false;
    }
    strcpy(_tbDeviceProvisionSecret, deviceProvisionSecret);
    return true;
}

bool tbDeviceEngine::setClientSsid(const char *clientSsid)
{
    if (!clientSsid)
    {
        return false;
    }
    // Allocate memory for the string
    _clientSsid = (char *)malloc(strlen(clientSsid) + 1);
    if (_clientSsid == nullptr)
    {
        // Handle memory allocation failure
        return false;
    }
    strcpy(_clientSsid, clientSsid);
    return true;
}

bool tbDeviceEngine::setClientPassword(const char *clientPassword)
{
    if (!clientPassword)
    {
        return false;
    }
    // Allocate memory for the string
    _clientPassword = (char *)malloc(strlen(clientPassword) + 1);
    if (_clientPassword == nullptr)
    {
        // Handle memory allocation failure
        return false;
    }
    strcpy(_clientPassword, clientPassword);
    return true;
}

bool tbDeviceEngine::setApSsid(const char *apSsid)
{
    if (!apSsid)
    {
        return false;
    }
    // Allocate memory for the string
    _apSsid = (char *)malloc(strlen(apSsid) + 1);
    if (_apSsid == nullptr)
    {
        // Handle memory allocation failure
        return false;
    }
    strcpy(_apSsid, apSsid);
    return true;
}

bool tbDeviceEngine::setApPassword(const char *apPassword)
{
    if (!apPassword)
    {
        return false;
    }
    // Allocate memory for the string
    _apPassword = (char *)malloc(strlen(apPassword) + 1);
    if (_apPassword == nullptr)
    {
        // Handle memory allocation failure
        return false;
    }
    strcpy(_apPassword, apPassword);
    return true;
}

bool tbDeviceEngine::setIsAp(bool isAp)
{
    _isAp = isAp;
    return true;
}
bool tbDeviceEngine::setIsGateway(bool isGateway)
{
    _isGateway = isGateway;
    return true;
}

bool tbDeviceEngine::setmDns(const char *mDns)
{
    if (!mDns)
    {
        return false;
    }
    _mDns = (char *)malloc(strlen(mDns) + 1); // Allocate memory
    if (_mDns == nullptr)
    {
        // Handle memory allocation failure (e.g., print error message)
        return false;
    }
    strcpy(_mDns, mDns);
    return true;
}

bool tbDeviceEngine::setConfigFile(const char *filePath)
{
    if (!filePath)
    {
        return false;
    }
    // Allocate memory for the string
    _tbConfigFilePath = (char *)malloc(strlen(filePath) + 1);
    if (_tbConfigFilePath == nullptr)
    {
        // Handle memory allocation failure
        return false;
    }
    strcpy(_tbConfigFilePath, filePath);
    return true;
}

bool tbDeviceEngine::setTbUpdateInterval(unsigned int interval)
{
    if (interval < 1000) // min 1sec
        interval = 1000;
    _tbUpdateInterval = interval;
    return true;
}

bool tbDeviceEngine::setTbOtaMode(bool otaMode)
{
    _tbOtaMode = otaMode;
    return true;
}

/// @brief Set all credentials for Thingsboard device
/// @param host // Thingsboard host
/// @param port  // Thingsboard port. Default 1883
/// @param deviceToken // Thingsboard Device Token
/// @param deviceProvisionKey  //Thingsboard Provision key
/// @param deviceProvisionSecret  // Thingsboard Provision Secret
/// @param clientSsid  // WiFi SSID. Device will connect to this SSID
/// @param clientPassword  // WiFi password. Device will connect to this SSID
/// @param apSsid  // Acess point SSID. Device will create AP using this SSID
/// @param apPassword  // Acess point SSID. Device will create AP using this password
/// @param isAp  // If true. Device will create AP.
/// @param mDns  // Device mDns call like "xxxxx.local"
void tbDeviceEngine::setAllCredentials(const char *host,
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
                                       bool otaMode)
{
    // Call existing setter functions for each parameter
    setTbHost(host); // Handle memory allocation in setTbHost
    setTbPort(port);
    setTbDeviceToken(deviceToken);                     // Handle memory allocation in setTbDeviceToken
    setTbDeviceProvisionKey(deviceProvisionKey);       // Handle memory allocation
    setTbDeviceProvisionSecret(deviceProvisionSecret); // Handle memory allocation
    setClientSsid(clientSsid);                         // Handle memory allocation
    setClientPassword(clientPassword);                 // Handle memory allocation
    setApSsid(apSsid);                                 // Handle memory allocation
    setApPassword(apPassword);                         // Handle memory allocation
    setIsAp(isAp);
    setTbUpdateInterval(tbUpdateInterval);
    setTbOtaMode(otaMode);
}

bool tbDeviceEngine::setAllCredentialsFromJson(const char *jsonString)
{
    // Create a StaticJsonDocument to parse the JSON string
    JsonDocument doc;

    // Deserialize the JSON string into the document
    DeserializationError error = deserializeJson(doc, jsonString);
    if (error)
    {
        USB_SERIAL.print(F("Failed to deserialize JSON: "));
        USB_SERIAL.println(error.c_str());
        return false;
    }

    // Check for all required keys
    if (!doc.containsKey("strTbHost") ||
        !doc.containsKey("intTbPort") ||
        !doc.containsKey("strToken") ||
        !doc.containsKey("strProvisionKey") ||
        !doc.containsKey("strProvisionSecret") ||
        !doc.containsKey("strClientSsid") ||
        !doc.containsKey("strClientPassword") ||
        !doc.containsKey("strApSsid") ||
        !doc.containsKey("strApPassword") ||
        !doc.containsKey("boolIsAp") ||
        !doc.containsKey("strMDns") ||
        !doc.containsKey("uintTbUpdateInterval") ||
        !doc.containsKey("boolOtaMode"))
    {
        USB_SERIAL.println("Missing required key in JSON");
        return false;
    }

    // Extract values from the JSON document
    const char *strTbHost = doc["strTbHost"];
    int intTbPort = doc["intTbPort"];
    const char *strToken = doc["strToken"];
    const char *strProvisionKey = doc["strProvisionKey"];
    const char *strProvisionSecret = doc["strProvisionSecret"];
    const char *strClientSsid = doc["strClientSsid"];
    const char *strClientPassword = doc["strClientPassword"];
    const char *strApSsid = doc["strApSsid"];
    const char *strApPassword = doc["strApPassword"];
    bool boolIsAp = doc["boolIsAp"];
    const char *strMDns = doc["strMDns"];
    unsigned int uintTbUpdateInterval = doc["uintTbUpdateInterval"];
    bool boolOtaMode = doc["boolOtaMode"];

    // Call existing setter functions for each parameter, handling memory allocation
    if (!setTbHost(strTbHost) ||
        !setTbPort(intTbPort) ||
        !setTbDeviceToken(strToken) ||
        !setTbDeviceProvisionKey(strProvisionKey) ||
        !setTbDeviceProvisionSecret(strProvisionSecret) ||
        !setClientSsid(strClientSsid) ||
        !setClientPassword(strClientPassword) ||
        !setApSsid(strApSsid) ||
        !setApPassword(strApPassword) ||
        !setIsAp(boolIsAp) ||
        !setmDns(strMDns) ||
        !setTbUpdateInterval(uintTbUpdateInterval) ||
        !setTbOtaMode(boolOtaMode))
    {
        return false; // Handle error setting parameters
    }
    return true;
}

String tbDeviceEngine::getAllCredentialsAsJson()
{
    // Create a JsonDocument to build the JSON response
    DynamicJsonDocument doc(256); // Adjust buffer size as needed

    // Add each credential key-value pair to the document
    doc["strTbHost"] = _tbHost;
    doc["intTbPort"] = _tbPort;
    doc["strToken"] = _tbDeviceToken;                     // Handle empty token
    doc["strProvisionKey"] = _tbDeviceProvisionKey;       // Handle empty key/secret
    doc["strProvisionSecret"] = _tbDeviceProvisionSecret; // Handle empty key/secret
    doc["strClientSsid"] = _clientSsid;
    doc["strClientPassword"] = _clientPassword;
    doc["strApSsid"] = _apSsid;
    doc["strApPassword"] = _apPassword;
    doc["boolIsAp"] = _isAp;
    doc["strMDns"] = _mDns;
    doc["uintTbUpdateInterval"] = _tbUpdateInterval;
    doc["boolOtaMode"] = _tbOtaMode;

    // Serialize the document into a string
    String jsonString;
    serializeJson(doc, jsonString);

    return jsonString;
}
// Function Getters
const char *tbDeviceEngine::getTbHost() const
{
    return _tbHost;
}

int tbDeviceEngine::getTbPort() const
{
    return _tbPort;
}

const char *tbDeviceEngine::getTbDeviceToken() const
{
    return _tbDeviceToken;
}

const char *tbDeviceEngine::getTbDeviceProvisionKey() const
{
    return _tbDeviceProvisionKey;
}

const char *tbDeviceEngine::getTbDeviceProvisionSecret() const
{
    return _tbDeviceProvisionSecret;
}

const char *tbDeviceEngine::getClientSsid() const
{
    return _clientSsid;
}

const char *tbDeviceEngine::getClientPassword() const
{
    return _clientPassword;
}

const char *tbDeviceEngine::getApSsid() const
{
    return _apSsid;
}

const char *tbDeviceEngine::getApPassword() const
{
    return _apPassword;
}

bool tbDeviceEngine::getIsAp() const
{
    return _isAp;
}
const char *tbDeviceEngine::getmDns() const
{
    return _mDns;
}

unsigned int tbDeviceEngine::getTbRpcRequestId()
{
    return _tbRpcRequestId;
}

unsigned int tbDeviceEngine::getTbUpdateInterval() const
{
    return _tbUpdateInterval;
}
bool tbDeviceEngine::getTbOtaMode()
{
    return _tbOtaMode;
}

void tbDeviceEngine::increaseTbRpcRequestId()
{
    _tbRpcRequestId++;
}

bool tbDeviceEngine::isProvisioned()
{
    // Check if all credentials are set
    if (strlen(_tbDeviceToken) > 0 && strlen(_tbDeviceProvisionKey) > 0 && strlen(_tbDeviceProvisionSecret) > 0)
    {
        // Device needs provisioning, remove unnecessary credentials
        *_tbDeviceProvisionKey = '\0';    // Set provision key to empty string
        *_tbDeviceProvisionSecret = '\0'; // Set provision secret to empty string
        return true;
    }
    else if (strlen(_tbDeviceToken) > 0 && (strlen(_tbDeviceProvisionKey) == 0 || strlen(_tbDeviceProvisionSecret) == 0))
    {
        // Check if only device token is set (provisioned)
        return true;
    }
    else if (strlen(_tbDeviceProvisionKey) == 0 || strlen(_tbDeviceProvisionSecret) == 0)
    {
        return false;
    }
    return false;
}

bool tbDeviceEngine::isCredentials()
{
    if (!strlen(_tbHost) || !strlen(_apSsid))
        return false;

    if (!_tbDeviceToken || *_tbDeviceToken == 0)
    {
        // If token is empty, both provision key and secret must not be empty
        return (_tbDeviceProvisionKey && *_tbDeviceProvisionKey != 0) && (_tbDeviceProvisionSecret && *_tbDeviceProvisionSecret != 0);
    }
    else
    {
        // If token is not empty, both provision key and secret must be empty
        isProvisioned();
        return !(_tbDeviceProvisionKey && *_tbDeviceProvisionKey != 0) && !(_tbDeviceProvisionSecret && *_tbDeviceProvisionSecret != 0);
    }
}
bool tbDeviceEngine::saveAllCredentialToFile()
{
    return writeFile(SPIFFS, _tbConfigFilePath, getAllCredentialsAsJson().c_str());
}
void tbDeviceEngine::printCredentials(bool printSensitive = false)
{
    USB_SERIAL.println("Credentials:");
    USB_SERIAL.print("  Host: ");
    USB_SERIAL.println(getTbHost());
    USB_SERIAL.print("  Port: ");
    USB_SERIAL.println(getTbPort());

    // Print device token only if printSensitive is true
    if (printSensitive)
    {
        USB_SERIAL.print("  Device Token: ");
        USB_SERIAL.println(getTbDeviceToken());
    }
    else
    {
        USB_SERIAL.println("  Device Token: (REDACTED)"); // Indicate redaction
    }

    // Likewise, conditionally print provision key and secret
    if (printSensitive)
    {
        USB_SERIAL.print("  Provision Key: ");
        USB_SERIAL.println(getTbDeviceProvisionKey());
        USB_SERIAL.print("  Provision Secret: ");
        USB_SERIAL.println(getTbDeviceProvisionSecret());
    }
    else
    {
        USB_SERIAL.println("  Provision Key: (REDACTED)");
        USB_SERIAL.println("  Provision Secret: (REDACTED)");
    }

    USB_SERIAL.print("  Client SSID: ");
    USB_SERIAL.println(getClientSsid());
    USB_SERIAL.print("  Client Password: ");
    if (printSensitive)
    {
        USB_SERIAL.println(getClientPassword()); // Handle empty password
    }
    else
    {
        USB_SERIAL.println(getClientPassword() ? "(REDACTED)" : ""); // Handle empty password
    }
    USB_SERIAL.print("  Access Point SSID: ");
    USB_SERIAL.println(getApSsid());
    USB_SERIAL.print("  Access Point Password: ");

    if (printSensitive)
    {
        USB_SERIAL.println(getApPassword()); // Handle empty password
    }
    else
    {
        USB_SERIAL.println(getApPassword() ? "(REDACTED)" : ""); // Handle empty password
    }

    USB_SERIAL.print("  Is Access Point: ");
    USB_SERIAL.println(getIsAp());
    USB_SERIAL.print("  mDNS: ");
    USB_SERIAL.println(getmDns());
    USB_SERIAL.println("  tbUpdateInterval:" + String(getTbUpdateInterval()));
    USB_SERIAL.println("  boolOtaMode:" + String(getTbOtaMode()));
}

bool tbDeviceEngine::loadAllCredentialsFromFile(bool printSensitive = false)
{
    if (strlen(_tbConfigFilePath) == 0)
    {
        return false;
    }
    String strTbConfig = readFile(SPIFFS, _tbConfigFilePath);
    if (setAllCredentialsFromJson(strTbConfig.c_str()))
    {
        printCredentials(printSensitive);
    }
    else
    {
        USB_SERIAL.println("tbConfig.json is error.Please check!!!");
        return false;
    }
    return true;
}