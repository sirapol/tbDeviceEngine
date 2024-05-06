#include <tbDeviceEngine.h>

tbDeviceEngine tbEngine;

void setup()
{

    USB_SERIAL.begin(USB_SERIAL_BAUD);
    delay(100);
    tbEngine.setTbHost("fluke-electronics.com");
    tbEngine.setTbDeviceToken("LomprVvl0eUfRXjSi3hz");
    tbEngine.setTbPort(1883);
    tbEngine.setClientSsid("injectorhome_2.4GHz");
    tbEngine.setClientPassword("sirapols0422");
    tbEngine.setIsAp(false);
    tbEngine.setIsGateway(false);

    USB_SERIAL.println("host = " + String(tbEngine.getTbHost()));
    USB_SERIAL.println("port = " + String(tbEngine.getTbPort()));
    USB_SERIAL.println("token = " + String(tbEngine.getTbDeviceToken()));

    tbEngine.begin();
}

void loop()
{
    tbEngine.loop();
    // Your code to send telemetry data or receive commands from ThingsBoard
}
