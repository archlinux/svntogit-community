# Maintainer: Brett Cornwall <ainola@archlinux.org>
# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Omar Pakker

pkgname=wlroots
pkgver=0.15.1
pkgrel=1
license=('MIT')
pkgdesc='Modular Wayland compositor library'
url='https://gitlab.freedesktop.org/wlroots/wlroots'
arch=('x86_64')
depends=(
    'libglvnd'
    'libinput'
    'seatd' 'libseat.so'
    'libxcb'
    'libxkbcommon' 'libxkbcommon.so'
    'opengl-driver'
    'pixman' 'libpixman-1.so'
    'systemd-libs' 'libudev.so'
    'vulkan-icd-loader' 'libvulkan.so'
    'wayland'
    'xcb-util-errors'
    'xcb-util-renderutil'
    'xcb-util-wm'
)
makedepends=(
    'glslang'
    'meson'
    'ninja'
    'systemd'
    'vulkan-headers'
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
    "$pkgname-$pkgver.tar.gz::https://gitlab.freedesktop.org/wlroots/wlroots/-/releases/$pkgver/downloads/wlroots-$pkgver.tar.gz"
    "https://gitlab.freedesktop.org/wlroots/wlroots/-/releases/$pkgver/downloads/wlroots-$pkgver.tar.gz.sig"
)
sha256sums=('5b92f11a52d978919ed1306e0d54c9d59f1762b28d44f0a2da3ef3b351305373'
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
