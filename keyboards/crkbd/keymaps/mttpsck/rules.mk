OLED_ENABLE  = yes
MOUSEKEY_ENABLE = yes
VIA_ENABLE         = no         # Enable VIA
VIAL_ENABLE         = no         # Enable VIAL
COMBO_ENABLE = yes
WPM_ENABLE = yes
SRC +=  ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/mode_icon_reader.c \
        ./lib/host_led_state_reader.c \
        ./lib/timelogger.c \
