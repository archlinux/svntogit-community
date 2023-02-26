# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Alad Wenter <alad@archlinux.org>
# Contributor: Matthew McGinn <mamcgi@gmail.com>
# Contributor: Gryffyn
# Contributor: Tetsumi

pkgname=python-pygame
pkgver=2.1.3
pkgrel=1
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org"
license=('LGPL')
makedepends=('python-setuptools' 'sdl2')
depends=('python' 'sdl2_mixer' 'sdl2_ttf' 'sdl2_image' 'portmidi')
source=("https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz")
sha256sums=('df29c4369df9231eebffac801fa7af021279d7e9dc4c1cae698cc4077c98d069')

build() {
    cd pygame-"$pkgver"
    python setup.py build
}

package() {
    cd pygame-"$pkgver"
    python setup.py install --root="$pkgdir" --prefix=/usr --skip-build
}
