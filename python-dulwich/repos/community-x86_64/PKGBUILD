# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.20.19
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-certifi' 'python-urllib3')
makedepends=('python-setuptools')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('7a5c976c5ce737ec207be1815c654351bf1d0387fc6480ed32cd58c9d0e2cda9')
b2sums=('89a63943a150ccd15549898689af68769b7f0cf25065e6cf9c9c5addb0fb3635fbc5c0fd23c79d2facdaf3086fd5e853e7ac3f9690f7fe40e0b561f0709651e9')

build() {
  cd $_name-$pkgver
  python setup.py build
}

check() {
  cd $_name-$pkgver
  python -m unittest dulwich.tests.test_suite
}

package() {
  cd $_name-$pkgver
  export PYTHONHASHSEED=0
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim:set ts=2 sw=2 et:
