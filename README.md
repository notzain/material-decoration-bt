![Demo](data/preview.png)

## material-decoration-bt
Material-styled window decoration theme for KWin. Resembles the decorations in Windows 10.
Extensive customization possible through src/Decoration.cc; theme also takes colors from the user's color scheme and KWin window rules.

Kvantum theme recommended for use with this theme overall: https://github.com/Luwx/Fluent-kvantum

If you so choose to use the theme above, place [this color scheme](https://github.com/yagomont/warna-mac-kvmd/blob/master/WarnaMac20DarkerKVMD.colors) in ~/.kde/share/apps/color-schemes/ ; it should blend in with Fluent Kvantum if you choose not to use top toolbars.

### Features of this fork
* Consistent shadows with great contrast (from the Breeze theme)
* 0.635 opacity by default, picked by trial and error to blend in with the themes above
* Tool to facillitate opacity changing 

### Installation

##### Prerequisites

* KDecoration2
* Might need other KDE Framework 5 headers; see the output of ´cmake´
* cmake

##### Building and installing

```
git clone https://github.com/yagomont/material-decoration-bt.git
cd material-decoration-bt/build
cmake -DCMAKE_INSTALL_PREFIX=/usr ..
sudo make -j4 install
```
