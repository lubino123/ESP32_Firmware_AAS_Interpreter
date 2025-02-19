set(COMPONENT_ADD_INCLUDEDIRS .)
set(COMPONENT_SRCS "OPC_lient.c")
idf_component_register(SRCS "OPC_klient.c"
                       PRIV_REQUIRES driver esp_eth esp_netif 
                       INCLUDE_DIRS "."
                       REQUIRES NFC_Recipes ethernet_init
                       REQUIRES "driver" "esp_wifi" "esp_eth" "lwip" "bootloader_support" "spi_flash" "nvs_flash" "esp_netif")
