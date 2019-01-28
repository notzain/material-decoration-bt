![Demo](data/preview.png)

## material-decoration-bt
Material-styled window decoration theme for KWin. Resembles the decorations in Windows 10.
Extensive customization possible through src/Decoration.cc; theme also takes colors from the user's color scheme and KWin window rules.

Kvantum theme recommended for use with this theme overall: https://github.com/Luwx/Fluent-kvantum

If you so choose to use the theme above, place [this color scheme](https://github.com/yagomont/warna-mac-kvmd/blob/master/WarnaMac20DarkerKVMD.colors) in ~/.kde/share/apps/color-schemes/ ; it should blend in with Fluent Kvantum if you choose not to use top toolbars.

### Installation

##### Prerequisites

* KDecoration2
* other KDE Framework 5 headers; see the output of ´make´
* cmake

##### Building from source

```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr ..
make
sudo make install
```
