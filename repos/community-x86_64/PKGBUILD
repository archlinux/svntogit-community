# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: csslayer <wengxt AT gmail com>

pkgname=fcitx5
pkgver=0.0.0.20201030
_commit=70959133711d7533e0e96acc9cb7a9308e929806
_endictver=20121020
pkgrel=1
pkgdesc="Next generation of fcitx"
arch=('x86_64')
url="https://github.com/fcitx/fcitx5"
license=('GPL')
conflicts=('fcitx')
groups=('fcitx5-im')
depends=('cairo' 'enchant' 'iso-codes' 'libgl' 'libxkbcommon-x11' 'pango' 'systemd' 'wayland'
         'wayland-protocols' 'xcb-imdkit' 'xcb-util-wm' 'libxkbfile' 'fmt' 'gdk-pixbuf2'
         'cldr-emoji-annotation')
makedepends=('extra-cmake-modules')
source=("https://github.com/fcitx/fcitx5/archive/$_commit/fcitx5-$_commit.tar.gz"
        https://download.fcitx-im.org/data/en_dict-$_endictver.tar.gz)
sha512sums=('008df9e15b3566cab85344daabbb53fdd571880e987d98746f8df3d275eaff78bb18b3f1abf89ae4f54fce0eab41bb800ef4a0300b943b0a5d01eb2516599821'
            '8418bd02492bfd786c0fab93be4400ef027ec8e9fac02220cc1f653f5eb67f54573a6a84a15baba19bb34ab892745c87df16499d6304ea75009131e2ab3b97f2')

prepare() {
  cd $pkgname-$_commit/src/modules/spell/dict
  ln -s "$srcdir"/en_dict-$_endictver.tar.gz ./
}

build() {
  cd $pkgname-$_commit

  cmake -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_INSTALL_LIBDIR=/usr/lib .
  make
}

check() {
  cd $pkgname-$_commit
  make test
}

package() {
  cd $pkgname-$_commit
  make DESTDIR="$pkgdir" install
}
