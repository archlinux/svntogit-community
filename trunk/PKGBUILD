# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Timothée Ravier <tim@siosm.fr>

_name=dulwich
pkgname=python-dulwich
pkgver=0.20.25
pkgrel=1
pkgdesc='Pure-Python implementation of the Git file formats and protocols'
arch=('x86_64')
url=https://www.dulwich.io
license=('GPL')
depends=('python-certifi' 'python-urllib3')
makedepends=('python-setuptools')
checkdepends=('python-gpgme')
optdepends=('python-fastimport: for fast-import support'
            'python-gpgme: for PGP signature support'
            'python-idna: for HTTPS support via urllib3'
            'python-pyopenssl: for HTTPS support via urllib3'
            'python-pyinotify: to watch for changes to refs')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/$_name/$_name-$pkgver.tar.gz")
sha256sums=('79baea81583eb61eb7bd4a819ab6096686b362c626a4640d84d4fc5539139353')
b2sums=('bdb053218bde037cf6cf3f2e0e6f2abd881537cfe2fb4a72f3169ea74ae6c4591def2d9eb1f3abcfbaf209e04931aa7c22fe38527e063e3ac77485afbe4330d1')

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
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
}

# vim:set ts=2 sw=2 et:
