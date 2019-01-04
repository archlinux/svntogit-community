# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Maintainer: Maxim Baz <$pkgname at maximbaz dot com>
# Contributor: Fabio 'Lolix' Loli <lolix@disroot.org> -> https://github.com/FabioLolix
# Contributor: Maximilian Kindshofer <maximilian@kindshofer.net>

pkgname=kitty
pkgver=0.13.2
pkgrel=1
pkgdesc="A modern, hackable, featureful, OpenGL based terminal emulator"
arch=('x86_64')
url="https://github.com/kovidgoyal/kitty"
license=('GPL3')
depends=('python3' 'freetype2'  'fontconfig' 'wayland' 'libx11' 'libxkbcommon-x11' 'hicolor-icon-theme' 'libgl')
makedepends=('pkg-config' 'python-setuptools' 'libxinerama' 'libxcursor' 'libxrandr' 'libxkbcommon' 'glfw-x11' 'wayland-protocols' 'mesa' 'python-sphinx')
optdepends=('imagemagick: viewing images with icat')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/kovidgoyal/$pkgname/archive/v$pkgver.tar.gz")
sha512sums=('cd2a3825cda8dbdf6d8df042de018e78c1b7faea8b01ac0e3524dd17d3ae577f28376fb9872bcb2f31b851ec7a02cc1bb9011d08002fd1509891c40393274f3a')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  python3 setup.py linux-package
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  python3 setup.py linux-package --prefix ${pkgdir}/usr

  install -Dm644 ${pkgdir}/usr/share/icons/hicolor/256x256/apps/kitty.png ${pkgdir}/usr/share/pixmaps/kitty.png
}
