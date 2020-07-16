# Maintainer: Brett Cornwall <ainola@archlinux.org>
# Contributor: Omar Pakker

pkgname=wlroots
pkgver=0.11.0
pkgrel=1
license=('MIT')
pkgdesc='Modular Wayland compositor library'
url='https://github.com/swaywm/wlroots'
arch=('x86_64')
depends=(
    'libinput'
    'libxkbcommon'
    'opengl-driver'
    'pixman'
    'xcb-util-errors'
    'xcb-util-image'
    'xcb-util-wm'
)
makedepends=(
    'meson'
    'ninja'
    'wayland-protocols'
)
provides=(
    'libwlroots.so'
)
source=(
    "$pkgname-$pkgver.tar.gz::https://github.com/swaywm/wlroots/archive/$pkgver.tar.gz"
    "https://github.com/swaywm/wlroots/releases/download/$pkgver/wlroots-$pkgver.tar.gz.sig"
)
sha256sums=('a7645e77229aab4942748c621be8bdb8b073d94f35f3e032b867246862bf2d01'
            'SKIP')
validpgpkeys=(
    '9DDA3B9FA5D58DD5392C78E652CB6609B22DA89A' # Drew DeVault
    '4100929B33EEB0FD1DB852797BC79407090047CA' # Sway signing key
)

build() {
    meson "$pkgname-$pkgver" build \
        --prefix=/usr \
        --buildtype=plain \
        -Dlibcap=enabled \
        -Dlogind=enabled \
        -Dlogind-provider=systemd \
        -Dxcb-errors=enabled \
        -Dxcb-icccm=enabled \
        -Dxcb-xkb=enabled \
        -Dxwayland=enabled \
        -Dx11-backend=enabled
    ninja -C build
}

package() {
    DESTDIR="$pkgdir" ninja -C build install
    install -Dm644 "$pkgname-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgname/"
}
