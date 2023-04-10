# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Maintainer: Bruno Pagani <archange@archlinux.org>

pkgname=kvantum
pkgver=1.0.10
pkgrel=1
pkgdesc='SVG-based theme engine for Qt5/6 (including config tool and extra themes)'
arch=(x86_64)
url='https://github.com/tsujan/Kvantum'
license=(GPL)
provides=(kvantum-qt5)
conflicts=(kvantum-qt5)
replaces=(kvantum-qt5)
depends=(qt5-svg kwindowsystem hicolor-icon-theme)
makedepends=(cmake qt5-tools qt6-tools qt6-svg)
optdepends=('qt6-svg: Qt6 style')
source=(https://github.com/tsujan/Kvantum/releases/download/V$pkgver/Kvantum-$pkgver.tar.xz{,.asc})
sha256sums=('4a070a1a6fac3d1861010aa44d34e665e4697bc64c4c5015a6448203c31f1f1f'
            'SKIP')
validpgpkeys=(19DFDF3A579BD509DBB572D8BE793007AD22DF7E) # Pedram Pourang <tsujan2000@gmail.com>

prepare() {
  # Fix Qt6 build with Qt5 installed
  sed -e 's|Qt6 Qt5|Qt6|' -i Kvantum-$pkgver/Kvantum/*/CMakeLists.txt
}

build() {
  cmake -B build5 -S Kvantum-$pkgver/Kvantum \
    -DCMAKE_INSTALL_PREFIX=/usr
  make -C build5

  cmake -B build6 -S Kvantum-$pkgver/Kvantum \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DENABLE_QT5=OFF
  make -C build6
}

package() {
  DESTDIR="$pkgdir" cmake --install build5 
  DESTDIR="$pkgdir" cmake --install build6
}
