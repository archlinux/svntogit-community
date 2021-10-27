# Maintainer: Alad Wenter <alad@archlinux.org>
# Contributor: Matthew McGinn <mamcgi@gmail.com>
# Contributor: Gryffyn
# Contributor: Tetsumi
pkgname=python-pygame
pkgver=2.0.1
pkgrel=3
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org"
license=('LGPL')
makedepends=('python-setuptools' 'sdl2')
depends=('python' 'sdl2_mixer' 'sdl2_ttf' 'sdl2_image' 'portmidi')
source=("https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz")
sha256sums=('8b1e7b63f47aafcdd8849933b206778747ef1802bd3d526aca45ed77141e4001')

build() {
    cd pygame-"$pkgver"
    python setup.py build
}

package() {
    cd pygame-"$pkgver"
    python setup.py install --root="$pkgdir" --prefix=/usr --skip-build
}
