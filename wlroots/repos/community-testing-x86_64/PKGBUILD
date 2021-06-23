# Maintainer: Brett Cornwall <ainola@archlinux.org>
# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Omar Pakker

pkgname=wlroots
pkgver=0.14.0
pkgrel=1
license=('MIT')
pkgdesc='Modular Wayland compositor library'
url='https://github.com/swaywm/wlroots'
arch=('x86_64')
depends=(
    'libinput'
    'libseat'
    'libxkbcommon'
    'opengl-driver'
    'pixman'
    'xcb-util-errors'
    'xcb-util-renderutil'
    'xcb-util-wm'
)
makedepends=(
    'meson'
    'ninja'
    'wayland-protocols'
    'xorg-xwayland'
)
optdepends=(
    'xorg-xwayland: Xwayland support'
)
provides=(
    'libwlroots.so'
)
source=(
    "$pkgname-$pkgver.tar.gz::https://github.com/swaywm/wlroots/archive/$pkgver.tar.gz"
    "https://github.com/swaywm/wlroots/releases/download/$pkgver/wlroots-$pkgver.tar.gz.sig"
)
sha256sums=('2a8435bf63681868699c4e3975df31cb111ad2d3f35740179036083f87382ac7'
            'SKIP')
validpgpkeys=(
    '34FF9526CFEF0E97A340E2E40FDE7BE0E88F5E48' # Simon Ser
    '9DDA3B9FA5D58DD5392C78E652CB6609B22DA89A' # Drew DeVault
    '4100929B33EEB0FD1DB852797BC79407090047CA' # Sway signing key
)

build() {
    arch-meson "$pkgname-$pkgver" build
    ninja -C build
}

package() {
    DESTDIR="$pkgdir" ninja -C build install
    install -Dm644 "$pkgname-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgname/"
}
