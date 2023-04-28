# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>

pkgname=ctwm
pkgver=4.1.0
pkgrel=1
pkgdesc="Claude's Tab Window Manager, a lightweight window manager for X"
arch=(x86_64)
url='https://ctwm.org/'
license=('custom:MIT' 'custom:X')
depends=(libjpeg-turbo libxmu libxpm xorg-xrandr)
makedepends=(cmake ctags doxygen gendesk graphviz ninja)
source=("https://ctwm.org/dist/$pkgname-$pkgver.tar.xz")
b2sums=('54baba4c51b7bebefc72d5438d9051a8474b3401de847cbda895ecca6954438cde60193b9a039ee9010d349700ae04824d5df87b03d6d6d9eb809cb5b3378767')

prepare() {
  gendesk -f -n --pkgname $pkgname --pkgdesc "$pkgdesc" --name CTWM
  gendesk -f -n -wm --pkgname ${pkgname}_kdm --exec $pkgname --name CTWM
}

build() {
  cmake \
    -B build \
    -D CMAKE_C_FLAGS="$CFLAGS -fPIC -w" \
    -D CMAKE_INSTALL_PREFIX=/usr \
    -G Ninja \
    -S $pkgname-$pkgver
  ninja -C build
}

package() {
  DESTDIR="$pkgdir" ninja -C build install
  install -Dm644 $pkgname.desktop \
    "$pkgdir"/usr/share/xsessions/$pkgname.desktop
  install -Dm644 ${pkgname}_kdm.desktop \
    "$pkgdir"/usr/share/apps/kdm/sessions/$pkgname.desktop
  install -Dm644 "$pkgname-$pkgver/COPYRIGHT" \
    "$pkgdir/usr/share/licenses/ctwm/COPYRIGHT"
}
