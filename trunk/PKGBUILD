# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Fabio 'Lolix' Loli <lolix@disroot.org> -> https://github.com/FabioLolix
# Contributor: Maximilian Kindshofer <maximilian@kindshofer.net>

pkgname=kitty
pkgver=0.12.3
pkgrel=1
pkgdesc="A modern, hackable, featureful, OpenGL based terminal emulator"
arch=('x86_64')
url="https://github.com/kovidgoyal/kitty"
license=('GPL3')
depends=('python3' 'freetype2'  'fontconfig' 'wayland' 'libx11' 'libxkbcommon-x11' 'hicolor-icon-theme' 'libgl')
makedepends=('pkg-config' 'python-setuptools' 'libxinerama' 'libxcursor' 'libxrandr' 'libxkbcommon' 'glfw-x11' 'wayland-protocols' 'mesa' 'python-sphinx')
optdepends=('imagemagick: viewing images with icat')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/kovidgoyal/$pkgname/archive/v$pkgver.tar.gz")
sha512sums=('a70c20f5d71db8ecd63c23f593abb156953a07493a7ca8a111ae77f6682dc252fb036a4fe99f19764fc1d339af5afad6cb7072a250160bb663cac1a49684d36b')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  python3 setup.py linux-package
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  python3 setup.py linux-package --prefix ${pkgdir}/usr

  install -Dm644 ${pkgdir}/usr/share/icons/hicolor/256x256/apps/kitty.png ${pkgdir}/usr/share/pixmaps/kitty.png
}
