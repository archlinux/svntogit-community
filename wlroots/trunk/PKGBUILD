# Maintainer: Ainola <ainola@archlinux.org>

pkgname=wlroots
pkgver=0.4
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
makedepends=('meson' 'ninja' 'wayland-protocols')
source=(
    "$pkgname-$pkgver.tar.gz::https://github.com/swaywm/wlroots/archive/$pkgver.tar.gz"
    "https://github.com/swaywm/wlroots/releases/download/0.4/wlroots-$pkgver.tar.gz.sig"
)
sha256sums=('f9308d4c9a0dbcf0009f5577e390c11b1bffdc38fa92681cc37dc2ec7ab927f0'
            'SKIP')
validpgpkeys=('9DDA3B9FA5D58DD5392C78E652CB6609B22DA89A') # Drew DeVault

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
