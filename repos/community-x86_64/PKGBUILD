# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Alad Wenter <alad@archlinux.org>
# Contributor: Matthew McGinn <mamcgi@gmail.com>
# Contributor: Gryffyn
# Contributor: Tetsumi

pkgname=python-pygame
pkgver=2.0.3
pkgrel=1
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org"
license=('LGPL')
makedepends=('python-setuptools' 'sdl2')
depends=('python' 'sdl2_mixer' 'sdl2_ttf' 'sdl2_image' 'portmidi')
source=("https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz")
sha256sums=('d097f2802a9d0d7fb40c49c789af2984b202baa8fd32701082598755f5973f51')

build() {
    cd pygame-"$pkgver"
    python setup.py build
}

package() {
    cd pygame-"$pkgver"
    python setup.py install --root="$pkgdir" --prefix=/usr --skip-build
}
