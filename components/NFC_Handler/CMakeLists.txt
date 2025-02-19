idf_component_register(SRCS "NFC_handler.c"
                    INCLUDE_DIRS "."
                    REQUIRES "driver"
                    REQUIRES "pn532"
                    REQUIRES "NFC_Reader")
