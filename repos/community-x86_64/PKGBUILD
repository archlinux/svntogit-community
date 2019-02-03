# Maintainer: Ainola <ainola@archlinux.org>

pkgname=wlroots
pkgver=0.3
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
source=("$pkgname-$pkgver.tar.gz::https://github.com/swaywm/wlroots/archive/$pkgver.tar.gz")
sha256sums=('6fe527dcaf223015276f6e8592becd1cc5215166d943d636a9fa578f57db684e')

build() {
    arch-meson "$pkgname-$pkgver" build \
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
