# Maintainer: Ainola <ainola@archlinux.org>
# Contributor: Omar Pakker

pkgbase=wlroots
pkgname=(wlroots rootston)
pkgver=0.6.0
pkgrel=2
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
    "$pkgbase-$pkgver.tar.gz::https://github.com/swaywm/wlroots/archive/$pkgver.tar.gz"
    "https://github.com/swaywm/wlroots/releases/download/$pkgver/wlroots-$pkgver.tar.gz.sig"
)
sha256sums=('9cf3716f3683d800df8b150f256ff66dad65faf13a9d67c284f67a9444d28c70'
            'SKIP')
validpgpkeys=('9DDA3B9FA5D58DD5392C78E652CB6609B22DA89A') # Drew DeVault

build() {
    meson "$pkgbase-$pkgver" build \
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

package_wlroots() {
    DESTDIR="$pkgdir" ninja -C build install
    install -Dm644 "$pkgbase-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/$pkgbase/"
}

package_rootston() {
    depends=(wlroots)

    install -Dm755 "build/rootston/rootston" -t "$pkgdir/usr/bin/"
    install -Dm755 "$pkgbase-$pkgver/rootston/rootston.ini.example" -t "$pkgdir/usr/share/doc/rootston/"
    install -Dm644 "$pkgbase-$pkgver/LICENSE" -t "$pkgdir/usr/share/licenses/rootston/"
}
