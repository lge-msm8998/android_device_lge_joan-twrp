# android_device_lge_joan
Tree for building TWRP for LGE V30 (Joan)

## TWRP device tree for Joan (LG V30)

https://github.com/lifehackerhansol-android/android_device_lge_joan-twrp/tree/android-9.0

## Kernel Sources

https://github.com/LineageOS/android_kernel_lge_msm8998

## How to compile

```sh
export ALLOW_MISSING_DEPENDENCIES=true
. build/envsetup.sh
lunch omni_joan-eng
make -j# recoveryimage
```

## Device specifications

| Device       | LG V30                                          |
| -----------: | :---------------------------------------------- |
| SoC          | Qualcomm MSM8998 Snapdragon 835                 |
| CPU          | Quad-core 2.45GHz Kryo & quad-core 1.9GHz Kryo  |
| GPU          | 710MHz Adreno 540                               |
| Memory       | 4GB RAM (LPDDR4X)                               |
| Shipped Android version | 7.1.1                                |
| Storage      | 64GB / 128GB (UFS 2.1 Flash) + microSD Card     |
| Battery      | Non-removable Li-Po 3300 mAh                    |
| Dimensions   | 151.7 x 75.4 x 7.3 mm                           |
| Display      | 2880 x 1440 (18:9), 6 inch POLED, HDR10         |
| Dust and Water resistance | IP68, MIL-STD-810G                 |
| Rear camera 1 | 16MP (hi553), 1-micron pixels, f/1.6, 3-axis OIS, PDAF, LED flash, 4K 30 fps, 1080p 60 fps, 720p 240 fps video |
| Rear camera 2 | 13MP (IMX 351), 1-micron pixels, f/1.9, no AF       |
| Front camera | 5MP (s5k3m3), 1.12-micron pixels, f/2.2 1080p 30 fps video |

## Device picture

![LG V30](http://www.lg.com/us/mobile-phones/v30/assets/images/SpecsPage/IntroModule/phone-front.png "LG V30 in Silver")


