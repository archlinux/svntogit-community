# Maintainer:
# Contributor: Eric Bélanger <eric@archlinux.org>

pkgbase=python-pygame
pkgname=python2-pygame
pkgver=1.9.4
pkgrel=1
pkgdesc="Python game library"
arch=('x86_64')
url="http://www.pygame.org/"
license=('LGPL')
depends=('sdl_mixer' 'sdl_ttf' 'sdl_image' 'python2' 'portmidi')
makedepends=('python2-setuptools')
source=(https://pypi.io/packages/source/p/pygame/pygame-$pkgver.tar.gz)
sha1sums=('9387835fab92a8b4a3c9e51e2c9267a670476aaa')

prepare() {
  cd pygame-${pkgver}
  find . -type f -exec sed -i 's#/usr/bin/env python#/usr/bin/env python2#' {} +
}

package_python2-pygame() {
  cd pygame-${pkgver}
  python2 config.py -auto
  python2 setup.py install --root="${pkgdir}" --prefix=/usr

# Copying the examples and tests
  cp -R examples lib/* "${pkgdir}/usr/lib/python2.7/site-packages/pygame"
  cp -R test/* "${pkgdir}/usr/lib/python2.7/site-packages/pygame/tests"

# Fixing permissions
  chmod 644 "${pkgdir}"/usr/include/python2.7/pygame/*
}
