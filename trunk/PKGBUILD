# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Fabio 'Lolix' Loli <lolix@disroot.org> -> https://github.com/FabioLolix
# Contributor: Maximilian Kindshofer <maximilian@kindshofer.net>

pkgname=kitty
pkgver=0.11.3
pkgrel=2
pkgdesc="A modern, hackable, featureful, OpenGL based terminal emulator"
arch=('x86_64')
url="https://github.com/kovidgoyal/kitty"
license=('GPL3')
depends=('python3' 'freetype2'  'fontconfig' 'wayland' 'libx11' 'libxkbcommon-x11' 'hicolor-icon-theme' 'libgl')
makedepends=('pkg-config' 'python-setuptools' 'libxinerama' 'libxcursor' 'libxrandr' 'libxkbcommon' 'glfw-x11' 'wayland-protocols' 'mesa' 'python-sphinx')
optdepends=('imagemagick: viewing images with icat')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/kovidgoyal/$pkgname/archive/v$pkgver.tar.gz")
sha512sums=('a5b4af74c70222df8ef6a6a8414eb18b7ebc5c959b4031d7a67d636ee912800a2c5fe627c57cf39d9a9eb9c6c1904dbebb4d40575cc8673bf704dd36f58b0783')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  python3 setup.py linux-package
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  python3 setup.py linux-package --prefix ${pkgdir}/usr

  install -Dm644 ${pkgdir}/usr/share/icons/hicolor/256x256/apps/kitty.png ${pkgdir}/usr/share/pixmaps/kitty.png
}
