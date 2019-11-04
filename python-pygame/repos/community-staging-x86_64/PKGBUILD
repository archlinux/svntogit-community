# Maintainer: Alad Wenter <alad@archlinux.org>
# Contributor: Matthew McGinn <mamcgi@gmail.com>
# Contributor: Gryffyn
# Contributor: Tetsumi
pkgname=python-pygame
pkgver=1.9.6
pkgrel=3
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org"
license=('LGPL')
makedepends=('python-setuptools')
depends=('python' 'sdl_mixer' 'sdl_ttf' 'sdl_image' 'portmidi')
source=("https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz")
sha256sums=('301c6428c0880ecd4a9e3951b80e539c33863b6ff356a443db1758de4f297957')

build() {
    cd pygame-"$pkgver"
    python setup.py build
}

package() {
    cd pygame-"$pkgver"
    python setup.py install --root="$pkgdir" --prefix=/usr --skip-build
}
