1. Edit the "Zigbee Device Config" component configuration header to "Coordinator or Router"
2. In app.c, change `status = sl_zigbee_af_network_creator_start(false); // distributed` to `status = sl_zigbee_af_network_creator_start(true); // centralized`
3. Install the "Trust Center Network Key Update Unicast" component
4. Add custom_cli.c/.h files
5. In main.c, include custom_cli.h and initialize it via app_init()
