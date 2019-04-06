# Maintainer:
# Contributor: Eric Bélanger <eric@archlinux.org>

pkgbase=python-pygame
pkgname=python2-pygame
pkgver=1.9.5
pkgrel=1
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org/"
license=('LGPL')
depends=('sdl_mixer' 'sdl_ttf' 'sdl_image' 'python2' 'portmidi')
makedepends=('python2-setuptools')
source=(https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz)
sha1sums=('72bec05e052f1b271f4fab219d078d0f768a72ea')

prepare() {
  cd pygame-${pkgver}
  # don't ship python2 *and* python3 compiled bytecode from upstream
  find . -name "*.pyc" -delete
  find . -type f -exec sed -i 's#/usr/bin/env python#/usr/bin/env python2#' {} +
}

build() {
  cd pygame-${pkgver}
  python2 setup.py build
}

package_python2-pygame() {
  cd pygame-${pkgver}
  python2 setup.py install --root="${pkgdir}" --prefix=/usr

# Copying the examples
  cp -R examples "${pkgdir}/usr/lib/python2.7/site-packages/pygame"

# Fixing permissions
  chmod 644 "${pkgdir}"/usr/include/python2.7/pygame/*
}
