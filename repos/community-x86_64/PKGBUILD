# Maintainer: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Fabio 'Lolix' Loli <lolix@disroot.org> -> https://github.com/FabioLolix
# Contributor: Maximilian Kindshofer <maximilian@kindshofer.net>

pkgname=kitty
pkgver=0.11.0
pkgrel=1
pkgdesc="A modern, hackable, featureful, OpenGL based terminal emulator"
arch=('x86_64')
url="https://github.com/kovidgoyal/kitty"
license=('GPL3')
depends=('python3' 'freetype2'  'fontconfig' 'wayland' 'libx11' 'libxkbcommon-x11' 'hicolor-icon-theme' 'libgl')
makedepends=('pkg-config' 'python-setuptools' 'libxinerama' 'libxcursor' 'libxrandr' 'libxkbcommon' 'glfw-x11' 'wayland-protocols' 'mesa' 'python-sphinx')
optdepends=('imagemagick: viewing images with icat')
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/kovidgoyal/$pkgname/archive/v$pkgver.tar.gz")
sha512sums=('33e9d0a8de5531d9dad341054dde7986eee9ad9ef1c97809c6ee7f3a5fc5ae210eff59ac02e571c31f233676329143f38f4e95d8971d28b21e6befc362e46984')

build() {
  cd "$srcdir/$pkgname-$pkgver"
  python3 setup.py linux-package
}

package() {
  cd "$srcdir/$pkgname-$pkgver"

  python3 setup.py linux-package --prefix ${pkgdir}/usr

  install -Dm644 ${pkgdir}/usr/share/icons/hicolor/256x256/apps/kitty.png ${pkgdir}/usr/share/pixmaps/kitty.png
}
