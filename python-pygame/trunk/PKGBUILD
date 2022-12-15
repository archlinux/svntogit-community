# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Alad Wenter <alad@archlinux.org>
# Contributor: Matthew McGinn <mamcgi@gmail.com>
# Contributor: Gryffyn
# Contributor: Tetsumi

pkgname=python-pygame
pkgver=2.1.2
pkgrel=3
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org"
license=('LGPL')
makedepends=('python-setuptools' 'sdl2')
depends=('python' 'sdl2_mixer' 'sdl2_ttf' 'sdl2_image' 'portmidi')
source=("https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz")
sha256sums=('d6d0eca28f886f0477cd0721ac688189155a587f2bb8eae740e52ca56c3ad23c')

build() {
    cd pygame-"$pkgver"
    python setup.py build
}

package() {
    cd pygame-"$pkgver"
    python setup.py install --root="$pkgdir" --prefix=/usr --skip-build
}
