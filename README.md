# Defect Detection Application
> The project is assigned by [FAREL Plastic](https://www.farel.com.tr/) that is a joint company partnered by [Farplas](https://www.farplas.com/) and [Wirthwein DE](https://www.wirthwein.de/en/).

This project aims to detect some specific surface defects on plastic surfaces. The final product targets operation on a conveyor belt. This code includes MATLAB modeling (with deep learning), final algorithm (conventional computer vision) and GUI (.NET) in C++ programming language.

The problem is clearly stated below, the defects are hard to be spotted by naked eye. So, it is best practice to adjust photometric settings of the lens & camera to acquire some data containing defect information.

![image](https://user-images.githubusercontent.com/97564250/232168728-1048200d-bf28-471a-9e33-2c4216e59127.png)
_Fig. 1: Two kinds of surface defects that are slightly whiter areas (e.g. the one on the left can be depicted as semi-ellipse)_
## Hardware

- Lens:				Fujinon HF8XA-5M
- Camera:			TIS DMK 27AUP031 (QE: best in 400-600 nm range)
- Sensor:     CMOS Aptina MT9P031
- Connection: USB 3.0 SuperSpeed

## Dependencies

- Language standard - C++14
- .NET Framework(C++/CLI) v4.7.2
- OpenCV v4.5.0
- Camera library:
	-	[tiscamera](https://github.com/TheImagingSource/tiscamera) (for Linux)
	-	TIS_UDSHL12_x64 (for Win, packed in SDK)
- Camera driver: [TIS Camera v2.9.8](https://www.theimagingsource.com/en-de/support/download/icwdmuvccamtis-2.9.8/)
- Camera C++ SDK: [IC C++ v3.5.7](https://www.theimagingsource.com/en-de/support/download/icimagingcontrolcpp-3.5.7/)

> **Warning** In case of broken URLS, all the software are likely to be found [here](https://www.theimagingsource.com/en-de/support/download/). 

## Installation
Simply download content in `/bin/Release/` and follow the steps from `setup.exe`. Only Windows x64 installation is provided. The camera driver has to be installed seperately. While, other dependencies are development related.

## MATLAB Experiment (learning-based)
This block under `/src/matlab/` section implements an Faster-RCNN based training to automatically detect and locate specific defect types. Although not used by this project, a MATLAB toolbox for TIS Camera can found [here](https://www.theimagingsource.com/en-de/support/download/icmatlabr2013b-3.4.0.58/).


https://user-images.githubusercontent.com/97564250/232167981-db8d8435-82a1-4b07-b515-fd259fd07898.mp4

_Fig. 2: Learning-based experiment (white pixels are candidate features, bounding box gives the most probable defect)_

## GUI (filter-based)
GUI is designed and compiled in .NET Framework. The algorithm leveraged conventional filter-based computer vision techniques, powered by OpenCV. In contrast to automated bounding boxes of learning-based simulation, this implementation needs user input for **fixed** ROIs. It is due to the fact that the system is assumed to stable on a conveyer belt; as a result, location automation is discarded to increase performance.


https://user-images.githubusercontent.com/97564250/232170817-78d9422e-edc1-4183-b817-39c488dad4c5.mp4

_Fig. 3: GUI demonstration by adjusting user defined ROI and calibration_
