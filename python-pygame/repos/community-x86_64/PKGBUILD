# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Alad Wenter <alad@archlinux.org>
# Contributor: Matthew McGinn <mamcgi@gmail.com>
# Contributor: Gryffyn
# Contributor: Tetsumi

pkgname=python-pygame
pkgver=2.1.3
pkgrel=3
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org"
license=('LGPL')
depends=('glibc' 'libpng' 'python' 'sdl2' 'sdl2_mixer' 'sdl2_ttf' 'sdl2_image' 'portmidi')
makedepends=('python-build' 'python-installer' 'python-setuptools' 'python-wheel' 'sdl2')
optdepends=(
    'python-numpy: for examples'
)
source=("https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz")
sha256sums=('df29c4369df9231eebffac801fa7af021279d7e9dc4c1cae698cc4077c98d069')
b2sums=('9f725e8afbc08f25a6f4ada3f66c1e96f6b3ff8efa1a14da965a79d0a383ecb2e5bec569b4c2665b198315d0097f4e5164e9f795d70f8d2870c8a599850df4ea')

build() {
    cd pygame-"$pkgver"
    python -m build --wheel --no-isolation
}

package() {
    cd pygame-"$pkgver"
    python -m installer --destdir="$pkgdir" dist/*.whl
}
