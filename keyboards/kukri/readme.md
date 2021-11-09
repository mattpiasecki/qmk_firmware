# Kukri

![Kukri](https://i.imgur.com/)

Kukri is a 45% traditionally staggered keyboard featuring thumb-accessible rolly encoders and a 6.9 degree inward slope for increased wrist comfort and a snap-offable right arrow which allows for 2x2 POS support in the bottom right corner.  

* Keyboard Maintainer: [H. Bond](https://github.com/drhigsby)
* Hardware Supported: BKF (https://github.com/drhigsby/kukri)
* Hardware Availability: open-source stacked acrylic case design available at maintainer's github / make your own

Make example for this keyboard (after setting up your build environment):

    make kukri:default

To place this keyboard into bootloader mode, press the reset button on the PCB or short the RST and GND pins on the pro micro. 

Flashing example for this keyboard:

    make kukri:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
