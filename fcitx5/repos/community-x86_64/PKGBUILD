# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: csslayer <wengxt AT gmail com>

pkgname=fcitx5
pkgver=0.0.0.20201028
_commit=386d7a7406545ee423fb5a02b5843c3f14776280
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
sha512sums=('ba99123db0ad3ce56720d9d08da99b6a111c0c5646243c086541f182c78be5f4e552618363b6e2e015b98fc8bc0d5f2b137838173000437a42c923d5787234e6'
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
