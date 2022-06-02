# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: csslayer <wengxt AT gmail com>

pkgname=fcitx5
pkgver=5.0.17
pkgrel=1
pkgdesc="Next generation of fcitx"
arch=('x86_64')
url="https://github.com/fcitx/fcitx5"
license=('GPL')
conflicts=('fcitx')
groups=('fcitx5-im')
depends=('cairo' 'enchant' 'iso-codes' 'libgl' 'libxkbcommon-x11' 'pango' 'systemd' 'wayland'
         'wayland-protocols' 'xcb-imdkit' 'xcb-util-wm' 'libxkbfile' 'fmt' 'gdk-pixbuf2'
         'unicode-cldr-annotations')
makedepends=('extra-cmake-modules' 'ninja')
source=("https://download.fcitx-im.org/fcitx5/fcitx5/fcitx5-${pkgver}_dict.tar.xz"{,.sig})
sha512sums=('fe2d45ffacef93aa6c7747a30d99923e6ce5fb8c54c9093fc1b3a87606eb4b9a789951110ac33371b191ccdd9e43a2063ab2665946c0c0f447e2c574f784491f'
            'SKIP')
validpgpkeys=('2CC8A0609AD2A479C65B6D5C8E8B898CBF2412F9') # Weng Xuetian <wengxt@gmail.com>

build() {
  cd $pkgname-$pkgver

  cmake -GNinja -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=/usr/lib \
        -DCMAKE_INSTALL_SYSCONFDIR=/etc -DCMAKE_INSTALL_LIBEXECDIR=/usr/lib .
  ninja
}

check() {
  cd $pkgname-$pkgver
  ninja test
}

package() {
  cd $pkgname-$pkgver
  DESTDIR="$pkgdir" ninja install
}
